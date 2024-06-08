#include "View.h"
#include <iostream>
#include "Song.h"

int View::displayWidth(const std::string& str) {
    // change UTF-8 to UTF-32 for set str_length
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
    auto utf16 = convert.from_bytes(str);
    return utf16.length();
}

std::string View::alignLeft(const std::string& str, const char& gap, int width) {
    std::locale::global(std::locale(""));
    int dataWidth = displayWidth(str);
    std::ostringstream oss;
    oss << std::left << std::setw(width + (str.length() - dataWidth)) << std::setfill(gap) << str;
    return oss.str();
}

std::string View::alignRight(const std::string& str, const char& gap, int width) {
    std::locale::global(std::locale(""));
    int dataWidth = displayWidth(str);
    std::ostringstream oss;
    oss << std::right << std::setw(width + (str.length() - dataWidth)) << std::setfill(gap) << str;
    return oss.str();
}

std::string View::alignMiddle(const std::string& str, const char& gap, int width) {
    std::locale::global(std::locale(""));
    int dataWidth = displayWidth(str);
    int leftWidth = (width - dataWidth) / 2;
    int rightWidth = width - dataWidth - leftWidth;
    std::ostringstream oss;
    oss << alignLeft("", gap, leftWidth) << "" << str << std::setw(rightWidth) << std::setfill(gap) << "";
    return oss.str();
}

void View::display_bottom() {
    string home = "-Home: [";
    home = home + HOME + "]";
    string goback = "Go back: [";
    goback = goback + GO_BACK + "]";
    string forward = "Forward: [";
    forward = forward + FORWARD + "]";
    string exit = "Exit: [";
    exit = exit + EXIT + "]-";
    cout << alignLeft("",'-', WIDTH) << endl;
    cout << alignLeft(home,' ', WIDTH/4)
         << alignLeft(goback,' ', WIDTH/4)
         << alignRight(forward,' ', WIDTH/4)
         << alignRight(exit,' ', WIDTH/4)
         << endl;
    cout << alignLeft("",'-', WIDTH) << endl;
}

void View::alignLength() {
    std::cout << "\033["<< LENGTH <<";0H";
}

string View::truncate(const std::string& str, int width) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    std::wstring wide_str = converter.from_bytes(str);

    if (wide_str.length() <= (long unsigned int)(width - 1)) {
        return converter.to_bytes(wide_str); 
    
    } else {
        wide_str = wide_str.substr(0, width - 4);
        return converter.to_bytes(wide_str) + "...";
    }
}

void View::displaySongs(vector<Song> songs, int pageNum, int size) {
    system("clear");
    cout << alignMiddle("MEDIA LIST", '=', WIDTH) << endl;
    cout << endl;
    cout << alignLeft("N0", ' ', NO_COL)
         << alignLeft("TITLE", ' ', TITLE_COL)
         << alignLeft("ARTIST", ' ', ARTIST_COL)
         << alignLeft("ALBUM", ' ', ALBUM_COL)
         << alignLeft("DURATION", ' ', DURATION_COL)
         << alignLeft("YEAR", ' ', YEAR_COL)
         << endl << endl;
    int count = pageNum * MAX_LINES + 1;
    for (auto it = songs.begin(); it != songs.end(); ++it) {
        cout << alignLeft(to_string(count), ' ', NO_COL)
             << alignLeft(truncate((*it).getTitle(), TITLE_COL), ' ', TITLE_COL) 
             << alignLeft(truncate((*it).getArtist(), ARTIST_COL), ' ', ARTIST_COL) 
             << alignLeft(truncate((*it).getAlbum(), ALBUM_COL), ' ', ALBUM_COL)
             << alignLeft(truncate((*it).getDuration(), DURATION_COL), ' ', DURATION_COL)
             << alignLeft(truncate((*it).getYear(), YEAR_COL), ' ', YEAR_COL)
             << endl;
        count++;
    }
        std::cout << "\033["<< LENGTH - 1 <<";0H";
    cout << "Page " << pageNum + 1 << " of " << (size / MAX_LINES) + 1 << endl;
}
