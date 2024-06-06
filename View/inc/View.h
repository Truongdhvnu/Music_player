#pragma once
#include <iostream>
#include <unicode/unistr.h>
#include <unicode/ustream.h>
#include <unicode/brkiter.h>
#include <locale>
#include <boost/locale.hpp>
#include "display.h"
#include <sstream>
#include <vector>
#include <string>
#include <filesystem>
#include <iomanip>
#include <codecvt>

using namespace std;

class View {
public:
    int displayWidth(const std::string& str);
    std::string alignLeft(const std::string& str, const char& gap, int width);
    std::string alignRight(const std::string& str, const char& gap, int width);
    std::string alignMiddle(const std::string& str, const char& gap, int width);
    string truncate(const string& text, int width);

    virtual void display_bottom();
        // cout << "--------------------------------------------------------------------------------------\n";
        // cout << "- Home: ["<< HOME << "]\t\t Go back: [" << GO_BACK << "]\t\t Forward: [" << FORWARD << "]\t\t Exit: [" << EXIT << "]   -\n";
        // cout << "--------------------------------------------------------------------------------------\n";
};
