#pragma once
#include "Model.h"
#include "Handler.h"
#include <deque>

class Controller {
private:
    static Model& model;
    static int view_index;
public:
    static deque<Handler*> recentView;
    Controller();
    static void changeHandler(Handler* handler);
    int exit();
    void run();
};