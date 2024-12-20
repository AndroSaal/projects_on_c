#include "tests.h"
//                                  TEST ##1
START_TEST(add_test_normal_values_n1) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;

  return_value = s21_add(value_1, value_2, &result);

  ck_assert_int_eq(return_value, 0);

  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);

  //                                  TEST ##2
}
END_TEST

START_TEST(add_test_normal_values_n2) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char string_1[32] = {'0'};
  s21_from_str_to_decimal("10", &value_1);
  s21_from_str_to_decimal("5", &value_2);

  return_value = s21_add(value_1, value_2, &result);

  ck_assert_int_eq(result.bits[0], 10 + 5);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##3
}
END_TEST

START_TEST(add_test_normal_values_n3) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char string_1[32] = {'0'};
  s21_from_str_to_decimal("-10", &value_1);
  s21_from_str_to_decimal("5", &value_2);

  return_value = s21_add(value_1, value_2, &result);
  int result_ = result.bits[0];
  if (s21_get_signed(result)) result_ *= -1;
  ck_assert_int_eq(result_, -10 + 5);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##4
}
END_TEST

START_TEST(add_test_normal_values_n4) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char string_1[32] = {'0'};
  s21_from_str_to_decimal("-10", &value_1);
  s21_from_str_to_decimal("-5", &value_2);

  return_value = s21_add(value_1, value_2, &result);

  int result_ = result.bits[0];
  if (s21_get_signed(result)) result_ *= -1;
  ck_assert_int_eq(result_, -10 + (-5));  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##5
}
END_TEST

START_TEST(add_test_normal_values_n5) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("100000000000000000000", &value_1);
  s21_from_str_to_decimal("5", &value_2);

  return_value = s21_add(value_1, value_2, &result);

  char result_exp[32] = "          100000000000000000005";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##6 выход за условленные рамки:
  //                                  слишком большое число
}
END_TEST

START_TEST(add_test_cringe_values_n6) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("1", &value_2);

  return_value = s21_add(value_1, value_2, &result);

  char result_exp[32] = "          100000000000000000005";
  s21_from_decimal_to_str(result_real, result);

  // ck_assert_str_eq(result_exp, result_real); //сумма
  ck_assert_int_eq(return_value, 1);

  //                                  TEST ##7 выход за условленные рамки:
  //                                  слишком маленькое число
}
END_TEST

START_TEST(add_test_cringe_values_n7) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("-1", &value_2);

  return_value = s21_add(value_1, value_2, &result);

  char result_exp[32] = "          100000000000000000005";
  s21_from_decimal_to_str(result_real, result);

  // ck_assert_str_eq(result_exp, result_real); //сумма
  ck_assert_int_eq(return_value, 2);

  //                                  TEST ##8 выход за мантиссу: банковское
  //                                  округление
}
END_TEST

START_TEST(add_test_normal_values_n8) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("-0.6", &value_2);

  return_value = s21_add(value_1, value_2, &result);

  char result_exp[32] = "  79228162514264337593543950334";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##9 выход за условленные рамки:
  //                                  слишком большое (не на слишком много)
  //                                  число
}
END_TEST

START_TEST(add_test_cringe_values_n9) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("0.0001", &value_2);

  return_value = s21_add(value_1, value_2, &result);

  // char result_exp[32] = "  79228162514264337593543950334";
  s21_from_decimal_to_str(result_real, result);

  // ck_assert_str_eq(result_exp, result_real); //сумма
  ck_assert_int_eq(return_value, 1);

  //                                  TEST ##10 выход за мантиссу: банковское
  //                                  округление
}
END_TEST

START_TEST(add_test_cringe_values_n10) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("-0.0001", &value_2);

  return_value = s21_add(value_1, value_2, &result);

  // char result_exp[32] = "  79228162514264337593543950335";
  s21_from_decimal_to_str(result_real, result);

  // ck_assert_str_eq(result_exp, result_real); //сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##11 выход за мантиссу: банковское
  //                                  округление
}
END_TEST

START_TEST(add_test_normal_values_n11) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("79228935.984384092143213", &value_1);
  s21_from_str_to_decimal("-2324424.13142432313", &value_2);

  return_value = s21_add(value_1, value_2, &result);

  char result_exp[32] = "       76904511.852959769013213";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##12 выход за мантиссу: банковское
  //                                  округление
}
END_TEST

