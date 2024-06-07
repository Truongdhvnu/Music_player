#include "Song.h"

//#include <MediaInfo/MediaInfo.h> // Thêm thư viện MediaInfo
//#include <taglib/mpegfile.h>

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
//         throw std::runtime_error("Song's path does not exist: " + this->path);
//     } else {
//         // Check file extension to determine if it's mp3 or mp4
//         std::string extension = fs::path(this->path).extension().string();
//         std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);

//         std::string audioPath;
//         bool isMp4 = false;
//         if (extension == ".mp4") {
//             // Create a temporary audio file path
//             audioPath = "temp_audio.mp3";

//             // Command to extract audio using ffmpeg
//             std::string command = "ffmpeg -i \"" + this->path + "\" -q:a 0 -map a \"" + audioPath + "\"";
//             // Execute the command
//             int result = std::system(command.c_str());
//             if (result != 0) {
//                 throw std::runtime_error("Failed to extract audio from video file.");
//             }
//             isMp4 = true;
//         } else if (extension == ".mp3") {
//             audioPath = this->path;
//         } else {
//             throw std::runtime_error("Unsupported file format: " + extension);
//         }

//         // Read metadata from the audio file
//         TagLib::FileRef ref(audioPath.c_str());
//         if (!ref.isNull() && ref.tag()) {
//             TagLib::Tag *tag = ref.tag();
//             std::string title = tag->title().toCString(true);
//             if (title.empty()) {
//                 fs::path p(this->path);
//                 this->title = p.stem().string();
//             } else {
//                 this->title = title;
//             }
//             this->artist = tag->artist().toCString(true);
//             this->album = tag->album().toCString(true);
//             this->year = std::to_string(tag->year());
//             this->duration = std::to_string(ref.audioProperties()->lengthInSeconds());
//         } else {
//             throw std::runtime_error("Failed to read metadata from audio file.");
//         }

//         // Append "MP4" to the title if the file is an MP4 and does not already contain "MP4"
//         if (isMp4) {
//             if (this->title.find("MP4") == std::string::npos) {
//                 this->title += " MP4";
//             }
//         }

//         // Clean up temporary audio file if it was created
//         if (isMp4) {
//             fs::remove(audioPath);
//         }
//     }
// }

//loi khi phat het mp4 ko next sang bai sau ma core dump luon
// void Song::getAllMetadata() {
//     if (!fs::exists(this->path)) {
//         throw runtime_error("Song's path does not exist: " + this->path);
//     }

//     fs::path filePath(this->path);

//     // Nếu là tệp .mp4, chuyển đổi sang .mp3
//     if (filePath.extension() == ".mp4") {
//         fs::path mp3Path = filePath.replace_extension(".mp3");
//         if (!fs::exists(mp3Path)) {
//             convertMP4toMP3(this->path, mp3Path.string());
//         }
//         // Cập nhật lại đường dẫn của file sau khi chuyển đổi
//         this->path = mp3Path.string();
//     }

//     // Bỏ qua nếu không phải là tệp .mp3
//     if (filePath.extension() != ".mp3") {
//         return;
//     }

//     TagLib::FileRef ref(this->path.c_str());
//     if (ref.isNull() || !ref.tag()) {
//         throw runtime_error("Failed to read metadata from: " + this->path);
//     }

//     TagLib::Tag *tag = ref.tag();
//     this->title = tag->title().isEmpty() ? filePath.stem().string() : tag->title().toCString(true);
//     this->artist = tag->artist().isEmpty() ? "Unknown" : tag->artist().toCString(true);
//     this->album = tag->album().isEmpty() ? "Unknown" : tag->album().toCString(true);
//     this->year = tag->year() == 0 ? "Unknown" : to_string(tag->year());
//     this->duration = to_string(ref.audioProperties()->lengthInSeconds());
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
