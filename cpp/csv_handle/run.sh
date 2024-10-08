#!/usr/bin/bash

rm -rd build/*
cd build || exit
cmake ..
make
cp bin/CSV_Handler ../
cd ..
./CSV_Handler
