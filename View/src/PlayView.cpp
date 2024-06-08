#include "PlayView.h"
#include <iostream>
#include <string>

using namespace std;

void PlayView::display(Song s) {
     View::display(s);
     this->displayBottom();     
}

void PlayView::displayBottom() {
     cout << alignLeft("",'-', WIDTH) << endl;
     cout << alignLeft("1. Replay", ' ', WIDTH/4) 
          << alignLeft("2. Pause", ' ', WIDTH/4) 
          << alignLeft("3. Resume", ' ', WIDTH/4)
          << alignLeft("4. Edit Metadata", ' ', WIDTH/4)
          << endl;
     cout << alignLeft("5. Next", ' ', WIDTH/4) 
          << alignLeft("6. Previous", ' ', WIDTH/4) 
          << alignLeft("7. Volume Up", ' ', WIDTH/4)
          << alignLeft("8. Volume Down", ' ', WIDTH/4)
          << endl;  
     View::displayBottom();       
}
