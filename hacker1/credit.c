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
    int len,i,l,a,d,z;//,e,k;
    int len_t=0,len_calc=0,count2=0,total=0;
    
    printf("enter credit card number\n");
    card_num = GetLongLong();
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
        t1=t1/10;
    }
    //geting alternate digits in an another arrays for calculation and verification
    for(i=0,l=0;i<len;i=i+2)    {
        c_tcalc[l] = c_no[i+1];
        c_t2[l] = c_no[i];
        l++;
    }
    for(a=0;a<len_calc;a++)     {
       c_tcalc[a] = c_tcalc[a]*2;
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
             c++;
           }
        if(c_tcalc[b] < 9 )    {
            c_2 = c_2 + c_tcalc[b]; 
        }
    }
    
    //spliting number for digit count
    for(d=0,z=0;d < count2;d++)        {
    split2[z] = split[d]%10; 
    z++;
    split2[z] = split[d]/10;
    z++;
    }
    
    //counting numbers
    for(i=0;i < count2*2;i++)    {
        c_1 = c_1 + split2[i];
    }
    for(i=0;i<len_t;i++)     {
        c_3 = c_3 + c_t2[i];
    }
    total = c_1 + c_2 + c_3;
    
    //identifying card issuer and verifying card     
    if((total%10) == 0)    { //his condition conferms that card is legit
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
    return count;
}
