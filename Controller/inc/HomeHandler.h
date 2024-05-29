#pragma once
#include "Handler.h"
#include "HomeView.cpp"
#include "Model.h"
#include <string>

class HomeHandler : public Handler {
private:
    HomeView view;
    Model& model;
    HomeHandler();
    static HomeHandler* instancePtr;
public:
    static HomeHandler* getInstance();
    void handle(string command);
    void onStart();
};