#include "tests.h"

START_TEST(equal_with_zero_true) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(equal_with_minus_zero_true) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("-0", &value_1);
  s21_from_str_to_decimal("-0.0", &value_2);

  ck_assert_int_eq(s21_is_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(equal_with_minus_zero_true_2) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("-0.0", &value_1);
  s21_from_str_to_decimal("0.0", &value_2);

  ck_assert_int_eq(s21_is_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(equal_default_true) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("420.0", &value_1);
  s21_from_str_to_decimal("420", &value_2);

  ck_assert_int_eq(s21_is_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(equal_default_true_2) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("7", &value_1);
  s21_from_str_to_decimal("7", &value_2);

  ck_assert_int_eq(s21_is_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(equal_default_true_3) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("7.77777777777777777", &value_1);
  s21_from_str_to_decimal("7.77777777777777777", &value_2);

  ck_assert_int_eq(s21_is_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(equal_default_false_1) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("777", &value_1);
  s21_from_str_to_decimal("420", &value_2);

  ck_assert_int_eq(s21_is_equal(value_1, value_2), FALSE);
}
END_TEST

START_TEST(equal_default_false_2) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("420.1234567890", &value_1);
  s21_from_str_to_decimal("777.0987654321", &value_2);

  ck_assert_int_eq(s21_is_equal(value_1, value_2), FALSE);
}
END_TEST

START_TEST(equal_default_false_3) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("420.0000000000000001", &value_1);
  s21_from_str_to_decimal("777.0000000000000002", &value_2);

  ck_assert_int_eq(s21_is_equal(value_1, value_2), FALSE);
}
END_TEST

START_TEST(equal_with_sign) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("777777777", &value_1);
  s21_from_str_to_decimal("-777777777", &value_2);

  ck_assert_int_eq(s21_is_equal(value_1, value_2), FALSE);
}
END_TEST

START_TEST(not_equal_with_zero_false) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), FALSE);
}
END_TEST

START_TEST(not_equal_with_minus_zero_false) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("-0", &value_1);
  s21_from_str_to_decimal("-0.0", &value_2);

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), FALSE);
}
END_TEST

START_TEST(not_equal_with_minus_zero_false_2) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("-0.0", &value_1);
  s21_from_str_to_decimal("0.0", &value_2);

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), FALSE);
}
END_TEST

START_TEST(not_equal_default_false) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("420.0", &value_1);
  s21_from_str_to_decimal("420", &value_2);

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), FALSE);
}
END_TEST

START_TEST(not_equal_default_false_2) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("7", &value_1);
  s21_from_str_to_decimal("7", &value_2);

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), FALSE);
}
END_TEST

START_TEST(not_equal_default_false_3) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("7.77777777777777777", &value_1);
  s21_from_str_to_decimal("7.77777777777777777", &value_2);

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), FALSE);
}
END_TEST

START_TEST(not_equal_default_true_1) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("777", &value_1);
  s21_from_str_to_decimal("420", &value_2);

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(not_equal_default_true_2) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("420.1234567890", &value_1);
  s21_from_str_to_decimal("777.0987654321", &value_2);

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(not_equal_default_true_3) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("420.0000000000000001", &value_1);
  s21_from_str_to_decimal("777.0000000000000002", &value_2);

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(not_equal_with_sign) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("777777777", &value_1);
  s21_from_str_to_decimal("-777777777", &value_2);

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(greater_with_zero_false) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), FALSE);
}
END_TEST

START_TEST(greater_with_minus_zero_false) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("-0", &value_1);
  s21_from_str_to_decimal("-0.0", &value_2);

  ck_assert_int_eq(s21_is_greater(value_1, value_2), FALSE);
}
END_TEST

START_TEST(greater_with_minus_zero_false_2) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("0.0", &value_1);
  s21_from_str_to_decimal("-0.0", &value_2);

  ck_assert_int_eq(s21_is_greater(value_1, value_2), FALSE);
}
END_TEST

START_TEST(greater_default_true) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("4200.0", &value_1);
  s21_from_str_to_decimal("420.0", &value_2);

  ck_assert_int_eq(s21_is_greater(value_1, value_2), TRUE);
}
END_TEST

START_TEST(greater_default_true_2) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("4200.00000000001", &value_1);
  s21_from_str_to_decimal("4200.00000000000", &value_2);

  ck_assert_int_eq(s21_is_greater(value_1, value_2), TRUE);
}
END_TEST

START_TEST(greater_default_true_3) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("777", &value_1);
  s21_from_str_to_decimal("420", &value_2);

  ck_assert_int_eq(s21_is_greater(value_1, value_2), TRUE);
}
END_TEST

START_TEST(greater_default_false) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("420", &value_1);
  s21_from_str_to_decimal("777", &value_2);

  ck_assert_int_eq(s21_is_greater(value_1, value_2), FALSE);
}
END_TEST

