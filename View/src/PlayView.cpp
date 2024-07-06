#include "PlayView.h"
#include <iostream>
#include <string>

using namespace std;

void PlayView::display(Song s, vector<Song> songs, int curPos) {
     View::display(s);
     cout << "\n";
     View::displayPlayingInfor(songs, curPos);
     View::alignLength(); 
     this->displayBottom();     
}

void PlayView::displayBottom() {
     cout << alignLeft("",'-', WIDTH) << endl;
     vector<string> option = {
          "-1. Replay",
          "2. Pause",
          "3. Resume",
          "4. Edit Metadata",
          "-5. Next",
          "6. Previous",
          "7. Volume Up",
          "8. Volume Down"
     };
     
     for(unsigned int i = 0; i < option.size(); i++) {
          if((line % option.size()) == i) View::highlightObj(alignLeft(option[i], ' ', WIDTH/4));
          else cout << alignLeft(option[i], ' ', WIDTH/4);
          if(i == 3 || i == 7) {
               cout << "\b-" << endl;
          }
        // else cout << i + 1 << ". " << option[i] << endl;
     }

     // cout << alignLeft("-1. Replay", ' ', WIDTH/4) 
     //      << alignLeft("2. Pause", ' ', WIDTH/4) 
     //      << alignLeft("3. Resume", ' ', WIDTH/4)
     //      << alignLeft("4. Edit Metadata", ' ', WIDTH/4 -1)
     //      << "-" <<endl;
     // cout << alignLeft("-5. Next", ' ', WIDTH/4) 
     //      << alignLeft("6. Previous", ' ', WIDTH/4) 
     //      << alignLeft("7. Volume Up", ' ', WIDTH/4)
     //      << alignLeft("8. Volume Down", ' ', WIDTH/4 -1) 
     //      << "-" <<endl;  
     View::displayBottom();       
}
