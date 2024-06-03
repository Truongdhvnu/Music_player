// #include "controller/MusicPlayer.h"
// #include <iostream>

// MusicPlayer::MusicPlayer() : music(nullptr), playing(false), paused(false), volume(50) {
//     if (SDL_Init(SDL_INIT_AUDIO) < 0) {
//         std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
//     }
//     if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
//         std::cerr << "Failed to initialize SDL_mixer: " << Mix_GetError() << std::endl;
//     }
// }
// MusicPlayer::~MusicPlayer() {
//     stop();
//     Mix_CloseAudio();
//     SDL_Quit();
// }

// void MusicPlayer::play(const std::string& filePath) {
//     if (playing) {
//         stop();
//     }
//     currentFile = filePath;
//     music = Mix_LoadMUS(filePath.c_str());
//     if (!music) {
//         std::cerr << "Failed to load music: " << Mix_GetError() << std::endl;
//         return;
//     }
//    playing = true;
//     musicThread = std::thread(&MusicPlayer::musicThreadFunc, this);
//     musicThread.detach();
// }

// void MusicPlayer::pause() {
//     if (playing && !paused) {
//         Mix_PauseMusic();
//         paused = true;
//     }
// }

// void MusicPlayer::resume() {
//     if (playing && paused) {
//         Mix_ResumeMusic();
//         paused = false;
//     }
// }

// void MusicPlayer::stop() {
//     if (playing) {
//         playing = false;
//         Mix_HaltMusic();
//         if (music) {
//             Mix_FreeMusic(music);
//             music = nullptr;
//         }
//     }
// }

// void MusicPlayer::next() {
//     // Implement next song logic
// }

// void MusicPlayer::previous() {
//     // Implement previous song logic
// }

// void MusicPlayer::setVolume(int volume) {
//     this->volume = volume;
//     Mix_VolumeMusic(volume);
// }

// bool MusicPlayer::isPlaying() const {
//     return playing;
// }

// void MusicPlayer::musicThreadFunc() {
//     Mix_PlayMusic(music, 1);
//     while (playing && Mix_PlayingMusic()) {
//         SDL_Delay(100);
//     }
//     stop();
// }

#include "MusicPlayer.h"
#include <iostream>

MusicPlayer::MusicPlayer() : music(nullptr), playing(false), paused(false), volume(50), currentIndex(-1) {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Failed to initialize SDL_mixer: " << Mix_GetError() << std::endl;
    }
}

MusicPlayer::~MusicPlayer() {
    stop();
    Mix_CloseAudio();
    SDL_Quit();
}

void MusicPlayer::play(const Song& song) {
    if (playing) {
        stop();
    }
    currentFile = song.getPath();
    std::string filePath = song.getPath();
    music = Mix_LoadMUS(filePath.c_str());
    if (!music) {
        std::cerr << "Failed to load music: " << Mix_GetError() << std::endl;
        return;
    }
    playing = true;

    //hien thi thoi gian
    musicDuration = stoi(song.getDuration());
    paused = false;
    startTime = std::chrono::steady_clock::now();
    ////////
    musicThread = std::thread(&MusicPlayer::musicThreadFunc, this);
    musicThread.detach();
}

void MusicPlayer::pause() {
    if (playing && !paused) {
        Mix_PauseMusic();
        paused = true;
        pauseTime = std::chrono::steady_clock::now();
    }
}

void MusicPlayer::resume() {
    if (playing && paused) {
        Mix_ResumeMusic();
        paused = false;
        auto pausedDuration = std::chrono::steady_clock::now() - pauseTime;
        startTime += pausedDuration;  // Adjust start time to account for pause
    }
}

void MusicPlayer::stop() {
    if (playing) {
        playing = false;
        Mix_HaltMusic();
        if (music) {
            Mix_FreeMusic(music);
            music = nullptr;
        }
    }
}

void MusicPlayer::next() {
    if ((long unsigned int)(currentIndex + 1) < playlist.size()) currentIndex++;
    else currentIndex = 0;
    playCurrentSong();
}

void MusicPlayer::previous() {
    if (currentIndex > 0) currentIndex--;
    else currentIndex = (int)playlist.size();
    playCurrentSong();
}

void MusicPlayer::setVolume(int volume) {
    this->volume = volume;
    Mix_VolumeMusic(volume);
}

bool MusicPlayer::isPlaying() const {
    return playing;
}

void MusicPlayer::setPlaylist(const std::vector<Song>& playlist) {
    this->playlist = playlist;
    currentIndex = -1;
}

void MusicPlayer::addToPlaylist(const Song& song) {
    playlist.push_back(song);
    if (currentIndex == -1) {
        currentIndex = 0;
        playCurrentSong();
    }
}

void MusicPlayer::clearPlaylist() {
    playlist.clear();
    currentIndex = -1;
}

// void MusicPlayer::musicThreadFunc() {
//     Mix_PlayMusic(music, 1);
//     while (playing && Mix_PlayingMusic()) {
//         SDL_Delay(100);
//     }
//     stop();
// }

void MusicPlayer::musicThreadFunc() {
    if (Mix_PlayMusic(music, 1) == -1) {
        std::cerr << "Failed to play music: " << Mix_GetError() << std::endl;
        playing = false; // Ensure playing is set to false if music playing fails
    }
    while (playing && Mix_PlayingMusic()) {
        SDL_Delay(100);
    }
    if (playing) { // If playing was not stopped manually
        next(); // Automatically play next song
    }
}
void MusicPlayer::playCurrentSong() {
    if (currentIndex >= 0 && (long unsigned int) currentIndex < playlist.size()) {
        play(playlist[currentIndex]);
    }
}

void MusicPlayer::setCurrentIndex(const int& index){
    this->currentIndex = index;
}

int MusicPlayer::getCurrentIndex(){
    return this->currentIndex;
}

std::string MusicPlayer::getCurrentTime() {
    int minute;
    int second;
    std::string currentTime;
    if (playing) {
        if (paused) {
            // return std::chrono::duration_cast<std::chrono::milliseconds>(pauseTime - startTime).count();
            minute = std::chrono::duration_cast<std::chrono::milliseconds>(pauseTime - startTime).count() / 60000;
            second = std::chrono::duration_cast<std::chrono::milliseconds>(pauseTime - startTime).count() /1000 % 60;
            // currentTime = std::to_string(minute) + ":" + std::to_string(second);
        } else {
            // return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - startTime).count();
            minute = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - startTime).count() / 60000;
            second = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - startTime).count() /1000 % 60;
            // currentTime = std::to_string(minute) + ":" + std::to_string(second);
        }
        currentTime = std::to_string(minute) + ":" + std::to_string(second);
        return currentTime;
    }
    return "00:00";
}

std::string MusicPlayer::getDuration() {
    int minute = musicDuration/60;
    int second = musicDuration%60;
    std::string duration = std::to_string(minute) + ":" + std::to_string(second);
    return duration;
}

int MusicPlayer::getFileDuration(const std::string& filePath) {
    TagLib::FileRef file(filePath.c_str());
    if (!file.isNull() && file.tag()) {
        return file.audioProperties()->length();
    }
    return 0;
}
