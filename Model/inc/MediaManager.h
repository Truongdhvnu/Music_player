#pragma once
#include <vector>
#include "Playlist.h"
#include "configs.h"
#include "display.h"
#include "Library.h"
#include "MediaList.h"

using namespace std;

class MediaManager {
private:
    Library songLib;
    vector<Playlist> playlists;
    vector<string> listDeleted;
    MediaList* currentMediaList = nullptr;
    bool playListActive = false;
    int curLibSongIndex = -1;
    int curPlistSongIndex = -1;
    int curLibPageOfSong = 0;
    int curPlistPageOfSong = 0;
    int activePlistIndex = 0;
public:
    /*
        Initialize (just name) for playlists whose names are names of .txt files in "./data/playlists" directory
    */
    MediaManager();

    bool isPlaylistActive();

    int getCurSongIndex();

    void setCurSongIndex(int data);

    int getNumberofSong();

    void setActivePList(int PlaylistNum);

    int getActivePListIndex();

    Playlist& getActivePlaylist();

    void setActiveLibrary();

    Library& getLibrary();

    vector<string> getPlaylistNames();

    Song& getSong(int index);
    
    Song& getCurSong();

    int getCurPageOfSongIndex();

    vector<Song> getCurPageOfSong();

    vector<Song> getPageOfSong(int pageNum);

    vector<Song>& sortCurList(int option);

    vector<Song>* getCurSongList();

    int isExistPlayList(string name);

    int renamePlaylist(int PlaylistNum, const string& newName);

    void createPlaylist(string name);

    /*
        Remeber to store name to listDeleted to update data when close program
    */
    int deletePlaylist(int pos);

    /*
        Call this funtion before exit program
    */
    void updateDatabase();
};
