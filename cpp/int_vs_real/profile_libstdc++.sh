#!/bin/bash

PROFILE_FILE=libstdc++.data
CC=g++ STDLIB=libstdc++ FLAGS=-g make all

sudo perf record -g -o ${PROFILE_FILE} ./a.out
sudo perf report -i ${PROFILE_FILE}
