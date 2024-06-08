#include "PlayView.h"
#include <iostream>

void PlayView::display(Song s) {
     system("clear");
     cout << alignMiddle("MEDIA PLAYING", '=', WIDTH) << endl;
     cout << endl;;
     cout << alignLeft("", ' ', NO_COL)
          << alignLeft("TITLE", ' ', TITLE_COL) 
          << alignLeft("ARTIST", ' ', ARTIST_COL) 
          << alignLeft("ALBUM", ' ', ALBUM_COL)
          << alignLeft("DURATION", ' ', DURATION_COL)
          << alignLeft("YEAR",' ', YEAR_COL)
          << endl << endl;
     cout << alignLeft("", ' ', NO_COL)
          << alignLeft(truncate(s.getTitle(),TITLE_COL), ' ', TITLE_COL) 
          << alignLeft(truncate(s.getArtist(), ARTIST_COL), ' ', ARTIST_COL) 
          << alignLeft(truncate(s.getAlbum(), ALBUM_COL), ' ', ALBUM_COL)
          << alignLeft(truncate(s.getDuration(), DURATION_COL), ' ', DURATION_COL)
          << alignLeft(truncate(s.getYear(), YEAR_COL), ' ', YEAR_COL)
          << endl;
     View::alignLength();
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
