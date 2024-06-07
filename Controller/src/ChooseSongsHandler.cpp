#include "Handler.h"
#include "PlaylistView.h"
#include "Model.h"
#include <string>
#include <stack>
#include "Controller.h"
#include "ChooseSongsHandler.h"
#include "display.h"
#include "PlayHandler.h"
#include "commonFunc.h"
#include "Playlist.h"
#include "EditPlaylistHandler.h"

int ChooseSongsHandler::currentPage = 0;
Playlist* ChooseSongsHandler::plist = nullptr;
ChooseSongsHandler::ChooseSongsHandler() : model(Model::getInstance()) {
    callback = Controller::changeHandler;
};

ChooseSongsHandler* ChooseSongsHandler::getInstance() {
    static ChooseSongsHandler pl = ChooseSongsHandler();
    return &pl;
}

void ChooseSongsHandler::onStart(void* passData) {
    try {
        ChooseSongsHandler::plist = (Playlist*)passData;
        vector<Song> songs = this->model.media_manager.getPageOfSong(0);
        ChooseSongsHandler::currentPage = 0;
        this->view.displaySongs(songs, 0);
    } catch (out_of_range& e) {
        // cout << e.what() << endl;
    }
}

void ChooseSongsHandler::handle(string command) {
    try {
        cout << "Choose index to add to playlist. Press \"d\" to done adding" << endl;
        if (!songListhandle(command, ChooseSongsHandler::currentPage)) {
            if(command == "d") {
                this->model.media_manager.setActivePList(this->model.media_manager.getActivePListIndex());
                this->change_handler(EditPlaylistHandler::getInstance());
            }
            else {
                try {
                    int pos = stoi(command) - 1;
                    Song& song = (*this->model.media_manager.getCurrentSongList())[pos];
                    plist->addSong(song.getPath());
                    cout << "Song added: " << song.getTitle() << endl;
                } catch (const exception& e) {
                cout << "Choose songs Handler: No actions or Invalid command" << endl;
                }
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
