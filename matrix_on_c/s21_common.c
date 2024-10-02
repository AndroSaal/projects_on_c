#include "s21_matrix.h"

// сравнение (небезопасная функция)
int s21_compare_matrix(
    matrix_t A, matrix_t B) {  // сюда поступают корр. матрицы равного размера
  int compare_result = SUCCESS;

  for (int i = 0; i < A.rows && compare_result; i++) {
    for (int j = 0; j < A.columns && compare_result; j++) {
      if (fabs(fabs(A.matrix[i][j]) - fabs(B.matrix[i][j])) > 1e-7) {
        compare_result = FAILURE;
      }
    }
  }

  return compare_result;
}

// заполнение матрицы
void s21_fill_matrix(matrix_t* A, double start, double step) {
  if (!s21_valid_matrix(A)) {
    double cur = start;

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        A->matrix[i][j] = cur;
        cur += step;
      }
    }
  }
}

// первичная проверка на валилдность
int s21_valid_matrix(matrix_t* A) {
  int error_code = OK;

  if (A) {
    if (A->matrix != NULL && A->rows > 0 && A->columns > 0)
      error_code = s21_check_matrix(A);
    else
      error_code = INCORR_MATRIX_ERROR;
  } else
    error_code = INCORR_MATRIX_ERROR;

  return error_code;
}

// вторичная проверка на валидность
int s21_check_matrix(matrix_t* A) {
  int error_code = OK;

  for (int i = 0; i < A->rows && !error_code; i++) {
    if (!A->matrix[i]) {
      error_code = INCORR_MATRIX_ERROR;
      //   fprintf(stderr, "LOL\n");
      //   break;
    }
    for (int j = 0; j < A->columns && !error_code; j++) {
      if (isinf(A->matrix[i][j]) || isnan(A->matrix[i][j]))
        error_code = MATH_ERROR;
    }
  }

  return error_code;
}

void s21_print_error(char* func_name, int error_code) {
  char error_massage_1[] = "GOT INCORRECT MATRIX, ERROR_CODE IS : ";
  char error_massage_2[] =
      "GOT MATH ERROR : WRONG SIZES or smth, ERROR_CODE IS : ";

  fprintf(stderr, "function where error came from is %s\n%s%d\n\n", func_name,
          error_code == 1 ? error_massage_1 : error_massage_2, error_code);
}

// void print_matrix(matrix_t matrix) {
//   for (int i = 0; i < matrix.rows; i++) {
//     for (int j = 0; j < matrix.columns; j++) {
//       printf("el_[%d][%d] is %lf ", i, j, matrix.matrix[i][j]);
//     }
//     printf("\n");
//   }
//   printf("\n");
// }
