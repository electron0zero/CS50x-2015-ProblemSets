#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 1000000
//you should pass lowercase words only in this hash function use tolower before passing word in this function. 
int hash (const char* word)
{   
    
    int hash = 0;
    int n;
    
    for (int i = 0; word[i] != '\0'; i++)
    {

        // alphabet case
        if(isalpha(word[i]))
            n = word [i] - 'A' + 1;
        
        // comma case
        else
            n = 27;
         
        hash = (hash+n)+i*27;
        //hash = ((hash << 3) + n) % SIZE;
    }
    return hash;    
}

int main(){
    char word[46];
    printf("enter a word\n");
    scanf("%s",word);
    int hashr;
    hashr = hash(word);
    printf("%d\n",hashr);
    return 0;
}



