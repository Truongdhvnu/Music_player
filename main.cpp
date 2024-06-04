#include "Controller.h"
#include "MediaManager.h"
#include "MusicPlayer.h"
using namespace std;
/*
    Test MVC
*/
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
    
    // m.setActiveLibrary();
    // Library* now = m.getActiveLibrary();
    // (*now).getSongFromPath("music");
    // m.sortCurrentList(SORT_ZA);
    // songs = m.getPageOfSong(0);
    // for(Song s: songs) {
    //     cout << s.getTitle() << endl;
    // }
    // Song abc("/home/cuongnk168/test_media/audio/Hoa-Trinh-Nu-Viet-Tu.mp3");
    // Song wer("/home/cuongnk168/test_media/audio/Anh-Cu-Di-Di-Hari-Won.mp3");
    Playlist p("BlackPink");
    p.addSong("/home/cuongnk168/test_media/audio/Hoa-Trinh-Nu-Viet-Tu.mp3");
    p.addSong("/home/cuongnk168/test_media/audio/Anh-Cu-Di-Di-Hari-Won.mp3");
    p.addSong("/home/cuongnk168/test_media/audio/Di-De-Tro-Ve-Soobin-Hoang-Son.mp3");
    MusicPlayer xyz;
    xyz.setPlaylist(&(p.getSongList()));
    int index = 1;
    xyz.setCurrentIndex(index);
    xyz.play(p.getSongList()[index]);
    int x;
    while(1){
    std::cin >> x;
    if (x == 1) xyz.pause();
    if (x == 2) xyz.resume();
    if (x == 3) xyz.next();
    if (x == 4) xyz.previous();
    if (x == 5) p.addSong("/home/cuongnk168/test_media/audio/Ngay-Chua-Giong-Bao-Bui-Lan-Huong.mp3");
    if (x == 0) break;
    }
int main() {
    Song test("/home/phuongvn/Desktop/Grenade - Bruno Mars.mp3", true);

    cout << "Testing: " << endl;
    cout << "Path: " << test.getPath() << endl;
    cout << "Title: " << test.getTitle() << endl;
    cout << "Artist: " << test.getArtist() << endl;
    cout << "Album: " << test.getAlbum() << endl;
    cout << "Year: " << test.getYear() << endl;
    cout << "Duration: " << test.getDuration() << endl;

    string temp;
    cout << "Title: ";
    cin >> temp;
    cout << endl;
    test.setTitle(temp);
    cout << "Artist: ";
    cin >> temp;
    cout << endl;
    test.setArtist(temp);
    cout << "Album: ";
    cin >> temp;
    cout << endl;
    test.setAlbum(temp);
    int temp1;
    cout << "Year: ";
    cin >> temp1;
    cout << endl;
    test.setYear(temp1);

    cout << "After edit: " << endl;
    cout << "Title: " << test.getTitle() << endl;
    cout << "Artist: " << test.getArtist() << endl;
    cout << "Album: " << test.getAlbum() << endl;
    cout << "Year: " << test.getYear() << endl;
    cout << "Duration: " << test.getDuration() << endl;

    return 0;
}
