#include "arithmetic_tests.c"
#include "comparison_tests.c"
#include "convertation_tests.c"
#include "other_tests.c"
#include "tests.h"

int arithmetic_test(void) {
  Suite *s1 = suite_create("arithmetic_functions_tests");
  TCase *tc1_1 = tcase_create("arithmetic_functions_tests");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, add_test_normal_values_n1);
  tcase_add_test(tc1_1, add_test_normal_values_n2);
  tcase_add_test(tc1_1, add_test_normal_values_n3);
  tcase_add_test(tc1_1, add_test_normal_values_n4);
  tcase_add_test(tc1_1, add_test_normal_values_n5);
  tcase_add_test(tc1_1, add_test_cringe_values_n6);
  tcase_add_test(tc1_1, add_test_cringe_values_n7);
  tcase_add_test(tc1_1, add_test_normal_values_n8);
  tcase_add_test(tc1_1, add_test_cringe_values_n9);
  tcase_add_test(tc1_1, add_test_cringe_values_n10);
  tcase_add_test(tc1_1, add_test_normal_values_n11);
  tcase_add_test(tc1_1, add_test_normal_values_n12);
  tcase_add_test(tc1_1, sub_test_cringe_values_n1);
  tcase_add_test(tc1_1, sub_test_cringe_values_n2);
  tcase_add_test(tc1_1, sub_test_cringe_values_n3);
  tcase_add_test(tc1_1, sub_test_cringe_values_n4);
  tcase_add_test(tc1_1, sub_test_cringe_values_n5);
  tcase_add_test(tc1_1, sub_test_normal_values_n6);
  tcase_add_test(tc1_1, sub_test_normal_values_n7);
  tcase_add_test(tc1_1, sub_test_normal_values_n8);
  tcase_add_test(tc1_1, sub_test_normal_values_n9);
  tcase_add_test(tc1_1, sub_test_normal_values_n10);
  tcase_add_test(tc1_1, sub_test_normal_values_n11);
  tcase_add_test(tc1_1, sub_test_normal_values_n12);
  tcase_add_test(tc1_1, sub_test_normal_values_n13);
  tcase_add_test(tc1_1, sub_test_normal_values_n14);
  tcase_add_test(tc1_1, sub_test_normal_values_n15);
  tcase_add_test(tc1_1, mul_test_normal_values_n1);
  tcase_add_test(tc1_1, mul_test_normal_values_n2);
  tcase_add_test(tc1_1, mul_test_normal_values_n3);
  tcase_add_test(tc1_1, mul_test_normal_values_n4);
  tcase_add_test(tc1_1, mul_test_normal_values_n5);
  tcase_add_test(tc1_1, mul_test_normal_values_n6);
  tcase_add_test(tc1_1, mul_test_normal_values_n7);
  tcase_add_test(tc1_1, mul_test_normal_values_n8);
  tcase_add_test(tc1_1, mul_test_normal_values_n9);
  tcase_add_test(tc1_1, mul_test_normal_values_n10);
  tcase_add_test(tc1_1, mul_test_normal_values_n11);
  tcase_add_test(tc1_1, mul_test_normal_values_n12);
  tcase_add_test(tc1_1, mul_test_normal_values_n13);
  tcase_add_test(tc1_1, mul_test_normal_values_n14);
  tcase_add_test(tc1_1, mul_test_normal_values_n15);
  tcase_add_test(tc1_1, mul_test_normal_values_n16);
  tcase_add_test(tc1_1, mul_test_normal_values_n17);
  tcase_add_test(tc1_1, mul_test_normal_values_n18);
  tcase_add_test(tc1_1, mul_test_normal_values_n19);
  tcase_add_test(tc1_1, mul_test_normal_values_n20);
  tcase_add_test(tc1_1, div_test_normal_values_n1);
  tcase_add_test(tc1_1, div_test_normal_values_n2);
  tcase_add_test(tc1_1, div_test_normal_values_n3);
  tcase_add_test(tc1_1, div_test_normal_values_n4);
  tcase_add_test(tc1_1, div_test_normal_values_n5);
  tcase_add_test(tc1_1, div_test_normal_values_n6);
  tcase_add_test(tc1_1, div_test_normal_values_n7);
  tcase_add_test(tc1_1, div_test_normal_values_n8);
  tcase_add_test(tc1_1, div_test_normal_values_n9);
  tcase_add_test(tc1_1, div_test_normal_values_n10);
  tcase_add_test(tc1_1, div_test_normal_values_n11);
  tcase_add_test(tc1_1, div_test_normal_values_n12);
  tcase_add_test(tc1_1, div_test_normal_values_n13);
  tcase_add_test(tc1_1, div_test_normal_values_n14);
  tcase_add_test(tc1_1, div_test_normal_values_n15);
  tcase_add_test(tc1_1, div_test_normal_values_n16);
  tcase_add_test(tc1_1, div_test_normal_values_n17);
  tcase_add_test(tc1_1, div_test_normal_values_n18);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return nf == 0 ? 0 : 1;
}

