#include "file_processing.h"

int wordfreak(int argc, char *argv[])
{
  int num_files;
  int *fds =
  fds = file_processor(argc, argv, &num_files);

  BST *word_freak = read_and_prep_input(num_files, fds);
  
  print_hashtable(word_freak);
  return 0;
}

int main(int argc, char *argv[]) 
{
  wordfreak(argc, argv);
  return 0;
}

