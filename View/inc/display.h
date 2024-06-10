#ifndef DISPLAY_H
#define DISPLAY_H

#define MAX_LINES 25
#define WIDTH 100
#define LENGTH 30
/*
    Define navigator letters
*/
#define HOME "h"
#define GO_BACK "<"
#define FORWARD ">"
#define EXIT "x"
#define CREATE "c"
#define DELETE "d"

/*
    Define
*/
#define MAX_HISTORY_PAGE 10
#define NEXT_PAGE "n"
#define PREVIOUS_PAGE "p"
#define SORT_BY_NAME "s"
#define SORT_BY_ARTIST "a"

enum PLAYOPTION {
    REPLAY,
    PAUSE,
    RESUME,
    EDIT_META_DATA,
    NEXT,
    PREVIOUS,
    VOLUME_UP,
    VOLUME_DOWN,
};

/* 
Define column size
*/
#define NO_COL 5
#define TITLE_COL 30
#define ARTIST_COL 25
#define ALBUM_COL 25
#define DURATION_COL 10
#define YEAR_COL 5
#define INDICATOR_COL 5

#define ALIGN_COL 30
#define LEFT_MARGIN 20

#define SONG_NUM_SHOW 7

#endif
