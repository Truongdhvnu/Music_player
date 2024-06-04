#include "Controller.h"
#include "MediaManager.h"
using namespace std;
/*
    Test MVC
*/
// int main() {
//     Controller c;
//     c.run();
//     return 0;
// }

/*
    Test media manager
*/
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
