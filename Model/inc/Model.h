#pragma once
#include <string>
#include <vector>
#include "MediaManager.h"

using namespace std;

class Model {
    vector<string> database;
    Model();
public:
    MediaManager media_manager;

    static Model& getInstance();
    vector<string> getPlaylist(int num);    
    // vector<Song> getPageOfSong(int pageNum);
    // void setActivePlist(int PlistNum);
    // void setActiveLibrary();
};