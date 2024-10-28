#!/bin/sh

if [ $1 = -p ]; then
  ./fft.out
  ./fft.out > spectre.txt
  echo "\nAll of the output is in the spectre.txt of course\n"
else
  ./fft.out > spectre.txt
  echo "All output is now in spectre.txt!\n"
fi
