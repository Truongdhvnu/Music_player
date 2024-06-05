#pragma once
#include "View.h"
#include <iostream>
#include "Song.h"

using namespace std;

class EditMetadataView : public View {
public:
    void display() {}
    void display(Song s) {
        system("clear");
        cout << "Change Metadata\n\n";
        cout << "\n\nTittle\t\tArtist\t\tAlbum\t\tDuration\tYear\n";
        cout << s.getTitle() << "\t" << s.getArtist() << "\t" << s.getAlbum() << "\t" << s.getDuration() << "\t\t" << s.getYear() << "\n\n\n";

        cout << "1. SetTitle \t\t 2.SetArtist \t\t 3.SetAlbum \t\t 4.SetYear\n";
        this->display_bottom();
    }
};
