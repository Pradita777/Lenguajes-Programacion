#ifndef Parser_h
#define Parser_h
#include <fstream> 
#include <cstring>
#include <string>

using namespace std;

enum Command { A_COMMAND, C_COMMAND, L_COMMAND };

class Parser {
public:
	Parser();
	Parser(char* argv[]);
	bool hasMoreCommands();
	void advance();
	void reset();
	Command commandType();
	string getCurrentCommand();
	string symbol();
	string dest();
	string comp();
	string jump();
	ifstream inputFile;
private:
	bool nextLine();
	bool isValidLine();
	bool isValidChar();
	bool comments();
	char filename[50];
	string fileLine;
	string::iterator lineIterator;
	string currentCommand;

};

#endif