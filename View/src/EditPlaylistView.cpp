#include "EditPlaylistView.h"
#include <iostream>

void EditPlaylistView::display(Song s) {
    int linesPrinted = 0;
    system("clear");
    cout << alignMiddle("EDIT PLAYLIST", '=', WIDTH) << endl;
    linesPrinted++;
    cout << endl;
    linesPrinted++;
    cout << alignLeft("", ' ', NO_COL)
         << alignLeft("TITLE", ' ', TITLE_COL) 
         << alignLeft("ARTIST", ' ', ARTIST_COL) 
         << alignLeft("ALBUM", ' ', ALBUM_COL)
         << alignLeft("DURATION", ' ', DURATION_COL)
         << alignLeft("",' ', YEAR_COL)
         << endl;
    linesPrinted++;
    cout << alignLeft("", ' ', NO_COL)
         << alignLeft(truncate(s.getTitle(),TITLE_COL), ' ', TITLE_COL) 
         << alignLeft(truncate(s.getArtist(), ARTIST_COL), ' ', ARTIST_COL) 
         << alignLeft(truncate(s.getAlbum(), ALBUM_COL), ' ', ALBUM_COL)
         << alignLeft(truncate(s.getDuration(), DURATION_COL), ' ', DURATION_COL)
         << alignLeft("", ' ', YEAR_COL)
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
