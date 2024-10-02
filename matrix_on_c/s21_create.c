#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = OK;

  if (result) {
    result->rows = 0;
    result->columns = 0;
    result->matrix = NULL;

    if (rows > 0 && columns > 0) {
      result->rows = rows;
      result->columns = columns;

      result->matrix = (double **)calloc(result->rows, sizeof(double *));
      if (!result->matrix)
        error = INCORR_MATRIX_ERROR;
      else {
        for (int i = 0; i < result->rows && !error; i++) {
          result->matrix[i] = (double *)calloc(result->columns, sizeof(double));
          if (!result->matrix[i]) error = INCORR_MATRIX_ERROR;
        }
      }

    } else
      error = INCORR_MATRIX_ERROR;

  } else
    error = INCORR_MATRIX_ERROR;
  if (error) s21_remove_matrix(result);

  return error;
}
