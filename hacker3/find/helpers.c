/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include<stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{   
    // going for binery search.
    int i,low=0, high=n+1;
    for(i=0;i<n;i++)    {
        int mid = (low+high)/2;
        if(values[mid] == value ){
            return true;
        }
        else
            if(values[mid] < value )   {
                low = mid+1;
            }
            else
                if(values[mid] > value )   {
                    high = mid-1;
                }
    }
    return false;
}
/*
 * Sorts array of n values.
 */
void sort(int values[],int n)
{
    //implimanting counting sort for O(n) type sorting algorithm pourpose.
    //finding the largest element from the list we are going to sort to maximum number of elements for hash or index array
    //printf("in function\n");
    int i, max = values[0];
    for(i=0;i<n;i++){
        if(values[i]>max){
        max = values[i];
        }
    }

    int hash[max+1]; //array for hashing;
    int output[n]; //array for output (after sorting at the end it got merged with values[n])
    
    //starilize the hash ( put 0 at every position in hash array to starilize it ).
    for(i=0;i<=max;i++){
    hash[i]=0;
    }
    
    //histogram for hashing.
    int tmp;
    for(i=0;i<n;i++){
        tmp=values[i];
        hash[tmp]=hash[tmp]+1;
    }

    //suming up the hash array in incriment order.
    for(i=0;i<max;i++){
    hash[i+1] = hash[i]+hash[i+1];
    }
    
    //mapping the hash and applying sorting and putting data in output[].
    int tmp1,tmp2;
    for(i=n;i>=0;i--){
        tmp1 = values[i];   //picking value of input array
        tmp2 = hash[tmp1];  //looking for hash value at hash[value_from_input] position.
        hash[tmp1]=hash[tmp1]-1; //maintaing histogram.
        output[tmp2-1]=tmp1;  //going at hashvalue position (index) in output array and putting value from input array in here.
    }

    for(i=0;i< n;i++){  //copying final output to input array so we don't need to return anyting.
    values[i]=output[i]; 
    }


}
