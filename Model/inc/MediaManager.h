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
    int currentLibSongIndex = 0;
    int currentPlistSongIndex = 0;
public:
    /*
        Initialize (just name) for playlists whose names are names of .txt files in "./data/playlists" directory
    */
    MediaManager();

    bool isPlaylistActive();

    int getCurrentSongIndex();
    
    void setCurrentSongIndex(int data);

    int getNumberofSong();
    
    void setActivePList(int PlaylistNum);

    Playlist* getActivePlaylist();

    void setActiveLibrary();

    Library* getActiveLibrary();

    vector<string> getPlaylistNames();

    vector<Song> getPageOfSong(int pageNum);

    vector<Song>& sortCurrentList(int option);

    vector<Song>* getCurrentSongList();

    int isExistPlayList(string name);

    int renamePlaylist(int PlaylistNum, const string& newName);

    void createPlaylist(Playlist& playlist);
    
    /*
        Remeber to store name to listDeleted to update data when close program
    */
    int deletePlaylist(int pos);

    /*
        Call this funtion before exit program
    */
    void updateDatabase();
};