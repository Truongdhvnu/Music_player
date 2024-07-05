#pragma once
#include "Handler.h"
#include "HomeView.h"
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
    void onStart(void* passData = nullptr);
    void leavePage(){}
    void reloadDisplay(int line);
};