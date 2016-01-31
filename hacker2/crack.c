//hacker edition of hacker2 of cs50x fall 2014 for more abou htis see .pdf file of hacker edition of fall 2014 cs50x by harvardx
/*TODO = documante this file 
here i am using dictoneryattack first and then trying to use brute force
*/ 
#define _XOPEN_SOURCE       /* See feature_test_macros(7) */
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char* argv[])
{   
        char* arg = malloc(sizeof(char));
        
        if(argc > 2 || argc < 2 ) {  //cheack if user typed more then one or no argument in program if quit from program.
               printf("retry !!! with only one argument as key\n");
            return 1;
        }
        arg = argv[1]; //getting hash of a pssword from command line argument.
        printf("hash in  arg = %s\n",arg);
        /*
        copy first two chaecters in salt because from man page of crypt(3) 
        function we know these are always only 2 charecters and always at first two char of hash  
        */
        char salt[3];
        salt[0] = arg[0];
        salt[1] = arg[1];
        salt[2] = '\0';
        //printf("salt = %s\n",salt);
        
        //file I/O part for dictonery attack with including dictonery
        FILE *fp;
        fp = fopen("words","r");
        if( fp == NULL )    {
        //printf("file can't be opened\n");
        //exit(0);
        }
        int len = 10;
        char str[len],newstr[len];
        char *out;
        out = malloc(sizeof(char));
        int result=10,lent,i,sucess = 0;
        while(fgets(str,len,fp) != NULL )    {
        //printf("line by line = %s",str);
        lent = strlen(str);
        //printf("lent of str is %d\n",lent);
        //print each element of str that comes from file.
        for(i=0;i<lent-1;i++){
        //printf("each element from str is = %c \n",str[i]);
        newstr[i] = str[i]; 
        }
        newstr[lent-1] = '\0';
        //printf("new str is %s\n",newstr);
        //lent = strlen(newstr);       
        //printf("lent of newstr is %d\n",lent);
        out = crypt(newstr,salt);
        //printf("crypt output is = %s\n",out);
        //printf("*\n");         
        result = strcmp(out,arg);
        //printf("strcmp output is = %d\n",result);
            if(result == 0)  {
            printf("password found is = %s\n",str);
            sucess = 1;
            break;
            }
        }
        //file I/O part ends here dictonery attack also ends here.
        //if dictonery attack fails prepare for brute force attack that starts from here.
        //program enter in this part only if sucess = 0 means fail of dictonery attack.
        char brute[9]
        if(sucess == 0 )    {       //start brute force beacuse dictonery attack is failed.
        //as we know password can't be longer then 8 char.
        
        
        
        
        
        
        
        
        
        
        
        }
        
        
        
        
        
        
        
        // Need to impliment crack(3) function and generate hash with salt and input from dictonery and compare them
/*        char test[10];*/
/*        test[0] = 'c'; */
/*        test[1] = 'r'; */
/*        test[2] = 'i'; */
/*        test[3] = 'm'; */
/*        test[4] = 's'; */
/*        test[5] = 'o'; */
/*        test[6] = 'n'; */
/*        test[7] = '\0';*/
/*        printf("%s\n",test);*/
/*        lent = strlen(test);*/
/*        printf(" test lent is %d\n",lent);*/
/*        */
/*        for(i=0;i<lent;i++){*/
/*        printf("each element from str is = %c \n",test[i]);*/
/*        }*/
        
        //crack(3) implmatnation starts
              
        
    return 0;
}
