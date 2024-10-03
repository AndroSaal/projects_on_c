#ifndef PARSER_H
#define PARSER_H

#include "main.h"

int get_patterns_and_flags(grep_flags* flags, grep_arguments* arguments,
                           int argc, char** argv);
int add_new_pattern(grep_arguments* arguments, const char* new_pattern);
void string_cat(char* all_patterns_str, const char* new_pattern, int size_old,
                int size_new);
int get_patterns_from_file(grep_arguments* arguments, char* file_name);
void str_free(char** str);
int get_regex_from_patterns(grep_flags* flags, grep_arguments* arguments,
                            regex_t* my_regex);
int get_files_from_argv(char** argv, int argc, grep_arguments* arguments);

#endif