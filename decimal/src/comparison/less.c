#include "../s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int res = 0;
  if (!s21_check(value_1) && !s21_check(value_2)) {
    if (s21_get_signed(value_1) && !s21_get_signed(value_2) &&
        !s21_is_zero_mantiss(value_1) && !s21_is_zero_mantiss(value_2)) {
      res = 1;
    } else if (!s21_get_signed(value_1) && s21_get_signed(value_2)) {
      res = 0;
    } else {
      s21_big_decimal big_value_1 = s21_convert_to_big_decimal(value_1);
      s21_big_decimal big_value_2 = s21_convert_to_big_decimal(value_2);
      if (big_value_1.scale || big_value_2.scale)
        s21_normalize_bigs(&big_value_1, &big_value_2);
      res = !s21_big_simple_is_greater_or_equel(big_value_1, big_value_2);
    }
  }
  return res;
}
