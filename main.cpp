#include "Controller.h"

int main() {
    Controller c;
    c.run();
    return 0;
}

// #pragma once
// #include "Handler.cpp"
// #include "PlaylistView.cpp"
// // #include "Model.cpp"
// #include <string>

// class Model {
//     vector<string> database;
//     Model() {
//         for(int i = 0; i < 100; i++) {
//             database.push_back("Name's song no." + to_string(i));
//         }
//     }
// public:
//     static Model& getInstance() {
//         static Model m = Model();
//         return m;
//     }

//     /*
//         Just implement example logic
//     */
//     vector<string> getPlaylist(int num) {
//         vector<string> temp;
//         for(int i = 0; i < 25; i++) {
//             temp.push_back(database[(num - 1) * 25 + i]);
//         }
//         return temp;
//     }     
// };

// class PlaylistHandler : public Handler {
// private:
//     PlaylistView view;
//     Model& model;

//     PlaylistHandler() : model(Model::getInstance()){};
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
//         } else {
//             try {
//                 int play_list_num = stoi(command);
//                 if (play_list_num >= 0) {
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

// int main() {
//     PlaylistHandler* h = PlaylistHandler::getInstance(); 
//     h->onStart();
//     string s;
//     while(true) {
//         cin >> s;
//         h->handle(s);
//     }
// }