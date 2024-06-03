#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <taglib/fileref.h>
#include <taglib/tag.h>

using namespace std;
namespace fs = std::filesystem;

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
    Song(string path, bool getMetadata=false) : path(path) {
        if (getMetadata) {
            this->getAllMetadata();
        }
    }

    void getAllMetadata() {
        if (!fs::exists(this->path)) {
            throw runtime_error("Song's path does not exist: " + this->path);
        } else {
            TagLib::FileRef ref(this->path.c_str());
            if (!ref.isNull() && ref.tag()) {
                TagLib::Tag *tag = ref.tag();
                string title = string(tag->title().toCString(true));
                if (title == "") {
                    fs::path p(this->path);
                    this->title = p.stem().string();
                } else {
                    this->title = title;
                }
                this->artist = string(tag->artist().toCString(true));
                this->album = string(tag->album().toCString(true));
                this->year = tag->year();
            }
        }
    };

    void setTitle(const string& newdata);
    void setArtist(const string& newdata);
    void setAlbum(const string& newdata);
    void setYear(const string& newdata);
    void setDuration(const string& newdata);
    int setMetadata(const Song& other);
    
    string getPath() const {
        return path;
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