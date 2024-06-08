#include "Handler.h"
#include "HomeView.h"
#include "Model.h"
#include "PlaylistHandler.h"
#include "Controller.h"
#include "GetdirHandler.h"
#include "SongListHandler.h"

// GetdirHandler* GetdirHandler::instancePtr = nullptr;
// GetdirHandler* GetdirHandler::instancePtr = nullptr;

GetdirHandler::GetdirHandler() : model(Model::getInstance()){
    changeHandelCallback = Controller::changeHandler;
}

GetdirHandler* GetdirHandler::getInstance() {
    static GetdirHandler in;
    return &in;
}

void GetdirHandler::setPath(string path) {
    view.path = path;
}

void GetdirHandler::setUsbPath(string path) {
    view.usbPath = path;
}

void GetdirHandler::handle(string command) {
    try {
        if (command == "1") {
            if(usbmonitor.USBGetStatus()==1)    //da co USB
            {
                directory=usbmonitor.getUserPathValue();
                setUsbPath(directory);
                view.display();
                usbmonitor.stopMonitoring();
                this->model.mediaManager.setActiveLibrary();
                this->model.mediaManager.getLibrary().getSongFromPath(directory);
                changeHandler(SongListHandler::getInstance());
            }
            else{
                // change_handler(GetdirHandler::getInstance());
                view.display();
                cout << "Waiting for USB inserted..." << endl;
                cout << "If USB inserted, press 1 again" << endl;
                cout << "If USB not detected, remove and insert again" << endl;
            }

        } else if (command == "2") {
            usbmonitor.stopMonitoring();
            cout <<"Input Directory: " << flush;
            cin >> directory;
            setPath(directory);
            this->model.mediaManager.setActiveLibrary();
            this->model.mediaManager.getLibrary().getSongFromPath(directory);
            if (!this->model.mediaManager.getLibrary().isAlreadyInCurDirs(directory)) {
                cout << "Do you wanna add this folder to recent dirs? [y/n]: ";
                string input;
                cin >> input;
                if (input == "y" || input == "Y") {
                    this->model.mediaManager.getLibrary().addPathToCurrentDirs(directory);
                }
            }
            changeHandler(SongListHandler::getInstance());
        } else if (command == "3") {
            usbmonitor.stopMonitoring();
            this->model.mediaManager.setActiveLibrary();
            this->model.mediaManager.getLibrary().getSongFromPath(view.path);
            changeHandler(SongListHandler::getInstance());
        }
        else {
            cout << "No actions or Invalid command" << endl;
        }
    } catch (runtime_error& e) {
        cout << "Getdir: " << e.what() << endl;
    }
}

void GetdirHandler::onStart(void* passData) {
    (void)passData;
    this->view.display();
    usbmonitor.stopMonitoring();
    usbmonitor.startMonitoring();
}
