#include "./cat.h"
#define _POSIX_C_SOURCE 200809L

int main(int argc, char **argv) {
  int success_status = 1;
  flags_ flags = {false, false, false, false, false, false};
  char **files_names = NULL;
  if (!parsing_arguments(argc, argv, &flags, &files_names))
    success_status = 0;
  else if (!s21_cat(files_names, flags, argc) && success_status)
    success_status = 0;
  if (files_names != NULL) free(files_names);
  return success_status;
}

int parsing_arguments(int argc, char **argv, flags_ *flags,
                      char ***files_names) {
  int success_status = 1;
  if (!parsing_flags(argc, argv, flags)) {
    success_status = 0;
    fprintf(stderr, "usage: cat [-belnstuv] [file ...]\n");
  } else if (!parsing_file_names(argc, argv, files_names)) {
    success_status = 0;
    fprintf(stderr, "troubles with memory allocation!\n success_status = %d\n",
            success_status);
  }
  return success_status;
}

int parsing_flags(int argc, char **argv, flags_ *flags) {
  int opt_code;
  int success_status = 1;
  struct option long_options[] = {{"number-nonblank", 0, 0, 'b'},
                                  {"number", 0, 0, 'n'},
                                  {"squeeze-blank", 0, 0, 's'},
                                  {0, 0, 0, 0}};
  while ((opt_code = getopt_long(argc, argv, "beEnstTv", long_options, 0)) !=
             -1 &&
         success_status) {
    switch (opt_code) {
      case 'b':
        flags->b = true;
        flags->n = true;
        break;
      case 'e':
        flags->e = true;
        flags->v = true;
        break;
      case 'E':
        flags->e = true;
        break;
      case 'n':
        flags->n = true;
        break;
      case 's':
        flags->s = true;
        break;
      case 't':
        flags->t = true;
        flags->v = true;
        break;
      case 'T':
        flags->t = true;
        break;
      case 'v':
        flags->v = true;
        break;
      case '?':
        success_status = 0;
        break;
      default:
        break;
    }
  }
  return success_status;
}

int parsing_file_names(int argc, char **argv, char ***files_names) {
  int file_name_index = 0;
  int success_status = 1;
  if ((argc - optind) != 0) {
    *files_names = (char **)malloc(sizeof(char *) * (argc - optind));
    if (!files_names) success_status = 0;
    if (success_status) {
      file_name_index = 0;
      for (int i = optind; i < argc; i++) {
        (*files_names)[file_name_index] = argv[i];
        file_name_index++;
      }
    }
  }
  return success_status;
}

int s21_cat(char **files_names, flags_ flags, int argc) {
  int success_status = 1;
  FILE *file = NULL;
  if (argc - optind == 0) {
    file_writer(stdin, flags);
  } else {
    for (int i = 0; i < argc - optind; i++) {
      if ((file = fopen(files_names[i], "r")) != NULL) {
        file_writer(file, flags);
      } else {
        success_status = 0;
        fprintf(stderr, "s21_cat %s: No such file or directory\n",
                files_names[i]);
      }
    }
  }
  return success_status;
}

void file_writer(FILE *file, flags_ flags) {
  int cur_symbol, prev_symbol = '\n';
  int line_number = 0;
  int flag_to_skip_line = 0;
  while ((cur_symbol = getc(file)) != EOF) {
    if (flags.s) {
      if (s_flag_output(&line_number, prev_symbol, cur_symbol, flags,
                        &flag_to_skip_line))
        continue;
    }
    if (flags.b) {
      b_flag_output(cur_symbol, prev_symbol, &line_number);
    }
    if (flags.n && !flags.b && !flag_to_skip_line) {
      n_flag_output(prev_symbol, &line_number);
    }
    if (flags.t) {
      t_flag_output(&cur_symbol);
    }
    if (flags.e) {
#ifdef __APPLE__
      e_flag_output(cur_symbol, prev_symbol, flags);
#endif
#ifdef __linux__
      e_flag_output_for_linux(cur_symbol);
#endif
    }
    if (flags.v) {
#ifdef __APPLE__
      v_flag_output(&cur_symbol);
#endif
#ifdef __linux__
      v_flag_output_for_linux(&cur_symbol);
#endif
    }
    putchar(cur_symbol);
    prev_symbol = cur_symbol;
  }
  if (file != stdin) fclose(file);
}

int s_flag_output(int *line_number, int prev_symbol, int cur_symbol,
                  flags_ flags, int *flag_to_skip_line) {
  int continue_ = 0;
  if (prev_symbol == '\n' && cur_symbol == '\n' && *flag_to_skip_line) {
    continue_ = 1;
  } else if (prev_symbol == '\n' && cur_symbol == '\n' &&
             !(*flag_to_skip_line)) {  // первая строчка, которую нужно оставить
    *flag_to_skip_line = 1;
    if (flags.n && !flags.b)
      printf("%6d\t", ++(*line_number));  // некий
                                          // костыль
  } else if (cur_symbol != '\n') {
    *flag_to_skip_line = 0;
  }
  return continue_;
}

void b_flag_output(int cur_symbol, int prev_symbol, int *line_number) {
  if (prev_symbol == '\n' && cur_symbol != '\n')
    printf("%6d\t", ++(*line_number));
}

void n_flag_output(int prev_symbol, int *line_number) {
  if (prev_symbol == '\n') printf("%6d\t", ++(*line_number));
}

void t_flag_output(int *cur_symbol) {
  if (*cur_symbol == '\t') {
    putchar('^');
    *cur_symbol = 'I';
  }
}

void e_flag_output(int cur_symbol, int prev_symbol, flags_ flags) {
  if (cur_symbol == '\n') {
    if (flags.b && prev_symbol == '\n') {
      printf("%7c", '\t');
      putchar('$');
    } else {
      putchar('$');
    }
  }
}

void e_flag_output_for_linux(int cur_symbol) {
  if (cur_symbol == '\n') {
    putchar('$');
  }
}

void v_flag_output(int *cur_symbol) {
  if ((*cur_symbol < ' ' && *cur_symbol >= 0) && *cur_symbol != '\t' &&
      *cur_symbol != '\n') {
    putchar('^');
    *cur_symbol += ASKII_SHIFT;
  } else if (*cur_symbol == DELETE_CHARACTER) {
    putchar('^');
    *cur_symbol = '?';
  } else if (*cur_symbol > DELETE_CHARACTER) {
    if (iscntrl(
            *cur_symbol -
            (DELETE_CHARACTER +
             1))) {  // проверяем, попадаем ли в диапазон управляющих символов
      *cur_symbol -= DELETE_CHARACTER + 1;
      putchar('M');
      putchar('-');
      putchar('^');
      *cur_symbol += ASKII_SHIFT;
    }
  }
}

void v_flag_output_for_linux(int *cur_symbol) {
  if (*cur_symbol == DELETE_CHARACTER) {
    putchar('^');
    *cur_symbol = '?';
  }
  if (*cur_symbol != '\t' && *cur_symbol != '\n') {
    if (*cur_symbol > DELETE_CHARACTER) {
      *cur_symbol -= DELETE_CHARACTER + 1;
      putchar('M');
      putchar('-');
    }
    if (*cur_symbol < ' ') {
      putchar('^');
      *cur_symbol += ASKII_SHIFT;
    }
  }
}