START_TEST(greater_with_sign_false) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("-1234567890", &value_1);
  s21_from_str_to_decimal("1234567890", &value_2);

  ck_assert_int_eq(s21_is_greater(value_1, value_2), FALSE);
}
END_TEST

START_TEST(greater_with_sign_true) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("1234567890", &value_1);
  s21_from_str_to_decimal("-1234567890", &value_2);

  ck_assert_int_eq(s21_is_greater(value_1, value_2), TRUE);
}
END_TEST

START_TEST(less_with_zero_false) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), FALSE);
}
END_TEST

START_TEST(less_with_minus_zero_false) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("-0", &value_1);
  s21_from_str_to_decimal("-0.0", &value_2);

  ck_assert_int_eq(s21_is_less(value_1, value_2), FALSE);
}
END_TEST

START_TEST(less_with_minus_zero_false_2) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("-0.0", &value_1);
  s21_from_str_to_decimal("0.0", &value_2);

  ck_assert_int_eq(s21_is_less(value_1, value_2), FALSE);
}
END_TEST

START_TEST(less_default_true) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("420.0", &value_1);
  s21_from_str_to_decimal("4200.0", &value_2);

  ck_assert_int_eq(s21_is_less(value_1, value_2), TRUE);
}
END_TEST

START_TEST(less_default_true_2) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("4200.0000000000", &value_1);
  s21_from_str_to_decimal("4200.00000000001", &value_2);

  ck_assert_int_eq(s21_is_less(value_1, value_2), TRUE);
}
END_TEST

START_TEST(less_default_true_3) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("7", &value_1);
  s21_from_str_to_decimal("420", &value_2);

  ck_assert_int_eq(s21_is_less(value_1, value_2), TRUE);
}
END_TEST

START_TEST(less_default_false) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("1234567890", &value_1);
  s21_from_str_to_decimal("777", &value_2);

  ck_assert_int_eq(s21_is_less(value_1, value_2), FALSE);
}
END_TEST

START_TEST(less_with_sign_false) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("1234567890", &value_1);
  s21_from_str_to_decimal("-1234567890", &value_2);

  ck_assert_int_eq(s21_is_less(value_1, value_2), FALSE);
}
END_TEST

START_TEST(less_with_sign_true) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("-1234567890", &value_1);
  s21_from_str_to_decimal("1234567890", &value_2);

  ck_assert_int_eq(s21_is_less(value_1, value_2), TRUE);
}
END_TEST

START_TEST(greater_or_equal_with_zero) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(greater_or_equal_with_minus_zero) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("-0", &value_1);
  s21_from_str_to_decimal("0.0", &value_2);

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(greater_or_equal_default_true_1) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("0.987654320", &value_1);
  s21_from_str_to_decimal("0.987654320", &value_2);

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(greater_or_equal_default_true_2) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("0.987654321", &value_1);
  s21_from_str_to_decimal("0.987654320", &value_2);

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(greater_or_equal_default_true_3) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("456", &value_1);
  s21_from_str_to_decimal("123", &value_2);

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(greater_or_equal_default_true_4) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("123", &value_1);
  s21_from_str_to_decimal("123", &value_2);

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(greater_or_equal_default_false) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("0.987654320", &value_1);
  s21_from_str_to_decimal("0.987654321", &value_2);

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), FALSE);
}
END_TEST

START_TEST(greater_or_equal_with_sign_false) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("-0.987654321", &value_1);
  s21_from_str_to_decimal("0.987654321", &value_2);

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), FALSE);
}
END_TEST

START_TEST(greater_or_equal_with_sign_true) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("-0.987654321", &value_1);
  s21_from_str_to_decimal("-0.987654321", &value_2);

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(less_or_equal_with_zero) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(less_or_equal_with_minus_zero) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("-0", &value_1);
  s21_from_str_to_decimal("0.0", &value_2);

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(less_or_equal_default_true_1) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("0.987654320", &value_1);
  s21_from_str_to_decimal("0.987654320", &value_2);

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(less_or_equal_default_true_2) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("0.987654320", &value_1);
  s21_from_str_to_decimal("0.987654321", &value_2);

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(less_or_equal_default_true_3) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("123", &value_1);
  s21_from_str_to_decimal("456", &value_2);

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(less_or_equal_default_true_4) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("123", &value_1);
  s21_from_str_to_decimal("123", &value_2);

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), TRUE);
}
END_TEST

START_TEST(less_or_equal_default_false) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("0.987654321", &value_1);
  s21_from_str_to_decimal("0.987654320", &value_2);

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), FALSE);
}
END_TEST

START_TEST(less_or_equal_with_sign_false) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("0.987654321", &value_1);
  s21_from_str_to_decimal("-0.987654321", &value_2);

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), FALSE);
}
END_TEST

START_TEST(less_or_equal_with_sign_true) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_from_str_to_decimal("-0.987654321", &value_1);
  s21_from_str_to_decimal("-0.987654321", &value_2);

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), TRUE);
}
END_TEST

