#CXXFLAGS=-g
program: main.o Parser.o Code.o SymbolTable.o
		g++ ${CXXFLAGS} -o program main.o Parser.o Code.o SymbolTable.o
main.o: main.cpp Parser.h Code.h SymbolTable.h
		g++ ${CXXFLAGS} -c main.cpp
Parser.o: Parser.cpp Parser.h
		g++ ${CXXFLAGS} -c Parser.cpp
Code.o: Code.cpp Code.h
		g++ ${CXXFLAGS} -c Code.cpp
SymbolTable.o: SymbolTable.cpp SymbolTable.h
		g++ ${CXXFLAGS} -c SymbolTable.cpp
clean:
		rm -f *.o
		rm -f program