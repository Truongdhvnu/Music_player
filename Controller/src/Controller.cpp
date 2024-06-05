#include <vector>
#include <stack>
#include <string>
#include "Controller.h"
#include "Handler.h"
#include "PlaylistHandler.h"
#include "MusicPlayer.h"
#include "HomeHandler.h"
#include "Model.h"
#include "display.h"

Model& Controller::model = Model::getInstance();
deque<Handler*> Controller::recentView;
int Controller::view_index = 0;

Controller::Controller() {
    Controller::recentView.push_back(HomeHandler::getInstance());
    Controller::recentView[view_index]->onStart();
}

void Controller::changeHandler(Handler* handler, void* paras) {
    while (recentView.size() > MAX_HISTORY_PAGE - 1)
    {
        recentView.pop_front();
        view_index--;
    }
    int temp = view_index;
    while (temp < recentView.size() - 1)
    {
        recentView.pop_back();
    }

    Controller::recentView.push_back(handler);
    view_index++;
    recentView[view_index]->onStart(paras);
}

/*
    Handel things before exit programs
*/
int Controller::exit() {
    return 0;
}

void Controller::run() {
    string command;
    while (true) {
        cin >> command;
        if (command == GO_BACK) {
            if (view_index >= 1) {
                view_index--;
                recentView[view_index]->onStart();
            }
        } else if (command == FORWARD) {
            if (recentView.size() - 1  > view_index) {
                view_index++;
                recentView[view_index]->onStart();
            }
        } else if (command == EXIT) {
            for(Handler* e : recentView) {
                e->handler_exit();              // có th nào nhạc đang phát nhưng không tắt đi được không? do chang_handler đã xóa mất the handler khỏi danh sách
            }
            this->exit();
            std::exit(0);
        }
        else if(command == HOME) {
            Controller::changeHandler(HomeHandler::getInstance());
        } else {
            Controller::recentView[view_index]->handle(command);
        }
    }
}

// int main() {
//     Controller c;
//     c.run();
//     return 0;
// }
