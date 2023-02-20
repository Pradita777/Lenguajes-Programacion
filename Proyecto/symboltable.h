#ifndef symboltable_h
#define symboltable_h
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

class SymbolTable {
	public:
		SymbolTable();
    SymbolTable(string symbol, int address);
		bool contains(string _symbol);
    void addEntry(string symbol , int address);
		int getAddress();
    void createAtable();
    string getSymbol();
    private:
    string symbol;
    int address;
};

#endif