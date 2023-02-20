#include "parser.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include "code.h"
#include "symboltable.h"

using namespace std;

parser::parser(string filename) {
	inputFile.open(filename, ifstream::in);
	nextLine();
}

bool parser::hasMoreCommands() {
	return !inputFile.eof();
}

bool parser::nextLine() {
	if (getline(inputFile, fileLine)) {
		lineIterator = fileLine.begin();
		return true;
	}
	return false;
}

bool parser::isValidLine()
{
	if (!nextLine())
		return false;

	while (true) {
		if (fileLine.empty() || lineIterator == fileLine.end()) {
			if (!nextLine())
				return false;
		}
		else {
			break;
		}
	}

	return true;
}

bool parser::isValidChar()
{
	while (isspace(*lineIterator) || lineIterator == fileLine.end()) {

		if (*lineIterator == '\n' || lineIterator == fileLine.end()) {
			if (!isValidLine()) {
				return false;
			}
		}
		else {
			lineIterator++;
		}
	}

	if (!comments()) {
		return false;
	}

	return true;
}

bool parser::comments()
{
	if (*lineIterator != '/') {
		return true;
	}

	++lineIterator;

	if (*lineIterator == '/') {
		return isValidLine() && isValidChar();
	}

	if (*lineIterator == '*') {
		while (true) {
			int numChars = distance(fileLine.begin(), lineIterator);
			size_t posit = fileLine.find("*/", numChars);

			if (posit != string::npos) {
				lineIterator = fileLine.begin() + posit + 2;
				return isValidChar();
			}
			if (!isValidLine()) {
				return false;
			}
		}
	}

	--lineIterator;
	return true;
}

bool parser::advance() {
	if (isValidChar()) {
		currentCommand.clear();
		while (lineIterator != fileLine.end() && !isspace(*lineIterator)) {
			currentCommand.append(1, *lineIterator);
			++lineIterator;
		}
    return true;
	}
  return false;
}


string parser::commandType() {
	//cout << currentCommand << "\n";
	if (currentCommand[0] == '@') {
		return "A_COMMAND";
	}
	if (currentCommand[0] == '(') {
		return "L_COMMAND";
	}
	return "C_COMMAND";
}

string parser::etiqueta(){
  string temporal = "";
  if(L_COMMAND){
    temporal = currentCommand.substr(1,currentCommand.length()-2);
  }
  return temporal;
}

string parser::symbol(){
  if (A_COMMAND){
    return currentCommand.substr(1);
	}
  return currentCommand.substr(1, currentCommand.length()-1);
}
        


string parser::dest() {
  string temp = "";
  string temp1 = "";
	int posEquals = currentCommand.find('=');
	if (posEquals == string::npos) {
    Code simbolo = Code();
    temp = currentCommand.substr(0,posEquals);
    temp1 = simbolo.dest0(temp);
	}else{
    Code simbolo = Code();
    temp = currentCommand.substr(0,posEquals);
    temp1 = simbolo.dest0(temp);
  }
	return temp1;
}

string parser::comp() {
  string temp = "";
  string temp1 = "";
	int posEquals = currentCommand.find('=');
	int posSemiColon = currentCommand.find(';');
	if (posEquals != string::npos && posSemiColon != string::npos) {
		temp =currentCommand.substr(posEquals + 1, posSemiColon-1);
    Code simbolo = Code();
    temp1 = simbolo.comp0(temp);
	}else if(posEquals == string::npos && posSemiColon != string::npos){
    temp = currentCommand.substr(0,posSemiColon);
    Code simbolo = Code();
    temp1 = simbolo.comp0(temp);
  }else if(posEquals != string::npos && posSemiColon == string::npos){
    temp = currentCommand.substr(posEquals + 1, -1);
    Code simbolo = Code();
    temp1 = simbolo.comp0(temp);
  }
	return temp1;
}

string parser::jump() {
  string temp = "";
  string temp1 = "";
	int posSemiColon = currentCommand.find(';');
	if (posSemiColon != string::npos) {
		temp = currentCommand.substr(posSemiColon+1,-1);
    Code simbolo = Code();
    temp1 = simbolo.jump0(temp);
	}else if(posSemiColon == string::npos){
    Code simbolo = Code();
    temp1 = simbolo.jump0(temp);
  }
	return temp1;
}