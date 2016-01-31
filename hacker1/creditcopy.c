//credit.c hacker edition
/*
it's too much massed up if you got free time and got noting to do then only try to read it.
all these printf() statments are for debug purpose only delete them in final sumbit
*/
#include<stdio.h>
#include<cs50.h>
/* 
this program uses that IBM's nice guy's ( Hans Peter Luhn ) algorithm for validating credit card information
for more about algorithm head to hacker1 pset pdf of cs50x fall 2014 
*/
int length(long long int card_number ); //function take card number and return its length of digits.

int main(void)
{   
    long long int card_num,t1;
    int len,i,j,l,a,d,z,i_,j_;//,e,k;
    int len_t=0,len_calc=0,count2=0,total=0;
    
    printf("enter credit card number\n");
    card_num = GetLongLong();
    //printf("card number is %lli \n",card_num);

    len = length(card_num); //len contains length of digits in card number.
    t1=card_num;   
    len_t=len-(len/2);
    
    if((len%2)!=0)  {   //this condition prevent from buffer overflow attack in case of len is a odd number
       len_calc = len_t-1;
    }   else
            len_calc = len_t;
            
    int c_no[len],c_tcalc[len_calc],c_t2[len_t]; //these decleration is here because we need len for decelaration of these variables.
    
    for(i=0;i<len;i++)      {   
        c_no[i] = t1%10;
        //printf("inside array %i when i = %i\n",c_no[i],i);
        t1=t1/10;
    }
    //geting alternate digits in an another arrays for calculation and verification
    for(j=0,l=0;j<len;j=j+2)    {
        c_tcalc[l] = c_no[j+1];
        c_t2[l] = c_no[j];
        l++;
    }
    //doing calculation with alaternate digits ( c_tcalc[] array )
    for(a=0;a<len_calc;a++)     {
       c_tcalc[a] = c_tcalc[a]*2;
       //printf("--c_tclac in calculation = %i \n",c_tcalc[a]);
       if(c_tcalc[a] > 9) {
                count2++; //to count double digit numbers after multiplication
           }
      }
      
    int split[count2],split2[count2*2],c=0,b,c_1=0,c_2=0,c_3=0;
    /*
    c_1 contains total of digits of number less then 9 in alternate digits that we multiplied with 2
    c_2 contains total of digits those number grater then 9 after split
    c_3 contains total of digits that we left whilechoosing alternate digits
    */
    //copying number grater then 9 in an another array for again split it to add this up for count
    for(b=0,c=0;b<len_calc;b++)       {
        if(c_tcalc[b] > 9) {
             split[c]=c_tcalc[b];
             //printf("split array = %i\n",split[c]);
             c++;
           }
        if(c_tcalc[b] < 9 )    {
            c_2 = c_2 + c_tcalc[b]; 
        }
    }
        //printf(" c_2  count = %i\n",c_2);
    
    //spliting number for digit count
    //printf("count2 = %i\n",count2);
    for(d=0,z=0;d < count2;d++)        {
    //printf("   d = %i \t z = %i \n",d,z);
    split2[z] = split[d]%10; 
    //printf("    split 2 = %i when z = %i\n",split2[z],z);
    z++;
    split2[z] = split[d]/10;
    //printf(" ++ split 2 = %i when z = %i\n",split2[z],z);
    //printf(" == d = %i \t z = %i \n",d,z);
    z++;
    }
    //counting numbers
    for(i_=0;i_ < count2*2;i_++)    {
        c_1 = c_1 + split2[i_];
    }
        //printf(" c_1  count = %i\n",c_1);
    for(j_=0;j_<len_t;j_++)     {
        c_3 = c_3 + c_t2[j_];
    }
        //printf(" c_3  count = %i\n",c_3);
    total = c_1 + c_2 + c_3;
        //printf(" total count = %i\n",total);    
    //identifying card issuer and verifying card 
        
    if((total%10) == 0)    { //his condition conrms that card is legit
            //this nested loop identifies that card issuer or tell that it is invalid
        if(c_no[len-1] == 4 )   {
        printf("VISA\n");
        }
        else
        if(c_no[len-1] == 3)   {
                if(c_no[len-2] == 4 || c_no[len-2] == 7 ) {
                printf("AMEX\n");
                } else {
                    printf("INVALID\n");
                }
        }
        else
        if(c_no[len-1] == 5)   {
                if(c_no[len-2] == 1 || c_no[len-2] == 2 || c_no[len-2] == 3 || c_no[len-2] == 4 || c_no[len-2] == 5 )  {
                printf("MASTERCARD\n");
                } else {
                    printf("INVALID\n");
                }
        }
        else {
        printf("INVALID\n");
        }       
      } else {
        printf("INVALID\n");      
      }
       
        
        
    //debug prints
/*    for(e=0;e<count2*2;e++)     {*/
/*       printf(" debug split 2 = %i when i = %i\n",split2[e],e);    */
/*    }*/
/*    */
/*    printf("printf count2 = %i \n",count2);   */
/*    printf("printf len_t = %i \n",len_t);*/
/*    printf("printf len_calc = %i \n",len_calc);*/
/*    for(k=0;k<len_calc;k++)    {*/
/*            printf("c_tcalc for calc = %i \n",c_tcalc[k]);*/
/*             }*/
/*     for(k=0;k<len_t;k++)    {*/
/*            printf("c_t2 = %i \n",c_t2[k]);*/
/*             }*/
             
     return 0;
}
// function take card number and return its length of digits.
int length(long long int card_number )
{  
    long long int cn_t;
    int count=0;
     cn_t=card_number;
    while(cn_t!=0)   
    {
        cn_t=cn_t/10;
        count++;
    }
   //printf("length of card number is  = %i\n",count);
    return count;
}
