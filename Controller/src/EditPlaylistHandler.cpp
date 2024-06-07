#include "Handler.h"
#include "PlaylistView.h"
#include "Model.h"
#include <string>
#include <stack>
#include "Controller.h"
#include "EditPlaylistHandler.h"
#include "display.h"
#include "PlayHandler.h"
#include "commonFunc.h"
#include "ChooseSongsHandler.h"

EditPlaylistHandler::EditPlaylistHandler() : model(Model::getInstance()) {
    callback = Controller::changeHandler;
};

EditPlaylistHandler* EditPlaylistHandler::getInstance() {
    static EditPlaylistHandler pl = EditPlaylistHandler();
    return &pl;
}

void EditPlaylistHandler::onStart(void* passData) {
    try {
        vector<Song> songs = this->model.media_manager.getPageOfSong(0);
        this->view.displaySongs(songs, 0);
    } catch (out_of_range& e) {
        // cout << e.what() << endl;
    }
}

void EditPlaylistHandler::handle(string command) {
    static int currentPage = 0;
    try {
        if (!songListhandle(command, currentPage)) {
            try {
                int option = stoi(command);
                std::string input;
                /* Clear cin buffer */
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                Playlist* pl = this->model.media_manager.getActivePlaylist();
                Library* temp;
                switch (option)
                {
                case 1:
                    cout << "Input new Name: " << flush;
                    std::getline(std::cin, input);
                    pl->rename(input);
                    break;
                case 2:
                    cout << "Input path to your folder: " << flush;
                    std::getline(std::cin, input);
                    this->model.media_manager.setActiveLibrary();
                    temp = this->model.media_manager.getActiveLibrary();
                    temp->getSongFromPath(input);
                    change_handler(ChooseSongsHandler::getInstance(), (void*)pl);
                    break;
                case 3:
                    cout << "Input song index: " << flush;
                    std::getline(std::cin, input);
                    pl->deleteSong(stoi(input) - 1);
                    this->onStart();
                    break;
                default:
                    break;
                }
            } catch (const exception& e) {
                cout << "SongList Handler: No actions or Invalid command" << endl;
            }
        } else {
            this->view.display_bottom();
        }
    } catch (out_of_range &e) {
        cout << e.what() << endl;
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }
};
