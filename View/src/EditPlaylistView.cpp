#include "EditPlaylistView.h"
#include <iostream>

void EditPlaylistView::displaySongs(vector<Song> songs,int pageNum, int size) {
    View::displaySongs(songs, pageNum, size);
    View::alignLength();
    this->display_bottom();      
}

void EditPlaylistView::display_bottom() {
    cout << alignLeft("",'-', WIDTH) << endl;
    cout << alignLeft("-1. Rename", ' ', WIDTH/4)
         << alignMiddle("2. Add", ' ', WIDTH/2)
         << alignRight("3. Remove-", ' ', WIDTH/4)
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
    cout << alignLeft(next,' ', WIDTH/4)
         << alignLeft(pre,' ', WIDTH/4)
         << alignRight(sortname,' ', WIDTH/4)
         << alignRight(sortartist,' ', WIDTH/4)
         << endl;
    View::display_bottom();
}
