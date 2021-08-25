#include <cc50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char *argv[])
{
    if(argv[1] < 0 || argc != 2)
    {
	return 1;
    }

    string k = argv[1];
    int j = strlen(k);

    for(int i = 0; i < j; i++)
    {
	if(k[i] >= 65 && k[i] <=  90)
	{
	    k[i] = k[i] - 65;
	}

	else if(k[i] >= 97 && k[i] <= 122)
	{
	    k[i] = k[i] - 97;
	}

	else
	{
	    return 1;
	}
    }

    string p = GetString();

    for(int i = 0, n = strlen(p), a = 0; i < n; i++)
    {
	if(p[i] >= 65 && p[i] <= 90)
	{
	    p[i] = 65 + ((p[i] - 65 + k[a % j]) % 26);
	    printf("%c", p[i]);
	    a++;
	}

	else if(p[i] >= 97 && p[i] <= 122)
	{
	    p[i] = 97 + ((p[i] - 97 + k[a % j]) % 26);
	    printf("%c", p[i]);
	    a++;
	}

	else
	{
	    printf("%c", p[i]);
	}
    }

    printf("\n");

    return 0;
}
