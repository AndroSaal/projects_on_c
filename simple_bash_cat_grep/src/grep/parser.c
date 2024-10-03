#include "parser.h"

int parser(grep_arguments* arguments, grep_flags* flags, regex_t* my_regex,
           int argc, char** argv) {
  int error = SUCCESS;

  error = get_patterns_and_flags(flags, arguments, argc, argv);
  if (error) {
    if (arguments->all_patterns_str != NULL)
      str_free(&arguments->all_patterns_str);
  }

  if (!error && !flags->e && !flags->f) {
    error = add_new_pattern(arguments, argv[optind]);
    optind++;
  }

  if (!error &&
      arguments->all_patterns_str == NULL) {  // то есть пустой файл в флаге -f
    error = 6;
  }

  if (!error)
    error = get_regex_from_patterns(
        flags, arguments, my_regex);  // в этой функции очищаются паттерны

  if (!error) error = get_files_from_argv(argv, argc, arguments);

  if (arguments->file_name_counts == 1) flags->h = true;
  return (error);
}

int get_patterns_and_flags(grep_flags* flags, grep_arguments* arguments,
                           int argc, char** argv) {
  int error = SUCCESS, opt = 0;
  while ((opt = getopt(argc, argv, "e:ivclnhsf:o")) != -1 && !error) {
    switch (opt) {
      case 'e':
        flags->e = true;
        error = add_new_pattern(arguments, optarg);
        break;
      case 'f':
        flags->f = true;
        error = get_patterns_from_file(arguments, optarg);
        break;
      case 'i':
        flags->i = true;
        break;
      case 'v':
        flags->v = true;
        break;
      case 'c':
        flags->c = true;
        break;
      case 'l':
        flags->l = true;
        break;
      case 'n':
        flags->n = true;
        break;
      case 'h':
        flags->h = true;
        break;
      case 's':
        flags->s = true;
        break;
      case 'o':
        flags->o = true;
        break;
      case '?':
        error = PARS_ERROR;
        break;
      case ':':
        error = PARS_ERROR;
        break;
      default:
        break;
    }
  }
  return error;
}

int add_new_pattern(grep_arguments* arguments, const char* new_pattern) {
  int error = SUCCESS;
  int n = strlen(new_pattern);
  if (arguments->len_pattern == 0) {
    arguments->all_patterns_str = calloc(1024, sizeof(char));
    if (!arguments->all_patterns_str) error = MEM_ERROR;
    arguments->mem_pattern = 1024;
  }
  if (arguments->mem_pattern < arguments->len_pattern + n) {
    char* buff = NULL;
    buff = arguments->all_patterns_str;
    arguments->all_patterns_str =
        realloc(arguments->all_patterns_str, arguments->mem_pattern * 5);
    if (!arguments->all_patterns_str) {
      free(buff);
      error = MEM_ERROR;
    }
  }
  if (arguments->len_pattern != 0) {
    strcat(arguments->all_patterns_str + arguments->len_pattern, "|");
    arguments->len_pattern++;
  }
  arguments->len_pattern +=
      sprintf(arguments->all_patterns_str + arguments->len_pattern, "(%s)",
              new_pattern);
  return error;
}

int get_patterns_from_file(grep_arguments* arguments, char* file_name) {
  int error = SUCCESS;
  size_t n = 0;
  char* str_from_file = NULL;
  FILE* fd = fopen(file_name, "r");
  if (!fd) {
    error = FILE_ERROR;
    fprintf(stderr, "s21_grep: %s: No such file or directory\n", file_name);
  } else {
    while (getline(&str_from_file, &n, fd) != -1) {
      if (str_from_file) {
        str_from_file[strcspn(str_from_file, "\n")] =
            '\0';  // Заменяет \n на \0 в str_from_file
        error = add_new_pattern(arguments, str_from_file);
      } else {
        break;
      }
    }
    if (str_from_file != NULL) str_free(&str_from_file);
    fclose(fd);
  }
  return error;
}

void str_free(char** str) {
  free(*str);
  *str = NULL;
}

int get_regex_from_patterns(grep_flags* flags, grep_arguments* arguments,
                            regex_t* my_regex) {
  int error = SUCCESS;
  int cflags = flags->i ? REG_EXTENDED | REG_ICASE : REG_EXTENDED;
  // fprintf(stderr, "PATTERN IS %s\n", arguments->all_patterns_str);
  error = regcomp(my_regex, arguments->all_patterns_str, cflags);
  if (error) {
    fprintf(stderr, "troubles with regcomp\n");
    str_free(&arguments->all_patterns_str);
    exit(1);
  }
  str_free(&arguments->all_patterns_str);

  return error;
}

int get_files_from_argv(char** argv, int argc, grep_arguments* arguments) {
  int error = SUCCESS;

  arguments->file_name_counts = argc - optind;
  if (arguments->file_name_counts) {
    arguments->files_names =
        (char**)malloc(sizeof(char*) * (arguments->file_name_counts));
    if (!arguments->files_names) {
      error = MEM_ERROR;
    } else {
      int file_name_index = 0;
      for (int i = optind; i < argc; i++) {
        arguments->files_names[file_name_index] = argv[i];
        file_name_index++;
      }
    }
  }
  return error;
}