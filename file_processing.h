#include "prepInput.h"

#ifndef FILE_PROCESSING_H
#define FILE_PROCESSING_H

int *open_file_descriptors(int num_files_inList, char **file_list);

int *file_processor(int argc, char *argv[], int *num_files);

#endif