// int main(void)
// {
//     Suite *s1 = suite_create("Core");
//     TCase *tc1_1 = tcase_create("equal");
//     TCase *tc1_2 = tcase_create("not_equal");
//     TCase *tc1_3 = tcase_create("greater");
//     TCase *tc1_4 = tcase_create("less");
//     TCase *tc1_5 = tcase_create("greater_or_equal");
//     TCase *tc1_6 = tcase_create("less_or_equal");
//     SRunner *sr = srunner_create(s1);
//     int nf;

//     /* User-specified pre-run code */
//     srunner_set_fork_status(sr, CK_NOFORK);

//     suite_add_tcase(s1, tc1_1);
//     tcase_add_test(tc1_1, equal_with_zero_true);
//     tcase_add_test(tc1_1, equal_with_minus_zero_true);
//     tcase_add_test(tc1_1, equal_with_minus_zero_true_2);
//     tcase_add_test(tc1_1, equal_default_true);
//     tcase_add_test(tc1_1, equal_default_true_2);
//     tcase_add_test(tc1_1, equal_default_true_3);
//     tcase_add_test(tc1_1, equal_default_false_1);
//     tcase_add_test(tc1_1, equal_default_false_2);
//     tcase_add_test(tc1_1, equal_default_false_3);
//     tcase_add_test(tc1_1, equal_with_sign);
//     suite_add_tcase(s1, tc1_2);
//     tcase_add_test(tc1_2, not_equal_with_zero_false);
//     tcase_add_test(tc1_2, not_equal_with_minus_zero_false);
//     tcase_add_test(tc1_2, not_equal_with_minus_zero_false_2);
//     tcase_add_test(tc1_2, not_equal_default_false);
//     tcase_add_test(tc1_2, not_equal_default_false_2);
//     tcase_add_test(tc1_2, not_equal_default_false_3);
//     tcase_add_test(tc1_2, not_equal_default_true_1);
//     tcase_add_test(tc1_2, not_equal_default_true_2);
//     tcase_add_test(tc1_2, not_equal_default_true_3);
//     tcase_add_test(tc1_2, not_equal_with_sign);
//     suite_add_tcase(s1, tc1_3);
//     tcase_add_test(tc1_3, greater_with_zero_false);
//     tcase_add_test(tc1_3, greater_with_minus_zero_false);
//     tcase_add_test(tc1_3, greater_with_minus_zero_false_2);
//     tcase_add_test(tc1_3, greater_default_true);
//     tcase_add_test(tc1_3, greater_default_true_2);
//     tcase_add_test(tc1_3, greater_default_true_3);
//     tcase_add_test(tc1_3, greater_default_false);
//     tcase_add_test(tc1_3, greater_with_sign_false);
//     tcase_add_test(tc1_3, greater_with_sign_true);
//     suite_add_tcase(s1, tc1_4);
//     tcase_add_test(tc1_4, less_with_zero_false);
//     tcase_add_test(tc1_4, less_with_minus_zero_false);
//     tcase_add_test(tc1_4, less_with_minus_zero_false_2);
//     tcase_add_test(tc1_4, less_default_true);
//     tcase_add_test(tc1_4, less_default_true_2);
//     tcase_add_test(tc1_4, less_default_true_3);
//     tcase_add_test(tc1_4, less_default_false);
//     tcase_add_test(tc1_4, less_with_sign_false);
//     tcase_add_test(tc1_4, less_with_sign_true);
//     suite_add_tcase(s1, tc1_5);
//     tcase_add_test(tc1_5, greater_or_equal_with_zero);
//     tcase_add_test(tc1_5, greater_or_equal_with_minus_zero);
//     tcase_add_test(tc1_5, greater_or_equal_default_true_1);
//     tcase_add_test(tc1_5, greater_or_equal_default_true_2);
//     tcase_add_test(tc1_5, greater_or_equal_default_true_3);
//     tcase_add_test(tc1_5, greater_or_equal_default_true_4);
//     tcase_add_test(tc1_5, greater_or_equal_default_false);
//     tcase_add_test(tc1_5, greater_or_equal_with_sign_false);
//     tcase_add_test(tc1_5, greater_or_equal_with_sign_true);
//     suite_add_tcase(s1, tc1_6);
//     tcase_add_test(tc1_6, less_or_equal_with_zero);
//     tcase_add_test(tc1_6, less_or_equal_with_minus_zero);
//     tcase_add_test(tc1_6, less_or_equal_default_true_1);
//     tcase_add_test(tc1_6, less_or_equal_default_true_2);
//     tcase_add_test(tc1_6, less_or_equal_default_true_3);
//     tcase_add_test(tc1_6, less_or_equal_default_true_4);
//     tcase_add_test(tc1_6, less_or_equal_default_false);
//     tcase_add_test(tc1_6, less_or_equal_with_sign_false);
//     tcase_add_test(tc1_6, less_or_equal_with_sign_true);

//     srunner_run_all(sr, CK_ENV);
//     nf = srunner_ntests_failed(sr);
//     srunner_free(sr);

//     return nf == 0 ? 0 : 1;
// }
