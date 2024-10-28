#ifndef HELPFUL_FUNCS_H
#define HELPFUL_FUNCS_H

#include <complex.h>

double *findAmplitude(complex double *fftResult, int N);
double *findFrequency(int N, int sampleRate);
void printSpectre(double *freqs, double *amps);

#endif
