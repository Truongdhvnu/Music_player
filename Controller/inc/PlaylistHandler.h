#pragma once
#include "Handler.h"
#include "PlaylistView.h"
#include "Model.h"
#include "string"

class PlaylistHandler : public Handler {
private:
    PlaylistView view;
    Model& model;
    PlaylistHandler();
public:
    static PlaylistHandler* getInstance();
    void onStart();
    void handle(string command);
};