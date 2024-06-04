#include "Handler.h"
#include "PlaylistView.h"
#include "Model.h"
#include <string>
#include <stack>
#include "Controller.h"
#include "PlayHandler.h"
#include "display.h"


/*

    ! Change currentSongIndex to media_maner.getCurrentSongIndex()

*/
int PlayHandler::currentSongIndex = 0;

PlayHandler::PlayHandler() : model(Model::getInstance()) {
    callback = Controller::changeHandler;
};

PlayHandler* PlayHandler::getInstance() {
    static PlayHandler pl = PlayHandler();
    return &pl;
}

void PlayHandler::onStart(void* passData) {
    try {
        if (passData != nullptr) {
            PlayHandler::currentSongIndex = *((int*)passData) - 1;
        }
        Song currentSong = (*this->model.media_manager.getCurrentSongList())[PlayHandler::currentSongIndex];
        this->view.display(currentSong);
        this->musicPlayer.setPlaylist(this->model.media_manager.getCurrentSongList());
        this->musicPlayer.setCurrentIndex(PlayHandler::currentSongIndex);  
        // Gọi hàm phát nhạc cho currentSong
    } catch (out_of_range& e) {
        // do Nothing
    }
}

void PlayHandler::handle(string command) {
    try {
        int option = stoi(command) - 1;
        switch(option) { 
            case PLAY:
                musicPlayer.play((*this->model.media_manager.getCurrentSongList())[musicPlayer.getCurrentIndex()]);
                break;
            case PAUSE:
                musicPlayer.pause();
                break;
            case RESUME:
                musicPlayer.resume();
                break;
            case SHUFFLE:
                cout << "Shiffle\n";
                break;
            case NEXT:
                musicPlayer.next();
                view.display((*this->model.media_manager.getCurrentSongList())[musicPlayer.getCurrentIndex()]);
                break;
            case PREVIOUS:
                musicPlayer.previous();
                view.display((*this->model.media_manager.getCurrentSongList())[musicPlayer.getCurrentIndex()]);
                break;
            case VOLUME_UP:
                musicPlayer.volumeUp();
                break;
            case VOLUME_DOWN:
                musicPlayer.volumeDown();
                break;
            default:
                cout << "Invalid\n";
                break;
        }
    } catch (exception& e) {
        cout << "Invalid Input" << endl;
    }
};  
