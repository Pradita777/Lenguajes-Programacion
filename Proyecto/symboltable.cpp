#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include "symboltable.h"

using namespace std;

SymbolTable::SymbolTable(){

}

SymbolTable::SymbolTable(string _Symbol, int _address){
  address = _address;
  symbol = _Symbol;
}

void SymbolTable::addEntry(string _symbol , int _address){
  string symbol = _symbol;
  int address = _address;
  SymbolTable temp = SymbolTable(symbol,address);
}

int SymbolTable::getAddress(){
  return address;
}

string SymbolTable::getSymbol(){
  return symbol;
}
