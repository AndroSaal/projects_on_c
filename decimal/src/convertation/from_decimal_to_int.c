#include "s21_convertation.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int err = 0;
  if (!s21_check(src) && dst != NULL) {
    int scale = 0;
    *dst = 0;
    long int temp = 0;
    for (int i = 0; i <= 95; i++) {
      if (s21_get_bit(src, i)) {
        temp += pow(2, i);
      }
    }
    if (s21_get_signed(src)) {
      if (temp < MIN_INT) {
        err = 1;
        temp = 0;
      }
      temp *= -1;
    }
    if (s21_get_scale(src)) {
      scale = s21_get_scale(src);
      temp /= (pow(10, scale));
    }
    if (temp > MAX_INT || temp < MIN_INT) {
      err = 1;
      temp = 0;
    }
    *dst = (int)temp;
  } else {
    err = 1;
  }
  return err;
}