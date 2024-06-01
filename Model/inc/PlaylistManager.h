#include "PlayList.h"
#include <vector>

using namespace std;

class PlaylistManager {
private:
    vector<Playlist> playlists;
    vector<string> deletePlaylistName; 
public:
    /*
        Initialize default Playlist that contain all songs then add it as 0th element of "playlists" vector
        Initialize (just name) for other playlists that are name of .txt file in "./data" directory
    */
    PlaylistManager();

    Playlist& getPlaylist(int index);

    vector<string> getPlaylistNames(int page_num);

    vector<Song> getPlaylistSongs(int PlaylistNum, int page_num);

    bool isExistPlayList(string name);

    int createPlaylist(string name, const Playlist& playlist);
    
    /*
        Remeber to store name to deletePlaylistName to update data when close program
    */
    int deletePlaylist(string name);

    int updateDatabase();
};
