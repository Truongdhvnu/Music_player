#pragma once
#include "Handler.h"
#include "PlaylistView.h"
#include "Model.h"
#include "string"

class ChoosePlaylistHandler : public Handler {
private:
    PlaylistView view;
    Model& model;
    ChoosePlaylistHandler();
public:
    static ChoosePlaylistHandler* getInstance();
    void onStart(void* passData = nullptr);
    void handle(string command);
};
