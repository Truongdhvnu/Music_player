// #pragma once
#include "Song.h"
#include "MediaList.h"
#include <vector>
#include <string>
#include "configs.h"
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

class Library : public MediaList{
private:    
    vector<string> dirPaths;
    bool needToChange = false;

    void getMediaFileFromDir(const string& dir) {
        if (!(fs::exists(dir) && fs::is_directory(dir))) {
            throw runtime_error("Can't access media directory: " + dir);
        }
        for (const auto& entry : fs::recursive_directory_iterator(dir)) {
            if (entry.is_regular_file()) {
                auto path = entry.path();
                if (path.extension() == ".mp3" || path.extension() == ".mp4") {
                    songList.push_back(Song(path.string(), true));
                }
            }
        }
    }

public:
    Library() {
        ifstream file(RECENT_PLAYING_DIRS_FILEDATA);
        if (!file.is_open()) {
            cout << "Error while trying to open app data file: " << RECENT_PLAYING_DIRS_FILEDATA;
        } else {
            string dir_path;
            while (getline(file, dir_path)) {
                this->dirPaths.push_back(dir_path);
            }
            file.close();
        }
    }

    void getSongFromCurrentDirs() {
        songList.clear();
        string message = "";
        for (string s: this->dirPaths) {
            try {
                this->getMediaFileFromDir(s);
            } catch (exception& e){
                message += e.what();
                this->needToChange = true;
            }
        }
        if (message != "") {
            throw runtime_error(message);
        }
    }

    void getSongFromPath(string path) {
        songList.clear();
        this->getMediaFileFromDir(path);
    }

    void addPathToCurrentDirs(string path) {
        bool isExist = false;
        for (string s: this->dirPaths) {
            if (path == s) {
                isExist = true;
                break;
            }
        }
        if (!isExist) {
            ofstream myfile(RECENT_PLAYING_DIRS_FILEDATA, std::ios_base::app);
            if (myfile.is_open()) {
                myfile << path + "\n";
                myfile.close();
                this->dirPaths.push_back(path);
            } else {
                cout << "Error while trying to write to app data file: " << RECENT_PLAYING_DIRS_FILEDATA;
            }
        }
    }
};

// int main() {
//     Library l;
//     try {
//         l.getSongFromCurrentDirs();
//     } catch (exception& e) {
//         cout << e.what() << endl;
//     }

//     vector<Song>& songs = l.getSongList();
//     for(Song s: songs) {
//         cout << s.getTitle() << endl;
//     }

//     Song news = l.getSong(2);
//     l.addPathToCurrentDirs("/home/dhtruong/Documents/MediaBrowser/data2");

//     try {
//         l.getSongFromCurrentDirs();
//     } catch (exception& e) {
//         cout << e.what() << endl;
//     }

//     l.getSongFromPath("/home/dhtruong/Documents/MediaBrowser/data");
//     cout << news.getPath() << endl;
//     cout << l.getNumberOfSong() << endl;

//     l.sort(SORT_ZA);
//     songs = l.getSongList();
//     for(Song s: songs) {
//         cout << s.getTitle() << endl;
//     }

//     cout << l.getPageOfSong(0).size();
//     return 0;
// }


//     void getMediaFileFromDir(const string& dir) {
//         if (!(fs::exists(dir) && fs::is_directory(dir))) {
//             throw runtime_error("Songs directory path does not exist: " + dir);
//         }
//         for (const auto& entry : fs::recursive_directory_iterator(dir)) {
//             if (entry.is_regular_file()) {
//                 auto path = entry.path();
//                 if (path.extension() == ".mp3" || path.extension() == ".mp4") {
//                     songList.push_back(Song(path.string(), true));
//                 }
//             }
//         }
//     }


// private:
//     Playlist& initialAsDefaultPlist() {
//         ifstream file(RECENT_PLAYING_DIRS_FILEDATA);
//         if (!file.is_open()) {
//             cout << "Error while trying to open app data file: " << RECENT_PLAYING_DIRS_FILEDATA;
//         } else {
//             string dir_path;
//             while (getline(file, dir_path)) {
//                 try {
//                     this->getMediaFileFromDir(dir_path);
//                 } catch (exception& e) {
//                     this->changed = true;
//                     cout << e.what() << '\n';
//                 }
//             }
//             file.close();
//         }
//         return *this;
//     }