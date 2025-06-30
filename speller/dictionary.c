// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

// Buffer constant
const unsigned int B = 46;

// Create hash_size variable to track hash size, set to zero, call in "size" fxn.
unsigned int hash_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Hash word using fxn
    unsigned int hash_value = hash(word);

    // create a cursor pointer to a node
    node *cursor = NULL;

    // set cursor pointer to appropriate hash table bucket
    cursor = table[hash_value];

    //Return true if word is found
    while (cursor != NULL)
    {
        if(strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
    cursor = cursor->next;

    }
    return false;

}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int n = strlen(word);
    int upper_index = 0;
    int buffer[n];

    int first = 0;
    int last = 0;
    int middle = 0;

    for (int i = 0; i < n; i++)
    {
        if (!isalpha(word[i]))
        {
            continue;
        }
        else
        {
            buffer[upper_index] = toupper(word[i]);
            upper_index++;
        }
    }

    first = buffer[0] - 'A';
    last = buffer[upper_index - 1] - 'A';
    middle = buffer[upper_index / 2] - 'A';

    unsigned int pre_hash = (26 * 26 * first + (26 * middle) + last) * 37 + (upper_index); // 37 Prime multiplyer

    unsigned int hash = (pre_hash) % N; // 3 scaling factor
    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Initalize hash table and set pointer to NULL
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // Open dictionary
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }
    // Create buffer array for word(below)
    char buffer[B];

    // Read through dic strings
    while(fscanf(source, "%s", buffer) != EOF)
    {
        // Create new node for each word
        node *n = malloc(sizeof (struct node));
        // Check malloc success
        if (n == NULL)
        {
            return false;
        }

        // valorize n-> word
        strcpy(n->word, buffer);

        //set n-> next to NULL
        n->next = NULL;

        // # fxn above

        //valorize table.next -> n
        if (table[hash(buffer)] == NULL)
        {
            table[hash(buffer)] = n;
        }
        // valorize n->next to table[hash]
        else
        {
            n->next = table[hash(buffer)];
            table[hash(buffer)] = n;
        }

        hash_size++;
    }
    //close dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return hash_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    //create cursor and temp pointer that point to node
    node *cursor = NULL;
    node *tmp = NULL;

    // Iterate through the hash table
    for (int i = 0; i < N; i++)
    {
        //Set cursor and temp to table[i]
        cursor = table[i];

        // Traverse each node until cursor is NULL and free tmp
        while (cursor != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }

    return true;
}
