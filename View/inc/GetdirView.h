#pragma once
#include <iostream>
#include "View.h"

using namespace std;

class GetdirView : public View {
public:
    void display();
    string path;
    string usbPath;
    int line = 0;
};