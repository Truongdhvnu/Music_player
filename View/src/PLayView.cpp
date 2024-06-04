#include "PlayView.h"
#include <iostream>

void PlayView::display(Song s) {
    int linesPrinted = 0;
    system("clear");
    cout << alignMiddle("MEDIA PLAYING", '=', WIDTH) << endl;
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

void PlayView::display_bottom() {
    cout << alignLeft("",'-', WIDTH) << endl;
    cout << alignLeft("1. PLay", ' ', WIDTH/4) 
         << alignLeft("2. Pause", ' ', WIDTH/4) 
         << alignLeft("3. Resume", ' ', WIDTH/4)
         << alignLeft("4. Shuffle", ' ', WIDTH/4)
         << endl;
    cout << alignLeft("5. Next", ' ', WIDTH/4) 
         << alignLeft("6. Previous", ' ', WIDTH/4) 
         << alignLeft("7. Volume Up", ' ', WIDTH/4)
         << alignLeft("8. Volume Down", ' ', WIDTH/4)
         << endl;  
    View::display_bottom();       
}