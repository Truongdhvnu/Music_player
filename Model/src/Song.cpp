#include <iostream>
#include <string>
#include <filesystem>
#include <taglib/fileref.h>
#include <taglib/tag.h>
#include "Song.h"

using namespace std;
namespace fs = std::filesystem;

Song::Song(string path, bool getMetadata) : path(path) {
    if (getMetadata) {
        this->getAllMetadata();
    }
}

void Song::getAllMetadata() {
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

void Song::setTitle(const string& newdata){};
void Song::setArtist(const string& newdata){};
void Song::setAlbum(const string& newdata){};
void Song::setYear(const string& newdata){};
void Song::setDuration(const string& newdata){};
int Song::setMetadata(const Song& other){};
    
string Song::getPath() const {
    return path;
}

string Song::getTitle() const {
    return title;
}

string Song::getArtist() const {
    return artist;
}

string Song::getAlbum() const {
    return album;
}

string Song::getYear() const {
    return year;
}

string Song::getDuration() const {
    return duration;
}
