#pragma once
#include <string>
#include <vector>

using namespace std;

class Model {
    vector<string> database;
    Model();
public:
    static Model& getInstance();
    vector<string> getPlaylist(int num);    
};