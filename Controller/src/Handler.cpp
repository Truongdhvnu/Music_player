#include <iostream>
#include <functional>
#include "Handler.h"
// #include "Controller.h"

using namespace std;

void Handler::leavePage() { 
}

void Handler::changeHandler(Handler *handler, void *passData) {
    Handler::changeHandelCallback(handler, passData);
}

void Handler::selfPop(void *passData) {
    Handler::popCallback(passData);
}

int Handler::exit() {
    return 0;
}