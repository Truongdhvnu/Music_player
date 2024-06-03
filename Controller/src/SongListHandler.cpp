#include "Handler.h"
#include "PlaylistView.h"
#include "Model.h"
#include <string>
#include <stack>
#include "Controller.h"
#include "SongListHandler.h"
#include "display.h"
#include "PlayHandler.h"

int SongListHandler::currentPage = 0;
int SongListHandler::currentSongIndex = 0;

SongListHandler::SongListHandler() : model(Model::getInstance()) {
    callback = Controller::changeHandler;
};

SongListHandler* SongListHandler::getInstance() {
    static SongListHandler pl = SongListHandler();
    return &pl;
}

void SongListHandler::onStart(void* passData) {
    try {
        // cout << this->model.media_manager.getCurrentSongList().size();
        vector<Song> songs = this->model.media_manager.getPageOfSong(0);
        this->view.displaySongs(songs, 0);
    } catch (out_of_range& e) {
        // cout << e.what() << endl;
    }
}

void SongListHandler::handle(string command) {
    try {
        if (command == PREVIOUS_PAGE) {
            vector<Song> songs = this->model.media_manager.getPageOfSong(currentPage - 1);
            currentPage--;
            this->view.displaySongs(songs, currentPage);
        } else if (command == NEXT_PAGE) {
            vector<Song> songs = this->model.media_manager.getPageOfSong(currentPage + 1);
            currentPage++;
            this->view.displaySongs(songs, currentPage);
        } else {
            if (command == SORT_BY_ARTIST) {
                this->model.media_manager.sortCurrentList(SORT_ARTIST);
                vector<Song> songs = this->model.media_manager.getPageOfSong(currentPage);
                this->view.displaySongs(songs, currentPage);
            } else if (command == SORT_BY_NAME) {
                static bool az = true;
                if (az) {
                    this->model.media_manager.sortCurrentList(SORT_AZ);
                    az = false;
                } else {
                    this->model.media_manager.sortCurrentList(SORT_ZA);
                    az = true;
                }
                vector<Song> songs = this->model.media_manager.getPageOfSong(currentPage);
                this->view.displaySongs(songs, currentPage);
            } else {
                try {
                    int selectedSong = stoi(command);
                    if (selectedSong >= 1 && selectedSong <= this->model.media_manager.getCurrentSongList().size()) {
                        SongListHandler::currentSongIndex = selectedSong;
                        this->change_handler(PlayHandler::getInstance(), (void*)&SongListHandler::currentSongIndex);
                    }
                } catch (const exception& e) {
                    cout << "SongList Handler: No actions or Invalid command\n";
                }
            }
        } 
    } catch (out_of_range &e) {
        cout << e.what() << endl;
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }
};  
