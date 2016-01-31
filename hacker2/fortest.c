#include<stdio.h>
#include<stdlib.h>
int main(void)  
{

    int length = 9;
    char words[length];
    int i;
    for(i=0;i < length ; i++ ){
    words[i] = '\0';
    }
    int i1,i2,i3,i4,i5,i6,i7,i8;
    //int j=0;
    int st = 33, le = 127; 
    //sucess = 1;
    for(i1=st;i1 < le ; i1++ ){
        for(i2=st;i2 < le ; i2++){
            for(i3=st;i3 < le ; i3++){
                for(i4=st;i4 < le ; i4++){
                    for(i5=st;i5 < le ; i5++){
                        for(i6=st;i6 < le ; i6++){
                            for(i7=st;i7 < le ; i7++){
                                for(i8=st;i8 < le ; i8++){
                                   words[0] = i8;
                                   words[1] = i7;
                                   words[2] = i6;
                                   words[3] = i5;
                                   words[4] = i4;
                                   words[5] = i3;
                                   words[6] = i2;
                                   words[7] = i1;        
                                   printf("%s\n",words); 
                                }
                               words[0] = i7;
                                   words[1] = i6;
                                   words[2] = i5;
                                   words[3] = i4;
                                   words[4] = i3;
                                   words[5] = i2;
                                   words[6] = i1;
                                   words[7] = '\0';        
                                   printf("%s\n",words); 
                            }
                            words[0] = i6;
                                   words[1] = i5;
                                   words[2] = i4;
                                   words[3] = i3;
                                   words[4] = i2;
                                   words[5] = i1;
                                   words[6] = '\0';       
                                   printf("%s\n",words);
                        }
                        words[0] = i5;
                                   words[1] = i4;
                                   words[2] = i3;
                                   words[3] = i2;
                                   words[4] = i1;
                                   words[5] = '\0';        
                                   printf("%s\n",words);
                    }
                    words[0] = i4;
                                   words[1] = i3;
                                   words[2] = i2;
                                   words[3] = i1;
                                   words[4] = '\0';        
                                   printf("%s\n",words);
                }
                words[0] = i3;
                                   words[1] = i2;
                                   words[2] = i1;
                                   words[3] = '\0';       
                                   printf("%s\n",words);
            }
            words[0] = i2;
                                   words[1] = i1;
                                   words[2] = '\0';       
                                   printf("%s\n",words);
        }
        words[0] = i1;
                                   words[1] = '\0';        
                                   printf("%s\n",words);
    }
    
}
/*                words[0] = i8;*/
/*                words[1] = i7;*/
/*                words[2] = i6;*/
/*                words[3] = i5;*/
/*                words[4] = i4;*/
/*                words[5] = i3;*/
/*                words[6] = i2;*/
/*                words[7] = i1;        */
/*                printf("%s\n",words);*/

