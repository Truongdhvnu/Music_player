#pragma once
#include "View.h"
#include <iostream>
#include <vector>
#include <Playlist.h>

using namespace std;

class PlaylistView : public View {
public:
    void display(vector<string> plists);
};
