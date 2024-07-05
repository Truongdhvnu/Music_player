#pragma once
#include <iostream>
#include <locale>
#include "display.h"
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <codecvt>
#include "Song.h"

using namespace std;

class View {
public:

/// @brief calculate the width of the given string when converted to UTF-16
/// @param str The input string
/// @return The width of the string in UTF-16 units
    static int displayWidth(const std::string& str);

/// @brief Aligns the given string to the left with a specified gap character and width
/// @param str The input string
/// @param gap The character to fill the gap
/// @param width The width to align the string
/// @return The aligned string
    static std::string alignLeft(const std::string& str, const char& gap, int width);

/// @brief Aligns the given string to the right with a specified gap character and width
/// @param str The input string
/// @param gap The character to fill the gap
/// @param width The width to align the string
/// @return The aligned string
    static std::string alignRight(const std::string& str, const char& gap, int width);

/// @brief Aligns the given string in the middle with a specified gap character and width
/// @param str The input string
/// @param gap The character to fill the gap
/// @param width The width to align the string
/// @return The aligned string    
    static std::string alignMiddle(const std::string& str, const char& gap, int width);

/// @brief Aligns the length of the view to a specified length    
    static void alignLength();

/// @brief Truncates the given string to fit within the specified width, adding "..." if truncated
/// @param str The input string
/// @param width The maximum width of the output string
/// @return The truncated string    
    static std::string truncate(const string& text, int width);

/// @brief Displays the list of songs currently playing
/// @param songs The list of songs
/// @param curPos The current position in the list    
    static void displayPlayingInfor(vector<Song> songs, int curPos);

/// @brief Displays a paginated list of songs
/// @param songs The list of songs
/// @param pageNum The current page number
/// @param size The total number of songs
    static void displaySongs(vector<Song> songs, int pageNum, int size, int line = 0, int highlight = 0);

/// @brief Displays the bottom menu with navigation option
    virtual void displayBottom();

/// @brief Displays the information of the given song
/// @param s The song to display information of
    virtual void display(Song s);

    static void highlightLine(string str);
    static void highlightObj(string str);
};
