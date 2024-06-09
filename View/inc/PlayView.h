#pragma once
#include "View.h"
#include <iostream>
#include <vector>
#include "Song.h" 

using namespace std;

class PlayView : public View {
public:
    void display(Song s, vector<Song> songs, int curPos);
    void displayBottom();
};
