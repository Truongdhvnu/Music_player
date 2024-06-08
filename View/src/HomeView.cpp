#include "HomeView.h"
#include <iostream>

void HomeView::display() {
    system("clear");
    cout << View::alignMiddle("MEDIA BROWSER", '=', WIDTH) << endl;
    cout << endl;
    cout << "Welcome. Select your option" << endl;
    cout << "1. Select directory" << endl;
    cout << "2. Play a playlist" << endl;
    cout << "3. Play songs from recent folders" << endl;  
    cout << "4. Edit playlists" << endl;

    View::alignLength();
    View::displayBottom();
}
 