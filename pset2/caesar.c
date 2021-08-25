#include <cc50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main (int argc, char *argv[])
{
    if (argv[1] < 0)
    {
	return 1;
    }

    if(argc != 2)
    {
	return 1;
    }

    int k = atoi(argv[1]);
    string p = GetString();

    for (int i = 0, n = strlen(p); i < n; i++)
    {
	if(p[i] >= 65 && p[i] <= 90)
	{
	    p[i] = 65 + ((p[i] - 65 + k) % 26);
	    printf("%c", p[i]);
	}

	else if(p[i] >= 97 && p[i] <= 122)
	{
	    p[i] = 97 + ((p[i] - 97 + k) % 26);
	    printf("%c", p[i]);
	}

	else
	{
	    printf("%c", p[i]);
	}
    }

    printf("\n");

    return 0;
}
