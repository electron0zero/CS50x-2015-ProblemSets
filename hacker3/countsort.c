#include<cs50.h>
#include <stdio.h>
#include <stdlib.h>

// maximum amount of hay
const int MAX = 65536;

void sort(int values[],int n); //sort prototype

int main(void)
{
     // fill haystack
    int size;
    int haystack[MAX];
    for (size = 0; size < MAX; size++)
    {
        // wait for hay until EOF
        printf("\nhaystack[%d] = ", size);
        int straw = GetInt();
        if (straw == INT_MAX)
        {
            break;
        }
     
        // add hay to stack
        haystack[size] = straw;
    }
    printf("\n");

    // sort the haystack
    sort(haystack, size);
   /*  why this function don't return anyting 
    *  because after sorting we did overwrited sorted output with input so no need to return it will sort and change the array you passed to it
    *  counting sort : what the hell is this.
    *  google it : counting sort visualisation
    *  for who need link : www.cs.usfca.edu/~galles/visualization/CountingSort.html
    */
    int i;
    for(i=0;i<size;i++){
    printf("%d\n",haystack[i]);
    }
    return 0;
}
//sort function
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
    //printf("counted max from input = %d\n",max);

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

    //printing histogram for debug pourposes.
    //for(i=0;i<=max;i++){
    //printf("histogram [occurance of %d] = %d \n",i,hash[i]);
    //}

    //suming up the hash array in incriment order.
    for(i=0;i<max;i++){
    hash[i+1] = hash[i]+hash[i+1];
    }

    //printing the value of hash sum
    //for(i=0;i<=max;i++){
    //printf("hash [%d] = %d \n",i,hash[i]);
    //}
    
    //mapping the hash and applying sorting and putting data in output[].
    int tmp1,tmp2;
    for(i=n;i>=0;i--){
        tmp1 = values[i];   //picking value of input array
        tmp2 = hash[tmp1];  //looking for hash value at hash[value_from_input] position.
        hash[tmp1]=hash[tmp1]-1; //maintaing histogram.
        output[tmp2-1]=tmp1;  //going at hashvalue position (index) in output array and putting value from input array in here.
    }

    //printing output array
    //for(i=0;i< n;i++){
    //printf("input array [%d]= %d\n",i,values[i]);
    //printf("output array [%d]= %d\n",i,output[i]);
    //}

    for(i=0;i< n;i++){  //copying final output to input array so we don't need to return anyting.
    values[i]=output[i]; 
    }


}
