#include "s21_convertation.h"

void s21_float_round(int i, char *float_char) {
  if (float_char[i + 1] >= '5' && float_char[i] <= '9') {
    for (int j = i; j >= 0; j--) {
      if (float_char[j] == '9') {
        float_char[j] = '0';
      } else {
        float_char[j]++;
        break;
      }
    }
  }
}

void s21_edit_str(char *float_char) {
  for (int i = 0, counter = 0; float_char[i] != '\0'; i++) {
    if (float_char[i] >= '0' && float_char[i] <= '9') counter++;
    if (counter == 7 && float_char[i]) {
      s21_float_round(i, float_char);
    } else if (counter > 7 && float_char[i] >= '0' && float_char[i] <= '9') {
      float_char[i] = '0';
    }
  }
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int err = 0;
  if (dst != NULL) {
    s21_make_mantiss_zero(dst);
    dst->bits[3] = 0;
    if (0 < fabsf(src) && fabsf(src) < 1e-28 || isnan(src) || isinf(src) ||
        79228162514264337593543950335.f < fabsf(src)) {
      err = 1;
    } else {
      s21_decimal dst_copy = {0};
      char float_char[32] = {'0'};
      float_char[31] = '\0';
      if (src < 0) {
        s21_set_signed(&dst_copy, 1);
        src *= -1;
      }
      sprintf(float_char, "%f", src);
      s21_edit_str(float_char);
      s21_from_str_to_decimal(float_char, &dst_copy);
      *dst = dst_copy;
    }
  } else {
    err = 1;
  }

  return err;
}
