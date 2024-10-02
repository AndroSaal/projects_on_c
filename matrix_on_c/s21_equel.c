#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int compare_result = FAILURE;

  if (A && B) {  // проверка указателя
    if (A->matrix && B->matrix && A->columns == B->columns &&
        A->rows == B->rows) {  // проверка на корректность
      compare_result = s21_compare_matrix(*A, *B);
    }
  }

  return compare_result;
}
