#include "EditMetadataHandler.h"
#include "Handler.h"
#include "HomeView.h"
#include "Model.h"
#include "PlaylistHandler.h"
#include "Controller.h"
#include "EditMetadataHandler.h"
#include "SongListHandler.h"
#include "PlayHandler.h"
#include <algorithm>
#include <cctype>
#include <string>
#include <limits>

EditMetadataHandler* EditMetadataHandler::instancePtr = nullptr;

EditMetadataHandler::EditMetadataHandler() : model(Model::getInstance()){
    changeHandelCallback = Controller::changeHandler;
}

EditMetadataHandler* EditMetadataHandler::getInstance() {
    if (instancePtr == nullptr) {
        EditMetadataHandler* instancePtr = new EditMetadataHandler();
        return instancePtr;
    } else {
        return instancePtr;
    }
}

void EditMetadataHandler::handle(string command) {
    try {
        int option = stoi(command);
        std::string input;
        /* Clear cin buffer */
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (option) {
            case 1:
                cout << "Input new Title: " << endl;
                std::getline(std::cin, input);
                this->model.mediaManager.getCurSong().setTitle(input);
                break;
            case 2:
                cout << "Input new Artist: ";
                std::getline(std::cin, input);
                this->model.mediaManager.getCurSong().setArtist(input);
                break;
            case 3:
                cout << "Input new Album: ";
                std::getline(std::cin, input);
                this->model.mediaManager.getCurSong().setAlbum(input);
                break;
            case 4:
                cout << "Input new Year: ";
                std::getline(std::cin, input);
                this->model.mediaManager.getCurSong().setYear(stoi(input));
                break;
            default:
                break;
        }
        this->onStart();
    } catch (runtime_error& e) {
        cout << "Editmetadata: "<< e.what() << endl;
    }
}

void EditMetadataHandler::onStart(void* passData) {
    (void)passData;
    Song currentSong = this->model.mediaManager.getCurSong();
    this->view.display(currentSong);
}
