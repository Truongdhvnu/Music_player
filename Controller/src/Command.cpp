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
#include "Controller.h"
#include "USBDetect.h"

// #define PORT "/dev/ttyACM0"
#define MESSAGE_LENGTH 3

std::atomic<bool> running(true);
char* PORT=NULL;

void Command::add_shared_data(std::string cmd) {
    std::unique_lock<std::mutex> lock(mtx);
    commands.push_back(cmd);
    dataReady = true;
    cv.notify_all();
}

void Command::com_producer() {
    int opset = 0;
    char read_buf[18] = {'\0'};
    bool checkUart = false;
    while(running) {
        std::string uart_port = USBMonitor::find_usb_serial_device();
        const char* port_str = uart_port.c_str();
        if (port_str == nullptr || strlen(port_str) == 0) {
            if(checkUart==true)
            {
                // std::cerr << "USB serial port Disconnect: " << PORT<< std::endl;

                // std::cout << "\033[41m" << std::flush; 
                // std::cout << "\33[2K" << std::flush;
                // std::cout << "   USB serial port Disconnect" << "\r" << std::flush;
                // std::cout << "\033[0m" << std::flush; 

                std::cout << "\033[s"; // Lưu vị trí con trỏ hiện tại
                std::cout << "\033[41m" << std::flush; // Đổi màu nền thành màu đỏ
                std::cout << "   USB serial port Disconnect" << std::flush; // In dòng thông báo với nền đỏ
                std::cout << "\033[0m" << std::flush; // Reset màu nền về mặc định
                std::cout << "\033[J" << std::flush; // Xóa tất cả các ký tự từ vị trí con trỏ đến cuối trang
                std::cout << "\033[u" << std::flush; // Đưa con trỏ về vị trí đã lưu trước đó
                closePort();
            }
            checkUart = false;
        }
        else {
            PORT = const_cast<char *>(port_str);
            if(checkUart==false) 
            {
                // std::cerr << "USB serial port Connect: " << PORT<< std::endl;

                // std::cout << "\033[42m" << std::flush; 
                // std::cout << "\33[2K" << std::flush;
                // std::cout << "   USB serial port Connect: " << PORT << "\r" << std::flush;
                // std::cout << "\033[0m" << std::flush; 

                std::cout << "\033[s";                  //Lưu vị trí con trỏ hiện tại
                std::cout << "\033[42m" << std::flush; // Đổi màu nền thành màu xanh
                std::cout << "   USB serial port Connect: " << PORT << std::flush;// In dòng thông báo với nền xanh
                std::cout << "\033[0m" << std::flush; // Reset màu nền về mặc định
                std::cout << "\033[J" << std::flush; // Xóa tất cả các ký tự từ vị trí con trỏ đến cuối trang
                std::cout << "\033[u" << std::flush; // Đưa con trỏ về vị trí đã lưu trước đó
                configPort();
            }
            checkUart = true;
        }

        if(checkUart)
        { 
            // std::cerr << "USB serial" << PORT<< std::endl;
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

            if(read_buf[0] == '9') {
                std::cout << std::endl << std::flush;
                add_shared_data("31v" + std::string(1,read_buf[2]));
            } 
            // else if(read_buf[0] == 'r') {
            //     std::cout << std::endl << std::flush;
            //     add_shared_data(std::string(1,tmp[0])+tmp[1]);
            // } else if(read_buf[0] == 'z') {
            //     std::cout << std::endl << std::flush;
            //     // tmp[1] += 48;
            //     add_shared_data(std::string(1,read_buf[1]));    
            //     // add_shared_data("3");
            // }
            for(int i = 3; i < opset; i++) {
                read_buf[i-3] = read_buf[i];
            }
            opset -= 3;
            // std::cout << "Read " << tmp << std::endl;
        } 
        else if (opset > 0) {
            opset -= 1;
            if(read_buf[0] == 'z') {
                std::cout << std::endl << std::flush;
                // add_shared_data(std::string("2"));
                // writeData("s");
                add_shared_data(std::string("z"));
            }
            else if(read_buf[0] == 'r') {
                std::cout << std::endl << std::flush;
                add_shared_data(std::string("r"));
                // add_shared_data(std::string(1, read_buf[0]));
            }
            // else if(read_buf[0] == 'n') add_shared_data(std::string("5"));
            // else if(read_buf[0] == 'n') add_shared_data(std::string("r2"));
            // else if(read_buf[0] == 'p') add_shared_data(std::string("6"));
            // else if(read_buf[0] == 'p') add_shared_data(std::string("r3"));
            else opset += 1;
        }
    }
    // while(running){
    // int serialPort = open(PORT, O_RDWR);
    // char read_buf[8];
    // memset(&read_buf, '\0', sizeof(read_buf));
    // int num_bytes = read(serialPort, &read_buf, sizeof(read_buf));

    // if (num_bytes < 0) {
    //     std::cerr << "Error reading: " << strerror(errno) << std::endl;
    //     // break;
    // }

    // if(num_bytes > 0) {
    //     if(read_buf[0] == 's') {
    //         std::cout << "\n";
    //         add_shared_data(std::string("2"));
    //     }
    //     else if(read_buf[0] == 'r') {
    //         std::cout << "\n";
    //         add_shared_data(std::string("3"));
    //     }
    //     else if(read_buf[0] == 'n') add_shared_data(std::string("5"));
    //     else if(read_buf[0] == 'p') add_shared_data(std::string("6"));
    //     else if(read_buf[0] == '9') {
    //         // string vol = (string)read_buf[0] + (string)read_buf[1];
    //         std::cout << "\n";
    //         add_shared_data(std::string(read_buf));;
    //     }

    //     // if(read_buf[0] == '3' && read_buf[1] == '1') {
    //     //     // string vol = (string)read_buf[0] + (string)read_buf[1];
    //     //     std::cout << "\n";
    //     //     Controller::recentView[view_index]->handle(read_buf);
    //     // }
    //     // else {
    //     //     std::cout << "\n";
    //     //     Controller::recentView[view_index]->handle(read_buf);
    //     // }
    // }

    // // if (num_bytes > 0) {
    // //     std::cout << "Read " << num_bytes << " bytes. Data: " << read_buf << std::endl;
    // // }
    // }
}
}

void Command::cin_producer() {
    std::string cmd;
    while (running) {
        // std::cin >> cmd;
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, cmd);
        if(cmd == EXIT) running = false;
        // Lock and push data
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
    //configPort();
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

void Command::writeData(std::string data) {
    // std::string data;
    int serialPort = open(PORT, O_RDWR);

    int num_bytes = write(serialPort, data.c_str(), data.size());
    if (num_bytes < 0) {
        std::cerr << "Error writing: " << strerror(errno) << std::endl;
    } else {
        // std::cout << "Sent " << num_bytes << " bytes." << std::endl;
    }
}

