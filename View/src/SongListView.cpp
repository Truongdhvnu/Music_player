#include "SongListView.h"
#include <iostream>

void SongListView::display_bottom() {
    cout << alignLeft("",'-', WIDTH) << endl; 
    string next = "-Next: [";
    next = next + NEXT_PAGE + "]";
    string pre = "Previous: [";
    pre = pre + PREVIOUS_PAGE + "]";
    string sortname = "SortName: [";
    sortname = sortname + SORT_BY_NAME + "]";
    string sortartist = "SortArtist: [";
    sortartist = sortartist + SORT_BY_ARTIST + "]-";
    // cout << alignLeft("",'-', WIDTH) << endl;
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
    cout << alignLeft("No", ' ', 5)
         << alignLeft("Title", ' ', 35) 
         << alignLeft("Artist", ' ', 25) 
         << alignLeft("Album", ' ', 25)
         << alignLeft("Duration", ' ', 10)
         << endl;
    linesPrinted++;
    int count = pageNum * MAX_LINES + 1;
    for (auto it = songs.begin(); it != songs.end(); ++it) {
        cout << alignLeft(to_string(count), ' ', 5)
             << alignLeft((*it).getTitle(), ' ', 35) 
             << alignLeft((*it).getArtist(), ' ', 25) 
             << alignLeft((*it).getAlbum(), ' ', 25)
             << alignLeft((*it).getDuration(), ' ', 10)
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
