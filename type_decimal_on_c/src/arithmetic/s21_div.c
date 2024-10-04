#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  // value_1 - N
  // value_2 - D
  // result  - Q

  int error = 0;
  if (result != NULL) {
    s21_make_mantiss_zero(result);
    result->bits[3] = 0;
    if (s21_is_zero_mantiss(value_2)) return divide_by_zero;

    s21_big_decimal big_value_1 = s21_convert_to_big_decimal(value_1);
    s21_big_decimal big_value_2 = s21_convert_to_big_decimal(value_2);
    s21_big_decimal big_result = ALL_BIG_ZERO;
    s21_big_decimal remainder = ALL_BIG_ZERO;

    int value_1_sign = s21_get_signed(value_1),
        value_2_sign = s21_get_signed(value_2), scale = 0;
    ;
    int sum_sign = value_2_sign + value_1_sign;

    error = s21_normalize_bigs(&big_value_1, &big_value_2);

    s21_set_signed(&value_1, 0);
    s21_set_signed(&value_2, 0);

    remainder = s21_del_mantiss(big_value_1, big_value_2, &big_result);

    if (!s21_big_is_zero_mantissa(remainder))
      error = s21_add_remainder(remainder, &big_result, big_value_2);

    if (sum_sign == 1) big_result.sign = 1;

    if (!error) {
      error = s21_big_convert_to_decimal(big_result, result);
    }

    if (error) error = big_result.sign ? TOO_SMALl : TOO_BIG;

    if (error) s21_make_mantiss_zero(result);
  } else {
    error = ERR;
  }

  if (error && result) {
    s21_make_mantiss_zero(result);
    result->bits[3] = 0;
  }

  return error;
}

int s21_add_remainder(s21_big_decimal remainder, s21_big_decimal *result,
                      s21_big_decimal del) {
  int err = 0;

  while (!s21_big_is_zero_mantissa(remainder) &&
         result->scale <= 55) {  // чем больше максимальная степень резалта, тем
                                 // выше точность...
    s21_big_mult_ten(result);
    s21_big_mult_ten(&remainder);
    s21_big_decimal prom_res = ALL_BIG_ZERO;  // промежуточный результат деления
    remainder = s21_del_mantiss(remainder, del, &prom_res);
    s21_big_simple_add(*result, prom_res, result);
    result->scale++;
  }

  err = s21_big_simple_add(remainder, *result, result);

  return err;
}

s21_big_decimal s21_del_mantiss(s21_big_decimal big_value_1,
                                s21_big_decimal big_value_2,
                                s21_big_decimal *result) {
  s21_big_decimal remainder = ALL_BIG_ZERO;
  for (int i = MAX_BIG_INDEX; i >= 0; i--) {  // непосредственно деление
    s21_big_to_left_shift(&remainder, 1);
    s21_big_set_bit(&remainder, 0, s21_big_get_bit(big_value_1, i));
    if (s21_big_simple_is_greater_or_equel(remainder, big_value_2)) {
      s21_big_simple_sub(remainder, big_value_2, &remainder);
      s21_big_set_bit(result, i, 1);
    }
  }

  return remainder;
}