START_TEST(add_test_normal_values_n12) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("-79228162514264337593543950335", &value_2);

  return_value = s21_add(value_1, value_2, &result);

  char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(sub_test_cringe_values_n1) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("-79228162514264337593543950335", &value_2);

  return_value = s21_sub(value_1, value_2, &result);

  // char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  // ck_assert_str_eq(result_exp, result_real); //сумма
  ck_assert_int_eq(return_value, 1);

  //                                  TEST ##2 слишком большое число
}
END_TEST

START_TEST(sub_test_cringe_values_n2) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("-792281625142", &value_2);

  return_value = s21_sub(value_1, value_2, &result);

  // char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  // ck_assert_str_eq(result_exp, result_real); //сумма
  ck_assert_int_eq(return_value, 1);

  //                                  TEST ##3 слишком маленькое число
}
END_TEST

START_TEST(sub_test_cringe_values_n3) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("792281625142", &value_2);

  return_value = s21_sub(value_1, value_2, &result);

  // char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  // ck_assert_str_eq(result_exp, result_real); //сумма
  ck_assert_int_eq(return_value, 2);

  //                                  TEST ##4 слишком маленькое число
}
END_TEST

START_TEST(sub_test_cringe_values_n4) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("1", &value_2);

  return_value = s21_sub(value_1, value_2, &result);

  // char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  // ck_assert_str_eq(result_exp, result_real); //сумма
  ck_assert_int_eq(return_value, 2);

  //                                  TEST ##5 слишком маленькое число
}
END_TEST

START_TEST(sub_test_cringe_values_n5) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("0.0000000003", &value_2);

  return_value = s21_sub(value_1, value_2, &result);

  // char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  // ck_assert_str_eq(result_exp, result_real); //сумма
  ck_assert_int_eq(return_value, 2);

  //                                  TEST ##5 нормальное число: банковское
  //                                  округление
}
END_TEST

START_TEST(sub_test_normal_values_n6) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("0.0000000003", &value_2);

  return_value = s21_sub(value_1, value_2, &result);

  char result_exp[32] = "  79228162514264337593543950335";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##6 нормальное число: банковское
  //                                  округление
}
END_TEST

START_TEST(sub_test_normal_values_n7) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("0.6", &value_2);

  return_value = s21_sub(value_1, value_2, &result);

  char result_exp[32] = "  79228162514264337593543950334";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##6 нормальное число
}
END_TEST

START_TEST(sub_test_normal_values_n8) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("792281625142643", &value_1);
  s21_from_str_to_decimal("234567898765432345", &value_2);

  return_value = s21_sub(value_1, value_2, &result);

  char result_exp[32] = "            -233775617140289702";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##7 нормальное число
}
END_TEST

START_TEST(sub_test_normal_values_n9) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("234567898765432345", &value_1);
  s21_from_str_to_decimal("792281625142643", &value_2);

  return_value = s21_sub(value_1, value_2, &result);

  char result_exp[32] = "             233775617140289702";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##8 нормальное число
}
END_TEST

START_TEST(sub_test_normal_values_n10) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("234567898765432345", &value_1);
  s21_from_str_to_decimal("234567898765432345", &value_2);

  return_value = s21_sub(value_1, value_2, &result);

  char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##9 нормальное число
}
END_TEST

START_TEST(sub_test_normal_values_n11) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("234567898765432345", &value_1);
  s21_from_str_to_decimal("234567898765432345.123456", &value_2);

  return_value = s21_sub(value_1, value_2, &result);

  char result_exp[32] = "                      -0.123456";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##10 нормальное число
}
END_TEST

START_TEST(sub_test_normal_values_n12) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("17", &value_1);
  s21_from_str_to_decimal("12", &value_2);

  return_value = s21_sub(value_1, value_2, &result);

  char result_exp[32] = "                              5";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##11 нормальное число
}
END_TEST

START_TEST(sub_test_normal_values_n13) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("0", &value_1);
  s21_from_str_to_decimal("0", &value_2);

  return_value = s21_sub(value_1, value_2, &result);

  char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##12 нормальное число
}
END_TEST

