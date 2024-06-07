#pragma once
#include <iostream>
#include <functional>
// #include "Controller.h"

using namespace std;

class Handler {
public:
    function<void(Handler*, void*)> changeHandelCallback;
    function<void(void*)> popCallback;
    virtual void handle(string command) = 0;
    virtual void onStart(void* passData = nullptr) = 0;
    virtual void leavePage();
    void changeHandler(Handler* handler, void* passData = nullptr);
    void selfPop(void* passData = nullptr);
    virtual int exit();
};
