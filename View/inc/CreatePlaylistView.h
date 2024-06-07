#pragma once
#include "View.h"
#include <iostream>
#include <vector>

using namespace std;

class CreatePlaylistView : public View {
public:
    void display(vector<string> plists);
    void display_bottom();
};