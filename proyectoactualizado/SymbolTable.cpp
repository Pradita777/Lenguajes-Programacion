#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include "SymbolTable.h"


using namespace std;

SymbolTable R0 = SymbolTable("R0", 0);
SymbolTable R1 = SymbolTable("R1", 1);
SymbolTable R2 = SymbolTable("R2", 2);
SymbolTable R3 = SymbolTable("R3", 3);
SymbolTable R4 = SymbolTable("R4", 4);
SymbolTable R5 = SymbolTable("R5", 5);
SymbolTable R6 = SymbolTable("R6", 6);
SymbolTable R7 = SymbolTable("R7", 7);
SymbolTable R8 = SymbolTable("R8", 8);
SymbolTable R9 = SymbolTable("R9", 9);
SymbolTable R10 = SymbolTable("R10", 10);
SymbolTable R11 = SymbolTable("R11", 11);
SymbolTable R12 = SymbolTable("R12", 12);
SymbolTable R13 = SymbolTable("R13", 13);
SymbolTable R14 = SymbolTable("R14", 14);
SymbolTable R15 = SymbolTable("R15", 15);
SymbolTable SCREEN = SymbolTable("SCREEN", 16384);
SymbolTable KBD = SymbolTable("KBD", 24576);
SymbolTable SP = SymbolTable("SP", 0);
SymbolTable LCL = SymbolTable("LCL", 1);
SymbolTable ARG = SymbolTable("ARG", 2);
SymbolTable THIS = SymbolTable("THIS", 3);
SymbolTable THAT = SymbolTable("THAT", 4);
SymbolTable WRITE = SymbolTable("WRITE", 18);
SymbolTable END = SymbolTable("END", 22);
SymbolTable i = SymbolTable("i", 16);
SymbolTable sum = SymbolTable("sum", 17);

SymbolTable::SymbolTable() {

}

SymbolTable::SymbolTable(string _Symbol, int _address) {
  address = _address;
  symbol = _Symbol;
}

vector <SymbolTable> symboltable;

void SymbolTable::createAtable() {
  symboltable.push_back(R0);
  symboltable.push_back(R1);
  symboltable.push_back(R2);
  symboltable.push_back(R3);
  symboltable.push_back(R4);
  symboltable.push_back(R5);
  symboltable.push_back(R6);
  symboltable.push_back(R7);
  symboltable.push_back(R8);
  symboltable.push_back(R9);
  symboltable.push_back(R10);
  symboltable.push_back(R11);
  symboltable.push_back(R12);
  symboltable.push_back(R13);
  symboltable.push_back(R14);
  symboltable.push_back(R15);
  symboltable.push_back(SCREEN);
  symboltable.push_back(KBD);
  symboltable.push_back(SP);
  symboltable.push_back(LCL);
  symboltable.push_back(ARG);
  symboltable.push_back(THIS);
  symboltable.push_back(THAT);
  symboltable.push_back(WRITE);
  symboltable.push_back(END);
  symboltable.push_back(i);
  symboltable.push_back(sum);
}

int SymbolTable::getAddress(string symbol) {
  for (int i = 0; i <= symboltable.size(); i++) {
    if (symbol == symboltable[i].getSymbol()) {
      return symboltable[i].address;
    }
  }
  return 0;
}

string SymbolTable::getSymbol() {
  return symbol;
}

void SymbolTable::addEntry(string symbol, int address) {
  this->symbol = symbol;
  this->address = address;
  SymbolTable temp = SymbolTable(symbol, address);
  symboltable.push_back(temp);
}

bool SymbolTable::contains(string _symbol) {
  for (int i = 0; i <= symboltable.size(); i++) {
    if (_symbol == symboltable[i].getSymbol()) {
      return true;
    }
  }

  return false;
}