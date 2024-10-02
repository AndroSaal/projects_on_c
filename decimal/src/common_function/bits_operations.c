#include "../s21_decimal.h"
// получение бита по индексу
int s21_get_bit(s21_decimal value,
                int index) {  // подуамть над обработкой некорректного индекса
  int mask = 0, res = 0;  // двигаем единичку в маске в нужную позицию
  if (index >= 0 && index <= MAX_BIG_INDEX) {
    mask = 0b1 << index % 32;
    res = (int)((value.bits[index / 32] & mask) != 0
                    ? 1
                    : 0);  // побитовое умножение. Результат какое-то число / 0
  } else
    res = -1;
  return res;
}

// установка заданного бита по индексу
void s21_set_bit(s21_decimal* value, int index,
                 int bit_value) {  // подумать над обработкой некорректного бита
  if (value != NULL) {
    int mask = 0b1 << index % 32;
    int cur_bit = s21_get_bit(*value, index);
    if (bit_value &&
        !cur_bit) {  // если пришедший бит == 1, тот что уже установлен == 0
      value->bits[index / 32] |= mask;
    } else if (!bit_value && cur_bit) {  // если пришедший бит == 0, тот что уже
                                         // установлен == 1
      value->bits[index / 32] &= ~mask;
    }
  }
}

int s21_get_signed(s21_decimal value) {
  return s21_get_bit(value, 127);  // 127 - индекс знака в четвертном бите
}

void s21_set_signed(s21_decimal* value, int signed_value) {
  s21_set_bit(value, 127, signed_value);
}

int s21_to_left_shift(s21_decimal* value,
                      int shift) {  // подумать над обработкой переполнения
  int val_1 = 0;
  int val_2 = 0;
  int err = 0;
  for (int j = 0; j < shift; j++) {
    for (int i = 0; i <= 96; i++) {
      val_1 = s21_get_bit(*value, i);
      s21_set_bit(value, i, val_2);
      val_2 = val_1;
    }
    err = s21_get_bit(*value, 96);
    if (err) {
      s21_set_bit(value, 96, 0);
      break;
    }
  }
  return err;
}

int s21_to_right_shift(s21_decimal* value,
                       int shift) {  // подумать над обработкой переполнения
  int val_1 = 0;
  int val_2 = 0;
  int err = s21_get_bit(*value, 96);
  if (err) return 1;
  for (int j = 0; j < shift; j++) {
    for (int i = 95; i >= 0; i--) {
      val_1 = s21_get_bit(*value, i);
      s21_set_bit(value, i, val_2);
      val_2 = val_1;
    }
  }
  return err;
}

s21_decimal s21_get_rounded(int znak, int scale) {
  s21_decimal odin = {0b1, 0, 0, 0};
  s21_set_signed(&odin, znak);
  s21_set_scale(&odin, scale);
  return odin;
}