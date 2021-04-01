// Implements a dictionary's functionality

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

#include "dictionary.h"


typedef struct node
{
    //End of word
    bool is_word;

    // Pointers
    struct node *children[27];
}
node;

struct node *newNode(void)
{
    // Malloc
    struct node *p_node = NULL;
    p_node = (struct node *) malloc(sizeof(struct node));

    if (p_node != NULL)
    {
        p_node->is_word = false;

       
        for (int i = 0; i < 27; i++)
        {
            p_node->children[i] = NULL;
        }
    }
    return p_node;
}

node *root_node;
int word_count = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int len = strlen(word);
    int index = 0;

    //Pointer
    node *parent = root_node;


    for (int i = 0; i < len; i++)
    {
        if (word[i] == '\'')
        {
            // Index for '\''
            index = 26;
            if (parent->children[index] == NULL)
            {
                // If NULL
                return false;
            }
            else
            {
                parent = parent->children[index];
            }
        }
        else 
        {
            // Lower
            if (parent->children[tolower(word[i]) - 'a'] == NULL)
            {
                return false;
            }
            else
            {
                //Children
                parent = parent->children[tolower(word[i]) - 'a'];
            }
        }
    }

    // Word Found
    if (parent->is_word)
    {
        return true;
    }

    // Word not found
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open File
    FILE *inptr = fopen(dictionary, "r");

    // Check
    if (inptr == NULL)
    {
        fprintf(stderr, "93. Could not open %s.\n", dictionary);
        return 2;
    }

    // Set a pointer 
    root_node = newNode();
    char word[47];

    // Read 
    while (fgets(word, sizeof(word), inptr) != NULL)
    {
        int index = 0;
        // Pointer to root
        node *parent = root_node;
        while (word[index] != '\n')
        {

            // Tolower
            if (word[index] == '\'')
            {
                // Check the value
                if (parent->children[26] == NULL)
                {
                    //Mallo new node
                    parent->children[26] = newNode();
                }
                // Children to pointer
                parent = parent->children[26];
            }
            else
            {
                if (parent->children[word[index] - 'a'] == NULL)
                {
                    parent->children[word[index] - 'a'] = newNode();
                }
                parent = parent->children[word[index] - 'a'];
            }
            index++;
        }
        // End of word
        parent->is_word = true;
        word_count++;
    }
    fclose(inptr);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Deletes trie from the bottom up
void delete_node(node *a_node)
{
    if (!a_node)
    {
        return;
    }

    // Lowest Node
    for (int i = 0; i < 27; i++)
    {
        // Free
        delete_node(a_node->children[i]);
    }

    // Free
    free(a_node);
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    delete_node(root_node);
    return true;
}