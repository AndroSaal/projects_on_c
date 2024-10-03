#ifndef MAIN_GREP_H
#define MAIN_GREP_H

#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L

#define SUCCESS 0
#define MEM_ERROR 1
#define PARS_ERROR 2
#define REGEX_ERROR 3
#define FILE_ERROR 4
#define ARG_ERROR 5
#define EMPTY_FILE_AT_F_FLAG 6

#include <ctype.h>
#include <getopt.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
  bool e;
  bool i;
  bool v;
  bool c;
  bool l;
  bool n;
  bool h;
  bool s;
  bool f;
  bool o;
} grep_flags;

typedef struct {
  char** files_names;
  int file_name_counts;
  char* all_patterns_str;
  int len_pattern;
  int mem_pattern;
} grep_arguments;

int output(grep_arguments* arguments, grep_flags flags, regex_t* my_regex);
int parser(grep_arguments* arguments, grep_flags* flags, regex_t* my_regex,
           int argc, char** argv);
void print_usage(void);
void printf_error_massage(int error);

#endif