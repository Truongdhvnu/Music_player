#include <iostream>
#include <string>
#include <filesystem>
#include <taglib/fileref.h>
#include <taglib/tag.h>
#include "Song.h"

//#include <MediaInfo/MediaInfo.h> // Thêm thư viện MediaInfo


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
            this->year = to_string(tag->year());
            this->duration = to_string(ref.audioProperties()->lengthInSeconds());
        }
    }
}

// void Song::getAllMetadata() {
//     if (!fs::exists(this->path)) {
//         throw runtime_error("Song's path does not exist: " + this->path);
//     } else {
//         fs::path filePath(this->path);
//         string extension = filePath.extension().string();
        
//         if (extension == ".mp3") {
//             TagLib::FileRef ref(this->path.c_str());
//             if (!ref.isNull() && ref.tag()) {
//                 TagLib::Tag *tag = ref.tag();
//                 string title = string(tag->title().toCString(true));
//                 if (title == "") {
//                     this->title = filePath.stem().string();
//                 } else {
//                     this->title = title;
//                 }
//                 this->artist = string(tag->artist().toCString(true));
//                 this->album = string(tag->album().toCString(true));
//                 this->year = to_string(tag->year());
//                 this->duration = to_string(ref.audioProperties()->lengthInSeconds());
//             }
//         } else if (extension == ".mp4") {
//             MediaInfoLib::MediaInfo MI;
//             MI.Open(this->path);

//             this->title = MI.Get(MediaInfoLib::Stream_General, 0, __T("Title")).c_str();
//             if (this->title.empty()) {
//                 this->title = filePath.stem().string();
//             }
//             this->artist = MI.Get(MediaInfoLib::Stream_General, 0, __T("Performer")).c_str();
//             this->album = MI.Get(MediaInfoLib::Stream_General, 0, __T("Album")).c_str();
//             this->year = MI.Get(MediaInfoLib::Stream_General, 0, __T("Recorded_Date")).c_str();
//             this->duration = MI.Get(MediaInfoLib::Stream_General, 0, __T("Duration")).c_str();

//             // Convert duration from milliseconds to seconds
//             if (!this->duration.empty()) {
//                 double durationInMs = std::stod(this->duration);
//                 this->duration = to_string(static_cast<int>(durationInMs / 1000));
//             }
//         } else {
//             throw runtime_error("Unsupported file format: " + extension);
//         }
//     }
// }

void Song::setTitle(const string& newdata) {
    if (!fs::exists(this->path)) {
        throw runtime_error("Song's path does not exist: " + this->path);
    } else {
        TagLib::FileRef ref(this->path.c_str());
        if (!ref.isNull() && ref.tag()) {
            TagLib::Tag *tag = ref.tag();
            tag->setTitle(newdata);
        }
        ref.save();
        this->title = newdata;
    }
}
void Song::setArtist(const string& newdata) {
    if (!fs::exists(this->path)) {
        throw runtime_error("Song's path does not exist: " + this->path);
    } else {
        TagLib::FileRef ref(this->path.c_str());
        if (!ref.isNull() && ref.tag()) {
            TagLib::Tag *tag = ref.tag();
            tag->setArtist(newdata);
        }
        ref.save();
        this->artist = newdata;
    }
}
void Song::setAlbum(const string& newdata) {
    if (!fs::exists(this->path)) {
        throw runtime_error("Song's path does not exist: " + this->path);
    } else {
        TagLib::FileRef ref(this->path.c_str());
        if (!ref.isNull() && ref.tag()) {
            TagLib::Tag *tag = ref.tag();
            tag->setAlbum(newdata);
        }
        ref.save();
        this->album = newdata;
    }
}
void Song::setYear(const unsigned int& newdata) {
    if (!fs::exists(this->path)) {
        throw runtime_error("Song's path does not exist: " + this->path);
    } else {
        TagLib::FileRef ref(this->path.c_str());
        if (!ref.isNull() && ref.tag()) {
            TagLib::Tag *tag = ref.tag();
            tag->setYear(newdata);
        }
        ref.save();
        this->year = to_string(newdata);
    }
}

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
    int totalSeconds = stoi(duration);
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;
    
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << minutes << ":"
        << std::setw(2) << std::setfill('0') << seconds;
    
    return oss.str();
}
