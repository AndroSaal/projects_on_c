#include "tests.h"

//                              Тесты на округление (floor)
//                              ТЕСТ №1
START_TEST(floor_normal_value_n1) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("79228162514264337593.43950335", &value_1);

  return_value = s21_floor(value_1, &result);

  char result_exp[32] = "           79228162514264337593";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №2
}
END_TEST

START_TEST(floor_normal_value_n2) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-79228162514264337593.43950335", &value_1);

  return_value = s21_floor(value_1, &result);

  char result_exp[32] = "          -79228162514264337594";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №3
}
END_TEST

START_TEST(floor_normal_value_n3) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("739.9", &value_1);

  return_value = s21_floor(value_1, &result);

  char result_exp[32] = "                            739";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №4
}
END_TEST

START_TEST(floor_normal_value_n4) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-739.1", &value_1);

  return_value = s21_floor(value_1, &result);

  char result_exp[32] = "                           -740";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №5
}
END_TEST

START_TEST(floor_normal_value_n5) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-999.1", &value_1);

  return_value = s21_floor(value_1, &result);

  char result_exp[32] = "                          -1000";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №6
}
END_TEST

START_TEST(floor_normal_value_n6) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("999.9", &value_1);

  return_value = s21_floor(value_1, &result);

  char result_exp[32] = "                            999";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №7
}
END_TEST

START_TEST(floor_normal_value_n7) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("1000", &value_1);

  return_value = s21_floor(value_1, &result);

  char result_exp[32] = "                           1000";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №8
}
END_TEST

START_TEST(floor_normal_value_n8) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-1000", &value_1);

  return_value = s21_floor(value_1, &result);

  char result_exp[32] = "                          -1000";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №9
}
END_TEST

START_TEST(floor_normal_value_n9) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("0", &value_1);

  return_value = s21_floor(value_1, &result);

  char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №10
}
END_TEST

START_TEST(floor_normal_value_n10) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("0.1", &value_1);

  return_value = s21_floor(value_1, &result);

  char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №11
}
END_TEST

START_TEST(floor_normal_value_n11) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-0.1", &value_1);

  return_value = s21_floor(value_1, &result);

  char result_exp[32] = "                             -1";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №12 //некорректный указатель на результат
}
END_TEST

START_TEST(floor_normal_value_n12) {
  s21_decimal value_1 = {0};
  s21_decimal* result = NULL;
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-0.1", &value_1);

  return_value = s21_floor(value_1, result);

  char result_exp[32] = "0";
  // s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 1);

  //                              ТЕСТ №13 //некорректный децимал
}
END_TEST

START_TEST(floor_normal_value_n13) {
  s21_decimal value_1 = {0};
  value_1.bits[3] = 0b11111111111111111111111111111111;  // заполняем то, что
                                                         // должно быть пустым
  s21_decimal* result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  // s21_from_str_to_decimal("-0.1", &value_1);

  return_value = s21_floor(value_1, result);

  char result_exp[32] = "0";
  // s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 1);

  //                              ТЕСТ №14 //некорректный децимал
}
END_TEST

START_TEST(floor_normal_value_n14) {
  s21_decimal value_1 = {0};
  s21_set_scale(&value_1, 30);  // заполняем то, что должно быть пустым
  s21_decimal* result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  // s21_from_str_to_decimal("-0.1", &value_1);

  return_value = s21_floor(value_1, result);

  char result_exp[32] = "0";
  // s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 1);

  //                              ТЕСТ №15 //некорректный децимал
}
END_TEST

START_TEST(floor_normal_value_n15) {
  s21_decimal value_1 = {0};
  s21_set_scale(&value_1, 321);  // заполняем то, что должно быть пустым
  s21_decimal* result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  // s21_from_str_to_decimal("-0.1", &value_1);

  return_value = s21_floor(value_1, result);

  char result_exp[32] = "0";
  // s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 1);

  //                              Тесты на округление (round)
  //                              ТЕСТ №1
}
END_TEST

START_TEST(round_normal_value_n1) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("1000.357", &value_1);

  return_value = s21_round(value_1, &result);

  char result_exp[32] = "                           1000";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №2
}
END_TEST

START_TEST(round_normal_value_n2) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("1000.5000", &value_1);

  return_value = s21_round(value_1, &result);

  char result_exp[32] = "                           1001";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №3
}
END_TEST

START_TEST(round_normal_value_n3) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-1000.5000", &value_1);

  return_value = s21_round(value_1, &result);

  char result_exp[32] = "                          -1001";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №4
}
END_TEST