int other_test(void) {
  Suite *s1 = suite_create("other_functions_tests");
  TCase *tc1_1 = tcase_create("other_functions_tests");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, floor_normal_value_n1);
  tcase_add_test(tc1_1, floor_normal_value_n2);
  tcase_add_test(tc1_1, floor_normal_value_n3);
  tcase_add_test(tc1_1, floor_normal_value_n4);
  tcase_add_test(tc1_1, floor_normal_value_n5);
  tcase_add_test(tc1_1, floor_normal_value_n6);
  tcase_add_test(tc1_1, floor_normal_value_n7);
  tcase_add_test(tc1_1, floor_normal_value_n8);
  tcase_add_test(tc1_1, floor_normal_value_n9);
  tcase_add_test(tc1_1, floor_normal_value_n10);
  tcase_add_test(tc1_1, floor_normal_value_n11);
  tcase_add_test(tc1_1, floor_normal_value_n12);
  tcase_add_test(tc1_1, floor_normal_value_n13);
  tcase_add_test(tc1_1, floor_normal_value_n14);
  tcase_add_test(tc1_1, floor_normal_value_n15);
  tcase_add_test(tc1_1, round_normal_value_n1);
  tcase_add_test(tc1_1, round_normal_value_n2);
  tcase_add_test(tc1_1, round_normal_value_n3);
  tcase_add_test(tc1_1, round_normal_value_n4);
  tcase_add_test(tc1_1, round_normal_value_n5);
  tcase_add_test(tc1_1, round_normal_value_n6);
  tcase_add_test(tc1_1, round_normal_value_n7);
  tcase_add_test(tc1_1, round_normal_value_n8);
  tcase_add_test(tc1_1, round_normal_value_n9);
  tcase_add_test(tc1_1, round_normal_value_n10);
  tcase_add_test(tc1_1, round_normal_value_n11);
  tcase_add_test(tc1_1, round_normal_value_n12);
  tcase_add_test(tc1_1, round_normal_value_n13);
  tcase_add_test(tc1_1, round_normal_value_n14);
  tcase_add_test(tc1_1, round_normal_value_n15);
  tcase_add_test(tc1_1, negate_normal_value_n1);
  tcase_add_test(tc1_1, negate_normal_value_n2);
  tcase_add_test(tc1_1, negate_normal_value_n3);
  tcase_add_test(tc1_1, negate_normal_value_n4);
  tcase_add_test(tc1_1, negate_normal_value_n5);
  tcase_add_test(tc1_1, negate_normal_value_n6);
  tcase_add_test(tc1_1, negate_normal_value_n7);
  tcase_add_test(tc1_1, truncate_normal_value_n1);
  tcase_add_test(tc1_1, truncate_normal_value_n2);
  tcase_add_test(tc1_1, truncate_normal_value_n3);
  tcase_add_test(tc1_1, truncate_normal_value_n4);
  tcase_add_test(tc1_1, truncate_normal_value_n5);
  tcase_add_test(tc1_1, truncate_normal_value_n6);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

