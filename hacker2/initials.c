//hacker edition
#include<stdio.h> //for standerd input output
#include<cs50.h> //for GetString()
#include<string.h> //for strlen()
#include<ctype.h> //for toupper()

int main(void)
{   
    int len,i,j,count=0;
    char* input;
    input = GetString();
    len = strlen(input);
    if(input[0]!= ' '){
        count = 1;    
    }else{
    count = 0;
    }
    int t=count; 
    for(i=0;i<len-1;i++)   {    //count no of words for size of new final array or you can say string but after appending '\0'.
        if(input[i] == ' ' && input[i+1] != ' ')  {
                    count++;
            } 
    }
    char out[count];
    if(t){
    out[0] = input[0]; // putting first word in final string by indexing to input.
    } 
    out[count]='\0'; //appending '\0' at end to make it a string.
    for(i=0,j=t;i<len;i++)   { //pick out first letter of word for final use.
        if(input[i] == ' ' && input[i+1] != ' ' )  {
               out[j] = input[i+1];
               j++;
            }
    }
    for(i=0;i<count;i++)   { //coverting final output to uppercase
                out[i] = toupper(out[i]);
    }
    printf("%s\n",out);     //printing final string.
}
