/****************************************************************************
 * resize.c
 *
 * CC50
 * Pset 5
 *
 * Resizes 24-bit BMPs by a factor n.
 ***************************************************************************/
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"


int
main(int argc, char *argv[])
{
    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;

    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: resize n infile outfile\n");
        return 1;
    }

    int n = atoi(argv[1]);

    if (n < 1 || n > 100)
    {
	printf("n must be an int between 1 and 100\n");
	return 2;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }

    // determine padding for scanlines of the original file
    int oldpadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    int oldWidth = bi.biWidth;
    int oldHeight = bi.biHeight;

    // determine the new height and width
    bi.biWidth = oldWidth * n;
    bi.biHeight = oldHeight * n;

    // determine the new padding
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // determine the new image size and file size
    bi.biSizeImage = (abs(bi.biHeight) * bi.biWidth * sizeof(RGBTRIPLE)) + (padding * abs(bi.biHeight));
    bf.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bi.biSizeImage;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(oldHeight); i < biHeight; i++)
    {
	// define the current file position, at the beginning of each line
	fpos_t position;
	fgetpos(inptr, &position);

	// write the pixels of each line a number n of times
	for (int r = 0; r < n; r++)
	{
	    if (r < n)
		fsetpos(inptr, &position);

            // iterate over pixels in scanline
            for (int j = 0; j < oldWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile
	        for (int k = 0; k < n; k++)
	        {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
	        }
            }

            // skip over padding, if any
            fseek(inptr, oldpadding, SEEK_CUR);

            // write padding to outfile
            for (int k = 0; k < padding; k++)
                fputc(0x00, outptr);
	}
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
