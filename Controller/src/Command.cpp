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
#include "Controller.h"
#include "USBDetect.h"

static char* PORT=NULL;

void Command::add_shared_data(std::string cmd) {
    std::unique_lock<std::mutex> lock(mtx);
    commands.push_back(cmd);
    dataReady = true;
    // cv.notify_all();
}

void Command::com_producer() {
    int opset = 0;
    int bufer_size = 18;
    char read_buf[bufer_size] = {'\0'};
    // bool checkUart = false;
    while(running) {
        std::string uart_port = USBMonitor::find_usb_serial_device();
        const char* port_str = uart_port.c_str();
        if (port_str == nullptr || strlen(port_str) == 0) {
            if(checkUart==true) {
                std::cout << "\033[s";                      // Save curent position
                std::cout << "\033[41m" << std::flush;      // Red backgound colour
                std::cout << "   USB serial port Disconnect" << std::flush;
                std::cout << "\033[0m" << std::flush;       // Reset backgound colour
                std::cout << "\033[J" << std::flush;        // Clear other letters in current row
                std::cout << "\033[u" << std::flush;        // Back to saved potion 
                closePort();
            }
            checkUart = false;
        }
        else {
            PORT = const_cast<char *>(port_str);
            if(checkUart==false) {
                std::cout << "\033[s";                 
                std::cout << "\033[42m" << std::flush;      // Green background colour
                std::cout << "   USB serial port Connect: " << PORT << std::flush;
                std::cout << "\033[0m" << std::flush;
                std::cout << "\033[J" << std::flush;
                std::cout << "\033[u" << std::flush;
                configPort();
            }
            checkUart = true;
        }
        // this->handleComPort();
        if(checkUart) {
            int serialPort = open(PORT, O_RDWR);

            int num_bytes = read(serialPort, read_buf + opset, bufer_size);
            opset += num_bytes;

            if(opset >= MESSAGE_LENGTH) {
                char tmp[MESSAGE_LENGTH + 1];
                for (int i = 0; i < MESSAGE_LENGTH; i++) {
                    tmp[i] = read_buf[i];
                }
                tmp[MESSAGE_LENGTH] = '\0';

                if (isReceiveCommandValid(tmp) == MESSAGE_CORRECT) {
                    add_shared_data(translateReceiveCommand(tmp));
                }

                for(int i = MESSAGE_LENGTH; i < opset; i++) {
                    read_buf[i-MESSAGE_LENGTH] = read_buf[i];
                }

                opset -= MESSAGE_LENGTH;
                if (DEBUG) {
                    std::cout << "Read " << translateReceiveCommand(tmp) << std::endl;
                }
            } 
        }
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
    comProducerThread = std::thread(&Command::com_producer, this);
}

std::string Command::getCommand() {
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);

    std::string input_buffer;
    while (1) {
        struct timeval timeout;
        timeout.tv_sec = 0; 
        timeout.tv_usec = 0;

        fd_set tmp_fds = read_fds;
        int ready = select(STDIN_FILENO + 1, &tmp_fds, NULL, NULL, &timeout);
        
        if (ready > 0) {
            if (FD_ISSET(STDIN_FILENO, &tmp_fds)) {
                char buffer[256];
                ssize_t bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
                buffer[bytes_read] = '\0';
                input_buffer.append(buffer);

                size_t newline_pos = input_buffer.find('\n');
                if (newline_pos != std::string::npos) {
                    std::string line = input_buffer.substr(0, newline_pos);
                    input_buffer.erase(0, newline_pos + 1);
                    // line[newline_pos] = '\0';
                    add_shared_data(line);
                    std::cout << "Received input: " << line << std::endl;
                    if (line == "1") cout << "hi cau\n";
                }
            }
        }

        std::unique_lock<std::mutex> lock(mtx);
        if (commands.size() > 0) {
            string result = commands[commands.size() - 1];
            commands.pop_back();
            return result;
        }
    }
}

Command::~Command() {
    closePort();
    running = false;
    comProducerThread.join();
}

bool Command::dataReady = false;

void Command::writeData(std::string data) {
    int serialPort = open(PORT, O_RDWR);
    int num_bytes = 0;
    int total_bytes_sent = 0;

    while (total_bytes_sent < MESSAGE_LENGTH) {
        num_bytes = write(serialPort, data.c_str() + total_bytes_sent, MESSAGE_LENGTH - total_bytes_sent);
        if (num_bytes < 0) {
            std::cerr << "Error writing: " << strerror(errno) << std::endl;
            break;
        } else {
            total_bytes_sent += num_bytes;
        }
    }

    // cout << "Send: " << data << endl;
}

void Command::handleComPort() {
    std::string uart_port = USBMonitor::find_usb_serial_device();
    const char* port_str = uart_port.c_str();
    if (port_str == nullptr || strlen(port_str) == 0) {
        if(checkUart==true) {
            std::cout << "\033[s";                      // Save curent position
            std::cout << "\033[41m" << std::flush;      // Red backgound colour
            std::cout << "Disconnected to USB serial port: " << std::flush;
            std::cout << "\033[0m" << std::flush;       // Reset backgound colour
            std::cout << "\033[J" << std::flush;        // Clear other letters in current row
            std::cout << "\033[u" << std::flush;        // Back to saved potion 
            closePort();
        }
        checkUart = false;
    }
    else {
        PORT = const_cast<char *>(port_str);
        if(checkUart==false) {
            std::cout << "\033[s";                 
            std::cout << "\033[42m" << std::flush;      // Green background colour
            std::cout << "Connected to USB serial port: " << PORT << std::flush;
            std::cout << "\033[0m" << std::flush; 
            std::cout << "\033[J" << std::flush;
            std::cout << "\033[u" << std::flush;
            configPort();
        }
        checkUart = true;
    }
}