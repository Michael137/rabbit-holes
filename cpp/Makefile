STDLIB=libc++
CC=clang++
STD=c++2a
CXXFLAGS=-std=${STD} -O3 -Wall -Werror -Wpedantic -stdlib=${STDLIB} ${SANITIZER_FLAGS}

all: clean compile

.PHONY:
clean:
	@rm -f a.out

compile: int_vs_real_dist.cc
	$(CC) $(CXXFLAGS) $(LDFLAGS) $(LINK_PROFILER) $^
