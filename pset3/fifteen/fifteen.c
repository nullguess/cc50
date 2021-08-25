/***************************************************************************
 * fifteen.c
 *
 * CC50
 * Pset 3
 *
 * Implements The Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 ***************************************************************************/

#define _XOPEN_SOURCE 500

#include <cc50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// constants
#define DIM_MIN 3
#define DIM_MAX 9


// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);


int
main(int argc, char *argv[])
{
    // greet user with instructions
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: %s d\n", argv[0]);
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %d x %d and %d x %d, inclusive.\n",
         DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }


    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}


/*
 * Clears screen using ANSI escape sequences.
 */

void
clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}


/*
 * Greets player.
 */

void
greet(void)
{
    clear();
    printf("WELCOME TO THE GAME OF FIFTEEN\n");
    usleep(2000000);
}


/*
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */

void
init(void)
{
    // TODO

    int n = (d*d) - 1;

    for (int line = 0; line < d; line++)
    {
	for (int column = 0; column < d; column++)
	{
	    board[line][column] = n;
	    n--;
	}
    }

    switch(d)
    {
	case 4:
	case 6:
	case 8:

	board[d-1][d-3] = 1;
	board[d-1][d-2] = 2;

        break;
    }

    return;
}


/* 
 * Prints the board in its current state.
 */

void
draw(void)
{
    // TODO

    for (int i = 0; i < d; i++)
    {
	for (int j = 0; j < d; j++)
	{
	    if (board[i][j] < 10)
	    {
	        char c = (board[i][j] == 0) ? '_' : board[i][j] + '0';
	        printf(" %c  ", c);
	    }

	    else
		printf("%d  ", board[i][j]);
	}

	printf("\n");
    }

    return;
}


/* 
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */

bool
move(int tile)
{
    // TODO

    for (int i = 0; i < d; i++)
    {
	for (int j = 0; j < d; j++)
	{
	    if (tile == board[i][j])
	    {
		if (board[i+1][j] == 0 && i < d-1)
		{
		    board[i+1][j] = tile;
		    board[i][j] = 0;

		    return true;
		}
		else if (board[i][j+1] == 0 && j < d-1)
		{
		    board[i][j+1] = tile;
		    board[i][j] = 0;

		    return true;
		}

		else if (board[i-1][j] == 0 && i > 0)
		{
		    board[i-1][j] = tile;
		    board[i][j] = 0;

		    return true;
		}
		else if (board[i][j-1] == 0 && j > 0)
		{

		    board[i][j-1] = tile;
		    board[i][j] = 0;

		    return true;
		}
		else
		    return false;
	    }
	}
    }


    return false;
}


/*
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */

bool
won(void)
{
    // TODO

    int a = 1;

    for (int i = 0; i < d; i++)
    {
	for (int j = 0; j < d; j++)
	{
	    if (a != board[i][j])
	    {
		if (i != d-1 && j != d-1)
		     return false;
	    }

	    else if (board[d-1][d-1] != 0)
		return false;

	    a++;
	}
    }

    return true;
}
