#pragma once
#include "View.h"
#include <iostream>
#include <vector>
#include "Song.h"
#include <iomanip>

using namespace std;

class SongListView : public View {
public:
    void display_bottom() {
        cout << "--------------------------------------------------------------------------------------\n";
        cout << "- Next: "<< NEXT_PAGE << "\t\t Pre: " << PREVIOUS_PAGE << "\t\tSortName: "
                << SORT_BY_NAME << "\t\tSortArtist: " << SORT_BY_ARTIST << "        -\n";
        View::display_bottom();
    }

    void displaySongs(vector<Song> songs, int pageNum) {
        system("clear");
        cout << "============================ MEDIA LIST =========================\n";
        cout << setw(5) << "No" << setw(40) << "Title" << setw(25) << "Artist"
                << setw(20) << "Album" << setw(20) << "Duration" << setw(10) << "Year\n";

        int count = pageNum * MAX_LINES + 1;
        for (auto it = songs.begin(); it != songs.end(); ++it) {
            cout << setw(5) << count << setw(40) << truncate((*it).getTitle(), 40)
                    << setw(25) << truncate((*it).getArtist(), 25) << setw(20)
                    << truncate((*it).getAlbum(), 25) << setw(20) << truncate((*it).getDuration(), 20) << setw(10) << (*it).getYear()<< "\n";
            count++;
        }
        this->display_bottom();
    }

    string truncate(const string& text, int width) {
        if ((int)text.length() <= width) {
            return text;
        } else {
            return text.substr(0, width - 3) + "...";
        }
    }
};
