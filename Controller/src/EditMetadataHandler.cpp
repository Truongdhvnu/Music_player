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
    callback = Controller::changeHandler;
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
                this->model.media_manager.getCurrentSong().setTitle(input);
                break;
            case 2:
                cout << "Input new Artist: ";
                std::getline(std::cin, input);
                this->model.media_manager.getCurrentSong().setArtist(input);
                break;
            case 3:
                cout << "Input new Album: ";
                std::getline(std::cin, input);
                this->model.media_manager.getCurrentSong().setAlbum(input);
                break;
            case 4:
                cout << "Input new Year: ";
                std::getline(std::cin, input);
                this->model.media_manager.getCurrentSong().setYear(stoi(input));
                break;
            default:
                break;
        }
        this->onStart();
    // } catch (runtime_error& e) {
    //     cout << e.what() << endl;
    // }
    } catch (exception& e) {
        cout << "Invalid Input" << endl;
    }
}

void EditMetadataHandler::onStart(void* passData) {
    (void)passData;
    try {
        Song currentSong = this->model.media_manager.getCurrentSong();
        this->view.display(currentSong);
    } catch (out_of_range& e) {
        // do Nothing
    }
}
