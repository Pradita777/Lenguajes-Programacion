#include <iostream>
#include "Parser.h"
#include "SymbolTable.h"
#include "Code.h"
#include <algorithm>

ofstream outputFile;
struct object {
	Parser* program;
	SymbolTable* symbolTable;
};

ofstream createOutputFile(char* argv[]) {
	string fileName(argv[1]);
	if (fileName.rfind(".") != string::npos) {
		fileName.erase(fileName.rfind("."));
	}
	fileName.append(".hack");
	ofstream file(fileName);
	return file;
}

string toBinary(int value) {
	string binary;
	for (int i = 0; i < 16; i++) {
		binary += to_string(value % 2);
		value /= 2;
	}
	reverse(binary.begin(), binary.end());
	return binary;
}

object inicializar(char* argv[]) {
	SymbolTable* symbolTable = new SymbolTable();
	Parser* program = new Parser(argv);
	object objectReturn;
	objectReturn.program = program;
	objectReturn.symbolTable = symbolTable;
	objectReturn.symbolTable->createAtable();
	return objectReturn;
}

void primeraPasada(Parser* program, SymbolTable* symbolTable) {
	int ROM = 0;

	while (program->hasMoreCommands()) {
		program->advance();
		switch (program->commandType()) {
		case L_COMMAND:
		{
			string symbol = program->symbol();
			if (!symbolTable->contains(symbol)) {
				symbolTable->addEntry(symbol, ROM);
			}
			break;
		}
		case C_COMMAND:
			ROM++;
			break;
		case A_COMMAND:
			ROM++;
			break;
		default:
			break;
		}
	}
}

void segundaPasada(Parser* program, SymbolTable* symbolTable) {
	Code* code;
	int RAM = 16;
	while (program->hasMoreCommands()) {
		program->advance();
		switch (program->commandType()) {
		case A_COMMAND:
		{
			string symbol = program->symbol();
			int value;
			if (isdigit(symbol.front())) {
				value = stoi(symbol);
				
			}
			else {
				if (!symbolTable->contains(symbol)) {
					symbolTable->addEntry(symbol, RAM);
					value = RAM;
					RAM++;
				}
				else {
					value = symbolTable->getAddress(symbol);
				}
			}

			toBinary(value);
			outputFile << toBinary(value) << endl;
			break;
		}
		case C_COMMAND:
		{
			string command = program->getCurrentCommand();
			string dest = program->dest();
			string comp = program->comp();
			string jump = program->jump();
			string cValue;
			string destBinary;
			string compBinary;
			string jumpBinary;
			if (!dest.empty()) {
				if (command.find(";") != string::npos) {
					cerr << "Syntax error: dest and semicolon";
					return;
				}
				else {
					destBinary = code->dest(dest);
				}
			}
			else if (command.find("=") != string::npos) {
				cerr << "Syntax error: dest equals";
				return;
			}
			else {
				destBinary = "000";
			}
			if (!comp.empty()) {
				compBinary = code->comp(comp);
			}
			else {
				compBinary = "0000000";
			}

			if (!jump.empty()) {
				jumpBinary = code->jump(jump);
			}
			else {
				jumpBinary = "000";
			}
			outputFile << "111";
			outputFile << compBinary;
			outputFile << destBinary;
			outputFile << jumpBinary << endl;
			break;
		}
		default:
			break;
		}
	}
}

void finalizar(ifstream& inputFile, ofstream& outputFile){

	if (inputFile.is_open()) {
		inputFile.close();
	}

	if (outputFile.is_open()) {
		outputFile.close();
	}
}

int main(int argc, char* argv[]) {
	outputFile = createOutputFile(argv);
	object objectToSend = inicializar(argv);
	primeraPasada(objectToSend.program, objectToSend.symbolTable);
	objectToSend.program->reset();
	segundaPasada(objectToSend.program, objectToSend.symbolTable);
	finalizar(objectToSend.program->inputFile, outputFile);

	
}