#include "HomeView.h"
#include <iostream>

void HomeView::display() {
    int linesPrinted = 0;
    system("clear");
    cout << View::alignMiddle("MEDIA BROWSER", '=', WIDTH) << endl;
    linesPrinted++;
    cout << endl;
    linesPrinted++;
    cout << "Welcome. Select your option" << endl;
    linesPrinted++;
    cout << "1. Select direction" << endl;
    linesPrinted++;
    cout << "2. Play a playlist" << endl;
    linesPrinted++;
    cout << "3. Play songs from recent folders" << endl;
    linesPrinted++;  
    cout << "4. Edit playlists" << endl;

    while (linesPrinted < LENGTH - 1) {
        cout << endl;
        linesPrinted++;
    }
    View::display_bottom();

}
 