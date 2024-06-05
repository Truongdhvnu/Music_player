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
                cout << "Playing\n";
                break;
            case PAUSE:
                cout << "Pause\n";
                break;
            case RESUME:
                cout << "Resume\n";
                break;
            case SHUFFLE:
                change_handler(EditMetadataHandler::getInstance());
                break;
            case NEXT:
                cout << "Next\n";
                break;
            case PREVIOUS:
                cout << "Previous\n";
                break;
            case VOLUME_UP:
                cout << "Volume up\n";
                break;
            case VOLUME_DOWN:
                cout << "Volume down\n";
                break;
            default:
                cout << "Invalid\n";
                break;
        }
    } catch (exception& e) {
        cout << "Invalid Input" << endl;
    }
};  
