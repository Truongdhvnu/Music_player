#include "Song.h"
#include <vector>
#include <string>

using namespace std;

class Playlist {
private:
    vector<Song> songList;
    string name;
    string numberOfSong;
    bool changed = false;  // set changed = true when data of the Playlist change by addSong, deleteSong methods
    bool fetchSong = false; 
public:
    /*
        Just only set name for playlist
    */
    Playlist(string name) : name(name) {};

    /*
        Each playlist is stored in a .txt file in .data/playlist_name with "playlist_name" is name of playlist
        Initialize songs (only path data) then add them to the songList vector
        Then this->fetchSong = true
    */
    void initialize();

    /*
        Return a song which had been initialize all metadata;
    */
    Song& getSong(int index);

    /*
        add a Song to playlist
        some case of input: 
            + absolute_path is not found
            + the song has been already in the playlist
        return 0 only if successful
    */
    int addSong(string absolute_path);

    int deleteSong(int index);

    int rename(string newName);
    
    /*
        Call this method at the end of program if data of Playlist change (changed = true)
    */
    int updateDataToFile();
};