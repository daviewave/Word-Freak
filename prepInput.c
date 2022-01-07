#include "prepInput.h"

BST *read_and_prep_input(int total_files, int *fd)
{
  BST *wordfreak = initialize_hashtable();

  int read_file = 0; //num_read
  int buffer = 0; //Buffer counter
  char word_buffer[BUFFER] = "\0"; //word[BUFF_SIZE]
  char word_holder[MAX_LETTERS_IN_WORD] = "";
  int last_word = 0;

  for(int file_num = 0; file_num < total_files + 1; ++file_num)
  {
    read_file = read(fd[file_num], word_buffer, BUFFER);
    if(read_file == ERROR_READING)
    {
      perror("ERROR READING: ");
      // exit(EXIT_FAILURE);
    }
    
    //Determines if the end of the file as reached before reaching the Max BUFFER
    if(read_file < BUFFER)
    {
      int close_file = close(fd[file_num]);
      if(close_file == ERROR_CLOSING)
      {
        perror("ERROR CLOSING: ");
        // exit(EXIT_FAILURE);
      }
      file_num++;
    }

    int word_cur_char = 0;   //Counts the current character of the words
    for(int cur_char = 0; cur_char < read_file; ++cur_char)
    {
      if(IS_LETTER(word_buffer[cur_char]))
      {
        word_holder[word_cur_char++] = tolower(word_buffer[cur_char]);
      }
      else if(IS_WHITESPACE(word_buffer[cur_char]))
      {
        if(strcmp(word_holder, "") != 0)
        {
          word_holder[word_cur_char] = '\0';
          word_cur_char = 0;
          create_and_insert_node(wordfreak, word_holder);
          word_holder[0] = '\0';
        }
      }
    }

    if(last_word < file_num && strcmp(word_holder, "") != 0)
    {
      word_holder[word_cur_char] = '\0';
      create_and_insert_node(wordfreak, word_holder);
      file_num++;
    }
  }
  free(fd);
  return wordfreak;
}

