/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "tests/test_difference.checkmk" instead.
 */

#include "test.h"

START_TEST(s21_sub_matrix_2) {
  // failure with different dimensions of matrices
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(5, 5, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), MATH_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_3) {
  // failure with non-finite value
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_fill_matrix(&A, 1, 1);
  s21_fill_matrix(&B, 1, 1);
  B.matrix[3][3] = INFINITY;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), MATH_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_4) {
  // sucess with initialized values
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t eq_matrix;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &eq_matrix);
  s21_fill_matrix(&A, 1, 1);
  s21_fill_matrix(&B, 1, 1);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_sub_matrix_5) {
  // sucess with uninitialized values
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t eq_matrix;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &eq_matrix);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_sub_matrix_6) {
  // sucess with task refence
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t eq_matrix;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &eq_matrix);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 5;
  A.matrix[2][0] = 0, A.matrix[2][1] = 0, A.matrix[2][2] = 6;
  B.matrix[0][0] = 1, B.matrix[0][1] = 0, B.matrix[0][2] = 0;
  B.matrix[1][0] = 2, B.matrix[1][1] = 0, B.matrix[1][2] = 0;
  B.matrix[2][0] = 3, B.matrix[2][1] = 4, B.matrix[2][2] = 1;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  eq_matrix.matrix[0][0] = 0, eq_matrix.matrix[0][1] = 2,
  eq_matrix.matrix[0][2] = 3;
  eq_matrix.matrix[1][0] = -2, eq_matrix.matrix[1][1] = 4,
  eq_matrix.matrix[1][2] = 5;
  eq_matrix.matrix[2][0] = -3, eq_matrix.matrix[2][1] = -4,
  eq_matrix.matrix[2][2] = 5;
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_sub_matrix_7) {
  // failure with NULL matrix
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_fill_matrix(&A, 1, 1);
  s21_fill_matrix(&B, 1, 1);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), INCORR_MATRIX_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

END_TEST

START_TEST(s21_sub_matrix_8) {
  // failure with NULL matrix
  matrix_t B;
  s21_create_matrix(3, 3, &B);
  s21_fill_matrix(&B, 1, 1);
  ck_assert_int_eq(s21_sub_matrix(NULL, &B, NULL), INCORR_MATRIX_ERROR);
  s21_remove_matrix(&B);
}

END_TEST

int test_difference_main(void) {
  Suite *s1 = suite_create("difference tests");
  TCase *tc1_1 = tcase_create("difference tests");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_sub_matrix_2);
  tcase_add_test(tc1_1, s21_sub_matrix_3);
  tcase_add_test(tc1_1, s21_sub_matrix_4);
  tcase_add_test(tc1_1, s21_sub_matrix_5);
  tcase_add_test(tc1_1, s21_sub_matrix_6);
  tcase_add_test(tc1_1, s21_sub_matrix_7);
  tcase_add_test(tc1_1, s21_sub_matrix_8);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
