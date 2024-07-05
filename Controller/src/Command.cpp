#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error number definitions
#include <termios.h> // POSIX terminal control definitions
#include <unistd.h> // UNIX standard function definitions
#include <condition_variable>
#include <atomic>
#include <thread>
#include <mutex>
#include "Command.h"
#include "Command_translate.h"

#define PORT "/dev/ttyACM0"

std::atomic<bool> running(true);

void Command::add_shared_data(std::string cmd) {
    std::unique_lock<std::mutex> lock(mtx);
    commands.push_back(cmd);
    dataReady = true;
    cv.notify_all();
}

void Command::com_producer() {
    int opset = 0;
    char read_buf[18] = {'\0'};
    while(running) {
        int serialPort = open(PORT, O_RDWR);

        int num_bytes = read(serialPort, read_buf + opset, 18);
        opset += num_bytes;

        // std::cout << "num byte: "<< num_bytes << std::endl;
        // std::cout << "opset: "<< opset << std::endl;
        // std::cout << "buffer: "<< read_buf << std::endl << std::endl;

        if(opset >= MESSAGE_LENGTH) {
            char tmp[MESSAGE_LENGTH + 1];
            for (int i = 0; i < MESSAGE_LENGTH; i++) {
                tmp[i] = read_buf[i];
            }
            tmp[MESSAGE_LENGTH] = '\0';

            if (isCommandValid(tmp) == MESSAGE_CORRECT) {
                // if(read_buf[] == '9') {
                    add_shared_data(translateCommand(tmp));
                    // cout << "Valid\n" << endl;
                // }
            }
            // std::cout << "Read " << tmp << std::endl;
            for(int i = MESSAGE_LENGTH; i < opset; i++) {
                read_buf[i - MESSAGE_LENGTH] = read_buf[i];
            }
            opset -= MESSAGE_LENGTH;
        } 
        // else if (opset > 0) {
        //     opset -= 1;
        //     if(read_buf[0] == 's') {
        //         add_shared_data(std::string("2"));
        //     }
        //     else if(read_buf[0] == 'r') {
        //         add_shared_data(std::string("3"));
        //     }
        //     else if(read_buf[0] == 'n') add_shared_data(std::string("5"));
        //     else if(read_buf[0] == 'p') add_shared_data(std::string("6"));
        //     else opset += 1;
        // }
    }
}

void Command::cin_producer() {
    std::string cmd;
    while (running) {
        std::cin >> cmd;
        // Lock and push data
        if (cmd == "x") {
            running = false;
        } 
        add_shared_data(cmd);
    }
}

void Command::configPort() {
    int serialPort = open(PORT, O_RDWR);
    // Kiểm tra lỗi
    if (serialPort < 0) {
        std::cerr << "Error " << errno << " opening " << PORT << ": " << strerror(errno) << std::endl;
        return;
    }

    struct termios tty;
    if(tcgetattr(serialPort, &tty) != 0) {
        std::cerr << "Error " << errno << " from tcgetattr: " << strerror(errno) << std::endl;
        std::exit(1);
    }

    cfsetispeed(&tty, B115200);
    cfsetospeed(&tty, B115200);

    tty.c_cflag &= ~PARENB; // No parity
    tty.c_cflag &= ~CSTOPB; // 1 stop bit
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8; // 8 bits per byte
    tty.c_cflag &= ~CRTSCTS; // No hardware flow control
    tty.c_cflag |= CREAD | CLOCAL; // Enable receiver, ignore modem control lines

    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO; // Disable echo
    tty.c_lflag &= ~ECHOE; // Disable erasure
    tty.c_lflag &= ~ECHONL; // Disable new-line echo
    tty.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP

    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
    tty.c_iflag &= ~(ICRNL | INLCR); // Disable CR-to-NL mapping

    tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
    tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed

    tty.c_cc[VTIME] = 20;    // Wait for up to 1s (10 deciseconds)
    tty.c_cc[VMIN] = 0;

    if (tcsetattr(serialPort, TCSANOW, &tty) != 0) {
        std::cerr << "Error " << errno << " from tcsetattr: " << strerror(errno) << std::endl;
        std::exit(1);
    }    
}

void Command::closePort() {
    int serialPort = open(PORT, O_RDWR);
    close(serialPort);
}

Command::Command() {
}

void Command::listen() {
    configPort();
    comProducerThread = std::thread(&Command::com_producer, this);
    cinProducerThread = std::thread(&Command::cin_producer, this);
}

std::string Command::getCommand() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return dataReady; });
    std::string result = commands[commands.size() - 1];
    commands.pop_back();
    // std::cout << "exit"<< std::endl;
    if (commands.size() == 0) {
        dataReady = false;
    }
    return result;
}

Command::~Command() {
    closePort();
    running = false;
    comProducerThread.join();
    cinProducerThread.join();
}

bool Command::dataReady = false;

// int main() {
//     Command cm;
//     while (running) {
//         std::string data = cm.getCommand();
//         std::cout << "Get Command: " << data << std::endl;
//     }
    
//     std::cout << "Program terminated." << std::endl;
//     return 0;
// }
