#!/bin/bash

set -e

make clean
clear
make

./out.exe

# valgrind ./out.exe
