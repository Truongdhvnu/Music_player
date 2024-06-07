#pragma once
#include <iostream>
#include <functional>
// #include "Controller.h"

using namespace std;

class Handler;

class Handler {
public:
    function<void(Handler*, void*)> callback;
    virtual void handle(string command) = 0;
    virtual void onStart(void* passData = nullptr) = 0;
    virtual void leavePage(){}
    void change_handler(Handler* handler, void* passData = nullptr);
    // void remove_handler();
    virtual int handler_exit();
};
