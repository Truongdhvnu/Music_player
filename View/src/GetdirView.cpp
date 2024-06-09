#include "GetdirView.h"

using namespace std;
void GetdirView::display() {
    system("clear");
    cout << View::alignMiddle(" SELECT DIRECTORY ", '=', WIDTH) << endl;
    cout << endl;
    cout << "Welcome. Select your option" << endl;
    cout << "1. USB path: " << usbPath << endl;
    cout << "2. Choose another path" << endl;
    cout << "3. Current path: " << path << endl;
    View::alignLength();
    View::displayBottom();
}

void GetdirView::displaypath(string directory){
    cout <<"Directory: " <<directory<<endl;  
};