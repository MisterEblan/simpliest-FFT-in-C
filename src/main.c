#include <complex.h>

#include "../include/fft_itself.h"
#include "../include/generate_sin.h"
#include "../include/helpful_funcs.h"

#define SAMPLE_RATE 1000

int main() {
  // Number of points
  int N = 2048;
  // Generated values of "signal"
  complex double *generatedSin = generateSin(N);
  // Result of the FFT algorithm
  complex double *fftResult = fft(generatedSin, N);
  // Amplitudes
  double *amps = findAmplitude(fftResult, N);
  // Frequencies
  double *freqs = findFrequency(N, SAMPLE_RATE);

  // Prints spectrogram
  printSpectre(freqs, amps);

  return 0;
}
