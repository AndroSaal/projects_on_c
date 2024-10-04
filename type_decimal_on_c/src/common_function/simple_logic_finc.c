#include "../s21_decimal.h"

// 10 = 0b01010
int s21_mult_10(s21_decimal *value) {
  s21_decimal value_copy = *value;
  s21_make_mantiss_zero(value);
  int err = 0;

  err = s21_to_left_shift(&value_copy, 3);
  err = s21_simple_add(value_copy, *value, value);
  err = s21_to_right_shift(&value_copy, 2);
  err = s21_simple_add(value_copy, *value, value);

  return err;
}

void s21_make_mantiss_zero(s21_decimal *value_1) {
  value_1->bits[0] = 0;
  value_1->bits[1] = 0;
  value_1->bits[2] = 0;
  return;
}

int s21_is_zero_mantiss(s21_decimal a) {
  int res = 0;
  if (!a.bits[0] && !a.bits[1] && !a.bits[2]) res = 1;
  return res;
}

unsigned int s21_div_10(s21_decimal *value_1) {
  s21_decimal value_1_copy = *value_1;
  int err = 0;
  s21_make_mantiss_zero(value_1);
  s21_decimal remainder = {0b0, 0b0, 0b0, 0b0};
  s21_decimal divider = {10, 0b0, 0b0, 0b0};
  for (int i = 95; i >= 0; i--) {
    err = s21_to_left_shift(&remainder, 1);
    if (err) fprintf(stderr, "AAAAAAHELP!!!\n");
    s21_set_bit(&remainder, 0, s21_get_bit(value_1_copy, i));
    if (s21_is_greater_or_equal(remainder, divider)) {
      s21_simple_sub(remainder, divider, &remainder);
      s21_set_bit(value_1, i, 1);
    }
  }
  return remainder.bits[0];
}

// сложение целочисленных двоичных чисел одного знака
int s21_simple_add(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result) {
  int sum = 0;
  int stock = 0;
  int error = 0;

  for (int i = 0; i < 96; i++) {
    int cur_bit_1 = s21_get_bit(value_1, i);
    int cur_bit_2 = s21_get_bit(value_2, i);
    sum = stock + cur_bit_1 + cur_bit_2;

    switch (sum) {
      case 2:
        stock = 1;
        sum = 0;
        break;
      case 3:
        stock = 1;
        sum = 1;
        break;
      default:
        stock = 0;
        break;
    }
    s21_set_bit(result, i, sum);
  }

  if (stock) {
    // error = 1;
    // fprintf(stderr, "TROUBLES WITH SIMPLE_ADD\n");
    error = s21_get_signed(value_1) ? TOO_SMALl : TOO_BIG;
  }

  if (s21_get_signed(value_1)) s21_set_signed(result, 1);

  return error;
}

int s21_simple_sub(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result) {
  s21_set_signed(&value_1, 0);
  s21_set_signed(&value_2, 0);
  s21_decimal bigger_value =
      s21_is_greater(value_1, value_2) == 1 ? value_1 : value_2;
  s21_decimal smaller_value =
      s21_is_greater(value_1, value_2) == 1 ? value_2 : value_1;
  s21_make_mantiss_zero(result);

  if (s21_is_equal(value_1, value_2)) return ok;

  int sub = 0, error = 0;

  for (int i = 0; i < 96; i++) {
    int cur_bit_1 = s21_get_bit(bigger_value, i);
    int cur_bit_2 = s21_get_bit(smaller_value, i);

    sub = cur_bit_1 - cur_bit_2;

    if (sub == -1) {
      s21_zaem(&bigger_value, i);
      s21_set_bit(&bigger_value, i, 1);
      sub = 1;
    }
    s21_set_bit(result, i, sub);
  }

  if (s21_get_signed(bigger_value)) s21_set_signed(result, 1);

  return 0;
}

void s21_zaem(s21_decimal *value, int index) {
  for (int i = index;; i++) {
    if (s21_get_bit(*value, i)) {
      s21_set_bit(value, i, 0);
      break;
    } else {
      s21_set_bit(value, i, 1);
    }
  }
}
