#include "Handler.h"
#include "HomeView.h"
#include "Model.h"
#include "PlaylistHandler.h"
#include "Controller.h"
#include "HomeHandler.h"
#include "SongListHandler.h"
#include "GetdirHandler.h"

HomeHandler* HomeHandler::instancePtr = nullptr;

HomeHandler::HomeHandler() : model(Model::getInstance()){
    callback = Controller::changeHandler;
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
            change_handler(GetdirHandler::getInstance());
        } else if (command == "2") {
            change_handler(PlaylistHandler::getInstance());
        } else if (command == "3") {
            this->model.media_manager.setActiveLibrary();
            Library* mylib = this->model.media_manager.getActiveLibrary();
            (*mylib).getSongFromCurrentDirs();
            change_handler(SongListHandler::getInstance());
        } else if (command == "4") {
            // change_handler();
        }
        else {
            cout << "No actions or Invalid command\n";
        }
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }
}

void HomeHandler::onStart(void* passData) {
    (void)passData;
    this->view.display();
    // this->view.display_bottom();
}


// int main() {
//     HomeHandler* h = HomeHandler::getInstance();
//     h->onStart();
//     string s;
//     cin >> s;
//     h->handle(s);
// }