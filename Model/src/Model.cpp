#pragma once
#include <string>
#include <vector>
#include "Model.h"

using namespace std;

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

Model::Model() {
    for(int i = 0; i < 100; i++) {
        database.push_back("Name's song no." + to_string(i));
    }
}
Model& Model::getInstance() {
    static Model m = Model();
    return m;
}

vector<string> Model::getPlaylist(int num) {
    vector<string> temp;
    for(int i = 0; i < 25; i++) {
        temp.push_back(database[(num - 1) * 25 + i]);
    }
    return temp;
}     