int comparison_test(void) {
  Suite *s1 = suite_create("comparison_functions_tests");
  TCase *tc1_1 = tcase_create("equal");
  TCase *tc1_2 = tcase_create("not_equal");
  TCase *tc1_3 = tcase_create("greater");
  TCase *tc1_4 = tcase_create("less");
  TCase *tc1_5 = tcase_create("greater_or_equal");
  TCase *tc1_6 = tcase_create("less_or_equal");
  SRunner *sr = srunner_create(s1);
  int nf;

  srunner_set_fork_status(sr, CK_NOFORK);

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, equal_with_zero_true);
  tcase_add_test(tc1_1, equal_with_minus_zero_true);
  tcase_add_test(tc1_1, equal_with_minus_zero_true_2);
  tcase_add_test(tc1_1, equal_default_true);
  tcase_add_test(tc1_1, equal_default_true_2);
  tcase_add_test(tc1_1, equal_default_true_3);
  tcase_add_test(tc1_1, equal_default_false_1);
  tcase_add_test(tc1_1, equal_default_false_2);
  tcase_add_test(tc1_1, equal_default_false_3);
  tcase_add_test(tc1_1, equal_with_sign);
  suite_add_tcase(s1, tc1_2);
  tcase_add_test(tc1_2, not_equal_with_zero_false);
  tcase_add_test(tc1_2, not_equal_with_minus_zero_false);
  tcase_add_test(tc1_2, not_equal_with_minus_zero_false_2);
  tcase_add_test(tc1_2, not_equal_default_false);
  tcase_add_test(tc1_2, not_equal_default_false_2);
  tcase_add_test(tc1_2, not_equal_default_false_3);
  tcase_add_test(tc1_2, not_equal_default_true_1);
  tcase_add_test(tc1_2, not_equal_default_true_2);
  tcase_add_test(tc1_2, not_equal_default_true_3);
  tcase_add_test(tc1_2, not_equal_with_sign);
  suite_add_tcase(s1, tc1_3);
  tcase_add_test(tc1_3, greater_with_zero_false);
  tcase_add_test(tc1_3, greater_with_minus_zero_false);
  tcase_add_test(tc1_3, greater_with_minus_zero_false_2);
  tcase_add_test(tc1_3, greater_default_true);
  tcase_add_test(tc1_3, greater_default_true_2);
  tcase_add_test(tc1_3, greater_default_true_3);
  tcase_add_test(tc1_3, greater_default_false);
  tcase_add_test(tc1_3, greater_with_sign_false);
  tcase_add_test(tc1_3, greater_with_sign_true);
  suite_add_tcase(s1, tc1_4);
  tcase_add_test(tc1_4, less_with_zero_false);
  tcase_add_test(tc1_4, less_with_minus_zero_false);
  tcase_add_test(tc1_4, less_with_minus_zero_false_2);
  tcase_add_test(tc1_4, less_default_true);
  tcase_add_test(tc1_4, less_default_true_2);
  tcase_add_test(tc1_4, less_default_true_3);
  tcase_add_test(tc1_4, less_default_false);
  tcase_add_test(tc1_4, less_with_sign_false);
  tcase_add_test(tc1_4, less_with_sign_true);
  suite_add_tcase(s1, tc1_5);
  tcase_add_test(tc1_5, greater_or_equal_with_zero);
  tcase_add_test(tc1_5, greater_or_equal_with_minus_zero);
  tcase_add_test(tc1_5, greater_or_equal_default_true_1);
  tcase_add_test(tc1_5, greater_or_equal_default_true_2);
  tcase_add_test(tc1_5, greater_or_equal_default_true_3);
  tcase_add_test(tc1_5, greater_or_equal_default_true_4);
  tcase_add_test(tc1_5, greater_or_equal_default_false);
  tcase_add_test(tc1_5, greater_or_equal_with_sign_false);
  tcase_add_test(tc1_5, greater_or_equal_with_sign_true);
  suite_add_tcase(s1, tc1_6);
  tcase_add_test(tc1_6, less_or_equal_with_zero);
  tcase_add_test(tc1_6, less_or_equal_with_minus_zero);
  tcase_add_test(tc1_6, less_or_equal_default_true_1);
  tcase_add_test(tc1_6, less_or_equal_default_true_2);
  tcase_add_test(tc1_6, less_or_equal_default_true_3);
  tcase_add_test(tc1_6, less_or_equal_default_true_4);
  tcase_add_test(tc1_6, less_or_equal_default_false);
  tcase_add_test(tc1_6, less_or_equal_with_sign_false);
  tcase_add_test(tc1_6, less_or_equal_with_sign_true);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

