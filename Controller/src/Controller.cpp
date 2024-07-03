#include <vector>
#include <stack>
#include <string>
#include "Controller.h"
#include "Handler.h"
#include "PlaylistHandler.h"
#include "MusicPlayer.h"
#include <USBDetect.h>
#include "HomeHandler.h"
#include "Model.h"
#include "display.h"
#include "Command.h"

Model& Controller::model = Model::getInstance();
deque<Handler*> Controller::recentView;
int Controller::view_index = 0;

Controller::Controller() {
    Controller::recentView.push_back(HomeHandler::getInstance());
    Controller::recentView[view_index]->onStart();
}

void Controller::PopHandler(void* paras) {
    recentView.pop_back();
    recentView[view_index]->onStart(paras);
}

void Controller::changeHandler(Handler* handler, void* paras) {
    while (recentView.size() > MAX_HISTORY_PAGE - 1)
    {
        recentView.pop_front();
        view_index--;
    }
    int temp = view_index;
    while ((long unsigned int)temp < recentView.size() - 1)
    {
        recentView.pop_back();
    }

    Controller::recentView.push_back(handler);
    recentView[view_index]->leavePage();
    view_index++;
    recentView[view_index]->onStart(paras);
}

int Controller::exit() {
    this->model.mediaManager.updateDatabase();
    return 0;
}

void Controller::run() {
    string command;
    Command cmd;
    while (true) {
        // cin >> command;
        cout << endl;
        command = cmd.getCommand();
        if (command == GO_BACK) {
            if (view_index >= 1) {
                recentView[view_index]->leavePage();
                view_index--;
                recentView[view_index]->onStart();
            }
        } else if (command == FORWARD) {
            if (recentView.size() - 1  > (long unsigned int)view_index) {
                recentView[view_index]->leavePage();
                view_index++;
                recentView[view_index]->onStart();
            }
        } else if (command == EXIT) {
            for(Handler* e : recentView) {
                e->exit();
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