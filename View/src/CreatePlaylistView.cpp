#include "CreatePlaylistView.h"
#include <iostream>

void CreatePlaylistView::displayBottom() {
    string create = "Create: [";
    create = create + CREATE + "]";
    string del = "Delete: [";
    del = del + DELETE + "]";
    cout << alignLeft("",'-', WIDTH) << endl;
    cout << alignMiddle(create,' ', WIDTH/2)
         << alignMiddle(del,' ', WIDTH/2)
         << endl;
    View::displayBottom();
}

void CreatePlaylistView::display(vector<string> plists) {
    system("clear");
    cout << View::alignMiddle(" EDIT PLAYLISTS ", '=', WIDTH) << endl;
    cout << endl;
    int num = plists.size();
    cout << "You have " << num << " playlists. Please select one" << endl;
    for(int i = 0; i < num; i++) {
        cout << i + 1 << ". " << plists[i] << endl;
    }
    View::alignLength();
    CreatePlaylistView::displayBottom();
}