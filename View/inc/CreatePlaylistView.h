#pragma once
#include "View.h"
#include <iostream>
#include <vector>

using namespace std;

class CreatePlaylistView : public View {
public:
    void display(vector<string> plists);
    void displayBottom();
    int line = 0;
};