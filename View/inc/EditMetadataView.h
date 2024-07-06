#pragma once
#include "View.h"
#include <iostream>
#include <vector>
#include "Song.h"

using namespace std;

class EditMetadataView  : public View {
public:
    void display(Song s);
    void displayBottom();
    int line = 0;
};
