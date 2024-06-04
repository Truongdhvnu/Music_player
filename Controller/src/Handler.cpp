#include <iostream>
#include <functional>
#include "Handler.h"
// #include "Controller.h"

using namespace std;

void Handler::change_handler(Handler* handler, void* passData) {
    Handler::callback(handler, passData);
}

int Handler::handler_exit() {
    return 0;
}