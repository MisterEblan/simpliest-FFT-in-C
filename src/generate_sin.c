#include <complex.h>
#include <math.h>
#include <stdlib.h>

complex double *generateSin(int numOfPoints) {
  complex double *result =
      (complex double *)malloc(numOfPoints * sizeof(complex double));

  double k = 0.00;
  for (int i = 0; i < numOfPoints; i++) {
    complex double value =
        sin(10 * 2.00 * M_PI * k) + 0.5 * sin(5 * 2 * M_PI * k);
    result[i] = value;

    k += 0.001;
  }

  return result;
}
