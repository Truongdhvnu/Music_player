#ifndef USBDETECT_H
#define USBDETECT_H
#pragma once
#include <libudev.h>
#include <iostream>
#include <atomic>
#include <thread>
#include <unistd.h>
#include <string.h>
#include <chrono>
#include <vector>

class USBMonitor {
public:
    USBMonitor();
    ~USBMonitor();
    void startMonitoring();
    void stopMonitoring();
    int USBGetStatus() const;
    void setUserPath();
    void clearUserPath();
    std::string getUserPathValue() const;
    void DetectUSBEvents();
    std::vector<std::string> getSubdirectories(const std::string& parentPath);

private:
    
    int status;
    std::string UserPath;
    struct udev* udev;
    struct udev_monitor* mon;
    std::atomic<bool> running;
    std::thread monitorThread;
};

#endif // USBDETECT_H
