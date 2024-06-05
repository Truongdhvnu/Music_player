#ifndef DISPLAY_H
#define DISPLAY_H

#define MAX_LINES 3

/*
    Define navigator letters
*/
#define HOME "h"
#define GO_BACK "<"
#define FORWARD ">"
#define EXIT "x"

/*
    Define
*/
#define MAX_HISTORY_PAGE 10
#define NEXT_PAGE "n"
#define PREVIOUS_PAGE "p"
#define SORT_BY_NAME "s"
#define SORT_BY_ARTIST "a"

enum PLAYOPTION {
    PLAY,
    PAUSE,
    RESUME,
    EDIT_META_DATA,
    NEXT,
    PREVIOUS,
    VOLUME_UP,
    VOLUME_DOWN,
};

#endif
