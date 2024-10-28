#!/bin/sh

CFLAGS="-Wextra -Wall -Iinclude"

clang $CFLAGS -o fft.out src/*.c
