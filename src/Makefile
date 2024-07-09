CPP=g++
CFLAGS=-Wall -Werror -Wextra -Wpedantic
STANDART=-std=c++17
GTEST=-lgtest

all: clean install tests

install: uninstall
	mkdir -p build && cd build && qmake ../view
	cd build && make 

uninstall:
	rm -rf build

dvi:
	doxygen

dist: install dvi
	mkdir -p dist
	tar cf dist/A1_MAZE_CPP_1.0 build doxygen

tests: clean
	$(CPP) $(CFLAGS) $(STANDART) -c eller/*.cpp file_handling/*.cpp maze/*.cpp waveAlgorithm/*.cpp tests/*.cpp $(GTEST)
	$(CPP) $(CFLAGS) $(STANDART) *.o -o unit_test $(GTEST)
	./unit_test

clean:
	@rm -rf \
	*.o 
	rm -rf doxygen
	rm -rf test
	rm -rf build dist
	rm -rf unit_tests

style:
	clang-format -i eller/*.* file_handling/*.* maze/*.*  tests/*.*  view/*.* waveAlgorithm/*.*
	clang-format -n eller/*.* file_handling/*.* maze/*.*  tests/*.*  view/*.* waveAlgorithm/*.*


