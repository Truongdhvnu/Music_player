#pragma once
#include <iostream>
#include <functional>
// #include "Controller.h"

using namespace std;

class Handler;
void foo(Handler* handler);

class Handler {
public:
    function<void(Handler*)> callback;
    virtual void handle(string command) = 0;
    virtual void onStart() = 0;  
    void change_handler(Handler* handler);
};
