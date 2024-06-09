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
    PlayHandler::PlayingInfor infor = this->getPlayingInfor();
    this->view.display(currentSong, infor.songs, infor.curPos);
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

PlayHandler::PlayingInfor PlayHandler::getPlayingInfor() {
    PlayingInfor result;
    if (this->model.mediaManager.getNumberofSong() < SONG_NUM_SHOW) {
        result.curPos = this->model.mediaManager.getCurSongIndex();
        result.songs = *this->model.mediaManager.getCurSongList();
    } else {
        for (int i = -SONG_NUM_SHOW/2; i <= SONG_NUM_SHOW/2; i++) {
            int pos = this->model.mediaManager.getCurSongIndex();
            pos += i;
            if (pos > this->model.mediaManager.getNumberofSong() - 1) {
                pos -= this->model.mediaManager.getNumberofSong() - 1;
            } else if (pos < 0) {
                pos += this->model.mediaManager.getNumberofSong();
            }
            result.songs.push_back(this->model.mediaManager.getSong(pos));
        }
        result.curPos = SONG_NUM_SHOW/2;
    }
    return result;
}

void PlayHandler::handle(string command) {
    try {
        int option = stoi(command) - 1;
        PlayHandler::PlayingInfor infor;
        switch(option) {
            case REPLAY:
                infor = this->getPlayingInfor();
                view.display(this->model.mediaManager.getCurSong(), infor.songs, infor.curPos);
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
                infor = this->getPlayingInfor();
                view.display(this->model.mediaManager.getCurSong(), infor.songs, infor.curPos);
                break;
            case PREVIOUS:
                musicPlayer.previous();
                this->model.mediaManager.setCurSongIndex(musicPlayer.getCurrentIndex());
                infor = this->getPlayingInfor();
                view.display(this->model.mediaManager.getCurSong(), infor.songs, infor.curPos);
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
