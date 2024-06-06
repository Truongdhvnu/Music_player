#include "EditMetadataView.h"
#include <iostream>

void EditMetadataView::display(Song s) {
    int linesPrinted = 0;
    system("clear");
    cout << alignMiddle("CHANGE METADATA", '=', WIDTH) << endl;
    linesPrinted++;
    cout << endl;
    linesPrinted++;
    cout << alignLeft("", ' ', NO_COL)
         << alignLeft("TITLE", ' ', TITLE_COL) 
         << alignLeft("ARTIST", ' ', ARTIST_COL) 
         << alignLeft("ALBUM", ' ', ALBUM_COL)
         << alignLeft("DURATION", ' ', DURATION_COL)
         << alignLeft("YEAR",' ', YEAR_COL)
         << endl;
    linesPrinted++;
    cout << alignLeft("", ' ', NO_COL)
         << alignLeft(truncate(s.getTitle(),TITLE_COL), ' ', TITLE_COL) 
         << alignLeft(truncate(s.getArtist(), ARTIST_COL), ' ', ARTIST_COL) 
         << alignLeft(truncate(s.getAlbum(), ALBUM_COL), ' ', ALBUM_COL)
         << alignLeft(truncate(s.getDuration(), DURATION_COL), ' ', DURATION_COL)
         << alignLeft(truncate(s.getYear(), YEAR_COL), ' ', YEAR_COL)
         << endl;
    linesPrinted++;

    while (linesPrinted < LENGTH - 1) {
        cout << endl;
        linesPrinted++;
    }
    this->display_bottom();     
}

void EditMetadataView::display_bottom() {
    cout << alignLeft("",'-', WIDTH) << endl;
    cout << alignLeft("1. Set Title", ' ', WIDTH/4) 
         << alignLeft("2. Set Artist", ' ', WIDTH/4) 
         << alignLeft("3. Set Album", ' ', WIDTH/4)
         << alignLeft("4. Set Year", ' ', WIDTH/4)
         << endl;  
    View::display_bottom();       
}