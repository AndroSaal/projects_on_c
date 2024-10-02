#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  if (s21_check(value) || !result) return 1;

  result->bits[0] = value.bits[0];
  result->bits[1] = value.bits[1];
  result->bits[2] = value.bits[2];
  result->bits[3] = value.bits[3];

  if (!s21_is_zero_mantiss(value))
    s21_set_signed(result, !s21_get_signed(value));

  return ok;
}