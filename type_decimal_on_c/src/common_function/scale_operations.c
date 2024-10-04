#include "../s21_decimal.h"

int s21_get_scale(s21_decimal value) {
  int scale = 0;
  int err = 0;
  // printf("bit = %d\n", s21_get_bit(value, 19 + 3 * 32));
  for (int i = 16; i < 24; i++) {
    int bit = s21_get_bit(value, i + 3 * 32);
    if (bit == 1) {
      scale += (int)pow(2.0, (double)(i - 16));
    } else if (bit == -1)
      err = -1;
    else
      continue;
  }
  if (scale > 28) {
    err = -1;
  }
  return err == -1 ? err : scale;
}

void s21_set_scale(s21_decimal* value, int scale) {
  int sign = s21_get_signed(*value);
  value->bits[3] = 0b0;
  value->bits[3] |= (scale << 16);
  s21_set_signed(value, sign);
}
