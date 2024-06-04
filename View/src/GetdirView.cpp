#include "GetdirView.h"

using namespace std;
void GetdirView::display() {
    system("clear");
    cout << "============================SELECT DIRECRTORY=========================\n\n";
    cout << "Welcome. Select your direction path\n";
    cout << "1. Select USB direction path\n";
    cout << "2. Choose another path\n";
    View::display_bottom();
}

void GetdirView::displaypath(string directory){
    cout <<"Directory: " <<directory<<endl;  
};