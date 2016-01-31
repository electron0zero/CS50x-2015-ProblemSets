/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4 Hacker Edition
 *
 * resize a .BMP file.
 */
// TODO impliment resize for srinking a bmp. i.e. when n is in between 0 and 1.

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];
    // hendling n (times of resize)
    char *ntime = argv[1];
    float n = atoi(ntime);
    
    //ensure that n is between 1 to 100
    if(n<0 || n >100 )
    {
        printf("retry !!! your resize factor must be between 0 to 100\n");
        return -1;
    }

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    //modifying headers
    //modifying width.
    int infile_biWidth = bi.biWidth;
    bi.biWidth = infile_biWidth*n;
    //modifying height.
    int infile_biHeight = bi.biHeight;
    bi.biHeight = infile_biHeight*n;
 
    // determine padding for input amd output files.
    int infile_padding =  (4 - (infile_biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int outfile_padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //modifying biSizeImage and bfSize (headers)
    bi.biSizeImage = bi.biWidth * abs(bi.biHeight)*sizeof(RGBTRIPLE)+outfile_padding*abs(bi.biHeight); 
    bf.bfSize = bi.biSizeImage + sizeof(bf)+sizeof(bi);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // temporary storage
    RGBTRIPLE triple;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(infile_biHeight); i < biHeight; i++)
    {
        for(int high=0;high<n;high++)   //this loop control height (resizeng BMP's height)
        {
            // iterate over pixels in scanline
            for(int j = 0; j < infile_biWidth; j++)
            {       
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                    for(int wid=0;wid<n;wid++)      //this loop control width (resizing BMP's width)
                    {     
                        //write RGB triple to outfile
                        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    }
            }
            // skip over padding of input file
            fseek(inptr,infile_padding, SEEK_CUR);
            // add the new padding to output file
            for (int k = 0; k < outfile_padding; k++)
            {
                fputc(0x00, outptr);
            }
            //move cursur back to at the start of scanline which we just finsed reading so we can re read that scan line print it again to resize height. 
            fseek(inptr,-(infile_padding+sizeof(RGBTRIPLE)*infile_biWidth), SEEK_CUR);   
        }
        //move curser to next line when we finsed printing the same line n times (height resizing) and read it so we can resize next scanline.
        fseek(inptr,(infile_padding+sizeof(RGBTRIPLE)*infile_biWidth), SEEK_CUR);
    }
    //resizing done

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's it if we reached this line means all is well let's celerate sucess by returning 0
    return 0;
}
