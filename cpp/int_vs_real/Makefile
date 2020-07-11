STD:=$(or $(STD),c++2a)

ifeq ($(CC),cc)
	CC:=clang++
endif

ifeq ($(findstring clang,$(CC)), clang)
  STDLIB:=$(or $(STDLIB),libc++)
  STDLIB_FLAG:=-stdlib=$(STDLIB)
endif

CXXFLAGS=-std=$(STD) -O3 -Wall -Werror -Wpedantic $(STDLIB_FLAG) $(SANITIZER_FLAGS) $(FLAGS)

all: clean compile

.PHONY:
clean:
	@rm -f a.out
	@rm -f *.old
	@rm -f *.data

compile: int_vs_real_dist.cc
	$(CC) $(CXXFLAGS) $(LDFLAGS) $(PROFILER) $^