START_TEST(sub_test_normal_values_n14) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("0.12345678765432123", &value_1);
  s21_from_str_to_decimal("123456754", &value_2);

  return_value = s21_sub(value_1, value_2, &result);

  char result_exp[32] = "   -123456753.87654321234567877";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##12 нормальное число
}
END_TEST

START_TEST(sub_test_normal_values_n15) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("657", &value_1);
  s21_from_str_to_decimal("57", &value_2);

  return_value = s21_sub(value_1, value_2, &result);

  char result_exp[32] = "                            600";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  // #suite mul_test
  // #tcase mul_test
  //                                   Тесты на умножение
  //                                   TEST ##1 нормальное число
}
END_TEST

START_TEST(mul_test_normal_values_n1) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("10", &value_1);
  s21_from_str_to_decimal("10", &value_2);

  return_value = s21_mul(value_1, value_2, &result);

  char result_exp[32] = "                            100";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##2 нормальное число
}
END_TEST

START_TEST(mul_test_normal_values_n2) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("100", &value_1);
  s21_from_str_to_decimal("-10", &value_2);

  return_value = s21_mul(value_1, value_2, &result);

  char result_exp[32] = "                          -1000";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##3 нормальное число
}
END_TEST

START_TEST(mul_test_normal_values_n3) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-100", &value_1);
  s21_from_str_to_decimal("-10", &value_2);

  return_value = s21_mul(value_1, value_2, &result);

  char result_exp[32] = "                           1000";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##4 нормальное число
}
END_TEST

START_TEST(mul_test_normal_values_n4) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("2345678987654", &value_1);
  s21_from_str_to_decimal("2343", &value_2);

  return_value = s21_mul(value_1, value_2, &result);

  char result_exp[32] = "               5495925868073322";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##5 нормальное число
}
END_TEST

START_TEST(mul_test_normal_values_n5) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("2345678987654", &value_1);
  s21_from_str_to_decimal("0.00003", &value_2);

  return_value = s21_mul(value_1, value_2, &result);

  char result_exp[32] = "                 70370369.62962";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##6 нормальное число
}
END_TEST

START_TEST(mul_test_normal_values_n6) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("0.02", &value_1);
  s21_from_str_to_decimal("0.02", &value_2);

  return_value = s21_mul(value_1, value_2, &result);

  char result_exp[32] = "                         0.0004";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##7 нормальное число
}
END_TEST

START_TEST(mul_test_normal_values_n7) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("1171", &value_1);
  s21_from_str_to_decimal("-89272035774827", &value_2);

  return_value = s21_mul(value_1, value_2, &result);

  char result_exp[32] = "            -104537553892322417";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##8 нормальное число
}
END_TEST

START_TEST(mul_test_normal_values_n8) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("77777777", &value_1);
  s21_from_str_to_decimal("6666666666", &value_2);

  return_value = s21_mul(value_1, value_2, &result);

  char result_exp[32] = "             518518513281481482";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##9 нормальное число
}
END_TEST

START_TEST(mul_test_normal_values_n9) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("7777.7777", &value_1);
  s21_from_str_to_decimal("666666.6666", &value_2);

  return_value = s21_mul(value_1, value_2, &result);

  char result_exp[32] = "            5185185132.81481482";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##10 нормальное число
}
END_TEST

START_TEST(mul_test_normal_values_n10) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-12345", &value_1);
  s21_from_str_to_decimal("-12345", &value_2);

  return_value = s21_mul(value_1, value_2, &result);

  char result_exp[32] = "                      152399025";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##11 слишком большое
}
END_TEST

START_TEST(mul_test_normal_values_n11) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("-79228162514264337593543950335", &value_2);

  return_value = s21_mul(value_1, value_2, &result);

  // char result_exp[32] = "0";
  // s21_from_decimal_to_str(result_real, result);

  // ck_assert_str_eq(result_exp, result_real); //сумма
  ck_assert_int_eq(return_value, 1);

  //                                  TEST ##12 слишком большое
}
END_TEST

START_TEST(mul_test_normal_values_n12) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("79228162514264337593543950335", &value_2);

  return_value = s21_mul(value_1, value_2, &result);

  // char result_exp[32] = "0";
  // s21_from_decimal_to_str(result_real, result);

  // ck_assert_str_eq(result_exp, result_real); //сумма
  ck_assert_int_eq(return_value, 2);

  //                                  TEST ##13 слишком большое
}
END_TEST

