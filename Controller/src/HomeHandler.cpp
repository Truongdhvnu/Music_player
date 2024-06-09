#include "Handler.h"
#include "HomeView.h"
#include "Model.h"
#include "PlaylistHandler.h"
#include "Controller.h"
#include "HomeHandler.h"
#include "SongListHandler.h"
#include "GetdirHandler.h"
#include "ChoosePlaylistHandler.h"

HomeHandler* HomeHandler::instancePtr = nullptr;

HomeHandler::HomeHandler() : model(Model::getInstance()){
    changeHandelCallback = Controller::changeHandler;
}

HomeHandler* HomeHandler::getInstance() {
    if (instancePtr == nullptr) {
        HomeHandler* instancePtr = new HomeHandler();
        return instancePtr;
    } else {
        return instancePtr;
    }
}

void HomeHandler::handle(string command) {
    try {
        if (command == "1") {
            changeHandler(GetdirHandler::getInstance());
        } else if (command == "2") {
            changeHandler(PlaylistHandler::getInstance());
        } else if (command == "3") {
            this->model.mediaManager.setActiveLibrary();
            this->model.mediaManager.getLibrary().getSongFromCurrentDirs();
            changeHandler(SongListHandler::getInstance());
        } else if (command == "4") {
            changeHandler(ChoosePlaylistHandler::getInstance());
        }
        else {
            cout << "No actions or Invalid command" << endl;
        }
    } catch (runtime_error& e) {
        cout << "Homehandler: " << e.what() << endl;
    }
}

void HomeHandler::onStart(void* passData) {
    (void)passData;
    this->view.display();
}