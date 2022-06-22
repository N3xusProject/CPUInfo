CFLAGS = -march=native -Iinclude
CFILES = $(wildcard src/*.c)
CC = gcc

bin/cpuinfo: $(CFILES)
	@mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@ -lcpuinfo

install_deps:
	cd lib/libcpuinfo; sudo make; sudo make install; sudo make clean
