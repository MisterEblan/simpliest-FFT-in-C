#include <complex.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double *findAmplitude(complex double *fftResult, int N) {
  double *result = (double *)malloc(N * sizeof(double));

  for (int i = 0; i < N; i++) {
    complex double realPart = creal(fftResult[i]);
    complex double imagPart = cimag(fftResult[i]);
    result[i] = sqrt(pow(creal(realPart), 2) + pow(cimag(imagPart), 2));
  }
  return result;
}

double *findFrequency(int N, int sampleRate) {
  double *result = (double *)malloc(N * sizeof(double));

  for (int i = 0; i < N; i++)
    result[i] = (i * sampleRate) / (double)N;

  return result;
}

void printSpectre(double *freqs, double *amps) {
  printf("\nГистограмма:\n");
  for (int i = 0; i < 32; i++) {
    printf("%10f: ", freqs[i]);
    for (double j = 0.00; j <= amps[i]; j += 10)
      printf("#");
    printf("\n");
  }
}
