#include "EditPlaylistView.h"
#include <iostream>

void EditPlaylistView::displaySongs(vector<Song> songs, int pageNum) {
    View::displaySongs(songs, pageNum);
    this->display_bottom();
}

void EditPlaylistView::display_bottom() {
    cout << alignLeft("",'-', WIDTH) << endl;
    // cout << alignLeft("1. Create", ' ', WIDTH/4)
    cout << alignLeft("1. Rename", ' ', WIDTH/4)
         << alignLeft("2. Add", ' ', WIDTH/4)
         << alignLeft("3. Remove", ' ', WIDTH/4)
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
    View::display_bottom();
}
