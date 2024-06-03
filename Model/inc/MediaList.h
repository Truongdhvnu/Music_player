#pragma once
#include "Song.h"
#include <vector>
#include "configs.h"
#include "display.h"

class MediaList {
protected:
    vector<Song> songList;

private:
    static bool sortByNameAZ(const Song &a, const Song &b) {
        return a.getTitle()[0] < b.getTitle()[0];
    }

    static bool sortByNameZA(const Song &a, const Song &b) {
        return !MediaList::sortByNameAZ(a, b);
    }

    static bool sortByArtist(const Song &a, const Song &b) {
        if (a.getArtist() == b.getArtist()) {
            return MediaList::sortByNameAZ(a, b);
        } else {
            return a.getArtist() < b.getArtist();
        }
    }

public:
    Song& getSong(int index) {
        if ((songList.size() > index) && (index >= 0)) {
            return songList[index];
        } else {
            throw out_of_range("getSong: song index is out of range\n");
        }
    };
    
    vector<Song>& getSongList() {
        return this->songList;        
    }

    int getNumberOfSong() {
        return this->songList.size();
    }
    
    vector<Song>& sort(int option) {
        switch (option) {
            case SORT_AZ:
                std::sort(songList.begin(), songList.end(), MediaList::sortByNameAZ);
                break;
            case SORT_ZA:
                std::sort(songList.begin(), songList.end(), MediaList::sortByNameZA);
                break;
            case SORT_ARTIST:
                std::sort(songList.begin(), songList.end(), MediaList::sortByArtist);
                break;
            default:
                break;
        }
        return songList;
    }

    vector<Song> getPageOfSong(int pageNum) {
        if (pageNum < 0) {
            throw out_of_range("No data for page no." + to_string(pageNum));
        }

        int numberOfSong = this->getNumberOfSong() - MAX_NUM_OF_LINES*(pageNum);
        numberOfSong = numberOfSong < MAX_NUM_OF_LINES ? numberOfSong : MAX_NUM_OF_LINES; 
        vector<Song> result;
        for(int i = pageNum * MAX_NUM_OF_LINES; i < numberOfSong; i++) {
            result.push_back(songList[i]);
        }
        return result;
    };
};