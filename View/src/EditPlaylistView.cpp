#include "EditPlaylistView.h"
#include <iostream>

void EditPlaylistView::displaySongs(vector<Song> songs,int pageNum, int size) {
    View::displaySongs(songs, pageNum, size);
    View::alignLength();
    this->displayBottom();      
}

void EditPlaylistView::displayBottom() {
    cout << alignLeft("",'-', WIDTH) << endl;
    cout << alignLeft("-1. Rename", ' ', 28)
         << alignLeft("2. Add From Cur", ' ', 28)
         << alignLeft("3. Add From New", ' ', 28)
         << alignLeft("4. Remove-", ' ', 15)
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
    View::displayBottom();
}
