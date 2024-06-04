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
    void display_bottom();
    void displaySongs(vector<Song> songs, int pageNum);
};
