#include "tests.h"

START_TEST(from_decimal_to_float_zero) {
  s21_decimal src = {{0}};
  float dst = 0;
  float result = 0;

  ck_assert_int_eq(s21_from_decimal_to_float(src, &dst), OK);
  ck_assert_float_eq(dst, result);
}
END_TEST

START_TEST(from_decimal_to_float_default_1) {
  s21_decimal src = {{0}};
  float dst = 0;
  float result = 777.777;

  s21_from_str_to_decimal("777.777", &src);

  ck_assert_int_eq(s21_from_decimal_to_float(src, &dst), OK);
  ck_assert_float_eq(dst, result);
}
END_TEST

START_TEST(from_decimal_to_float_default_2) {
  s21_decimal src = {{0}};
  float dst = 0;
  float result = 420420420;

  s21_from_str_to_decimal("420420420", &src);

  ck_assert_int_eq(s21_from_decimal_to_float(src, &dst), OK);
  ck_assert_float_eq(dst, result);
}
END_TEST

START_TEST(from_decimal_to_float_default_minus_1) {
  s21_decimal src = {{0}};
  float dst = 0;
  float result = -420420420;

  s21_from_str_to_decimal("-420420420", &src);

  ck_assert_int_eq(s21_from_decimal_to_float(src, &dst), OK);
  ck_assert_float_eq(dst, result);
}
END_TEST

START_TEST(from_decimal_to_float_default_minus_2) {
  s21_decimal src = {{0}};
  float dst = 0;
  float result = -7.777707;

  s21_from_str_to_decimal("-7.777707", &src);

  ck_assert_int_eq(s21_from_decimal_to_float(src, &dst), OK);
  ck_assert_float_eq(dst, result);
}
END_TEST

START_TEST(from_decimal_to_int_zero) {
  s21_decimal src = {{0}};
  int dst = 12;
  int result = 0;

  ck_assert_int_eq(s21_from_decimal_to_int(src, &dst), OK);
  ck_assert_int_eq(dst, result);
}
END_TEST

START_TEST(from_decimal_to_int_minus) {
  s21_decimal src = {{0}};
  int dst = 0;
  int result = -7777707;

  s21_from_str_to_decimal("-7777707", &src);

  ck_assert_int_eq(s21_from_decimal_to_int(src, &dst), OK);
  ck_assert_int_eq(dst, result);
}
END_TEST

START_TEST(from_decimal_to_int_default) {
  s21_decimal src = {{0}};
  int dst = 0;
  int result = 1234567890;

  s21_from_str_to_decimal("1234567890", &src);

  ck_assert_int_eq(s21_from_decimal_to_int(src, &dst), OK);
  ck_assert_int_eq(dst, result);
}
END_TEST

START_TEST(from_decimal_to_int_too_big_int) {
  s21_decimal src = {{0}};
  int dst = 123;
  int result = 0;

  s21_from_str_to_decimal("2147483648", &src);

  ck_assert_int_eq(s21_from_decimal_to_int(src, &dst), ERROR);
  ck_assert_int_eq(dst, result);
}
END_TEST

START_TEST(from_decimal_to_int_too_small_int) {
  s21_decimal src = {{0}};
  int dst = 123;
  int result = 0;

  s21_from_str_to_decimal("-2147483649", &src);

  ck_assert_int_eq(s21_from_decimal_to_int(src, &dst), ERROR);
  ck_assert_int_eq(dst, result);
}
END_TEST

START_TEST(from_decimal_to_int_rounding) {
  s21_decimal src = {{0}};
  int dst = 123;
  int result = 25;

  s21_from_str_to_decimal("25.64", &src);

  ck_assert_int_eq(s21_from_decimal_to_int(src, &dst), OK);
  ck_assert_int_eq(dst, result);
}
END_TEST

START_TEST(from_decimal_to_int_rounding_minus) {
  s21_decimal src = {{0}};
  int dst = 123;
  int result = -12625;

  s21_from_str_to_decimal("-12625.94", &src);

  ck_assert_int_eq(s21_from_decimal_to_int(src, &dst), OK);
  ck_assert_int_eq(dst, result);
}
END_TEST

