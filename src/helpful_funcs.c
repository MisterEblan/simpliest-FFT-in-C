#include <complex.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Description:
 *   Calculate amplitudes of the FFT algorithm output.
 *
 * Input:
 *   fftResult - result of the FFT algorithm that contains complex numbers.
 *   N - number of points.
 *
 * Output:
 *   Returns a pointer to double that contains calculated amplitudes.
 **/
double *findAmplitude(complex double *fftResult, int N) {
  double *result = (double *)malloc(N * sizeof(double));

  for (int i = 0; i < N; i++) {
    complex double realPart = creal(fftResult[i]);
    complex double imagPart = cimag(fftResult[i]);
    result[i] = sqrt(pow(creal(realPart), 2) + pow(cimag(imagPart), 2));
  }
  return result;
}

/**
 * Description:
 *   Calculate frequencies for the exact number of points.
 * Input:
 *   N - number of points.
 *   sampleRate - sample rate of the signal.
 * Output:
 *   Returns a pointer to double that contains calculated frequencies.
 **/
double *findFrequency(int N, int sampleRate) {
  double *result = (double *)malloc(N * sizeof(double));

  for (int i = 0; i < N; i++)
    result[i] = (i * sampleRate) / (double)N;

  return result;
}

/**
 * Description:
 *   Prints very simple spectrogram in console
 * Input:
 *   freqs - pointer to double with calculated frequencies.
 *   amps - pointer to double with calculated amplitudes.
 * Output:
 *   Returns nothing, prints spectrogram in console.
 **/
void printSpectre(double *freqs, double *amps) {
  printf("\nSpectrogram:\n");
  for (int i = 0; i < 32; i++) {
    printf("%10f: ", freqs[i]);
    // The line below is responsible for scale
    // of spectrogram
    for (double j = 0.00; j <= amps[i]; j += 10)
      printf("#");
    printf("\n");
  }
}
