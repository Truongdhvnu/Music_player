#include "MusicPlayer.h"
#include <iostream>

MusicPlayer::MusicPlayer() : music(nullptr), playing(false), paused(false), volume(50), currentIndex(-1), stopProgress(false) {
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

void MusicPlayer::setSongEndCallback(std::function<void()> callback) {
    songEndCallback = callback;
}

void MusicPlayer::hiddenProgressBar() { 
    stopProgress = true;
}

void MusicPlayer::unhideProgressBar() {
    if(playing) {
        stopProgress = false;
        progressThread = std::thread(&MusicPlayer::displayProgress, this); // Bắt đầu thread cho displayProgress
        progressThread.detach(); 
    } 
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
    musicDuration = getFileDuration(filePath);
    paused = false;
    startTime = std::chrono::steady_clock::now();
    musicThread = std::thread(&MusicPlayer::musicThreadFunc, this);
    musicThread.detach();

    stopProgress = false; // Đặt lại biến dừng progress
    progressThread = std::thread(&MusicPlayer::displayProgress, this); // Bắt đầu thread cho displayProgress
    progressThread.detach();
}

void MusicPlayer::pause() {
    if (playing && !paused) {
        Mix_PauseMusic();
        paused = true;
        pauseTime = std::chrono::steady_clock::now();
        stopProgress = true;
    }
}

void MusicPlayer::resume() {
    if (playing && paused) {
        Mix_ResumeMusic();
        paused = false;
        auto pausedDuration = std::chrono::steady_clock::now() - pauseTime;
        startTime += pausedDuration;  // Adjust start time to account for pause
        stopProgress = false;
        progressThread = std::thread(&MusicPlayer::displayProgress, this); 
        progressThread.detach();
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
        stopProgress = true;
    }
}

void MusicPlayer::next() {
    if ((long unsigned int)(currentIndex + 1) < playlist->size()) currentIndex++;
    else currentIndex = 0;
    playCurrentSong();
}

void MusicPlayer::previous() {
    if (currentIndex > 0) currentIndex--;
    else currentIndex = (int)playlist->size();
    playCurrentSong();
}

void MusicPlayer::setVolume(int volume) {
    this->volume = volume;
    Mix_VolumeMusic(volume);
}

void MusicPlayer::volumeUp() {
    if(this->volume <= 90) this->volume += 10;
    else this->volume = 100;
    Mix_VolumeMusic(this->volume);
}

void MusicPlayer::volumeDown() {
    if(this->volume >= 10) this->volume -= 10;
    else this->volume = 0;
    Mix_VolumeMusic(this->volume);
}

bool MusicPlayer::isPlaying() const {
    return playing;
}

void MusicPlayer::setPlaylist(std::vector<Song>* playlist) {
    this->playlist = playlist;
    currentIndex = -1;
}

void MusicPlayer::addToPlaylist(const Song& song) {
    playlist->push_back(song);
    if (currentIndex == -1) {
        currentIndex = 0;
        playCurrentSong();
    }
}

void MusicPlayer::clearPlaylist() {
    playlist->clear();
    currentIndex = -1;
}

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
        if (songEndCallback) {
            songEndCallback(); // Gọi callback khi bài hát kết thúc
        }
    }
}
void MusicPlayer::playCurrentSong() {
    if (currentIndex >= 0 && (long unsigned int) currentIndex < playlist->size()) {
        play((*playlist)[currentIndex]);
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
    int second = getElapsedTime();
    if (playing) {
        minute = second/60;
        second = second%60;
        std::string currentTime = (minute < 10 ? "0" : "") + std::to_string(minute) + ":" +
                                  (second < 10 ? "0" : "") + std::to_string(second);
        return currentTime;
    }
    return "00:00";
}

std::string MusicPlayer::getDuration() {
    int minute = musicDuration/60;
    int second = musicDuration%60;
    std::string duration = (minute < 10 ? "0" : "") + std::to_string(minute) + ":" +
                           (second < 10 ? "0" : "") + std::to_string(second);
    return duration;
}

int MusicPlayer::getFileDuration(const std::string& filePath) {
    TagLib::FileRef file(filePath.c_str());
    if (!file.isNull() && file.tag()) {
        return file.audioProperties()->length();
    }
    return 0;
}

int MusicPlayer::getElapsedTime() {
    if (playing) {
        if (paused) {
            return std::chrono::duration_cast<std::chrono::seconds>(pauseTime - startTime).count();
        } else {
            return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - startTime).count();
        }
    } else return 0;    
}

// void MusicPlayer::shuffle() {
//     // Khởi tạo công cụ sinh số ngẫu nhiên
//     std::random_device rd;
//     std::mt19937 g(rd());

//     // Sử dụng std::shuffle để trộn các phần tử trong vector
//     std::shuffle(playlist->begin(), playlist->end(), g);
// }

void MusicPlayer::displayProgress() {
    while (!stopProgress) {
        std::string currentTime = getCurrentTime();
        std::string totalTime = getDuration();

        int totalDuration = musicDuration;
        int elapsedSeconds = getElapsedTime();
        int progressLength = 70;
        int pos = static_cast<int>((static_cast<double>(elapsedSeconds) / totalDuration) * progressLength);
        std::string progressBar = std::string(pos, '#') + std::string(progressLength - pos, '.');
        {
            std::lock_guard<std::mutex> lock(mtx);
            std::cout << "\r" << currentTime << " [" << progressBar << "] " << totalTime 
                      << "     Volume: " << volume << "%" << std::flush;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    stopProgress = true;
    // std::cout << std::endl;
}