START_TEST(from_float_to_decimal_default) {
  s21_decimal dst = {{0}};
  float src = 7.7777777;
  s21_decimal result = {{0}};

  char res[128] = {'0'};
  char expected[128] = {'0'};

  s21_from_str_to_decimal("7.777778", &result);

  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), OK);

  s21_from_decimal_to_str(res, dst);
  s21_from_decimal_to_str(expected, result);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(from_float_to_decimal_default_2) {
  s21_decimal dst = {{0}};
  float src = 123456789.0;
  s21_decimal result = {{0}};

  char res[128] = {'0'};
  char expected[128] = {'0'};

  s21_from_str_to_decimal("123456800.000000", &result);

  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), OK);

  s21_from_decimal_to_str(res, dst);
  s21_from_decimal_to_str(expected, result);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(from_float_to_decimal_default_3) {
  s21_decimal dst = {{0}};
  float src = 254678399999;
  s21_decimal result = {{0}};

  char res[128] = {'0'};
  char expected[128] = {'0'};

  s21_from_str_to_decimal("254678400000.000000", &result);

  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), OK);

  s21_from_decimal_to_str(res, dst);
  s21_from_decimal_to_str(expected, result);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(from_float_to_decimal_default_minus) {
  s21_decimal dst = {{0}};
  float src = -123456789.0;
  s21_decimal result = {{0}};

  char res[128] = {'0'};
  char expected[128] = {'0'};

  s21_from_str_to_decimal("-123456800.000000", &result);

  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), OK);

  s21_from_decimal_to_str(res, dst);
  s21_from_decimal_to_str(expected, result);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(from_float_to_decimal_minus_scale) {
  s21_decimal dst = {{0}};
  float src = -12.34567890;
  s21_decimal result = {{0}};

  char res[128] = {'0'};
  char expected[128] = {'0'};

  s21_from_str_to_decimal("-12.345680", &result);

  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), OK);

  s21_from_decimal_to_str(res, dst);
  s21_from_decimal_to_str(expected, result);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(from_float_to_decimal_scale) {
  s21_decimal dst = {{0}};
  float src = 2.34567890;
  s21_decimal result = {{0}};

  char res[128] = {'0'};
  char expected[128] = {'0'};

  s21_from_str_to_decimal("2.345679", &result);

  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), OK);

  s21_from_decimal_to_str(res, dst);
  s21_from_decimal_to_str(expected, result);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(from_int_to_decimal_zero) {
  s21_decimal dst = {{0}};
  int src = 0;
  s21_decimal result = {{0}};

  char res[128] = {'0'};
  char expected[128] = {'0'};

  s21_from_str_to_decimal("0", &result);

  ck_assert_int_eq(s21_from_int_to_decimal(src, &dst), OK);

  s21_from_decimal_to_str(res, dst);
  s21_from_decimal_to_str(expected, result);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(from_int_to_decimal_default_1) {
  s21_decimal dst = {{0}};
  int src = 420;
  s21_decimal result = {{0}};

  char res[128] = {'0'};
  char expected[128] = {'0'};

  s21_from_str_to_decimal("420", &result);

  ck_assert_int_eq(s21_from_int_to_decimal(src, &dst), OK);

  s21_from_decimal_to_str(res, dst);
  s21_from_decimal_to_str(expected, result);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(from_int_to_decimal_default_2) {
  s21_decimal dst = {{0}};
  int src = 777777777;
  s21_decimal result = {{0}};

  char res[128] = {'0'};
  char expected[128] = {'0'};

  s21_from_str_to_decimal("777777777", &result);

  ck_assert_int_eq(s21_from_int_to_decimal(src, &dst), OK);

  s21_from_decimal_to_str(res, dst);
  s21_from_decimal_to_str(expected, result);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(from_int_to_decimal_minus) {
  s21_decimal dst = {{0}};
  int src = -420;
  s21_decimal result = {{0}};

  char res[128] = {'0'};
  char expected[128] = {'0'};

  s21_from_str_to_decimal("-420", &result);

  ck_assert_int_eq(s21_from_int_to_decimal(src, &dst), OK);

  s21_from_decimal_to_str(res, dst);
  s21_from_decimal_to_str(expected, result);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(from_int_to_decimal_minus_2) {
  s21_decimal dst = {{0}};
  int src = -777777777;
  s21_decimal result = {{0}};

  char res[128] = {'0'};
  char expected[128] = {'0'};

  s21_from_str_to_decimal("-777777777", &result);

  ck_assert_int_eq(s21_from_int_to_decimal(src, &dst), OK);

  s21_from_decimal_to_str(res, dst);
  s21_from_decimal_to_str(expected, result);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(from_int_to_decimal_too_big) {
  s21_decimal dst = {{0}};
  long int src = 2147483647;  //
  s21_decimal result = {{0}};

  char res[128] = {'0'};
  char expected[128] = {'0'};

  s21_from_str_to_decimal("2147483647", &result);

  ck_assert_int_eq(s21_from_int_to_decimal(src, &dst), OK);

  s21_from_decimal_to_str(res, dst);
  s21_from_decimal_to_str(expected, result);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(from_int_to_decimal_too_small) {
  s21_decimal dst = {{0}};
  long int src = -2147483648;
  s21_decimal result = {{0}};

  char res[128] = {'0'};
  char expected[128] = {'0'};

  s21_from_str_to_decimal("-2147483648", &result);

  ck_assert_int_eq(s21_from_int_to_decimal(src, &dst), OK);

  s21_from_decimal_to_str(res, dst);
  s21_from_decimal_to_str(expected, result);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(from_int_to_decimal_rounding_1) {
  s21_decimal dst = {{0}};
  long int src = (long int)25.876;
  s21_decimal result = {{0}};

  char res[128] = {'0'};
  char expected[128] = {'0'};

  s21_from_str_to_decimal("25", &result);

  ck_assert_int_eq(s21_from_int_to_decimal(src, &dst), OK);

  s21_from_decimal_to_str(res, dst);
  s21_from_decimal_to_str(expected, result);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(from_int_to_decimal_rounding_2) {
  s21_decimal dst = {{0}};
  long int src = (long int)-79.999999;
  s21_decimal result = {{0}};

  char res[128] = {'0'};
  char expected[128] = {'0'};

  s21_from_str_to_decimal("-79", &result);

  ck_assert_int_eq(s21_from_int_to_decimal(src, &dst), OK);

  s21_from_decimal_to_str(res, dst);
  s21_from_decimal_to_str(expected, result);

  ck_assert_str_eq(res, expected);
}
END_TEST

// int main(void)
// {
//     Suite *s1 = suite_create("Core");
//     TCase *tc1_1 = tcase_create("from_decimal_to_float");
//     TCase *tc1_2 = tcase_create("from_decimal_to_int");
//     TCase *tc1_3 = tcase_create("from_float_to_decimal");
//     TCase *tc1_4 = tcase_create("from_int_to_decimal");
//     SRunner *sr = srunner_create(s1);
//     int nf;

//     suite_add_tcase(s1, tc1_1);
//     tcase_add_test(tc1_1, from_decimal_to_float_zero);
//     tcase_add_test(tc1_1, from_decimal_to_float_default_1);
//     tcase_add_test(tc1_1, from_decimal_to_float_default_2);
//     tcase_add_test(tc1_1, from_decimal_to_float_default_minus_1);
//     tcase_add_test(tc1_1, from_decimal_to_float_default_minus_2);
//     suite_add_tcase(s1, tc1_2);
//     tcase_add_test(tc1_2, from_decimal_to_int_zero);
//     tcase_add_test(tc1_2, from_decimal_to_int_minus);
//     tcase_add_test(tc1_2, from_decimal_to_int_default);
//     tcase_add_test(tc1_2, from_decimal_to_int_too_big_int);
//     tcase_add_test(tc1_2, from_decimal_to_int_too_small_int);
//     tcase_add_test(tc1_2, from_decimal_to_int_rounding);
//     tcase_add_test(tc1_2, from_decimal_to_int_rounding_minus);
//     suite_add_tcase(s1, tc1_3);
//     tcase_add_test(tc1_3, from_float_to_decimal_default);
//     tcase_add_test(tc1_3, from_float_to_decimal_default_2);
//     tcase_add_test(tc1_3, from_float_to_decimal_default_3);
//     tcase_add_test(tc1_3, from_float_to_decimal_default_minus);
//     tcase_add_test(tc1_3, from_float_to_decimal_minus_scale);
//     tcase_add_test(tc1_3, from_float_to_decimal_scale);
//     suite_add_tcase(s1, tc1_4);
//     tcase_add_test(tc1_4, from_int_to_decimal_zero);
//     tcase_add_test(tc1_4, from_int_to_decimal_default_1);
//     tcase_add_test(tc1_4, from_int_to_decimal_default_2);
//     tcase_add_test(tc1_4, from_int_to_decimal_minus);
//     tcase_add_test(tc1_4, from_int_to_decimal_minus_2);
//     tcase_add_test(tc1_4, from_int_to_decimal_too_big);
//     tcase_add_test(tc1_4, from_int_to_decimal_too_small);
//     tcase_add_test(tc1_4, from_int_to_decimal_rounding_1);
//     tcase_add_test(tc1_4, from_int_to_decimal_rounding_2);

//     srunner_run_all(sr, CK_ENV);
//     nf = srunner_ntests_failed(sr);
//     srunner_free(sr);

//     return nf == 0 ? 0 : 1;
// }
