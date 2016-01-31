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
        
        if(argc > 2 || argc < 2 ) {  //cheack if user typed more then one or no argument in program if quit from program.
               printf("retry !!! with only one argument as key\n");
            return 1;
        }
        arg = argv[1]; //getting key from command line argument to char* arg.
        int keylen = strlen(arg); //length of key
        
        for(i=0;i<keylen;i++)   {
            int test = isalpha(arg[i]);
            //printf("test = %d\n",test);
            if(!test){
            printf("retry !!! with alphanumaric key\n");
            return 1;
           }
        }        
        
        
        
        input = GetString();
        int len = strlen(input); //length of inpuut string
        char output[len];
        char tmpary[len];
        tmpary[len] = '\0';
        output[len] = '\0';
        //int keylen = strlen(arg); //length of key
        int div = len/keylen;
        int j,k=0;
        //int mod = len%keylen;
        //printf("print keylen = %d \n",keylen);
        //printf("print div = %d \n",div);
        //printf("print mod = %d \n",mod);
       
        
       
                    int kc=0; //key count while filling tmpary[].
                        //copy key in new array in repetative way and fill it up till len-1 pos
                        for(i=0;i<div;i++)  {
                            for(j=0;j<keylen;j++) {
                                
                                tmp = isalpha(input[k]);
                                //printf("print tmp = %d\n",tmp);
                             
                             if(tmp) {
                                 //printf("kc = %d\n",kc);
                                 while(kc >= keylen){
                                 kc=0;
                                 }                                    
                                 tmpary[k]=arg[kc]; 
                                 //printf("++print tmpary = %c \n",tmpary[k]);
                                 //printf("++print arg = %c \n",arg[j]);
                                 kc++;

                                }else{
                                tmpary[k] = input[k]; 
                                }
                             //printf("k= %d \n",k);      
                             k++;
                            
                             } 

                         }
                         //it take care of mod part 
                       for(i=k;i<len;i++)    {
                                
                                tmp = isalpha(input[i]);
                                //printf("print tmp = %d\n",tmp);
                             
                             if(tmp) {
                             //printf("kc = %d\n",kc);
                                 while(kc >= keylen){
                                 kc=0;
                                 }
                                 
                           tmpary[i]=arg[kc];
                           kc++;
                            //printf("print tmpary = %c \n",tmpary[k]);
                            //printf("print arg = %c \n",arg[j]); 
                            //j++;  check
                            //k++;
                            //printf("i= %d \n",i);                  
                             }else{
                                tmpary[k] = input[k]; 
                                }
                             //printf("k= %d \n",k);      
                             k++;
                        }

/*                         for(i=0;i<len;i++) {*/
/*                                printf("tmp ary = %c\n",tmpary[i]);*/
/*                            }*/
                        
                        //printf("final string in tmpary = %s\n",tmpary);
                //copied  key in another array and after this we have to rotate the plain text into cypher text
                
            //
            for(i=0;i<len;i++)  {         
                tmp = isalpha(input[i]);
                //printf("print tmp = %d\n",tmp);
                    if(tmp) {                
                            
                        up = isupper(input[i]);
                        if(up)  {
                        //testing key and converting it for use in here
                        keyup = isupper(tmpary[i]);
                        if(keyup){
                        key = tmpary[i]-65;
                        //printf("key = %d\n",key); 
                        }else{
                        key = tmpary[i]-97;
                        //printf("key = %d\n",key);
                        }
                        
                        
                        ascii = input[i];
                        num = ascii-65;
                        ctn = (num + key )%26;
                        ascii = ctn+65;
                        output[i] = ascii;                  
                        }
                            else    {
                            //key checking
                             keyup = isupper(tmpary[i]);
                             if(keyup){
                             key = tmpary[i]-65;
                             //printf("key = %d\n",key); 
                             }else{
                             key = tmpary[i]-97;
                             //printf("key = %d\n",key);
                             }
                            
                            //lowercase letters
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
