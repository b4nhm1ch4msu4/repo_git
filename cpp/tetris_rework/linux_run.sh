#!/usr/bin/bash

rm -rf build/*
cd build
cmake ..
make
cd bin
cp tetris ../../
cd ../../
echo $(pwd)
./tetris
