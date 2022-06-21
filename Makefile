CFLAGS = -march=native -Iinclude -masm=intel
CFILES = $(wildcard src/*.c)

bin/cpuinfo: $(CFILES)
	@mkdir -p bin
	clang $(CFLAGS) $^ -o $@
