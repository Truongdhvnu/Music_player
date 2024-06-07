#include "Handler.h"
#include "PlaylistView.h"
#include "Model.h"
#include <string>
#include <stack>
#include "Controller.h"
#include "SongListHandler.h"
#include "display.h"
#include "PlayHandler.h"
#include "commonFunc.h"

int SongListHandler::currentPage = 0;
int SongListHandler::currentSongIndex = 0;

SongListHandler::SongListHandler() : model(Model::getInstance()) {
    changeHandelCallback = Controller::changeHandler;
};

SongListHandler* SongListHandler::getInstance() {
    static SongListHandler pl = SongListHandler();
    return &pl;
}

void SongListHandler::onStart(void* passData) {
    (void)passData;
    try {
        // if (passData != nullptr) nếu không để = 0, có thể lỗi khi đổi giữa lib và plist
        vector<Song> songs = this->model.media_manager.getPageOfSong(0);
        SongListHandler::currentPage = 0;
        this->view.displaySongs(songs, 0);
    } catch (out_of_range& e) {
        // cout << e.what() << endl;
    }
}

void SongListHandler::handle(string command) {
    try {
        if (!songListhandle(command, SongListHandler::currentPage)) {
            try {
                int selectedSong = stoi(command);
                if (selectedSong >= 1 && selectedSong <= this->model.media_manager.getNumberofSong()) {
                    SongListHandler::currentSongIndex = selectedSong;
                    this->changeHandler(PlayHandler::getInstance(), (void*)&SongListHandler::currentSongIndex);
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
