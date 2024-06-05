#pragma once
#include "Handler.h"
#include "PlayView.h"
#include "Model.h"
#include "string"

class PlayHandler : public Handler {
private:
    PlayView view;
    Model& model;
    PlayHandler();
    static int currentPage;
public:
    static int currentSongIndex;
    static PlayHandler* getInstance();
    void onStart(void* passData = nullptr);
    void handle(string command);
};