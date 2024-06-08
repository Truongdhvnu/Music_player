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
    changeHandelCallback = Controller::changeHandler;
};

ChoosePlaylistHandler* ChoosePlaylistHandler::getInstance() {
    static ChoosePlaylistHandler pl = ChoosePlaylistHandler();
    return &pl;
}

void ChoosePlaylistHandler::onStart(void* passData) {
    (void)passData;
    vector<string> plists = this->model.media_manager.getPlaylistNames();
    this->view.display(plists);
}

void ChoosePlaylistHandler::handle(string command) {
    try {
        /* Clear cin buffer */
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (command == "c") {
            cout << "Enter name of new playlist: " << flush;
            getline(cin, command);
            this->model.media_manager.createPlaylist(command);
            this->onStart();
        }
        else if (command == "d") {
            cout << "Choose index playlist to delete: " << flush;
            cin >> command;
            int plist_num = stoi(command);
            if (plist_num > 0) {
                this->model.media_manager.deletePlaylist(plist_num - 1);
            }
            this->onStart();
        }
        else {
            int plist_num = stoi(command);
            if (plist_num > 0) {
                this->model.media_manager.setActivePList(plist_num - 1);
                changeHandler(EditPlaylistHandler::getInstance());
            }
        }
    } catch (const exception& e) {
        cout << "Pl Handler: No actions or Invalid command"  << endl;
    }
}
