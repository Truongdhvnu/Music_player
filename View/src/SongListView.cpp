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

void SongListView::displaySongs(vector<Song> songs, int pageNum, int size) {
    View::displaySongs(songs, pageNum, size);
    View::alignLength();
    this->display_bottom(); 
}

