#include "EditMetadataView.h"
#include <iostream>

void EditMetadataView::display(Song s) {
    int linesPrinted = 0;
    system("clear");
    cout << alignMiddle("CHANGE METADATA", '=', WIDTH) << endl;
    linesPrinted++;
    cout << endl;
    linesPrinted++;
    cout << alignLeft("Title", ' ', 35) 
         << alignLeft("Artist", ' ', 25) 
         << alignLeft("Album", ' ', 25)
         << alignLeft("Duration", ' ', 10)
         << alignLeft("Year",' ', 5)
         << endl;
    linesPrinted++;
    cout << alignLeft(s.getTitle(), ' ', 35) 
         << alignLeft(s.getArtist(), ' ', 25) 
         << alignLeft(s.getAlbum(), ' ', 25)
         << alignLeft(s.getDuration(), ' ', 10)
         << alignLeft(s.getYear(), ' ', 5)
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
         << alignLeft("4. Set Yeat", ' ', WIDTH/4)
         << endl;  
    View::display_bottom();       
}