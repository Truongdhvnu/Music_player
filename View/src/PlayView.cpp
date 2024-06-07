#include "PlayView.h"
#include <iostream>

void PlayView::display(Song s) {
    int linesPrinted = 0;
    system("clear");
    cout << alignMiddle("MEDIA PLAYING", '=', WIDTH) << endl;
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

void PlayView::display_bottom() {
    cout << alignLeft("",'-', WIDTH) << endl;
    cout << alignLeft("1. Play", ' ', WIDTH/4) 
         << alignLeft("2. Pause", ' ', WIDTH/4) 
         << alignLeft("3. Resume", ' ', WIDTH/4)
         << alignLeft("4. Edit Metadata", ' ', WIDTH/4)
         << endl;
    cout << alignLeft("5. Next", ' ', WIDTH/4) 
         << alignLeft("6. Previous", ' ', WIDTH/4) 
         << alignLeft("7. Volume Up", ' ', WIDTH/4)
         << alignLeft("8. Volume Down", ' ', WIDTH/4)
         << endl;  
    View::display_bottom();       
}