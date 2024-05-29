#pragma once
#include <iostream>

using namespace std;

class View {
public:
    virtual void display() = 0;
    void display_bottom() {
        cout << "Home: h\t\t Back: b\t\t Next: >\t\t Previous: < \n";
    }
};
