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
    // if (instancePtr == nullptr) {
    //     GetdirHandler* instancePtr = new GetdirHandler();
    //     return instancePtr;
    // } else {
    //     return instancePtr;
    // }
    static GetdirHandler in;
    return &in;
}

void GetdirHandler::setGetdirViewPath(string path) {
    view.path = path;
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
                changeHandler(SongListHandler::getInstance());
            }
            else{
                changeHandler(GetdirHandler::getInstance());
                cout << "Waiting for USB inserted..." << endl;
                cout << "If USB inserted, press 1 again" << endl;
                cout << "If USB not detected, remove and insert again" << endl;
            }

        } else if (command == "2") {
            usbmonitor.stopMonitoring();
            cout <<"Input Directory: " << flush;
            cin >> directory;
            setGetdirViewPath(directory);
            this->model.media_manager.setActiveLibrary();
            Library* lib=this->model.media_manager.getActiveLibrary();
            (*lib).getSongFromPath(directory);
            changeHandler(SongListHandler::getInstance());
        } else if (command == "3") {
            usbmonitor.stopMonitoring();
            this->model.media_manager.setActiveLibrary();
            Library* lib=this->model.media_manager.getActiveLibrary();
            (*lib).getSongFromPath(view.path);
            changeHandler(SongListHandler::getInstance());
        }
        else {
            cout << "No actions or Invalid command" << endl;
        }
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }
}

void GetdirHandler::onStart(void* passData) {
    (void)passData;
    this->view.display();
    usbmonitor.stopMonitoring();
    usbmonitor.startMonitoring();
}
