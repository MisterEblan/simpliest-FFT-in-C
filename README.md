# My own implementation of Fast Fourier Transform (FFT) algorithm

It's the simpliest implementation of FFT algorithm made by my own from scratch.
It was difficult to understand the concept of this algorithm and of course I still don't fully understand it, but i tried my best.

# What's the function used for testing?

The function defined in `generate_sin.c` file and it's formula is $\sin(10 * 2\pi x) + 0.5 * \sin(5 * 2\pi x)$.

I took 2048 points with sample rate 1000 Hz.

# How to build and run project

## Compiler

I used `clang` for compilation.

## Scripts

I haven't made a lot of .sh scripts yet, but I've made two little scripts to build (`build.sh`) project and run (`run.sh`) to run it *after building.*

### `run.sh` script flag

By default `run.sh` execute `fft.out` (the result of building a project) and stream it in `spectre.txt` without any output in console.

If `-p` flag added it will first print output in console and then run the executable again and strem it in `spectre.txt`.

### What's the output?

Output of a builded is kinda spectrogram that made with `#` symbol.

You can change its *"scale"* by changing step (line 30) in `printSpectre()` function source code of which is located in `src` directory
