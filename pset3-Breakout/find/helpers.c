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
void sort(int values[], int n)
{

    // implimating bubble sort for sorting purpose
  int i,j,k,tmp;
  bool flag = false;    //using flag to identify that if in a whole pass if there's no swap made means it's sorted and get out of loop 
  for(k=0;k<n;k++)   {
    for(i=0,j=1;i<n;i++,j++)    {
            if(values[i]>values[j]){
            //swap
            tmp=values[i];
            values[i]= values[j];
            values[j]=tmp;
            flag = true;    //if swap is made falg will turn true.
            }
    }
    if(flag == false ){
    break;  //if there's no swap made means it's sorted and get out of here.
    }  
  }
}
