#!/bin/bash

LINK_PROFILER=-lprofiler make all

CPUPROFILE=gprofile.txt ./a.out

pprof --text a.out gprofile.txt
