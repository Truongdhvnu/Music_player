#include "Handler.h"
#include "PlaylistView.h"
#include "Model.h"
#include <string>
#include <stack>
#include "Controller.h"
#include "PlaylistHandler.h"
#include "display.h"

PlaylistHandler::PlaylistHandler() : model(Model::getInstance()) {
    callback = Controller::changeHandler;
};

PlaylistHandler* PlaylistHandler::getInstance() {
    static PlaylistHandler pl = PlaylistHandler();
    return &pl;
}

void PlaylistHandler::onStart() {
    this->view.display();
    this->view.display_bottom();
}

void PlaylistHandler::handle(string command) {
    static int current_plist = 0;
    if (command == PREVIOUS_PAGE) {
        this->handle(to_string(current_plist - 1));
    } else if (command == NEXT_PAGE) {
        this->handle(to_string(current_plist + 1));  
    } else {
        try {
            int play_list_num = stoi(command);
            if (play_list_num > 0) {
                current_plist = play_list_num;
                const vector<string> plist = this->model.getPlaylist(play_list_num);
                this->view.displayPlaylist(plist);
            }
        } catch (const exception& e) {
            cout << "P No actions or Invalid command\n";
        }
    } 
};  

// #include "PlaylistView.cpp"
// #include "Model.h"
// #include <string>
// #include <stack>

// class Controller {
// private:
//     Model& model = Model::getInstance();
// public:
//     static stack<Handler*> recentView;
//     Controller();
//     static void changeHandler(Handler* handler);
//     void run();
// };

// class PlaylistHandler : public Handler {
// private:
//     PlaylistView view;
//     Model model;
//     PlaylistHandler() : model(Model::getInstance()) {
//         callback = Controller::changeHandler;
//         // callback = foo;
//     };
// public:
//     static PlaylistHandler* getInstance() {
//         static PlaylistHandler pl = PlaylistHandler();
//         return &pl;
//     }
    
//     void onStart() {
//         this->view.display();
//         this->view.display_bottom();
//     }

//     void handle(string command) {
//         static int current_plist = 0;
//         if (command == "<") {
//             this->handle(to_string(current_plist - 1));
//         } else if (command == ">") {
//             this->handle(to_string(current_plist + 1));  
//         } else if (command == "b") {
//             this->change_handler(PlaylistHandler::getInstance());
//         } else {
//             try {
//                 int play_list_num = stoi(command);
//                 if (play_list_num > 0) {
//                     current_plist = play_list_num;
//                     const vector<string> plist = this->model.getPlaylist(play_list_num);
//                     this->view.displayPlaylist(plist);
//                 }
//             } catch (const exception& e) {
//                 cout << "Please input valid command\n";
//             }
//         } 
//     };  
// };

// stack<Handler*> Controller::recentView;

// Controller::Controller() {
//     Controller::recentView.push(PlaylistHandler::getInstance());
//     Controller::recentView.top()->onStart();
// }

// void Controller::changeHandler(Handler* handler) {
//     Controller::recentView.push(handler);
//     Controller::recentView.top()->onStart();
// }

// void Controller::run() {
//     string command;
//     while (true) {
//         cin >> command;
//         Controller::recentView.top()->handle(command);
//     }
// }

// int main() {
//     Controller c;
//     c.run();
//     return 0;
// }

// int main() {
//     PlaylistHandler* h = PlaylistHandler::getInstance(); 
//     h->onStart();
//     string s;
//     while(true) {
//         cin >> s;
//         h->handle(s);
//     }
// }