START_TEST(mul_test_normal_values_n13) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-2", &value_1);
  s21_from_str_to_decimal("79228162514264337593543950335", &value_2);

  return_value = s21_mul(value_1, value_2, &result);

  // char result_exp[32] = "0";
  // s21_from_decimal_to_str(result_real, result);

  // ck_assert_str_eq(result_exp, result_real); //сумма
  ck_assert_int_eq(return_value, 2);

  //                                  TEST ##14 банковское округление
}
END_TEST

START_TEST(mul_test_normal_values_n14) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-1", &value_1);
  s21_from_str_to_decimal("79228162514264337593543950335", &value_2);

  return_value = s21_mul(value_1, value_2, &result);

  char result_exp[32] = " -79228162514264337593543950335";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##15 банковское округление
}
END_TEST

START_TEST(mul_test_normal_values_n15) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-0.9", &value_1);
  s21_from_str_to_decimal("79228162514264337593543950335", &value_2);

  return_value = s21_mul(value_1, value_2, &result);

  char result_exp[32] = " -71305346262837903834189555302";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##16 банковское округление
}
END_TEST

START_TEST(mul_test_normal_values_n16) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("-0.99", &value_2);

  return_value = s21_mul(value_1, value_2, &result);

  char result_exp[32] = " -78435880889121694217608510832";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##17 банковское округление
}
END_TEST

START_TEST(mul_test_normal_values_n17) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("-0.8", &value_2);

  return_value = s21_mul(value_1, value_2, &result);

  char result_exp[32] = " -63382530011411470074835160268";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##18 банковское округление
}
END_TEST

START_TEST(mul_test_normal_values_n18) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("-0.9999999999", &value_2);

  return_value = s21_mul(value_1, value_2, &result);

  char result_exp[32] = " -79228162506341521342117516576";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##19 банковское округление
}
END_TEST

START_TEST(mul_test_normal_values_n19) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("-0.000000000001", &value_2);

  return_value = s21_mul(value_1, value_2, &result);

  char result_exp[32] = "-79228162514264337.593543950335";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##20 банковское округление
}
END_TEST

START_TEST(mul_test_normal_values_n20) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("-0.125", &value_2);

  return_value = s21_mul(value_1, value_2, &result);

  char result_exp[32] = "   9903520314283042199192993792";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  // # suite del_test
  // # tcase del_test
  //                                   Тесты на деление
  //                                   TEST ##1 нормальное число
}
END_TEST

START_TEST(div_test_normal_values_n1) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("5", &value_2);

  return_value = s21_div(value_1, value_2, &result);

  char result_exp[32] = " -15845632502852867518708790067";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  Тесты на деление
  //                                  TEST ##2 нормальное число
}
END_TEST

START_TEST(div_test_normal_values_n2) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-10", &value_1);
  s21_from_str_to_decimal("5", &value_2);

  return_value = s21_div(value_1, value_2, &result);

  char result_exp[32] = "                             -2";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  Тесты на деление
  //                                  TEST ##3 нормальное число
}
END_TEST

START_TEST(div_test_normal_values_n3) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("1", &value_1);
  s21_from_str_to_decimal("3", &value_2);

  return_value = s21_div(value_1, value_2, &result);

  char result_exp[32] = " 0.3333333333333333333333333333";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  Тесты на деление
  //                                  TEST ##4 нормальное число
}
END_TEST

START_TEST(div_test_normal_values_n4) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("2", &value_1);
  s21_from_str_to_decimal("2", &value_2);

  return_value = s21_div(value_1, value_2, &result);

  char result_exp[32] = "                              1";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##5 нормальное число
}
END_TEST

START_TEST(div_test_normal_values_n5) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("4", &value_1);
  s21_from_str_to_decimal("5", &value_2);

  return_value = s21_div(value_1, value_2, &result);

  char result_exp[32] = "                            0.8";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##6 нормальное число
}
END_TEST

START_TEST(div_test_normal_values_n6) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("100", &value_1);
  s21_from_str_to_decimal("-1", &value_2);

  return_value = s21_div(value_1, value_2, &result);

  char result_exp[32] = "                           -100";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##7 нормальное число
}
END_TEST

