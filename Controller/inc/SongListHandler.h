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
public:
    static SongListHandler* getInstance();
    void onStart(void* passData = nullptr);
    void handle(string command);
    void leavePage(){}  
};