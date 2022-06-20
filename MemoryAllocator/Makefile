# Makefile for the ROS 2 Allocator
CC = g++

# CFLAGS build with all warnings and C++ 17
CFLAGS = -c -Wall -std=c++17

all: main

test: main.o ROSAllocator.o
	$(CC) main.o -o test
	
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
	
clean:
	rm main.o main

