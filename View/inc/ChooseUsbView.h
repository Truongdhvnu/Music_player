#pragma once
#include "View.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ChooseUsbView : public View {
public:
    void display(vector<string> usbpath);
    void display_bottom();
};
