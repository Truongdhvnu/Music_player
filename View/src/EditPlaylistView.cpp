#include "EditPlaylistView.h"
#include <iostream>

void EditPlaylistView::display(Song s) {
    int linesPrinted = 0;
    system("clear");
    cout << alignMiddle("EDIT PLAYLIST", '=', WIDTH) << endl;
    linesPrinted++;
    cout << endl;
    linesPrinted++;
    cout << alignLeft("Title", ' ', 40) 
         << alignLeft("Artist", ' ', 25) 
         << alignLeft("Album", ' ', 25)
         << alignLeft("Duration", ' ', 10)
         << endl;
    linesPrinted++;
    cout << alignLeft(s.getTitle(), ' ', 40) 
         << alignLeft(s.getArtist(), ' ', 25) 
         << alignLeft(s.getAlbum(), ' ', 25)
         << alignLeft(s.getDuration(), ' ', 10)
         << endl;
    linesPrinted++;

    while (linesPrinted < LENGTH - 1) {
        cout << endl;
        linesPrinted++;
    }
    this->display_bottom();      
}

void EditPlaylistView::display_bottom() {
    cout << alignLeft("",'-', WIDTH) << endl;
    cout << alignLeft("1. Create", ' ', WIDTH/4) 
         << alignLeft("2. Rename", ' ', WIDTH/4) 
         << alignLeft("3. Add", ' ', WIDTH/4)
         << alignLeft("4. Remove", ' ', WIDTH/4)
         << endl;  
    SongListView::display_bottom(); 
}
