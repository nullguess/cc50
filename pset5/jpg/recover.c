/***************************************************************************
* resize.c
*
* CC50
* Pset 5
*
* Recover JPG's "excluded".
****************************************************************************/
#include <stdint.h>
#include <stdio.h>

int is_jpg(uint8_t buffer[]);

int
main(void)
{
    FILE *input = fopen("card.raw", "r");
    if (input == NULL)
    {
	    printf("Could not open card.raw.\n");
	    return 1;
    }

    uint8_t buffer[512];
    FILE *output;
    int count = 0;
    char name[50];

    while (fread(&buffer, 512, 1, input) == 1)
    {
	while (is_jpg(buffer) == 0)
	{
	    sprintf(name, "%03d.jpg", count);
	    output = fopen(name, "w");
	    fwrite(&buffer, 512, 1, output);

	    count++;

	    while (fread(&buffer, 512, 1, input) == 1 && is_jpg(buffer) == 2)
		    fwrite(&buffer, 512, 1, output);
	}
    }

    fclose(input);
    fclose(output);
}

int
is_jpg(uint8_t buffer[])
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] == 0xe0)
	    return 0;
    else if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] == 0xe1)
	    return 0;
    else
	    return 2;
}

