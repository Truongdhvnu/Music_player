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

// #define PORT "/dev/ttyACM0"
#define MESSAGE_LENGTH 3

extern std::atomic<bool> running;
extern char* PORT;

class Command {
private:
    std::vector<std::string> commands;
    std::mutex mtx;
    std::condition_variable cv;
    static bool dataReady;
    std::thread comProducerThread;
    std::thread cinProducerThread;

    void add_shared_data(std::string cmd);
    
    void com_producer();

    void cin_producer();

    void configPort();

    void closePort();


public:
    Command();

    std::string getCommand();

    ~Command();
};