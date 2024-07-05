#pragma once
#include "View.h"
#include <iostream>
#include <vector>
#include "Song.h"
#include <iomanip>
#include <sstream>

using namespace std;

class SongListView : public View {
public:
    void displayBottom();
    void displaySongs(vector<Song> songs, int pageNum, int size);
    int line = 0;
};
