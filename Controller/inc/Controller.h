#pragma once
#include "Model.h"
#include "Handler.h"
#include <stack>

class Controller {
private:
    Model& model = Model::getInstance();
public:
    static stack<Handler*> recentView;
    Controller();
    static void changeHandler(Handler* handler);
    void run();
};