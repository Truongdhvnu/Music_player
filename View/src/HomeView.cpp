#pragma once
#include "View.cpp"
#include <iostream>

using namespace std;

class HomeView : public View {
public:
    void display() {
        system("clear");
        cout << "Welcome. Select your option\n";
        cout << "1. Select dictionary\n";
        cout << "2. Show playlist\n";        
    }
};