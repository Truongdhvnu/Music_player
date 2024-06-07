#pragma once
#include "Handler.h"
#include "SongListView.h"
#include "Model.h"
#include "string"

class ChooseSongsHandler : public Handler {
private:
    SongListView view;
    Model& model;
    ChooseSongsHandler();
    static int currentPage;
    static Playlist* plist;
public:
    static ChooseSongsHandler* getInstance();
    void onStart(void* passData = nullptr);
    void handle(string command);
    void leavePage(); 
};
