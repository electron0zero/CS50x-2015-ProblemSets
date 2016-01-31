/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4 Hacker Edition
 *
 * Recovers JPGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#define BUFFER_SIZE 512

int main(void)
{
    //opening forensic card file
    FILE *cardfile = fopen("card.raw", "r");
    //ensure that file is opened.
    if (cardfile == NULL)
    {
        printf("Could not open file card.raw \n");
        return 1;
    }
   
    //buffer for all the awasome stuff like checking for jpg headers.
    uint8_t buffer[512];
    //counter that keep track of files
    int fileno = 0;
    FILE *image = NULL;
    
    while(fread(buffer, BUFFER_SIZE, 1, cardfile) == 1)
    {
        if( buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ( buffer[3] == 0xe0 || buffer[3] == 0xe1 ))
        {
            char title[8];
            sprintf(title,"%0.3d.jpg",fileno);
            if(image != NULL)   //close a image file if it's open
            {
                fclose(image);
            }
            //open a new file in append mode
            image = fopen(title,"a");
            fileno++; 
        }
        
        if(image != NULL) //if a file is open write buffer in it.
        {
            fwrite(buffer, BUFFER_SIZE, 1, image);
        }
    }   
    //while loop is over and we recoverd all files.

    //close last open file    
    fclose(image);
    //closing forensic image file.
    fclose(cardfile); 
    
    //if we got here means all is well,let's celebrate sucess using "return 0".
    return 0;
}
