#ifndef OUTPUT_H
#define OUTPUT_H

#include "main.h"

void work_with_file(FILE *file, grep_flags flags, char *file_name,
                    regex_t my_regex);
void o_flag_handle(regex_t *my_regex, grep_flags flags, char *str_from_file,
                   char *file_name, int line_counter);

#endif