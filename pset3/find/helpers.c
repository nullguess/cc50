/****************************************************************************
 * helpers.c
 *
 * CC50
 * Pset 3
 *
 * Helper functions for Problem Set 3.
 ***************************************************************************/

#include <cc50.h>
#include <stdio.h>
#include "helpers.h"

/*
 * Returns true if value is in array of n values, else false.
 */

bool
search(int value, int array[], int n)
{
    // TODO: re-implement as binary search
    int begin = 0;
    int end = n;

    while (begin <= end)
    {
	int a = (begin + end) / 2;

	if (array[a] == value)
	{
	    return true;
	}

	if (array[a] < value)
	{
	    begin = a + 1;
	}

	else
	{
	    end = a - 1;
	}
    }

    return false;

    /*for (int i = 0; i < n; i++)
        if (array[i] == value)
            return true;
    return false;*/
}


/*
 * Sorts array of n values.
 */
void
sort(int values[], int n)
{
    // TODO: implement an O(n^2) sort
    int k = 0;
    int i = 0;
    int x = values[i];

    for (k = 0; k < n-1; k++)
    {
	for (i = 0; i < n-k-1; i++)
	{
	    x = values[i];
	    if (values[i] > values[i+1])
	    {
		values[i] = values[i+1];
		values[i+1] = x;
	    }
	}
    }

    return;
}


