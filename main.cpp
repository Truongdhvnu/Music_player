#include "Controller.h"
#include "MediaManager.h"
#include "MusicPlayer.h"


#include "Playlist.h"

using namespace std;
/*
    Test MVC
*/
// int main() {
//     Controller c;
//     c.run();
//     return 0;
// }
int main() {
    Controller c;
    c.run();
    return 0;
}

/*
    Test media manager
*/
// int main() {
//     cout.setf(std::ios::unitbuf);
//     MediaManager m;
//     vector<string> names = m.getPlaylistNames();
//     for (string name: names) {
//         cout << name << " ";
//     }
//     cout << endl;

//     // m.renamePlaylist(1, "Taylor");
//     names = m.getPlaylistNames();
//     for (string name: names) {
//         cout << name << " ";
//     }
//     cout << endl;
    
//     m.setActivePList(1);
//     Playlist* current = m.getActivePlaylist();
//     (*current).addSong("music/I Knew You Were Trouble - Taylor Swift.mp3");
//     // (*current).deleteSong(0);
//     (*current).addSong("music/Rolling in the Deep - Adele.mp3");
//     // m.deletePlaylist(2);

//     // Playlist p("BlackPink");
//     // p.addSong("music/Teenage Dream.mp3");
//     // m.createPlaylist(p);

//     names = m.getPlaylistNames();
//     for (string name: names) {
//         cout << name << " ";
//     }
//     cout << endl;
//     m.updateDatabase();
    
//     vector<Song> songs = m.sortCurrentList(SORT_AZ);
//     cout <<"Sort by name AZ " << songs.size() << "\n";
//     for (Song s: songs) {
//         cout << s.getTitle() << "\n";
//     }
//     cout << endl;

//     m.sortCurrentList(SORT_ZA);
//     songs = m.getCurrentSongList();
//     cout <<"Sort by name ZA " << songs.size() << "\n";
//     for (Song s: songs) {
//         cout << s.getTitle() << "\n";
//     }
//     cout << endl;

//     m.sortCurrentList(SORT_ARTIST);
//     songs = m.getCurrentSongList();
//     cout <<"Sort by name ARTIST " << songs.size() << "\n";
//     for (Song s: songs) {
//         cout << s.getTitle() << "\t\t" << s.getArtist() <<  "\n";
//     }
//     cout << endl;
    
//     m.setActiveLibrary();
//     Library* now = m.getActiveLibrary();
//     (*now).getSongFromPath("music");
//     m.sortCurrentList(SORT_ZA);
//     songs = m.getPageOfSong(0);
//     for(Song s: songs) {
//         cout << s.getTitle() << endl;
//     }
//     return 0;
// }

/*
    Test playmusic
*/
// int main() {
//     Playlist p("BlackPink");
//     p.addSong("music/Heart Attack - Demi Lovato.mp3");
//     p.addSong("music/Teenage Dream.mp3");
//     p.addSong("music/Teenage Dream.mp3");
//     MusicPlayer xyz;
//     xyz.setPlaylist(&(p.getSongList()));
//     int index = 1;
//     xyz.setCurrentIndex(index);
//     xyz.play(p.getSongList()[index]);
//     int x;
//     while(1){
//         std::cin >> x;
//         if (x == 1) xyz.pause();
//         if (x == 2) xyz.resume();
//         if (x == 3) xyz.next();
//         if (x == 4) xyz.previous();
//         if (x == 5) p.addSong("music/Whistle - Flo Rida.mp3");
//         if (x == 0) break;
//     }
//     return 0;
// }

// int main(){
//     USBMonitor usbMonitor;
//     usbMonitor.startMonitoring();
//     cout <<"Waiting USB"<<endl;
//     while(usbMonitor.USBGetStatus()==0)    //chua co USB
//     {
//         ;//WAIT
//     }
//     if(usbMonitor.USBGetStatus()==1)    //da co USB
//     {
//         usbMonitor.stopMonitoring();
//     }
//     string path=usbMonitor.getUserPathValue();
//     cout <<"Path: "<<path<<endl;

//     return 0;
// }