#include "s21_convertation.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int err = 0;
  int scale = 0;
  if (s21_check(src) || dst == NULL) {
    err = 1;
  } else if (s21_is_zero_mantiss(src)) {
    *dst = 0;
  } else {
    double temp = 0.0;
    for (int i = 0; i <= 95; i++) {
      if (s21_get_bit(src, i)) {
        temp += pow(2.0, i);
      }
    }
    if (s21_get_signed(src)) {
      temp *= -1;
    }

    if (s21_get_scale(src)) {
      scale = s21_get_scale(src);
      temp /= pow(10, scale);
    }

    if (fabs((float)temp) < MIN_FLOAT || fabs((float)temp) > MAX_FLOAT) {
      *dst = 0.0;
      err = 1;
    }

    *dst = (float)temp;
  }

  return err;
}