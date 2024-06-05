#include "Handler.h"
#include "PlaylistView.h"
#include "Model.h"
#include <string>
#include <stack>
#include "Controller.h"
#include "PlayHandler.h"
#include "display.h"
#include "EditMetadataHandler.h"

/*

    ! Change currentSongIndex to media_maner.getCurrentSongIndex()

*/
int PlayHandler::currentSongIndex = 0;

PlayHandler::PlayHandler() : model(Model::getInstance()) {
    callback = Controller::changeHandler;
    musicPlayer.setSongEndCallback(std::bind(&PlayHandler::updateView, this)); // Đặt callback cho musicPlayer
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
        this->musicPlayer.unhideProgressBar();
        // Gọi hàm phát nhạc cho currentSong
    } catch (out_of_range& e) {
        // do Nothing
    }
}

void PlayHandler::leavePage() {
    musicPlayer.hiddenProgressBar();
}

void PlayHandler::updateView() {
    Song currentSong = (*this->model.media_manager.getCurrentSongList())[musicPlayer.getCurrentIndex()];
    view.display(currentSong);
}


void PlayHandler::handle(string command) {
    try {
        int option = stoi(command) - 1;
        switch(option) {
            case PLAY:
                view.display((*this->model.media_manager.getCurrentSongList())[musicPlayer.getCurrentIndex()]);
                musicPlayer.play((*this->model.media_manager.getCurrentSongList())[musicPlayer.getCurrentIndex()]);
                break;
            case PAUSE:
                musicPlayer.pause();
                view.display((*this->model.media_manager.getCurrentSongList())[musicPlayer.getCurrentIndex()]);
                break;
            case RESUME:
                musicPlayer.resume();
                view.display((*this->model.media_manager.getCurrentSongList())[musicPlayer.getCurrentIndex()]);
                break;
            case EDIT_META_DATA:
                change_handler(EditMetadataHandler::getInstance());
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
                view.display((*this->model.media_manager.getCurrentSongList())[musicPlayer.getCurrentIndex()]);
                break;
            case VOLUME_DOWN:
                musicPlayer.volumeDown();
                view.display((*this->model.media_manager.getCurrentSongList())[musicPlayer.getCurrentIndex()]);
                break;
            default:
                cout << "Invalid";
                break;
        }
    } catch (exception& e) {
        cout << "Invalid Input";
    }
};
