#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <string>
#include <vector>
#include <thread>
#include <atomic>
#include <chrono>
#include <algorithm>
#include <random>
#include <taglib/fileref.h>
#include <taglib/tag.h>
#include "Song.h"
#include <mutex>
#include <functional>

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
    void volumeUp();
    void volumeDown();
    bool isPlaying() const;
    void shuffle();

    void setPlaylist(std::vector<Song>* playlist);
    void addToPlaylist(const Song& song);
    void clearPlaylist();
    void setCurrentIndex(const int& index);
    int getCurrentIndex();

    std::string getCurrentTime();
    std::string getDuration();

    void setSongEndCallback(std::function<void()> callback);

    void hiddenProgressBar();
    void unhideProgressBar();

private:
    void musicThreadFunc();
    void playCurrentSong();
    int getFileDuration(const std::string& filePath);
    int getElapsedTime();

    std::string currentFile;
    Mix_Music* music;
    std::thread musicThread;
    std::atomic<bool> playing;
    std::atomic<bool> paused;
    std::atomic<int> volume;

    std::vector<Song>* playlist;
    int currentIndex;

    int musicDuration;
    int elapsedTime;
    std::chrono::time_point<std::chrono::steady_clock> startTime;
    std::chrono::time_point<std::chrono::steady_clock> pauseTime;

    void displayProgress(); // Thêm khai báo hàm displayProgress
    std::thread progressThread; // Thêm biến thread cho displayProgress
    std::atomic<bool> stopProgress; // Thêm biến atomic để dừng progressThread
    std::mutex mtx; // Thêm mutex để đảm bảo an toàn trong multi-threading

    std::function<void()> songEndCallback; // Thêm callback
};

#endif // MUSICPLAYER_H
