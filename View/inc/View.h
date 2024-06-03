#pragma once
#include <iostream>
#include "display.h"

using namespace std;

class View {
public:
    virtual void display() = 0;
    virtual void display_bottom() {
        cout << "--------------------------------------------------------------------------------------\n";
        cout << "- Home: "<< HOME << "\t\t Go back: " << GO_BACK << "\t\t Forward: " << FORWARD << "\t\t Exit: " << EXIT << "     -\n";
        cout << "--------------------------------------------------------------------------------------\n";
    }
};
