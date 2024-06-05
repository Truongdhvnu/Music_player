#pragma once
#include "View.h"
#include <iostream>
#include <vector>
#include "Song.h"
#include "SongListView.h"

using namespace std;

class EditPlaylistView : public SongListView {
public:
    void display(Song s);
    //  {
    //     system("clear");
    //     cout << "============================ EDIT PLAYLIST =========================\n";
    //     cout << "\n\nTittle\t\tArtist\t\tAlbum\t\tDuration\n";
    //     cout << s.getTitle() << "\t" << s.getArtist() << "\t" << s.getAlbum() << "\t" << s.getDuration() << "\n\n\n";
    //     this->display_bottom();
    // }

    void display_bottom();
    //  {
    //     cout << "\n";
    //     cout << "1. Create\t\t 2. Rename \t\t 3. Add \t\t 4. Remove\n";
    //     SongListView::display_bottom();
    // }
};
