#pragma once
#include "View.h"
#include <iostream>
#include <vector>
#include "Song.h"
#include <iomanip>
#include <sstream>

using namespace std;

class EditPlaylistView : public View {
public:
    void display_bottom();
    void displaySongs(vector<Song> songs, int pageNumn, int size);
    // void display(Song s);
};
