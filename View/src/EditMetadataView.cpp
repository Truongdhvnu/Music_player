#include "EditMetadataView.h"
#include <iostream>

void EditMetadataView::display(Song s) {
    View::display(s);
    View::alignLength(); 
    this->displayBottom();     
}

void EditMetadataView::displayBottom() {
    cout << alignLeft("",'-', WIDTH) << endl;
    cout << alignLeft("1. Set Title", ' ', WIDTH/4) 
         << alignLeft("2. Set Artist", ' ', WIDTH/4) 
         << alignLeft("3. Set Album", ' ', WIDTH/4)
         << alignLeft("4. Set Year", ' ', WIDTH/4)
         << endl;  
    View::displayBottom();       
}