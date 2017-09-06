
CXX=clang++
CXXFLAXS= -I../include/ -std=c++11 -g


tests: basic_test

%_test: %_test.cpp ../include/*.h
	$(CXX) $(CXXFLAXS) $< -o $@