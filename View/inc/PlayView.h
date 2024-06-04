#pragma once
#include "View.h"
#include <iostream>
#include <vector>
#include "Song.h" 

using namespace std;

class PlayView : public View {
public:
    void display(Song s);
    //     system("clear");
    //     cout << "============================ MEDIA PLAYING =========================\n";
    //     cout << "\n\nTittle\t\tArtist\t\tAlbum\t\tDuration\n"; 
    //     cout << s.getTitle() << "\t" << s.getArtist() << "\t" << s.getAlbum() << "\t" << s.getDuration() << "\n\n\n"; 
    //     this->display_bottom();  

    void display_bottom();
        // cout << "\n";
        // cout << "1. Play\t\t 2. Pause \t\t 3. Resume \t\t 4. Shuffle \n5. Next\t\t 6. Pevious\t\t 7. Volume Up\t\t 8. Volume Down\n";
        // View::display_bottom();
};
