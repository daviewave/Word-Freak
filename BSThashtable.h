#include "defInclude.h"
#ifndef BST_H
#define BST_H

typedef struct BST_nodes
{
  struct BST_nodes *left, *right;
  char *key;  
  int word_frequency;
  int value;
}BST_node;

typedef struct BST_
{
  BST_node *root;      //Pointing to the root of a BST
}BST;

/*Initializes each BST's root on the hashtable to NULL*/
BST* initialize_hashtable();

/*Displays the content of a BST with a particular index*/
void print_BST(BST_node *tree);                      //Probably DOnt need in final project

// /*Displays all the BSTs in the hashtable*/
void print_hashtable(BST *hashtable);                  //Probably DOnt need in final project

/*  This assigns an INDEX(!) to which BST to add the given word
to based the first letter of the word in the node   */
int hash_firstLetter(char *key);

/*searches for the given key in the given BST*/
/*Returns NULL if the word is not already there*/
BST_node* search_BST(BST_node *tree, char *key);

/*Functions similary to search in that is recursively searches a BST but in
this case it should return the node just above or below it */
void insert_node(BST_node *tree, BST_node *toAdd, BST* hashtable);

/*Inserts a newly created node into 1 of 26 BSTs based on the hashcode*/
void create_and_insert_node(BST *hashtable, char *word);

/*Frees memory that was allocated for BST nodes that was unused*/
void free_BSTnode(BST_node *tree);

/*Frees memory that was allocated for ALL BSTs that was unused and the array of BSTs*/
void free_BST_hashtable(BST *hashtable);

#endif