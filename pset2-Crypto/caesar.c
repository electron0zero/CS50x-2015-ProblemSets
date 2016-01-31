#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(int argc,char *argv[])
{   
        int key,i,tmp,up,ascii,num,ctn;
        char *input;
        char *arg = malloc(sizeof(char));
        arg = argv[1]; //getting key from command line argument to char* arg.
        
        if(argc > 2 || argc < 2 ) {  //cheack if user typed more then one or no argument in program if quit from program.
               printf("retry !!! with only one argument as key\n");
            return 1;
        }
        
        input = GetString();
        key = atoi(arg);    //converted key into int from char* using atoi();
        int len = strlen(input);
        char output[len];
        output[len] = '\0';
        
        for(i=0;i<len;i++)  {
            tmp = isalpha(input[i]);
                if(tmp)  {
                    up = isupper(input[i]);
                    if(up)  {
                    ascii = input[i];
                    num = ascii-65;
                    ctn = (num + key )%26;
                    ascii = ctn+65;
                    output[i] = ascii;                  
                    }
                    else    {
                    ascii = input[i];
                    num = ascii-97;
                    ctn = (num + key )%26;                    
                    ascii = ctn+97;
                    output[i] = ascii;                                                      
                    }  
                } 
                else {
                output[i] = input[i];
                }
        }
        printf("%s\n",output); //priting final output or cyphered text
        return 0;
}
