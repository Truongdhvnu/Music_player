// #ifndef MUSICPLAYER_H
// #define MUSICPLAYER_H

// #include <SDL2/SDL.h>
// #include <SDL2/SDL_mixer.h>
// #include <string>
// #include <vector>
// #include <thread>
// #include <atomic>
// #include <chrono>
// #include <taglib/fileref.h>
// #include <taglib/tag.h>

// class MusicPlayer {
// public:
//     MusicPlayer();
//     ~MusicPlayer();

//     void play(const std::string& filePath);
//     void pause();
//     void resume();
//     void stop();
//     void next();
//     void previous();
//     void setVolume(int volume);
//     bool isPlaying() const;
    
//     void setPlaylist(const std::vector<std::string>& playlist);
//     void addToPlaylist(const std::string& filePath);
//     void clearPlaylist();
//     void setCurrentIndex(const int& index);
//     int getCurrentIndex();

//     std::string getCurrentTime();
//     std::string getDuration();

// private:
//     void musicThreadFunc();
//     void playCurrentSong();
//     int getFileDuration(const std::string& filePath);

//     std::string currentFile;
//     Mix_Music* music;
//     std::thread musicThread;
//     std::atomic<bool> playing;
//     std::atomic<bool> paused;
//     std::atomic<int> volume;

//     std::vector<std::string> playlist;
//     int currentIndex;

//     int musicDuration;
//     std::chrono::time_point<std::chrono::steady_clock> startTime;
//     std::chrono::time_point<std::chrono::steady_clock> pauseTime;
// };

// #endif // MUSICPLAYER_H

#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <string>
#include <vector>
#include <thread>
#include <atomic>
#include <chrono>
#include <taglib/fileref.h>
#include <taglib/tag.h>
#include "Song.h"

class MusicPlayer {
public:
    MusicPlayer();
    ~MusicPlayer();

    void play(const Song& song);
    void pause();
    void resume();
    void stop();
    void next();
    void previous();
    void setVolume(int volume);
    bool isPlaying() const;
    
    void setPlaylist(const std::vector<Song>& playlist);
    void addToPlaylist(const Song& song);
    void clearPlaylist();
    void setCurrentIndex(const int& index);
    int getCurrentIndex();

    std::string getCurrentTime();
    std::string getDuration();

private:
    void musicThreadFunc();
    void playCurrentSong();
    int getFileDuration(const std::string& filePath);

    std::string currentFile;
    Mix_Music* music;
    std::thread musicThread;
    std::atomic<bool> playing;
    std::atomic<bool> paused;
    std::atomic<int> volume;

    std::vector<Song>& playlist;
    int currentIndex;

    int musicDuration;
    std::chrono::time_point<std::chrono::steady_clock> startTime;
    std::chrono::time_point<std::chrono::steady_clock> pauseTime;
};

#endif // MUSICPLAYER_H

