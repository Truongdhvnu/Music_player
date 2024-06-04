#pragma once
#include <iostream>
#include "View.h"

using namespace std;

class GetdirView : public View {
public:
    void display();

    void displaypath(string directory);
};