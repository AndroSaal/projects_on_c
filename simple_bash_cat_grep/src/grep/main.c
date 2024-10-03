#include "main.h"

int main(int argc, char** argv) {
  int error = 0;

  grep_flags flags = {false, false, false, false, false,
                      false, false, false, false, false};
  grep_arguments arguments = {NULL, 0, NULL, 0, 0};
  regex_t my_regex = {0};

  if (argc == 1)
    print_usage();
  else if ((error = parser(&arguments, &flags, &my_regex, argc, argv)))
    printf_error_massage(error);
  else if ((error = output(&arguments, flags, &my_regex)))
    printf_error_massage(error);

  return error;
}

void printf_error_massage(int error) {
  switch (error) {
    case (MEM_ERROR):
      fprintf(stderr, "MEMORY ALLOCATION ERROR!\n");
      break;
    case (PARS_ERROR):
      fprintf(stderr, "PARSING ERROR!\n");
      break;
    case (REGEX_ERROR):
      fprintf(stderr, "REGEX COMPILATION ERROR!\n");
      break;
    case (ARG_ERROR):
      fprintf(stderr, "WRONG QUALITY OF ARGUMENTS!\n");
      break;
    case (EMPTY_FILE_AT_F_FLAG):
      fprintf(stderr, "GOT EMPTY FILE AS PATTERNS-FILE\n");
    default:
      break;
  }
}

void print_usage(void) {
  printf(
      "usage: grep [-abcdDEFGHhIiJLlMmnOopqRSsUVvwXxZz] [-A num] [-B num] "
      "[-C[num]]\n");
  printf("\t[-e pattern] [-f file] [--binary-files=value] [--color=when]\n");
  printf(
      "\t[--context[=num]] [--directories=action] [--label] "
      "[--line-buffered]\n");
  printf("\t[--null] [pattern] [file ...]");
}