#include "Handler.h"
#include "PlaylistView.h"
#include "Model.h"
#include <string>
#include <stack>
#include "Controller.h"
#include "ChoosePlaylistHandler.h"
#include "display.h"
#include "EditPlaylistHandler.h"

ChoosePlaylistHandler::ChoosePlaylistHandler() : model(Model::getInstance()) {
    callback = Controller::changeHandler;
};

ChoosePlaylistHandler* ChoosePlaylistHandler::getInstance() {
    static ChoosePlaylistHandler pl = ChoosePlaylistHandler();
    return &pl;
}

void ChoosePlaylistHandler::onStart(void* passData) {
    vector<string> plists = this->model.media_manager.getPlaylistNames();
    this->view.display(plists);
}

void ChoosePlaylistHandler::handle(string command) {
    try {
        int plist_num = stoi(command);
        if (plist_num > 0) {
            this->model.media_manager.setActivePList(plist_num - 1);
            change_handler(EditPlaylistHandler::getInstance());
        }
    } catch (const exception& e) {
        cout << "Pl Handler: No actions or Invalid command"  << endl;
    }
}