START_TEST(round_normal_value_n4) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-1009.9", &value_1);

  return_value = s21_round(value_1, &result);

  char result_exp[32] = "                          -1010";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №5
}
END_TEST

START_TEST(round_normal_value_n5) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("1009.9", &value_1);

  return_value = s21_round(value_1, &result);

  char result_exp[32] = "                           1010";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №6
}
END_TEST

START_TEST(round_normal_value_n6) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("1009.4", &value_1);

  return_value = s21_round(value_1, &result);

  char result_exp[32] = "                           1009";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №7
}
END_TEST

START_TEST(round_normal_value_n7) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("1009.4", &value_1);

  return_value = s21_round(value_1, &result);

  char result_exp[32] = "                           1009";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №8
}
END_TEST

START_TEST(round_normal_value_n8) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-1009.4", &value_1);

  return_value = s21_round(value_1, &result);

  char result_exp[32] = "                          -1009";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №9
}
END_TEST

START_TEST(round_normal_value_n9) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-1009.4", &value_1);

  return_value = s21_round(value_1, &result);

  char result_exp[32] = "                          -1009";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №10
}
END_TEST

START_TEST(round_normal_value_n10) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("0", &value_1);

  return_value = s21_round(value_1, &result);

  char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №11 некорректный аргумент
}
END_TEST

START_TEST(round_normal_value_n11) {
  s21_decimal value_1 = {0};
  value_1.bits[3] = 0b11111111111111111111111111111111;
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("0", &value_1);

  return_value = s21_round(value_1, &result);

  char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 1);

  //                              ТЕСТ №12 некорректный аргумент
}
END_TEST

START_TEST(round_normal_value_n12) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_set_scale(&value_1, 321);
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("0", &value_1);

  return_value = s21_round(value_1, &result);

  char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 1);

  //                              ТЕСТ №13 корректный аргумент
}
END_TEST

START_TEST(round_normal_value_n13) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("12345678999999999999999999999", &value_1);
  s21_set_scale(&value_1, 10);

  return_value = s21_round(value_1, &result);

  char result_exp[32] = "            1234567900000000000";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №14 некорректный аргумент
}
END_TEST

START_TEST(round_normal_value_n14) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("12345678999999999999999999999", &value_1);
  s21_set_scale(&value_1, 29);

  return_value = s21_round(value_1, &result);

  char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 1);

  //                              ТЕСТ №15 корректный аргумент
}
END_TEST

START_TEST(round_normal_value_n15) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("129", &value_1);
  s21_set_scale(&value_1, 12);

  return_value = s21_round(value_1, &result);

  char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              Тесты на отрицание (negate)
  //                              ТЕСТ №1 корректный аргумент
}
END_TEST

START_TEST(negate_normal_value_n1) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("129", &value_1);
  s21_set_scale(&value_1, 12);

  return_value = s21_negate(value_1, &result);

  char result_exp[32] = "                -0.000000000129";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №2 корректный аргумент
}
END_TEST

START_TEST(negate_normal_value_n2) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("129", &value_1);

  return_value = s21_negate(value_1, &result);

  char result_exp[32] = "                           -129";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №3 корректный аргумент
}
END_TEST

START_TEST(negate_normal_value_n3) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-129", &value_1);

  return_value = s21_negate(value_1, &result);

  char result_exp[32] = "                            129";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №4 корректный аргумент
}
END_TEST

START_TEST(negate_normal_value_n4) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("0", &value_1);

  return_value = s21_negate(value_1, &result);

  char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №5 некорректный аргумент
}
END_TEST

START_TEST(negate_normal_value_n5) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("0", &value_1);
  s21_set_scale(&value_1, 29);

  return_value = s21_negate(value_1, &result);

  char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 1);

  //                              ТЕСТ №6 некорректный аргумент
}
END_TEST

START_TEST(negate_normal_value_n6) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("0", &value_1);
  value_1.bits[3] = 17;

  return_value = s21_negate(value_1, &result);

  char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 1);

  //                              ТЕСТ №7 некорректный аргумент
}
END_TEST

START_TEST(negate_normal_value_n7) {
  s21_decimal value_1 = {0};
  s21_decimal* result = NULL;
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("0", &value_1);
  value_1.bits[3] = 17;

  return_value = s21_negate(value_1, result);

  char result_exp[32] = "0";
  // s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 1);

  //                              Тесты на отброса (truncate)
  //                              ТЕСТ №1 некорректный аргумент
}
END_TEST

START_TEST(truncate_normal_value_n1) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("12345.2123", &value_1);

  return_value = s21_truncate(value_1, &result);

  char result_exp[32] = "                          12345";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №2 некорректный аргумент
}
END_TEST

