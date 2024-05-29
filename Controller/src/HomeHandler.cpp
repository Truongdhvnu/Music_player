#pragma once
#include "Handler.h"
#include "HomeView.cpp"
#include "Model.h"
#include "PlaylistHandler.h"
#include "Controller.h"
#include "HomeHandler.h"

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
    if (command == "1") {
        system("clear");
        cout << "do sth here\n";
        this->view.display_bottom();
    } else if (command == "2") {
        change_handler(PlaylistHandler::getInstance());
    } else {
        cout << "Invalid command";
    }
}

void HomeHandler::onStart() {
    this->view.display();
    this->view.display_bottom();
}


// int main() {
//     HomeHandler* h = HomeHandler::getInstance();
//     h->onStart();
//     string s;
//     cin >> s;
//     h->handle(s);
// }