#include "s21_convertation.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int err = ok;
  if (dst != NULL) {
    s21_make_mantiss_zero(dst);
    dst->bits[3] = 0;
    if (src <= MAX_INT &&
        src > MIN_INT) {  // Защита от NULL и некорректных значений
      if (src < 0) {
        s21_set_signed(dst, 1);
        src *= -1;
      }
      dst->bits[0] = src;
    } else if (src == MIN_INT) {
      // src += 1;
      // src *= -1;
      // s21_decimal odin = {1, 0, 0, 0};
      // dst->bits[0] = src;
      s21_set_bit(dst, 31, 1);
      // s21_simple_add(*dst, odin, dst);
      s21_set_signed(dst, 1);
    } else
      err = 1;
  } else
    err = 1;  // ошибка конвертации
  return err;
}