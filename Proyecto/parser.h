#ifndef parser_h
#define parser_h
#include <fstream> 
#include <cstring>
#include <string>

using namespace std;

enum Command { A_COMMAND, C_COMMAND, L_COMMAND };

class parser {
public:
parser();
	parser(string filename);
	bool hasMoreCommands();
	bool advance();
  string commandType();
	string symbol();
	string dest();
	string comp();
	string jump();
  string etiqueta();
  string getCurrentCommand();
  void reset();
private:
	bool nextLine();
	bool isValidLine();
	bool isValidChar();
	bool comments();
  bool saltolinea();
	char filename[10000];
	ifstream inputFile;
	string fileLine;
	string::iterator lineIterator;
	string currentCommand;
};

#endif