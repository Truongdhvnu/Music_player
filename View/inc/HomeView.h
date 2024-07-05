#pragma once
#include "View.h"
#include <iostream>
#include <vector>

using namespace std;

class HomeView : public View {
public:
    void display();
    int line = 0;
};