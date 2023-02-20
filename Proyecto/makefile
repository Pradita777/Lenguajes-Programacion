
programa: main.o parser.o code.o symboltable.o
		g++ ${CXXFLAGS} -o programa main.o parser.o code.o symboltable.o
main.o: main.cpp parser.h code.h symboltable.h
		g++ ${CXXFLAGS} -c main.cpp
parser.o: parser.cpp parser.h
		g++ ${CXXFLAGS} -c parser.cpp
code.o: code.cpp code.h
		g++ ${CXXFLAGS} -c code.cpp
symbolTable.o: symboltable.cpp symboltable.h
		g++ ${CXXFLAGS} -c symboltable.cpp
clean:
		rm -f *.o
		rm -f programa