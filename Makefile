CXX_OPTS=-std=c++0x -DBOOST_SPIRIT_DEBUG

all: prog

clean:
	rm -f *.o
	rm -f prog

prog: main.o complex_utils_parser.o complex_utils_generator.o
	$(CXX) $(CXX_OPTS) -o $@ $+

main.o: main.cxx complex_utils.hxx
	$(CXX) $(CXX_OPTS) -c $<

complex_utils_parser.o: complex_utils_parser.cxx complex_parser.hxx complex_utils.hxx
	$(CXX) $(CXX_OPTS) -c $<

complex_utils_generator.o: complex_utils_generator.cxx complex_generator.hxx complex_utils.hxx
	$(CXX) $(CXX_OPTS) -c $<
