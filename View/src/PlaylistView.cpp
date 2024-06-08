#include "PlaylistView.h"
#include <iostream>

void PlaylistView::display(vector<string> plists) {
    int linesPrinted = 0;
    system("clear");
    cout << View::alignMiddle("SELECT PLAYLIST", '=', WIDTH) << endl;
    linesPrinted++;
    cout << endl;
    linesPrinted++;
    int num = plists.size();
    cout << "You have " << num << " playlists. Please select one" << endl;
    linesPrinted++;
    for(int i = 0; i < num; i++) {
        cout << i + 1 << ". " << plists[i] << endl;
        linesPrinted++;
    }

    while (linesPrinted < LENGTH - 1) {
        cout << endl;
        linesPrinted++;
    }
    View::display_bottom();
}