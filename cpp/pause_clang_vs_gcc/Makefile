ifeq ($(CC),cc)
	CC:=clang++
endif

CXXFLAGS=-O0 -Wall -Werror -Wpedantic -S $(FLAGS)

all: clean compile

.PHONY:
clean:
	@rm -f a.out
	@rm -f *.s

compile: pause.cc
	$(CC) $(CXXFLAGS) $(LDFLAGS) $(PROFILER) $^
