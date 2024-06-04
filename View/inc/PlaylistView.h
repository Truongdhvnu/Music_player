#pragma once
#include "View.h"
#include <iostream>
#include <vector>
#include <Playlist.h>

using namespace std;

class PlaylistView : public View {
public:
    void display(vector<string> plists) {
        system("clear");
        cout << "============================SELECT PLAYLIST==============================\n\n";
        int num = plists.size();
        cout << "You have " << num << " playlists. Please select one\n";
        for(int i = 0; i < num; i++) {
            cout << i + 1 << ". " << plists[i] << "\n";
        }
        cout << "\n\n";
        View::display_bottom();
    }
};
