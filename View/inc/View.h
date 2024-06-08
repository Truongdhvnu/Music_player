#pragma once
#include <iostream>
// #include <unicode/unistr.h>
// #include <unicode/ustream.h>
// #include <unicode/brkiter.h>
#include <locale>
// #include <boost/locale.hpp>
#include "display.h"
#include <sstream>
#include <vector>
#include <string>
// #include <filesystem>
#include <iomanip>
#include <codecvt>
#include <vector>
#include "Song.h"

using namespace std;

class View {
public:
    static int displayWidth(const std::string& str);
    static std::string alignLeft(const std::string& str, const char& gap, int width);
    static std::string alignRight(const std::string& str, const char& gap, int width);
    static std::string alignMiddle(const std::string& str, const char& gap, int width);
    static void alignLength();
    static std::string truncate(const string& text, int width);
    static void displaySongs(vector<Song> songs, int pageNum, int size);
    virtual void displayBottom();
    virtual void display(Song s);
};
