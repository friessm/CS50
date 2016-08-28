/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

#define ALPHABET_SIZE 27

/**
 * Defining structs, variables and function prototypes
 */

// trie node
typedef struct trie
{
    bool is_word;
    struct trie* children[ALPHABET_SIZE];
}
node_t;

// initialise root node (pointer)
node_t* node;

// initialise the node (pointer) that moves through the trie
node_t* current;

// initialise counter for check function
unsigned int counter = 0;

// unloader function that gets called inside of the unload function
bool unload_helper(node_t* node);


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // capital and non-capital letters have to be handled equally
    // both have to be true
    
    // root node
    node_t* current = node;
    
    int child;
    int index = 0;

    // iterate until the last char of the word
    while (word[index] != '\0')
    {
        if (isalpha(word[index]))
        {
            // if letter is upper-case
            if (isupper(word[index]))
            {
                child = (word[index] - 'A');
            }
            
            // if letter is lower-case
            else
            {
                child = (word[index] - 'a');
            }
        }

        // if neither lower nor upper case letter it has to be an apostrophe
        else
        {
            child = 26;
        }
        
        // increment char index by 1
        index++;

        // check if the next letter is in the trie tree
        if (current->children[child] == NULL)
        {
            return false;
        }
            
        // if not in the trie tree
        else
        {
            // traverse to the next node
            current = current->children[child];
        }    
    }
    
    // if iterated through word without returning false AND is_word is true
    if (current->is_word == true)
    {
        current = node;
        return true;
    }
    
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // allocate memory to the root pointer node
    // calloc sets all children to NULL by default
    node = calloc(1, sizeof(node_t));
    
    // address as the root node
    current = node;
    
    int letter;

    // open dictionary
    FILE* dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        fclose(dict);
        return false;
    }
    
    // iterate over the file
    while (fgetc(dict) != EOF)
    {
        // set file position indicator one position back
        fseek(dict, -1, SEEK_CUR);
        
        // iterate over the word from the dictionary letter by letter
        for (int c = fgetc(dict); c != '\n' && c != EOF; c = fgetc(dict))
        {
            letter = c;
                
            if (isalpha(letter))
            {
                // if letter is upper-case
                if (islower(letter))
                {
                    letter = (letter - 'a');
                }
            }
            
            // if neither lower nor upper case letter it has to be an apostrophe
            else
            {
                letter = 26;
            }
            
            
            // is there already a sub-node?
            if (current->children[letter] != NULL)
            {
                // traverse to sub-node
                current = current->children[letter];
            }
    
            // create a new sub-node
            else
            {
                // dynamically allocate memory to address where pointer points to
                current->children[letter] = calloc(1, sizeof(node_t));

                // traverse to newly created sub-node
                current = current->children[letter]; 
            }
        }
        // end of word reached, set boolean to true
        current->is_word = true;
        
        // increment counter by one;
        counter++;
        
        // current should point at the root node again, so we can start from
        // the root node when implementing the next word
        current = node;
    }
    
    // close file
    fclose(dict);
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // dereference pointer and return the amount of words stored in the trie
    //if (l!oad)
    return counter;
    
    // return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    if (unload_helper(node) == true)
        return true;
    
    return false;
}

/**
 * Recursive function for freeing the nodes of the trie recursively
 */ 
bool unload_helper(node_t* node)
{
    // check if node is a NULL-pointer
    if (node == NULL)
        return false;
    
    // use recursion for freeing the memory
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        // if the child is not NULL go to next node, otherwise iterate to next child
        if (node->children[i] !=NULL)
        {
            unload_helper(node->children[i]);
        }
    }
    // free the current node; only if all children are filled with NULL values
    free(node);
    
    return true;
}
