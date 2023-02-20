#ifndef SymbolTable_h
#define SymbolTable_h
#include <fstream>
#include <string>

using namespace std;



class SymbolTable {
	public:
		SymbolTable();
    SymbolTable(string symbol, int address);
		void addEntry(string symbol , int address);
		bool contains(string _symbol);
		int getAddress(string symbol);
    void createAtable();
    string getSymbol();
    private:
    string symbol;
    int address;
};

#endif