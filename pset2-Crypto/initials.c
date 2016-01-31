#include<stdio.h> //for standerd input output
#include<cs50.h> //for GetString()
#include<string.h> //for strlen()
#include<ctype.h> //for toupper()

int main(void)
{   
    int len,i,j,count=1;
    char* input;
    input = GetString();
    len = strlen(input);
    
    for(i=0;i<len-1;i++)   {    //count no of words for size of new final array or you can say string but after appending '\0'.
        if(input[i] == ' ' && i < len-1 )  {
                    count++;
            }   
    }
    char out[count];
    out[0] = input[0]; // putting first word in final string by indexing to input.
    out[count]='\0'; //appending '\0' at end to make it a string.
    
    for(i=0,j=1;i<len-1;i++)   { //pick out first letter of word for final use.
        if(input[i] == ' ' && i < len - 1)  {
               out[j] = input[i+1];
               j++;
            } 
    }
    
    for(i=0;i<=count;i++)   { //coverting final output to uppercase
                out[i] = toupper(out[i]);
    }
    printf("%s\n",out);    
}
