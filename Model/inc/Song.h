#include <iostream>
#include <string>

using namespace std;

class Song {
private:
    string path;
    string title;
    string artist;
    string album;
    string year;
    string duration;
public:
    /*
        Just initialize path of the song, but metadata 
    */
    Song(string path) : path(path) {}
    void getAllMetadata();

    void setTitle(const string& newdata);
    void setArtist(const string& newdata);
    void setAlbum(const string& newdata);
    void setYear(const string& newdata);
    void setDuration(const string& newdata);
    int setMetadata(const Song& other);
    
    string getPath() const {
        return title;
    }

    string getTitle() const {
        return title;
    }

    string getArtist() const {
        return artist;
    }

    string getAlbum() const {
        return album;
    }

    string getYear() const {
        return year;
    }

    string getDuration() const {
        return duration;
    }
};