START_TEST(div_test_normal_values_n7) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-25", &value_1);
  s21_from_str_to_decimal("-5", &value_2);

  return_value = s21_div(value_1, value_2, &result);

  char result_exp[32] = "                              5";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##8 нормальное число
}
END_TEST

START_TEST(div_test_normal_values_n8) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-3456788239023456789", &value_1);
  s21_from_str_to_decimal("-13", &value_2);

  return_value = s21_div(value_1, value_2, &result);

  char result_exp[32] = " 265906787617188983.76923076923";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##9 слишком маленькое
}
END_TEST

START_TEST(div_test_normal_values_n9) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("0.1", &value_2);

  return_value = s21_div(value_1, value_2, &result);

  char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 2);

  //                                  TEST ##10 слишком большое
}
END_TEST

START_TEST(div_test_normal_values_n10) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("0.1111111", &value_2);

  return_value = s21_div(value_1, value_2, &result);

  char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 1);

  //                                  TEST ##11 слишком маленькое
}
END_TEST

START_TEST(div_test_normal_values_n11) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("-0.000000000000000000014", &value_2);

  return_value = s21_div(value_1, value_2, &result);

  char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 2);

  //                                  TEST ##12 нормальное число
}
END_TEST

START_TEST(div_test_normal_values_n12) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("5", &value_2);

  return_value = s21_div(value_1, value_2, &result);

  char result_exp[32] = "  15845632502852867518708790067";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##13 деление на 0
}
END_TEST

START_TEST(div_test_normal_values_n13) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("0", &value_2);

  return_value = s21_div(value_1, value_2, &result);

  char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 3);

  //                                  TEST ##14 нормальное
}
END_TEST

START_TEST(div_test_normal_values_n14) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("0", &value_1);
  s21_from_str_to_decimal("645", &value_2);

  return_value = s21_div(value_1, value_2, &result);

  char result_exp[32] = "                              0";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##15 нормальное
}
END_TEST

START_TEST(div_test_normal_values_n15) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-145", &value_1);
  s21_from_str_to_decimal("645", &value_2);

  return_value = s21_div(value_1, value_2, &result);

  char result_exp[32] = "-0.2248062015503875968992248062";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##16 нормальное
}
END_TEST

START_TEST(div_test_normal_values_n16) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("-79228162514264337593543950335", &value_2);

  return_value = s21_div(value_1, value_2, &result);

  char result_exp[32] = "                             -1";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##17 нормальное
}
END_TEST

START_TEST(div_test_normal_values_n17) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("-79228162514264337593543950335", &value_1);
  s21_from_str_to_decimal("-79228162514264337593543950335", &value_2);

  return_value = s21_div(value_1, value_2, &result);

  char result_exp[32] = "                              1";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);

  //                                  TEST ##18 нормальное
}
END_TEST

START_TEST(div_test_normal_values_n18) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = 0;
  char result_real[32] = {'0'};
  s21_from_str_to_decimal("0.0003", &value_1);
  s21_from_str_to_decimal("3", &value_2);

  return_value = s21_div(value_1, value_2, &result);

  char result_exp[32] = "                         0.0001";
  s21_from_decimal_to_str(result_real, result);

  ck_assert_str_eq(result_exp, result_real);  // сумма
  ck_assert_int_eq(return_value, 0);
}
END_TEST

// int main(void)
// {
//     Suite *s1 = suite_create("arithmetic_functions_tests");
//     TCase *tc1_1 = tcase_create("arithmetic_functions_tests");
//     SRunner *sr = srunner_create(s1);
//     int nf;

