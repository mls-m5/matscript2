
.PHONY: tests

all: matscript tests

matscript:
	make -C src/
	g++ main.cpp src/*.o -o matscript -std=c++11 -g -Iinclude
	

tests:
	@echo building tests...
	make -C tests/