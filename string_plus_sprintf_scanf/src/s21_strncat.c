#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  char *d = dest;
  while (*d != '\0') {
    d++;
  }

  while (i < n && src[i] != '\0') {
    d[i] = src[i];
    i++;
  }
  if (*(d + i) == 0) d[i] = '\0';

  return dest;
}
