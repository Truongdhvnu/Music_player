#include <vector>
#include <stack>
#include <string>
#include "Controller.h"
#include "Handler.h"
#include "PlaylistHandler.h"
#include "HomeHandler.h"

stack<Handler*> Controller::recentView;

Controller::Controller() {
    Controller::recentView.push(HomeHandler::getInstance());
    Controller::recentView.top()->onStart();
}

void Controller::changeHandler(Handler* handler) {
    Controller::recentView.push(handler);
    Controller::recentView.top()->onStart();
}

void Controller::run() {
    string command;
    while (true) {
        cin >> command;
        if (command == "b") {
            if (recentView.size() > 1) {
                recentView.pop();
            }
            recentView.top()->onStart();
        } else if(command == "h") {
            recentView.push(HomeHandler::getInstance());
            recentView.top()->onStart();
        } else {
            Controller::recentView.top()->handle(command);
        }
    }
}

// int main() {
//     Controller c;
//     c.run();
//     return 0;
// }