START_TEST(truncate_normal_value_n2) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("0.2123", &value_1);

  return_value = s21_truncate(value_1, &result);

  char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №3 некорректный аргумент
}
END_TEST

START_TEST(truncate_normal_value_n3) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("123456789.23456789", &value_1);

  return_value = s21_truncate(value_1, &result);

  char result_exp[32] = "                      123456789";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №4 некорректный аргумент
}
END_TEST

START_TEST(truncate_normal_value_n4) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("1234.2345678", &value_1);

  return_value = s21_truncate(value_1, &result);

  char result_exp[32] = "                           1234";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №5 некорректный аргумент
}
END_TEST

START_TEST(truncate_normal_value_n5) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-1234.2345678", &value_1);

  return_value = s21_truncate(value_1, &result);

  char result_exp[32] = "                          -1234";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                              ТЕСТ №6 некорректный аргумент
}
END_TEST

START_TEST(truncate_normal_value_n6) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-0.2345678", &value_1);

  return_value = s21_truncate(value_1, &result);

  char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);
}
END_TEST

// int main(void)
// {
//     Suite *s1 = suite_create("other_functions_tests");
//     TCase *tc1_1 = tcase_create("other_functions_tests");
//     SRunner *sr = srunner_create(s1);
//     int nf;

//     suite_add_tcase(s1, tc1_1);
//     tcase_add_test(tc1_1, floor_normal_value_n1);
//     tcase_add_test(tc1_1, floor_normal_value_n2);
//     tcase_add_test(tc1_1, floor_normal_value_n3);
//     tcase_add_test(tc1_1, floor_normal_value_n4);
//     tcase_add_test(tc1_1, floor_normal_value_n5);
//     tcase_add_test(tc1_1, floor_normal_value_n6);
//     tcase_add_test(tc1_1, floor_normal_value_n7);
//     tcase_add_test(tc1_1, floor_normal_value_n8);
//     tcase_add_test(tc1_1, floor_normal_value_n9);
//     tcase_add_test(tc1_1, floor_normal_value_n10);
//     tcase_add_test(tc1_1, floor_normal_value_n11);
//     tcase_add_test(tc1_1, floor_normal_value_n12);
//     tcase_add_test(tc1_1, floor_normal_value_n13);
//     tcase_add_test(tc1_1, floor_normal_value_n14);
//     tcase_add_test(tc1_1, floor_normal_value_n15);
//     tcase_add_test(tc1_1, round_normal_value_n1);
//     tcase_add_test(tc1_1, round_normal_value_n2);
//     tcase_add_test(tc1_1, round_normal_value_n3);
//     tcase_add_test(tc1_1, round_normal_value_n4);
//     tcase_add_test(tc1_1, round_normal_value_n5);
//     tcase_add_test(tc1_1, round_normal_value_n6);
//     tcase_add_test(tc1_1, round_normal_value_n7);
//     tcase_add_test(tc1_1, round_normal_value_n8);
//     tcase_add_test(tc1_1, round_normal_value_n9);
//     tcase_add_test(tc1_1, round_normal_value_n10);
//     tcase_add_test(tc1_1, round_normal_value_n11);
//     tcase_add_test(tc1_1, round_normal_value_n12);
//     tcase_add_test(tc1_1, round_normal_value_n13);
//     tcase_add_test(tc1_1, round_normal_value_n14);
//     tcase_add_test(tc1_1, round_normal_value_n15);
//     tcase_add_test(tc1_1, negate_normal_value_n1);
//     tcase_add_test(tc1_1, negate_normal_value_n2);
//     tcase_add_test(tc1_1, negate_normal_value_n3);
//     tcase_add_test(tc1_1, negate_normal_value_n4);
//     tcase_add_test(tc1_1, negate_normal_value_n5);
//     tcase_add_test(tc1_1, negate_normal_value_n6);
//     tcase_add_test(tc1_1, negate_normal_value_n7);
//     tcase_add_test(tc1_1, truncate_normal_value_n1);
//     tcase_add_test(tc1_1, truncate_normal_value_n2);
//     tcase_add_test(tc1_1, truncate_normal_value_n3);
//     tcase_add_test(tc1_1, truncate_normal_value_n4);
//     tcase_add_test(tc1_1, truncate_normal_value_n5);
//     tcase_add_test(tc1_1, truncate_normal_value_n6);

//     srunner_run_all(sr, CK_ENV);
//     nf = srunner_ntests_failed(sr);
//     srunner_free(sr);

//     return nf == 0 ? 0 : 1;
// }
