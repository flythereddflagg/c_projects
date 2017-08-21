#!/bin/bash

set -e

make clean
clear
make

./main.exe

# valgrind ./main.exe
