#!/bin/bash

cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" 

make all

make compiler_tst; tst/compiler_tst