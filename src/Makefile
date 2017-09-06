
CXX=clang++
CXXFLAGS= -std=c++11 -I../include
OBJ=ast.o

all: $(OBJ)

%.o: %.cpp
	$(CXX) $< -c -o $@ $(CXXFLAGS)