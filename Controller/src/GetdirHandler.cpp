#include "Handler.h"
#include "HomeView.h"
#include "Model.h"
#include "PlaylistHandler.h"
#include "Controller.h"
#include "GetdirHandler.h"
#include "SongListHandler.h"

// GetdirHandler* GetdirHandler::instancePtr = nullptr;

GetdirHandler::GetdirHandler() : model(Model::getInstance()){
    callback = Controller::changeHandler;
}

GetdirHandler* GetdirHandler::getInstance() {
    // if (instancePtr == nullptr) {
    //     GetdirHandler* instancePtr = new GetdirHandler();
    //     return instancePtr;
    // } else {
    //     return instancePtr;
    // }
    static GetdirHandler in;
    return &in;
}

void GetdirHandler::handle(string command) {
    try {
        if (command == "1") {
            if(usbmonitor.USBGetStatus()==1)    //da co USB
            {
                directory=usbmonitor.getUserPathValue();
                usbmonitor.stopMonitoring();
                this->model.media_manager.setActiveLibrary();
                Library* lib=this->model.media_manager.getActiveLibrary();
                (*lib).getSongFromPath(directory);
                change_handler(SongListHandler::getInstance());
            }
            else{
                change_handler(GetdirHandler::getInstance());
                cout << "Waiting for USB inserted..."<<endl;
                cout << "If USB inserted, press 1 again"<<endl;
                cout << "If USB not detected, remove and insert again"<<endl;
            }
            
        } else if (command == "2") {
            cout <<"Input Directory: ";
            cin >> directory;
            usbmonitor.stopMonitoring();
            this->model.media_manager.setActiveLibrary();
            Library* lib=this->model.media_manager.getActiveLibrary();
            (*lib).getSongFromPath(directory);
            change_handler(SongListHandler::getInstance());
        }
        else if (command == "3") {
            usbmonitor.stopMonitoring();
            this->model.media_manager.setActiveLibrary();
            Library* lib=this->model.media_manager.getActiveLibrary();
            (*lib).getSongFromPath(directory);
            change_handler(SongListHandler::getInstance());
        }
        else {
            cout << "No actions or Invalid command\n";
        }
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }
}

void GetdirHandler::onStart(void* passData) {
    this->view.display();
    this->view.displaypath(directory);
    usbmonitor.stopMonitoring();
    usbmonitor.startMonitoring();
}

