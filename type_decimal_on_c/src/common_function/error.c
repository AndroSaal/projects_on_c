#include "../s21_decimal.h"

int s21_check(s21_decimal value_1) {
  int err = 0;
  if (s21_check_bit3(value_1, 96, 111) || s21_check_bit3(value_1, 120, 126) ||
      s21_get_scale(value_1) == -1) {
    err = 1;
  }
  return err;
}

int s21_check_bit3(s21_decimal value_1, int min_index, int max_index) {
  int err = 0;
  for (int i = min_index; i <= max_index; i++) {
    if (s21_get_bit(value_1, i)) {
      err = 1;
      break;
    }
  }
  return err;
}