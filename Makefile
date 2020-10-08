

main: main.o funcs.o caesar.o viginere.o decrypt.o
	g++ -o main main.o funcs.o caesar.o viginere.o decrypt.o

tests: tests.o 
	g++ -o tests tests.o caesar.o viginere.o decrypt.o


funcs.o: funcs.cpp funcs.h

main.o: main.cpp funcs.h

caesar.o: caesar.cpp caesar.h

viginere.o: viginere.cpp viginere.h

decrypt.o : decrypt.cpp decrypt.h


tests.o: tests.cpp  doctest.h caesar.h viginere.h decrypt.h

clean:
	rm -f main.o tests.o funcs.o caesar.o viginere.o decrypt.o

help:
	@echo  make main : make executable named main
	@echo make tests : make test suite named tests

