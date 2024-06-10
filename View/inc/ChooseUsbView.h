#pragma once
#include "View.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ChooseUsbView : public View {
public:
    //Display multi USB chose
    void display(vector<string> usbpath);
};
