#pragma once
#include "View.h"
#include <iostream>
#include <vector>

using namespace std;

class PlaylistView : public View {
public:
    void display() {
        system("clear");
        cout << "You have 2 playlists. Please select one to display\n";
        cout << "1. Stupid\n";
        cout << "2. Beauty\n";    
    }
    void display_options() {
        cout << "--------------------------------------------------------------------------------------\n";
        cout << "- Next page: "<< NEXT_PAGE << "\t\t Previous pape: " << PREVIOUS_PAGE << "                                    -\n";
    }

    void display_bottom() {
        this->display_options();
        View::display_bottom();
    }
    
    void displayPlaylist(const vector<string>& plist) {
        system("clear");
        this->display();
        for (auto it = plist.begin(); it != plist.end(); ++it) {
            cout << *it << endl;
        }
        display_bottom();   
    }
};
