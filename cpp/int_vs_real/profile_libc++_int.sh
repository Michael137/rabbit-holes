#!/bin/bash

PROFILE_FILE=libc++.data
CC=clang++ STDLIB=libc++ FLAGS="-g -DPROFILE_INT" make all

sudo perf record -g -o ${PROFILE_FILE} ./a.out
sudo perf report -i ${PROFILE_FILE}
