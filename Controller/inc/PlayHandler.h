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
    MusicPlayer musicPlayer;
    PlayHandler();
    static int currentPage;
    static bool onDisplay;
public:
    typedef struct PlayingInfor {
        int curPos;
        vector<Song> songs;
    } PlayingInfor;
    static PlayHandler* getInstance();
    void onStart(void* passData = nullptr);
    void handle(string command);
    void leavePage();
    void updateView();
    PlayingInfor getPlayingInfor();
};
