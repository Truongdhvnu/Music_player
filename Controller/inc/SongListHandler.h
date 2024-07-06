#pragma once
#include "Handler.h"
#include "SongListView.h"
#include "Model.h"
#include "string"

class SongListHandler : public Handler {
private:
    SongListView view;
    Model& model;
    SongListHandler();
    static int currentPage;
    static int currentSongIndex;
    static int fullPage;
public:
    static SongListHandler* getInstance();
    void onStart(void* passData = nullptr);
    void handle(string command);
    void leavePage(){}  
    void reloadDisplay(int line);
};
