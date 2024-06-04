#pragma once
#include <iostream>
#include "View.h"

using namespace std;

class GetdirView : public View {
public:
    void display() {
        system("clear");
        cout << "============================SELECT DIRECRTORY=========================\n\n";
        cout << "Welcome. Select your direction path\n";
        cout << "1. Select USB direction path\n";
        cout << "2. Choose another path\n";
        View::display_bottom();
    }

    void displaypath(string directory){
        cout <<"Directory: " <<directory<<endl;
    }
};