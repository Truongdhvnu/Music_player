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
    // cout << alignLeft("1. Create", ' ', WIDTH/4)
    cout << alignLeft("1. Rename", ' ', WIDTH/4)
         << alignLeft("2. Add", ' ', WIDTH/4)
         << alignLeft("3. Remove", ' ', WIDTH/4)
         << endl;
    string next = "-Next: [";
    next = next + NEXT_PAGE + "]";
    string pre = "Previous: [";
    pre = pre + PREVIOUS_PAGE + "]";
    string sortname = "SortName: [";
    sortname = sortname + SORT_BY_NAME + "]";
    string sortartist = "SortArtist: [";
    sortartist = sortartist + SORT_BY_ARTIST + "]-";
    cout << alignLeft("",'-', WIDTH) << endl;
    cout << alignLeft(next,' ', 28)
         << alignLeft(pre,' ', 28)
         << alignLeft(sortname,' ', 28)
         << alignRight(sortartist,' ', 0)
         << endl;
    View::display_bottom();
}
