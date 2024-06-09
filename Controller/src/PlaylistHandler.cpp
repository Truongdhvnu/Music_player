#include "Handler.h"
#include "PlaylistView.h"
#include "Model.h"
#include <string>
#include <stack>
#include "Controller.h"
#include "PlaylistHandler.h"
#include "display.h"
#include "SongListHandler.h"

PlaylistHandler::PlaylistHandler() : model(Model::getInstance()) {
    changeHandelCallback = Controller::changeHandler;
};

PlaylistHandler* PlaylistHandler::getInstance() {
    static PlaylistHandler pl;
    return &pl;
}

void PlaylistHandler::onStart(void* passData) {
    (void)passData;
    vector<string> plists = this->model.mediaManager.getPlaylistNames();
    this->view.display(plists);
}

void PlaylistHandler::handle(string command) {
    try {
        int plist_num = stoi(command);
        if (plist_num > 0) {
            this->model.mediaManager.setActivePList(plist_num - 1);
            changeHandler(SongListHandler::getInstance());
        }
    } catch (const exception& e) {
        cout << "Pl Handler: No actions or Invalid command" << endl;
    }
}
