#include "CreatePlaylistView.h"
#include <iostream>

void CreatePlaylistView::display_bottom() {
    string create = "Create: [";
    create = create + CREATE + "]";
    string del = "Delete: [";
    del = del + DELETE + "]";
    cout << alignLeft("",'-', WIDTH) << endl;
    cout << alignMiddle(create,' ', WIDTH/2)
         << alignMiddle(del,' ', WIDTH/2)
         << endl;
    View::display_bottom();
}

void CreatePlaylistView::display(vector<string> plists) {
    int linesPrinted = 0;
    system("clear");
    cout << View::alignMiddle("EDIT PLAYLISTS", '=', WIDTH) << endl;
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
    CreatePlaylistView::display_bottom();
}