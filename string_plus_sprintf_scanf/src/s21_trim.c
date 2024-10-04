#include "s21_string.h"

int startwith(const char *src, const char *totrim, int offset) {
  int res = 0;
  s21_size_t size = s21_strlen(totrim);
  for (s21_size_t i = 0; i < size; i++) {
    if (src[offset] == totrim[i]) res = 1;
  }
  return res;
}

int endwith(const char *src, const char *totrim, int offset) {
  int res = 0;
  offset--;
  s21_size_t size = s21_strlen(totrim);
  for (s21_size_t i = 0; i < size; i++) {
    if (src[offset] == totrim[i]) res = 1;
  }
  return res;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *newstr = s21_NULL;
  if (src) {
    if (trim_chars && trim_chars[0]) {
      newstr = calloc(s21_strlen(src) + 1, 1);
      s21_size_t start = 0, end = s21_strlen(src);
      while (startwith(src, trim_chars, start)) {
        start++;
      }
      if (start != end) {
        while (endwith(src, trim_chars, end)) end--;
      } else {
        newstr[0] = '\0';
      }
      for (int i = 0; start < end; i++) {
        newstr[i] = src[start];
        start++;
      }
    } else {
      newstr = s21_trim(src, "\t\n ");
    }
  }
  return newstr;
}