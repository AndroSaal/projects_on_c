#ifndef CAT_H
#define CAT_H

#ifdef __linux__
#define _GNU_SOURCE_
#endif
#define DELETE_CHARACTER 127
#define ASKII_SHIFT 64

#include <ctype.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
  bool b;
  bool e;
  bool n;
  bool s;
  bool t;
  bool v;
} flags_;

// Основные функции
int parsing_arguments(int argc, char **argv, flags_ *flags,
                      char ***files_names);
int parsing_flags(int argc, char **argv, flags_ *flags);
int parsing_file_names(int argc, char **argv, char ***files_names);
int s21_cat(char **files_names, flags_ flags, int argc);
void file_writer(FILE *file, flags_ flags);

// Обработка флагов
int s_flag_output(int *line_number, int prev_symbol, int cur_symbol,
                  flags_ flags, int *flag_to_skip_line);
void b_flag_output(int cur_symbol, int prev_symbol, int *line_number);
void n_flag_output(int prev_symbol, int *line_number);
void t_flag_output(int *cur_symbol);
void e_flag_output(int cur_symbol, int prev_symbol, flags_ flags);
void e_flag_output_for_linux(int cur_symbol);
void v_flag_output(int *cur_symbol);
void v_flag_output_for_linux(int *cur_symbol);

#endif