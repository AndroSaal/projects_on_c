#include "s21_strerror.h"

char *s21_strerror(int errnum) {
  static char *errors_arr[SIZE_OF_ERRORLIST] = ERRORLIST;
  static char unknown_error[1024];  // статический массив для сообщения о
                                    // неизвестной ошибке
  char *error = s21_NULL;

  if (errnum >= 0 && errnum < SIZE_OF_ERRORLIST) {
    error = errors_arr[errnum];
  } else {
    s21_strncpy(unknown_error, UNKNOWN, sizeof(unknown_error) - 1);

    unknown_error[sizeof(unknown_error) - 1] = '\0';

    int offset = s21_strlen(unknown_error);
    if (errnum < 0) {
      unknown_error[offset++] = '-';
      errnum = -errnum;
    }

    int start = offset;
    do {
      unknown_error[offset++] = (errnum % 10) + '0';
      errnum /= 10;
    } while (errnum > 0 && offset < (int)(sizeof(unknown_error) - 1));

    for (int i = start, j = offset - 1; i < j; i++, j--) {
      char temp = unknown_error[i];
      unknown_error[i] = unknown_error[j];
      unknown_error[j] = temp;
    }
    unknown_error[offset] = '\0';

    error = unknown_error;
  }

  return error;
}
