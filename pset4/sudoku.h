/****************************************************************************
 * sudoku.h
 *
 * CC 50
 * Pset 4
 *
 * Compile-time options for the game of Sudoku.
 ***************************************************************************/

// game's author
#define AUTHOR "Kauê"

// game's title
#define TITLE "Sudoku"

// banner's colors
#define FG_BANNER COLOR_WHITE
#define BG_BANNER COLOR_BLACK

// grid's colors
#define FG_GRID COLOR_WHITE
#define BG_GRID COLOR_BLACK

// border's colors
#define FG_BORDER COLOR_WHITE
#define BG_BORDER COLOR_CYAN

// logo's colors
#define FG_LOGO COLOR_BLUE
#define BG_LOGO COLOR_BLACK

#define FG_WIN COLOR_GREEN
#define BG_WIN COLOR_BLACK

#define FG_DEFAULT COLOR_MAGENTA
#define BG_DEFAULT COLOR_BLACK

// nicknames for pairs of colors
enum { PAIR_BANNER = 1, PAIR_GRID, PAIR_BORDER, PAIR_LOGO, PAIR_WIN, PAIR_DEFAULT };
