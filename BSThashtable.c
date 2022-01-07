#include "BSThashtable.h"

BST* initialize_hashtable()
{
  BST* hashtable = (BST*)malloc(sizeof(BST_node*) * HASHTABLE_SIZE);

  for(int i = 0; i < HASHTABLE_SIZE; ++i)
  {
    hashtable[i].root = NULL;
  }
  return hashtable;
}

void print_BST(BST_node *tree_root)
{
  if(tree_root == NULL)
  {
    return;
  }
  char line_size[LETTERS_PER_LINE] = "";
  sprintf(line_size, "%-45s|%10i\n", tree_root->key, tree_root->word_frequency);
  int write_output = write(STDOUT, line_size, LETTERS_PER_LINE);
  if(write_output == ERROR_WRITING)
  {
    perror("ERROR WRITING ");
  }

  if(tree_root->left != NULL)
  {
    print_BST(tree_root->left);
  }
  if(tree_root->right != NULL)
  {
    print_BST(tree_root->right);
  }
}

void print_hashtable(BST *hashtable)
{
  for(int i = 0; i < HASHTABLE_SIZE; ++i)
  {
    BST_node *current_tree = hashtable[i].root;
    if(current_tree != NULL)
    {
      print_BST(hashtable[i].root);
    }
  }
}

int hash_firstLetter(char *key)
{
  int first_letter = key[0];
  int count = 0;
  for(int i = 97; count < HASHTABLE_SIZE; ++i)
  {
    if(first_letter == i)
    {
      return i - 97;
    }
    count++;
  }
  return -1; //Not a lowercase letter --- marks the end of whats considered a word 
}

 BST_node* search_BST(BST_node *tree, char *key)
{
  if(tree == NULL) //Technically dont need this right now atleast because it checks a different way in insertion
  {
    return NULL; //BST does not contain any words
  }
  if(strcmp(key, tree->key) == 0)
  {
    tree->value = -10;
    return tree; //The BST contains the searched word
  }

  else if(strcmp(key, tree->key) > 0 )  //if the ascii value of key is greater than (lower in alphabetical order) check if the left node is null and if its not then recursively search to the left
  {
    if(tree->left != NULL)
    {
      return search_BST(tree->left, key);
    }
    else
    {
      return tree;
    } 
  }
  else      //if the ascii value of key is less than (first in alphabetical order) check if the right node is null and if its not then recursively search to the left
  {
    if(tree->right != NULL)
    {
      return search_BST(tree->right, key);
    }
    else
    {
      return tree;
    }
  }
  return NULL; 
}

void insert_node(BST_node *tree, BST_node *toAdd, BST* hashtable)
{
  if(strcmp(toAdd->key, tree->key) > 0)  /*word is after curr alphabetically -- search to the left if the left node is not NULL */
  {
    if(tree->left == NULL)   //Lowest rank alphabetically (to the left) so it inserted there
    {
      tree->left = toAdd;
      return;
    }
    else
    {
      insert_node(tree->left, toAdd, hashtable);
    }
  } 
  else
  {
    if(tree->right == NULL) //Highest rank alphabetically (to the right) so its inserted here
    {
       tree->right = toAdd;
       return;
    }
    else
    {
      return insert_node(tree->right, toAdd, hashtable);
    }
  }
}

void create_and_insert_node(BST *hashtable, char *word)
{
  int hashcode = hash_firstLetter(word);
  BST_node *check_tree = (BST_node*) hashtable[hashcode].root;

  /* CASE 1: BST for that letter already contains words*/
  /* Need to search that tree to see if the same word  */
  /* has already been added to that BST                */
  BST_node *tree_results = search_BST(check_tree, word);
  
  if(tree_results != NULL && tree_results->value == -10)
  {
    tree_results->value = 0;
    tree_results->word_frequency++; //Word already exists on the BST so word frequency is increased
    return;
  }

  /*Creates new node and allocates space because its now known this is a word that hasnt been seen yet*/
  /*initializes new node's   feilds*/
  BST_node *new_node = (BST_node*)malloc(sizeof(BST_node));
  new_node->key = (char*)malloc(sizeof(MAX_LETTERS_IN_WORD));

  //new_node->key = (char*)malloc(MAX_LETTERS_IN_WORD);

  new_node->left = NULL;
  new_node->right = NULL;
  strcpy(new_node->key, word);
  new_node->word_frequency = 1;
  
  
  /*CASE 2: BST for the given word does not contain any elements yet*/
  if(check_tree == NULL)
  {
    /*Because this BST is empty, make new node the root*/
    hashtable[hashcode].root = new_node;
    return;
  }
  else
  {
    insert_node(check_tree, new_node, hashtable);
  }
  //CASE 3: (else statement just above)       
  /*Now we known that the BST that was hashed is not NULL at the root (contains words already) and
    it does not already contain the same word that was passed in*/
  /*Need to determine its place within that tree and insert it alphabetically*/
  /*calls function above so it can recursively check to see where it belongs within the BST*/  
}

void free_BSTnode(BST_node *tree)
{
  if(tree == NULL)
  {
    return;
  }
    free_BSTnode(&(*tree->left));
    free_BSTnode(&(*tree->right));
    free(&tree->key);
    free(&(*tree));
    tree = NULL;  
}

void free_BST_hashtable(BST *hashtable)
{
  for(int i = 0; i < HASHTABLE_SIZE; ++i)
  {
    BST_node *cur_tree = hashtable[i].root;
    free_BSTnode(cur_tree);
  }
  free(hashtable);
}