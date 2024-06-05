#include "SongListView.h"
#include <iostream>

void SongListView::display_bottom() {
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

void SongListView::displaySongs(vector<Song> songs, int pageNum) {
    int linesPrinted = 0;
    system("clear");
    cout << alignMiddle("MEDIA LIST", '=', WIDTH) << endl;
    linesPrinted++;
    cout << endl;
    linesPrinted++;   
        cout << alignLeft("NO", ' ', NO_COL)
         << alignLeft("TITLE", ' ', TITLE_COL) 
         << alignLeft("ARTIST", ' ', ARTIST_COL) 
         << alignLeft("ALBUM", ' ', ALBUM_COL)
         << alignLeft("DURATION", ' ', DURATION_COL)
         << alignLeft("YEAR",' ', YEAR_COL)
         << endl;
    linesPrinted++;
    int count = pageNum * MAX_LINES + 1;
    for (auto it = songs.begin(); it != songs.end(); ++it) {
        cout << alignLeft(to_string(count), ' ', NO_COL)
             << alignLeft(truncate((*it).getTitle(), TITLE_COL), ' ', TITLE_COL) 
             << alignLeft(truncate((*it).getArtist(), ARTIST_COL), ' ', ARTIST_COL) 
             << alignLeft(truncate((*it).getAlbum(), ALBUM_COL), ' ', ALBUM_COL)
             << alignLeft(truncate((*it).getDuration(), DURATION_COL), ' ', DURATION_COL)
             << alignLeft(truncate((*it).getYear(), YEAR_COL), ' ', YEAR_COL)
             << endl;
        linesPrinted++;
        count++;
    }
        
    while (linesPrinted < LENGTH - 1) {
        cout << endl;
        linesPrinted++;
    }
    this->display_bottom(); 
}
