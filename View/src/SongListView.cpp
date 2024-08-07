#include "SongListView.h"
#include <iostream>

void SongListView::displayBottom() {
    string next = "-Next: [";
    next = next + NEXT_PAGE + "]";
    string pre = "Previous: [";
    pre = pre + PREVIOUS_PAGE + "]";
    string sortname = "SortName: [";
    sortname = sortname + SORT_BY_NAME + "]";
    string sortartist = "SortArtist: [";
    sortartist = sortartist + SORT_BY_ARTIST + "]-";
    cout << alignLeft("",'-', WIDTH) << endl;
    cout << alignLeft(next,' ', WIDTH/4)
         << alignLeft(pre,' ', WIDTH/4)
         << alignRight(sortname,' ', WIDTH/4)
         << alignRight(sortartist,' ', WIDTH/4)
         << endl;
    View::displayBottom();
}

void SongListView::displaySongs(vector<Song> songs, int pageNum, int size) {
    View::displaySongs(songs, pageNum, size, line);
    View::alignLength();
    this->displayBottom(); 
}

