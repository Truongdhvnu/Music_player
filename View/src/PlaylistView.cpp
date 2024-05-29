#pragma once
#include "View.cpp"
#include <iostream>
#include <vector>

using namespace std;

class PlaylistView : public View {
public:
    void display() {
        system("clear");
        cout << "You have \"n\" playlists. Please select one to display\n";
        cout << "1. Stupid\n";
        cout << "2. Beauty\n";    
    }

    void displayPlaylist(const vector<string>& plist) {
        system("clear");
        this->display();
        for (auto it = plist.begin(); it != plist.end(); ++it) {
            cout << *it << endl;
        }
        View::display_bottom();   
    }
};
