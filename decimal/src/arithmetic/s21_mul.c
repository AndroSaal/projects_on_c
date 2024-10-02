#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = ok;
  if (result != NULL) {
    s21_make_mantiss_zero(result);
    result->bits[3] = 0;

    int sign_1 = s21_get_signed(value_1), sign_2 = s21_get_signed(value_2),
        diff = 0, flag_to_round = 0;
    sign_1 += sign_2;

    s21_big_decimal big_value_1 = s21_convert_to_big_decimal(value_1);
    s21_big_decimal big_value_2 = s21_convert_to_big_decimal(value_2);
    s21_big_decimal big_result = ALL_BIG_ZERO;

    for (int i = MAX_BIG_INDEX; i >= 0; i--) {
      if (error) break;
      if (s21_big_get_bit(big_value_2, i)) {
        s21_big_decimal value_1_big_copy = big_value_1;
        error = s21_big_to_left_shift(&value_1_big_copy, i);
        error = s21_big_simple_add(big_result, value_1_big_copy, &big_result);
      }
    }

    big_result.scale = big_value_1.scale + big_value_2.scale;

    if (!error) error = s21_big_convert_to_decimal(big_result, result);

    if (sign_1 == 2 || sign_1 == 0)
      s21_set_signed(result, 0);
    else
      s21_set_signed(result, 1);

    if (error) error = s21_get_signed(*result) ? TOO_SMALl : TOO_BIG;
  } else {
    error = ERR;
  }

  if (error && result) {
    s21_make_mantiss_zero(result);
    result->bits[3] = 0;
  }

  return error;
}
