#include "output.h"

int output(grep_arguments *arguments, grep_flags flags, regex_t *my_regex) {
  int error = SUCCESS;
  FILE *fd = NULL;
  if (!arguments->file_name_counts)
    work_with_file(stdin, flags, "", *my_regex);
  else {
    for (int i = 0; i < arguments->file_name_counts; i++) {
      fd = fopen(arguments->files_names[i], "r");
      if (!fd) {
        error = FILE_ERROR;
        if (!flags.s)
          fprintf(stderr, "s21_grep: %s: No such file or directory\n",
                  arguments->files_names[i]);
        continue;
      } else {
        work_with_file(fd, flags, arguments->files_names[i], *my_regex);
        fclose(fd);
      }
    }
    free(arguments->files_names);
  }
  regfree(my_regex);
  return error;
}

void work_with_file(FILE *file, grep_flags flags, char *file_name,
                    regex_t my_regex) {
  size_t n = 0;
  int match_counter = 0, line_counter = 0, match = 0;
  char *str_from_file = NULL;
  while ((getline(&str_from_file, &n, file)) != -1) {
    line_counter++;
    match = !regexec(&my_regex, str_from_file, 0, NULL, 0);
    if ((match && !flags.v) || (!match && flags.v)) {
      match_counter++;
      if (!flags.c && !flags.l &&
          ((flags.v && flags.o) || (flags.v && !flags.o) ||
           (!flags.v && !flags.o))) {
        if (!flags.h && strlen(file_name)) printf("%s:", file_name);
        if (flags.n) printf("%d:", line_counter);
        printf("%s", str_from_file);
        if (strchr(str_from_file, '\n') == NULL) printf("\n");
      }
      if (flags.o && !flags.v && !flags.c && !flags.l) {
        o_flag_handle(&my_regex, flags, str_from_file, file_name, line_counter);
      }
    }
    if (str_from_file) {
      free(str_from_file);
      str_from_file = NULL;
    }
  }
  if (str_from_file) free(str_from_file);
  if ((flags.c && !flags.l) || (!flags.c && flags.l)) {
    if (!flags.h &&
        ((flags.l && match_counter) || (flags.c && match_counter))) {
      printf("%s", file_name);
      if (!flags.c)
        printf("\n");
      else
        printf(": ");
    } else if (flags.l && match_counter)
      printf("%s\n", file_name);
    if (flags.c) printf("%d\n", match_counter);
  } else if (flags.c && flags.l) {
    if (!flags.h) printf("%s: ", file_name);
    match_counter ? printf("1\n") : printf("0\n");
    if (match_counter) printf("%s\n", file_name);
  }
}

void o_flag_handle(regex_t *my_regex, grep_flags flags, char *str_from_file,
                   char *file_name, int line_counter) {
  regmatch_t match;
  int offset = 0;

  while (regexec(my_regex, str_from_file + offset, 1, &match, 0) == 0) {
    if (!flags.h) printf("%s:", file_name);
    if (flags.n) printf("%d:", line_counter);
    for (int i = match.rm_so; i < match.rm_eo; i++) {
      printf("%c", str_from_file[i + offset]);
      if (i == match.rm_eo - 1) printf("\n");
    }
    offset += match.rm_eo;
  }
}