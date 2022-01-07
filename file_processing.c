#include "file_processing.h"

int *open_file_descriptors(int num_files_inList, char **file_name)
{
  int *file_directories = calloc(num_files_inList, sizeof(int));
  
  if(file_directories == ERROR_ALLOCATING)
  {
    perror("ERROR ALLOCATING");
    // exit(EXIT_FAILURE);
  }
  for(int i = 0; i < num_files_inList; i++)
  {
    char path[PATH_SIZE] = "";    

    strcat(path, file_name[i]);

    if((file_directories[i] = open(path, O_RDONLY)) == ERROR_OPENING)
    {
      perror("ERROR OPENING");
      return NULL;
    }
  }
  return file_directories;
}

int *file_processor(int argc, char *argv[], int *num_files)
{
  int *file_directories;
  char *word = getenv("WORD_FREAK");

  if(word != NULL)
  {
    file_directories = open_file_descriptors((*num_files = 1), &word);
    if(file_directories == NULL)
    {
      perror("EMPTY FILE DESCRIPTOR: ");
      //exit(EXIT_FAILURE);
    }
  }
  else if(argc > 1)
  {
    file_directories = open_file_descriptors(argc - 1, argv + 1);
    if(file_directories == NULL)
    {
      perror("EMPTY FILE DESCRIPTOR: ");
      // // exit(EXIT_FAILURE);
    }
    *num_files = argc - 1; 
  }
  else if(argc == 1)
  {
    file_directories = malloc(sizeof(int));
    if(file_directories == ERROR_ALLOCATING)
    {
      perror("ERROR ALLOCATING: ");
    }
    file_directories[0] = STDIN_FILENO;
    *num_files = 1;
  }
  return file_directories;
}