#include "Handler.h"
#include "PlaylistView.h"
#include "Model.h"
#include <string>
#include "display.h"

int songListhandle(string command, int& currentPage) {
    Model &model = Model::getInstance();
    if (command == PREVIOUS_PAGE) {
        vector<Song> songs = model.media_manager.getPageOfSong(currentPage - 1);
        currentPage--;
        View::displaySongs(songs, currentPage);
    } else if (command == NEXT_PAGE) {
        vector<Song> songs = model.media_manager.getPageOfSong(currentPage + 1);
        currentPage++;
        View::displaySongs(songs, currentPage);
    } else if (command == SORT_BY_ARTIST) {
        model.media_manager.sortCurrentList(SORT_ARTIST);
        vector<Song> songs = model.media_manager.getPageOfSong(currentPage);
        View::displaySongs(songs, currentPage);
    } else if (command == SORT_BY_NAME) {
        static bool az = true;
        if (az) {
            model.media_manager.sortCurrentList(SORT_AZ);
            az = false;
        } else {
            model.media_manager.sortCurrentList(SORT_ZA);
            az = true;
        }
        vector<Song> songs = model.media_manager.getPageOfSong(currentPage);
        View::displaySongs(songs, currentPage);
    } else {
        return 0;
    }
    return 1;
}