int convertation_test(void) {
  Suite *s1 = suite_create("convertation_functions_tests");
  TCase *tc1_1 = tcase_create("from_decimal_to_float");
  TCase *tc1_2 = tcase_create("from_decimal_to_int");
  TCase *tc1_3 = tcase_create("from_float_to_decimal");
  TCase *tc1_4 = tcase_create("from_int_to_decimal");
  SRunner *sr = srunner_create(s1);
  int nf;

  srunner_set_fork_status(sr, CK_NOFORK);

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, from_decimal_to_float_zero);
  tcase_add_test(tc1_1, from_decimal_to_float_default_1);
  tcase_add_test(tc1_1, from_decimal_to_float_default_2);
  tcase_add_test(tc1_1, from_decimal_to_float_default_minus_1);
  tcase_add_test(tc1_1, from_decimal_to_float_default_minus_2);
  suite_add_tcase(s1, tc1_2);
  tcase_add_test(tc1_2, from_decimal_to_int_zero);
  tcase_add_test(tc1_2, from_decimal_to_int_minus);
  tcase_add_test(tc1_2, from_decimal_to_int_default);
  tcase_add_test(tc1_2, from_decimal_to_int_too_big_int);
  tcase_add_test(tc1_2, from_decimal_to_int_too_small_int);
  tcase_add_test(tc1_2, from_decimal_to_int_rounding);
  tcase_add_test(tc1_2, from_decimal_to_int_rounding_minus);
  suite_add_tcase(s1, tc1_3);
  tcase_add_test(tc1_3, from_float_to_decimal_default);
  tcase_add_test(tc1_3, from_float_to_decimal_default_2);
  tcase_add_test(tc1_3, from_float_to_decimal_default_3);
  tcase_add_test(tc1_3, from_float_to_decimal_default_minus);
  tcase_add_test(tc1_3, from_float_to_decimal_minus_scale);
  tcase_add_test(tc1_3, from_float_to_decimal_scale);
  suite_add_tcase(s1, tc1_4);
  tcase_add_test(tc1_4, from_int_to_decimal_zero);
  tcase_add_test(tc1_4, from_int_to_decimal_default_1);
  tcase_add_test(tc1_4, from_int_to_decimal_default_2);
  tcase_add_test(tc1_4, from_int_to_decimal_minus);
  tcase_add_test(tc1_4, from_int_to_decimal_minus_2);
  tcase_add_test(tc1_4, from_int_to_decimal_too_big);
  tcase_add_test(tc1_4, from_int_to_decimal_too_small);
  tcase_add_test(tc1_4, from_int_to_decimal_rounding_1);
  tcase_add_test(tc1_4, from_int_to_decimal_rounding_2);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

int main(void) {
  int nf = other_test();
  printf("\n");
  nf += arithmetic_test();
  printf("\n");
  nf += comparison_test();
  printf("\n");
  nf += convertation_test();

  return nf == 0 ? 0 : 1;
}