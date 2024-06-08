#include "Handler.h"
#include "PlaylistView.h"
#include "Model.h"
#include <string>
#include <stack>
#include "Controller.h"
#include "PlayHandler.h"
#include "display.h"
#include "EditMetadataHandler.h"

bool PlayHandler::onDisplay = false;

PlayHandler::PlayHandler() : model(Model::getInstance()) {
    changeHandelCallback = Controller::changeHandler;
    musicPlayer.setSongEndCallback(std::bind(&PlayHandler::updateView, this)); // Đặt callback cho musicPlayer
};

PlayHandler* PlayHandler::getInstance() {
    static PlayHandler pl;
    return &pl;
}

void PlayHandler::onStart(void* passData) {
    int preIndex = this->model.mediaManager.getCurSongIndex();
    if (passData != nullptr) {
        this->model.mediaManager.setCurSongIndex(*((int*)passData) - 1);
    }

    Song currentSong = this->model.mediaManager.getCurSong();
    this->view.display(currentSong);
    this->musicPlayer.setPlaylist(this->model.mediaManager.getCurSongList());
    this->musicPlayer.setCurrentIndex(this->model.mediaManager.getCurSongIndex());
    this->musicPlayer.unhideProgressBar();
    onDisplay = true;

    if((passData != nullptr && *((int*)passData) != preIndex + 1)) {
        musicPlayer.play(this->model.mediaManager.getCurSong());
    }
}

void PlayHandler::leavePage() {
    musicPlayer.hiddenProgressBar();
    onDisplay = false;
}

void PlayHandler::updateView() {
    this->model.mediaManager.setCurSongIndex(musicPlayer.getCurrentIndex());
    if(onDisplay) {
        this->changeHandler(PlayHandler::getInstance());
    } else {
        musicPlayer.hiddenProgressBar();
    }
}

void PlayHandler::handle(string command) {
    try {
        int option = stoi(command) - 1;
        switch(option) {
            case REPLAY:
                view.display(this->model.mediaManager.getCurSong());
                musicPlayer.play(this->model.mediaManager.getCurSong());
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
                changeHandler(EditMetadataHandler::getInstance());
                break;
            case NEXT:
                musicPlayer.next();
                this->model.mediaManager.setCurSongIndex(musicPlayer.getCurrentIndex());
                view.display(this->model.mediaManager.getCurSong());
                break;
            case PREVIOUS:
                musicPlayer.previous();
                this->model.mediaManager.setCurSongIndex(musicPlayer.getCurrentIndex());
                view.display(this->model.mediaManager.getCurSong());
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
