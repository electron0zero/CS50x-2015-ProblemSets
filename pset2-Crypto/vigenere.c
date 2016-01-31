#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(int argc,char* argv[])
{   
        int i,tmp,up,ascii,num,ctn,key=0,keyup=0;
        char* input;
        char* arg = malloc(sizeof(char));
        if(argc > 2 || argc < 2 ) {  //cheack if user typed more then one or no argument in program if quit program with errer.
               printf("retry !!! with only one argument as key\n");
            return 1;
        }
        arg = argv[1]; //getting key from command line argument to char* arg.
        int keylen = strlen(arg); //getting length of key
        for(i=0;i<keylen;i++)   { //check for non-alphanumaric key if quit program with errer.
            int test = isalpha(arg[i]);
            if(!test){
            printf("retry !!! with alphanumaric key\n");
            return 1;
           }
        }        
        input = GetString();    //prompt user for input.
        int len = strlen(input); //length of input string
        char output[len];
        char tmpary[len];
        tmpary[len] = '\0';     //putting '\0' at end of strings
        output[len] = '\0';
        int div = len/keylen;
        int j,k=0;
        int kc=0; //key count while filling tmpary[].
                //copy key in new array in repetative way and fill it up till len-1 pos
                        for(i=0;i<div;i++)  {
                            for(j=0;j<keylen;j++) {
                                tmp = isalpha(input[k]);
                             if(tmp) {
                                 while(kc >= keylen){
                                 kc=0;
                                 }                                    
                                 tmpary[k]=arg[kc]; 
                                 kc++;
                             }
                             else{
                                tmpary[k] = input[k]; 
                                }
                             k++;
                            
                             } 
                         }
                   //it take care of rest of partwhere we have to chop off the key whn key don't map fully. 
                       for(i=k;i<len;i++)    {
                           tmp = isalpha(input[i]);
                             if(tmp) {
                                    while(kc >= keylen) {   //this loop take care of kc variable that used in copying key in new tmpary[] array.
                                    kc=0;
                                    }
                                tmpary[i]=arg[kc];
                                kc++;                 
                             }else{
                                tmpary[k] = input[k]; 
                                }
                             k++;
                        }
        //copied  key in another tmpary[] array and after this we have to convert the plain text into cypher text
        //plain to cypher text conversion
            for(i=0;i<len;i++)  {         
                tmp = isalpha(input[i]);
                    if(tmp) {                
                        up = isupper(input[i]);
                        if(up)  {  //if input is alphanum and uppercase
                            keyup = isupper(tmpary[i]);
                            if(keyup){      //testing key and converting it for use in here
                            key = tmpary[i]-65;
                         }
                         else{
                         key = tmpary[i]-97;
                         }
                        //text conversion starts here and if we need we do a-z roation. for uppercase letters
                        ascii = input[i];
                        num = ascii-65;
                        ctn = (num + key )%26;
                        ascii = ctn+65;
                        output[i] = ascii;                  
                        }
                        else    {   //if input is alphanum and lowercase
                             keyup = isupper(tmpary[i]);
                             if(keyup){     //testing key and converting it for use in here
                             key = tmpary[i]-65;
                             }else{
                             key = tmpary[i]-97;
                             }
                        //text conversion starts here and if we need we do a-z roation. for lowercase letters
                            ascii = input[i];
                            num = ascii-97;
                            ctn = (num + key )%26;                    
                            ascii = ctn+97;
                            output[i] = ascii;                                                      
                            }  
                    }
                    else {      //if input is not alphanumaric do noting and keep as-it-is.
                    output[i] = input[i];
                    }
          }
        printf("%s\n",output); //priting final output or cyphered text
    return 0;
}
