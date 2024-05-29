#pragma once
#include <iostream>
#include <functional>
#include "Handler.h"
// #include "Controller.h"

using namespace std;

// function<void(Handler*)> Handler::callback = Controller::changeHandler;

// class Handler;
// void foo(Handler* handler);

// class Handler {
// public:
//     function<void(Handler*)> callback = foo;
//     virtual void handle(string command) = 0;
//     virtual void onStart() = 0;  
//     void change_handler(Handler* handler);
// };

void foo(Handler* handler) {
    cout << "Up\n";
}

void Handler::change_handler(Handler* handler) {
    Handler::callback(handler);
}
