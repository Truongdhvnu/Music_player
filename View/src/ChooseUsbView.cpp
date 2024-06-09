#include "ChooseUsbView.h"

//Display multi USB chose
void ChooseUsbView::display(vector<string> usbpath) {
    int linesPrinted = 0;
    system("clear");
    cout << alignMiddle("CHOSE USB", '=', WIDTH) << endl;
    linesPrinted++;
    cout << endl;
    linesPrinted++;
    cout << alignLeft("No", ' ', NO_COL)
         << alignLeft("USB Folder", ' ', TITLE_COL)
         << endl;
    linesPrinted++;
    int index = 1;  // Biến đếm số thứ tự
    for (const string& path : usbpath) {
        // Tìm vị trí của ký tự '/' cuối cùng trong đường dẫn
        size_t pos = path.find_last_of("/\\");
        string folderName;
        
        if (pos != string::npos) {
            // Tách tên folder từ đường dẫn
            folderName = path.substr(pos + 1);
        } else {
            // Nếu không tìm thấy '/', thì toàn bộ chuỗi là tên folder
            folderName = path;
        }

        // In tên folder
        cout << alignLeft(to_string(index), ' ', NO_COL)
             << alignLeft(truncate(folderName,TITLE_COL), ' ', TITLE_COL) 
             << endl;
        linesPrinted++;
        index++;
    }
    while (linesPrinted < LENGTH - 1) {
        cout << endl;
        linesPrinted++;
    }
    this->displayBottom();     
}

void ChooseUsbView::displayBottom() {
    View::displayBottom();       
}
