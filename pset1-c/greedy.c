#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)  
{
    float money_t,cent;
    int count_25=0,count_10=0,count_5=0,count_1=0,cent_int=0,temp,rem,total=0;
    
// test user input
        do
        {    printf("Enter money for change\n");
            money_t = GetFloat();
            
        } while(money_t < 0);
        
//convert total cash into cents and use round function from math library to avoid floting point imprecessions.
        cent = money_t * 100.0;
        cent_int = round(cent);
        rem = cent_int;
         
        if(rem >= 25 ) {
            temp=cent_int;
            count_25 = temp/25;

            rem = temp%25;
        }
        if(rem >= 10 ) {
            temp = rem;
            count_10 = temp/10;

            rem = temp%10; 
        }
        if(rem >= 5 )    {
            temp = rem;
            count_5 = temp/5;

            rem = temp%5;
        }
        if( rem >= 1 )  {
            temp = rem;
            count_1 = temp/1;

        }
        
/*  these print stetments help to debug and see actual no. of coins as denominations

        printf("count_25 = %i\n",count_25); 
        printf("count_10 = %i\n",count_10);
        printf("count_5 = %i\n",count_5);
        printf("count_1 = %i\n",count_1);   */
        
        total=count_25+count_10+count_5+count_1;
        printf("%i\n",total);
        
}
