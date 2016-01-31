/***************************************************************************
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 ***************************************************************************/
 
// standard libraries
#define _XOPEN_SOURCE   //for srand48() and drand48() { more see msn page }
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // this if part ensure that you run this program with atleast with 2 OR 3 command line arugments.
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // argv store input in char* so we directely can't typecast char* to int so we use function atoi() to conver it to int
    //after conversion we stored it into variable n for further use of argument that we provides in command line
    int n = atoi(argv[1]);

    // if user provide 3 command line arguments then we take 3rd (optional) argument from command line and used it as seed for function srand().
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else //if 3rd argument ( seed ) is not provided use time as seed {see more at man page of time()}
    {
        srand48((long int) time(NULL));
    }
    // srand is a compulsery function while using drand() it is dependent function of srand48(), it utilize output of srand48().
    //n contains 2nd argument of commandline or it contains how many random numbers to be generated so using a for loop we generate that much random numbers 
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));  // when drand48() called it genterate a random number each time it called. 
    }

    // return 0 on as repersentation of sucess of program.
    return 0;
}
