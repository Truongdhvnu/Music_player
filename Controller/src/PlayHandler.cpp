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
bool PlayHandler::onDisplay = false;

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
            this->model.media_manager.setCurrentSongIndex(*((int*)passData) - 1);
        }
        Song currentSong = (*this->model.media_manager.getCurrentSongList())[this->model.media_manager.getCurrentSongIndex()];
        this->view.display(currentSong);
        this->musicPlayer.setPlaylist(this->model.media_manager.getCurrentSongList());
        this->musicPlayer.setCurrentIndex(this->model.media_manager.getCurrentSongIndex());
        this->musicPlayer.unhideProgressBar();
        onDisplay = true;
        // Gọi hàm phát nhạc cho currentSong
    } catch (out_of_range& e) {
        // do Nothing
    }
}

void PlayHandler::leavePage() {
    musicPlayer.hiddenProgressBar();
    onDisplay = false;
}

void PlayHandler::updateView() {
    this->model.media_manager.setCurrentSongIndex(musicPlayer.getCurrentIndex());
    if(onDisplay) {
        this->change_handler(PlayHandler::getInstance());
    } else {
        musicPlayer.hiddenProgressBar();
    }

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
                cout << "\033[F" << "\033[101C" << "\b \b" << flush;
                break;
            case RESUME:
                musicPlayer.resume();
                cout << "\033[F" << "\033[101C" << "\b \b" << flush;
                break;
            case EDIT_META_DATA:
                change_handler(EditMetadataHandler::getInstance());
                break;
            case NEXT:
                musicPlayer.next();
                this->model.media_manager.setCurrentSongIndex(musicPlayer.getCurrentIndex());
                view.display((*this->model.media_manager.getCurrentSongList())[musicPlayer.getCurrentIndex()]);
                break;
            case PREVIOUS:
                musicPlayer.previous();
                this->model.media_manager.setCurrentSongIndex(musicPlayer.getCurrentIndex());
                view.display((*this->model.media_manager.getCurrentSongList())[musicPlayer.getCurrentIndex()]);
                break;
            case VOLUME_UP:
                musicPlayer.volumeUp();
                cout << "\033[F" << "\033[101C" << "\b \b" << flush;
                break;
            case VOLUME_DOWN:
                musicPlayer.volumeDown();
                cout << "\033[F" << "\033[101C" << "\b \b" << flush;
                break;
            default:    
                cout << "\033[F" << "\033[K" << "Invalid" << flush;
                break;
        }
    } catch (exception& e) {
        cout << "\033[F" << "\033[K" <<"Invalid Input" << flush;
    }
};
