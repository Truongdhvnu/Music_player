#include "HomeView.h"
#include <iostream>

void HomeView::display() {
    vector<string> option = {
        "1. Select direction",
        "2. Play a playlist",
        "3. Play songs from recent folders",
        "4. Edit playlists"
    };
    // int num = option.size();

    system("clear");
    cout << View::alignMiddle(" MEDIA BROWSER ", '=', WIDTH) << endl;
    cout << endl;
    cout << "Welcome. Select your option:" << endl << endl;

    for(unsigned int i = 0; i < option.size(); i++) {
        if((line % option.size()) == i) View::highlightLine(option[i]);
        else cout << option[i] << endl;
        // else cout << i + 1 << ". " << option[i] << endl;
    }
    // cout << "1. Select direction" << endl;
    // cout << "2. Play a playlist" << endl;
    // cout << "3. Play songs from recent folders" << endl;  
    // cout << "4. Edit playlists" << endl;

    View::alignLength();
    View::displayBottom();
}
 