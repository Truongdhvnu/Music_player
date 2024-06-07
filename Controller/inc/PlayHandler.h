#pragma once
#include "Handler.h"
#include "PlayView.h"
#include "Model.h"
#include "string"
#include "MusicPlayer.h"

class PlayHandler : public Handler {
private:
    PlayView view;
    Model& model;
    PlayHandler();
    static int currentPage;
    static bool onDisplay;
public:
    static int currentSongIndex;
    static PlayHandler* getInstance();
    void onStart(void* passData = nullptr);
    void handle(string command);
    MusicPlayer musicPlayer;
    void leavePage();

    void updateView(); // Thêm phương thức updateView
};