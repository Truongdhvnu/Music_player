#pragma once
#include "Handler.h"
#include "Model.h"
#include "string"
#include "USBDetect.h"
#include "HomeView.h"
#include "Controller.h"
#include "ChooseUsbView.h"
#include "SongListHandler.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <MusicPlayer.h>

class ChooseUsbHandler : public Handler {
private:
    ChooseUsbView view;
    USBMonitor usbMonitor;
    MusicPlayer musicPlayer;
    Model& model;
    std::vector<std::string> usbPath;

    // Private constructor
    ChooseUsbHandler() : model(Model::getInstance()) {};

public:
    static ChooseUsbHandler* getInstance() {
        static ChooseUsbHandler instance;
        return &instance;
    }


    void onStart(void* passData = nullptr) {
        (void)passData;
        usbMonitor.setUserPath();
        usbPath = usbMonitor.getSubdirectories(usbMonitor.getUserPathValue());
        this->view.display(usbPath);
    }

    void handle(std::string command) {
        std::cout <<"Vao handle cua chose USB"<<std::endl;
        try {
            int cmdIndex = std::stoi(command);
            if (cmdIndex <= (int)usbPath.size() && cmdIndex > 0) {
                this->model.media_manager.setActiveLibrary();
                Library* lib = this->model.media_manager.getActiveLibrary();
                std::string path_dir = usbPath[cmdIndex - 1];
                (*lib).getSongFromPath(path_dir);
                std::cout <<"Using path"<<path_dir<<std::endl;
                // view.display((*this->model.media_manager.getCurrentSongList())[musicPlayer.getCurrentIndex()]);
                // std::cout <<"Using path"<<path_dir<<std::endl;
                change_handler(SongListHandler::getInstance());
            } else {
                std::cout << "No actions or Invalid command in chosing usb" << std::endl;
            }
        } catch (std::runtime_error& e) {
            std::cout << e.what() << std::endl;
        }
    }

    void leavePage() {
        // Định nghĩa hàm leavePage nếu cần, hoặc để trống nếu chưa sử dụng.
    }
};
