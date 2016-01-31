#include<stdio.h>
#include<cs50.h>

int main(void)  
{
    int height,con,space,fill;
        // test that the user input is in range 
        do
        {
            printf("Enter height for mario ( 0<height<23 )\n");
            height = GetInt();
        }while(height < 0 || height > 23);
        //if program comes here means correct input 
        //let's print mario steps here 
        for(con=0 ; con < height ; con++ )  {
            for(space=0;space<(height-1)-con;space++)   {
            printf(" ");
            }
            for(fill=0;fill<con+2;fill++) {
            printf("#");
            }
            printf("\n");
        }
}
