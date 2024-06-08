#pragma once
#include "Song.h"
#include "MediaList.h"
#include <vector>
#include <string>

using namespace std;

class Library : public MediaList{
private:    
    vector<string> dirPaths;
    bool needToChange = false;
    void getMediaFileFromDir(const string& dir);
    bool songfetched = false;
public:
    Library();

    bool isSongFetched();

    void getSongFromCurrentDirs();

    void getSongFromPath(string path);

    void addPathToCurrentDirs(string path);

    bool isAlreadyInCurDirs(string path);
};