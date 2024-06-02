#include <filesystem>
#include <vector>
#include "Playlist.h"
#include "configs.h"
#include "display.h"
#include "Library.h"

using namespace std;
namespace fs = std::filesystem;

class MediaManager {
private:
    Library lib;
    vector<Playlist> playlists;
    vector<string> listDeleted; 
public:
    /*
        Initialize (just name) for playlists whose names are names of .txt files in "./data/playlists" directory
    */
    MediaManager() {
        for (const auto& entry : fs::directory_iterator(PLAYLIST_FILES_DIR)) {
            if (entry.is_regular_file()) {
                auto path = entry.path();
                if (path.extension() == ".txt") {
                    playlists.push_back(Playlist(path.stem().string()));
                }
            }
        }
    };

    Playlist& getPlaylistNum(int index) {
        if ((0 <= index) && (index < playlists.size())) {
            return playlists[index].initialize();
        } else {
            throw out_of_range("getPlaylist: Playlist index is out of bound\n");
        }
    };

    vector<string> getPlaylistNames() {
        vector<string> result;
        for(auto p = playlists.begin(); p != playlists.end(); ++p) {
            result.push_back((*p).getName());
        }
        return result;
    };

    vector<Song> getPlaylistSongs(int PlaylistNum, int pageNum) {
        if (pageNum < 0 || PlaylistNum < 0 || PlaylistNum >= this->playlists.size()) {
            throw out_of_range("No data for Playlist no." + to_string(PlaylistNum) + "/page " + to_string(pageNum));
        }

        Playlist& pl = this->getPlaylistNum(PlaylistNum);
        if (pageNum * MAX_NUM_OF_LINES >= pl.getNumberOfSong()) {
            throw out_of_range("No more data\n");
        }
        
        int numberOfSong = pl.getNumberOfSong() - MAX_NUM_OF_LINES*(pageNum);
        numberOfSong = numberOfSong < MAX_NUM_OF_LINES ? numberOfSong : MAX_NUM_OF_LINES; 
        vector<Song> result;
        for(int i = pageNum * MAX_NUM_OF_LINES; i < numberOfSong; i++) {
            result.push_back(pl.getSong(i));
        }
        return result;
    };

private:
    static bool sortByNameAZ(const Song &a, const Song &b) {
        return a.getTitle()[0] < b.getTitle()[0];
    }

    static bool sortByNameZA(const Song &a, const Song &b) {
        return !MediaManager::sortByNameAZ(a, b);
    }

    static bool sortByArtist(const Song &a, const Song &b) {
        if (a.getArtist() == b.getArtist()) {
            return MediaManager::sortByNameAZ(a, b);
        } else {
            return a.getArtist() < b.getArtist();
        }
    }
public:
    vector<Song>& sort(int PlaylistNum, int option) {
        vector<Song>& songlist = playlists[PlaylistNum].initialize().getSongList();
        if (PlaylistNum < 0 || PlaylistNum >= this->playlists.size()) {
            throw out_of_range("Playlist rename: Index of playlist out of bound " + to_string(PlaylistNum) + "\n");
        } else {
            switch (option) {
                case SORT_AZ:
                    std::sort(songlist.begin(), songlist.end(), MediaManager::sortByNameAZ);
                    break;
                case SORT_ZA:
                    std::sort(songlist.begin(), songlist.end(), MediaManager::sortByNameZA);
                    break;
                case SORT_ARTIST:
                    std::sort(songlist.begin(), songlist.end(), MediaManager::sortByArtist);
                    break;
                default:
                    break;
            }
            return songlist;
        }
    }

    int isExistPlayList(string name) {
        int count = 0;
        for (auto it = playlists.begin(); it != playlists.end(); ++it) {
            if (name == (*it).getName()) {
                return count;
            } else {
                count++;
            }
        }
        return -1;
    };

    int renamePlaylist(int PlaylistNum, const string& newName) {        
        if (this->isExistPlayList(newName) >= 0) {
            throw runtime_error("rename Plist: Plist with name " + newName + "has already exíted\n");
        }

        if (PlaylistNum < 0 || PlaylistNum >= this->playlists.size()) {
            throw out_of_range("Playlist rename: Index of playlist out of bound " + to_string(PlaylistNum) + "\n");
        } else {
            return this->playlists[PlaylistNum].rename(newName);
        }
    };

    void createPlaylist(Playlist& playlist) {
        if (this->isExistPlayList(playlist.getName()) < 0) {
            playlist.newCreated = true;
            this->playlists.push_back(playlist);
        } else {
            throw runtime_error("create Plist: Playlist existed\n");
        }
    }
    
    /*
        Remeber to store name to listDeleted to update data when close program
    */
    int deletePlaylist(int pos) {
        if (pos >= 0 && pos < this->playlists.size()) {
            this->listDeleted.push_back(this->playlists[pos].getName());
            this->playlists.erase(this->playlists.begin() + pos);
            return 0;
        } else {
            throw runtime_error("delete Plist: Playlist index out of range\n");
        }
    }

    /*
        Call this funtion before exit program
    */
    void updateDatabase() {
        for (auto it = playlists.begin(); it != playlists.end(); ++it) {
            (*it).updateDataToFile();
        }
        for (auto it = listDeleted.begin(); it != listDeleted.end(); ++it) {
            fs::path plPath(PLAYLIST_FILES_DIR);
            plPath.append(*it + ".txt");
            if (std::remove(plPath.string().c_str()) != 0) {
                cout << "Error while trying to delete data file: " << plPath.string() << endl;
            }
        }
    }
};

int main() {
    cout.setf(std::ios::unitbuf);
    MediaManager m;
    vector<string> names = m.getPlaylistNames();
    for (string name: names) {
        cout << name << " ";
    }
    cout << endl;

    // m.renamePlaylist(1, "Taylor");
    names = m.getPlaylistNames();
    for (string name: names) {
        cout << name << " ";
    }
    cout << endl;

    m.getPlaylistNum(1).addSong("/home/dhtruong/Documents/MediaBrowser/data/I Knew You Were Trouble - Taylor Swift.mp3");
    m.getPlaylistNum(1).deleteSong(0);
    m.getPlaylistNum(1).addSong("/home/dhtruong/Documents/MediaBrowser/data/Rolling in the Deep - Adele.mp3");
    // m.deletePlaylist(2);

    // Playlist p("BlackPink");
    // p.addSong("/home/dhtruong/Documents/MediaBrowser/data/Teenage Dream.mp3");
    // m.createPlaylist(p);

    names = m.getPlaylistNames();
    for (string name: names) {
        cout << name << " ";
    }
    m.updateDatabase();

    m.sort(0, SORT_AZ);
    vector<Song> songs = m.getPlaylistSongs(0, 0);
    cout <<"Sort by name AZ\n";
    for (Song s: songs) {
        cout << s.getTitle() << "\n";
    }
    cout << endl;

    m.sort(0, SORT_ZA);
    songs = m.getPlaylistSongs(0, 0);
    cout <<"Sort by name ZA\n";
    for (Song s: songs) {
        cout << s.getTitle() << "\n";
    }
    cout << endl;

    m.sort(0, SORT_ARTIST);
    songs = m.getPlaylistSongs(0, 0);
    cout <<"Sort by name ARTIST\n";
    for (Song s: songs) {
        cout << s.getTitle() << "\n";
    }
    
    
    return 0;
}
