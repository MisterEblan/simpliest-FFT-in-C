#include <complex.h>

#include "../include/fft_itself.h"
#include "../include/generate_sin.h"
#include "../include/helpful_funcs.h"

#define SAMPLE_RATE 1000

int main() {
  int N = 2048; // Количество точек
  complex double *generatedSin = generateSin(N);
  complex double *fftResult = fft(generatedSin, N);
  double *amps = findAmplitude(fftResult, N);
  double *freqs = findFrequency(N, SAMPLE_RATE);

  printSpectre(freqs, amps);

  return 0;
}
