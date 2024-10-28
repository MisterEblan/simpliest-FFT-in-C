#include <complex.h>
#include <math.h>
#include <stdlib.h>

complex double *fft(complex double *X, int N) {
  if (N <= 1)
    return X;

  complex double *result = (complex double *)malloc(N * sizeof(complex double));

  complex double *X_even =
      (complex double *)malloc(N / 2 * sizeof(complex double));

  complex double *X_odd =
      (complex double *)malloc(N / 2 * sizeof(complex double));

  for (int i = 0; i < N / 2; i++) {
    X_even[i] = X[i * 2];
    X_odd[i] = X[i * 2 + 1];
  }

  complex double *recurEven = fft(X_even, N / 2);
  complex double *recurOdd = fft(X_odd, N / 2);

  for (int k = 0; k < N / 2; k++) {
    complex double t = cexp(-2.0 * I * M_PI * k / N) * recurOdd[k];

    result[k] = recurEven[k] + t;
    result[k + N / 2] = recurEven[k] - t;
  }

  free(recurEven);
  free(recurOdd);

  return result;
}
