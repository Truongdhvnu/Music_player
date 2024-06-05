#include "GetdirView.h"

using namespace std;
void GetdirView::display() {
    system("clear");
    int linesPrinted = 0;
    cout << View::alignMiddle("SELECT DIRECRTORY", '=', WIDTH) << endl;
    cout << endl;
    linesPrinted++;
    cout << "Welcome. Select your option" << endl;
    linesPrinted++;
    cout << "1. Select USB direction path" << endl;
    linesPrinted++;
    cout << "2. Choose another path" << endl;
    linesPrinted++;
    cout << "3. Current path: " << path << endl;

    while (linesPrinted < LENGTH - 1) {
        cout << endl;
        linesPrinted++;
    }
    View::display_bottom();
}

void GetdirView::displaypath(string directory){
    cout <<"Directory: " <<directory<<endl;  
};