//     suite_add_tcase(s1, tc1_1);
//     tcase_add_test(tc1_1, add_test_normal_values_n1);
//     tcase_add_test(tc1_1, add_test_normal_values_n2);
//     tcase_add_test(tc1_1, add_test_normal_values_n3);
//     tcase_add_test(tc1_1, add_test_normal_values_n4);
//     tcase_add_test(tc1_1, add_test_normal_values_n5);
//     tcase_add_test(tc1_1, add_test_cringe_values_n6);
//     tcase_add_test(tc1_1, add_test_cringe_values_n7);
//     tcase_add_test(tc1_1, add_test_normal_values_n8);
//     tcase_add_test(tc1_1, add_test_cringe_values_n9);
//     tcase_add_test(tc1_1, add_test_cringe_values_n10);
//     tcase_add_test(tc1_1, add_test_normal_values_n11);
//     tcase_add_test(tc1_1, add_test_normal_values_n12);
//     tcase_add_test(tc1_1, sub_test_cringe_values_n1);
//     tcase_add_test(tc1_1, sub_test_cringe_values_n2);
//     tcase_add_test(tc1_1, sub_test_cringe_values_n3);
//     tcase_add_test(tc1_1, sub_test_cringe_values_n4);
//     tcase_add_test(tc1_1, sub_test_cringe_values_n5);
//     tcase_add_test(tc1_1, sub_test_normal_values_n6);
//     tcase_add_test(tc1_1, sub_test_normal_values_n7);
//     tcase_add_test(tc1_1, sub_test_normal_values_n8);
//     tcase_add_test(tc1_1, sub_test_normal_values_n9);
//     tcase_add_test(tc1_1, sub_test_normal_values_n10);
//     tcase_add_test(tc1_1, sub_test_normal_values_n11);
//     tcase_add_test(tc1_1, sub_test_normal_values_n12);
//     tcase_add_test(tc1_1, sub_test_normal_values_n13);
//     tcase_add_test(tc1_1, sub_test_normal_values_n14);
//     tcase_add_test(tc1_1, sub_test_normal_values_n15);
//     tcase_add_test(tc1_1, mul_test_normal_values_n1);
//     tcase_add_test(tc1_1, mul_test_normal_values_n2);
//     tcase_add_test(tc1_1, mul_test_normal_values_n3);
//     tcase_add_test(tc1_1, mul_test_normal_values_n4);
//     tcase_add_test(tc1_1, mul_test_normal_values_n5);
//     tcase_add_test(tc1_1, mul_test_normal_values_n6);
//     tcase_add_test(tc1_1, mul_test_normal_values_n7);
//     tcase_add_test(tc1_1, mul_test_normal_values_n8);
//     tcase_add_test(tc1_1, mul_test_normal_values_n9);
//     tcase_add_test(tc1_1, mul_test_normal_values_n10);
//     tcase_add_test(tc1_1, mul_test_normal_values_n11);
//     tcase_add_test(tc1_1, mul_test_normal_values_n12);
//     tcase_add_test(tc1_1, mul_test_normal_values_n13);
//     tcase_add_test(tc1_1, mul_test_normal_values_n14);
//     tcase_add_test(tc1_1, mul_test_normal_values_n15);
//     tcase_add_test(tc1_1, mul_test_normal_values_n16);
//     tcase_add_test(tc1_1, mul_test_normal_values_n17);
//     tcase_add_test(tc1_1, mul_test_normal_values_n18);
//     tcase_add_test(tc1_1, mul_test_normal_values_n19);
//     tcase_add_test(tc1_1, mul_test_normal_values_n20);
//     tcase_add_test(tc1_1, div_test_normal_values_n1);
//     tcase_add_test(tc1_1, div_test_normal_values_n2);
//     tcase_add_test(tc1_1, div_test_normal_values_n3);
//     tcase_add_test(tc1_1, div_test_normal_values_n4);
//     tcase_add_test(tc1_1, div_test_normal_values_n5);
//     tcase_add_test(tc1_1, div_test_normal_values_n6);
//     tcase_add_test(tc1_1, div_test_normal_values_n7);
//     tcase_add_test(tc1_1, div_test_normal_values_n8);
//     tcase_add_test(tc1_1, div_test_normal_values_n9);
//     tcase_add_test(tc1_1, div_test_normal_values_n10);
//     tcase_add_test(tc1_1, div_test_normal_values_n11);
//     tcase_add_test(tc1_1, div_test_normal_values_n12);
//     tcase_add_test(tc1_1, div_test_normal_values_n13);
//     tcase_add_test(tc1_1, div_test_normal_values_n14);
//     tcase_add_test(tc1_1, div_test_normal_values_n15);
//     tcase_add_test(tc1_1, div_test_normal_values_n16);
//     tcase_add_test(tc1_1, div_test_normal_values_n17);
//     tcase_add_test(tc1_1, div_test_normal_values_n18);

//     srunner_run_all(sr, CK_ENV);
//     nf = srunner_ntests_failed(sr);
//     srunner_free(sr);

//     return nf == 0 ? 0 : 1;
// }
