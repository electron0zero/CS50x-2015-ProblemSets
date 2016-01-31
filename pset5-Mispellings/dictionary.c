/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 *
 * got help from : https://github.com/Oteng/CS50-pset5-Mispellings/blob/master/dictionary.c in hash function
 *
 ***************************************************************************/
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "dictionary.h"

//size of hash table
#define SIZE 5000000  

/* node for linked list
 */
typedef struct node
{
        char word[LENGTH+1];
        struct node* next;
        
}
node;

//creating a hash table
//this is the hash table array where we will store our word and if word is already there we will do some branching to avoid collision.
node* hashtable[SIZE] = {NULL};


/**
 * hash function for calculating hash value for given word. 
 */

int hash (const char* word)
{   
    
    int hash = 0;
    int n;
    
    for (int i = 0; word[i] != '\0'; i++)
    {

        // alphabet case
        if(isalpha(word[i]))
            n = word [i] - 'A' + 1;
        
        // comma case
        else
            n = 27;
         
        hash = (hash+n)+i*27;
    }
    return hash;    
}

//global variable for counting dictionery size in size() function and we will maintain it while loading in load().
int DictSize = 0;

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{   
    //impliment load with the help of hash data structure
    
    //open dictionary file
    FILE* Dictfile = fopen(dictionary,"r");
    //perform a check that dictionary file is opened.
    if(Dictfile == NULL){
        printf("Can't open Dictionary file :-( \n");
        return false;
    }
    
    // word to store the word that we will read from file and load in dictionery.
    char word[LENGTH+1];

    // retrive words from file and load them into hash using hash() function.
    while(fscanf(Dictfile,"%s\n",word) != EOF ){
        
        //keep track of size for size().
        DictSize++;

        //malloc a new node for word.
        node* newWord = malloc(sizeof(node));

        //assign word into newWord's word
        strcpy(newWord->word, word);

        //find out hash index for hashing that word.
        int index = hash(word);

        //putting that word into hash table at index achived by hash function
        //if hash table is empty put that word there otherwise branch that word
        if(hashtable[index] == NULL){

            hashtable[index] = newWord; //adding node as a root
            newWord->next = NULL;           
        }
        else{   //while branching that word we will add that word at start of branch (at begening of link list).
            newWord->next = hashtable[index];
            hashtable[index] = newWord; //added a word in start of a linked list.
        }
        //hopefully we loaded words in dictionery  
    }
    //close the dictionery file
    fclose(Dictfile);
    
    //looks like we done here so return true and say we suceed here.
    return true;
}


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    //checks that the given word is in dictonry
   
    //let's impliment check functionality.
    char tmp[LENGTH+1];     //temperory variable to store word.
    
    int len = strlen(word);      //length of tmp.
    //converting word to lowercase word by word using tolower();.
    for(int i=0;i<len;i++){
        tmp[i] = tolower(word[i]); 
    }
    tmp[len] = '\0';

    //finding hash function index for word
    int index = hash(tmp);

    //use that index and find word at given index or in branches.
    //look at index postion if index is NULL word is not in dictionery
    if(hashtable[index] == NULL){
        return false;   //failure !!!  word not found.
    }
    
    //if above situation is not fullfill means a word is present at that position so match and find that exect word is there.
    //create a curser and scan that index and it's branches.

    node* curser = hashtable[index];

    while(curser != NULL )    //untill we reach at the end of that index and branch.
    {   
        if(strcmp(tmp,curser->word) == 0){  //if word is found in that index or branch.
            return true;
        }
        curser = curser->next;     //move curser to next position
    }
    //word not found in here so go 
    return false;
}



/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{   
    //impliment size and calculate size while loading or may be after by counting is_word flag in trie

    if(DictSize > 0){
        return DictSize;
    }
    else{
        return 0;
    }
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{   
    //frees memeory and ensure that there's no memory leaks
    int index = 0;  //set index to zero to iterate over whole hashtable.
    
    while( index < SIZE )
    {
        if(hashtable[index] == NULL){
        index++;
        }
        else
        {
            while(hashtable[index] != NULL){
            
                node* curser = hashtable[index];
                hashtable[index] = curser->next;
                free(curser);
            }
            index++;    //go tiill SIZE to empty whole hashtable.
        }
    
    }

    return true;    //we are done with free.
}
