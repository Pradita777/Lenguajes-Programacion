#include "Parser.h"
#include <string>
#include <iostream>

using namespace std;

Parser::Parser() {
}

Parser::Parser(char* argv[]) {
	strcpy(filename, argv[1]);
	inputFile.open(filename, ifstream::in);
	nextLine();
}

bool Parser::hasMoreCommands() {
	return !inputFile.eof();
}

string Parser::getCurrentCommand() {
	return currentCommand;
}

bool Parser::nextLine() {
	if (getline(inputFile, fileLine)) {
		lineIterator = fileLine.begin();
		return true;
	}
	return false;
}

bool Parser::isValidLine() {
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

bool Parser::isValidChar() {
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

bool Parser::comments() {
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
void Parser::reset() {
	inputFile.clear();
	inputFile.seekg(0);
	nextLine();
}

void Parser::advance() {
	if (isValidChar()) {
		currentCommand.clear();
		while (lineIterator != fileLine.end() && !isspace(*lineIterator)) {
			currentCommand.append(1, *lineIterator);
			++lineIterator;
		}
	}
}

Command Parser::commandType() {
	if (currentCommand.front() == '@') {
		return A_COMMAND;
	}

	if (currentCommand.front() == '(') {
		return L_COMMAND;
	}
	return C_COMMAND;
}

string Parser::symbol() {
	if (Parser::commandType() == A_COMMAND) {
		return currentCommand.substr(1);
	}

	return currentCommand.substr(1, currentCommand.length() - 2);
}

string Parser::dest() {
	int posEquals = currentCommand.find('=');
	if (posEquals != string::npos) {
		return currentCommand.substr(0, posEquals);
	}

	return "";
}

string Parser::comp() {
	int posEquals = currentCommand.find('=');
	int posSemiColon = currentCommand.find(';');
	if (posEquals == string::npos) {
		return currentCommand.substr(0, posSemiColon);
	}

	if (posSemiColon == string::npos) {
		return currentCommand.substr(posEquals + 1);
	}
	return currentCommand.substr(posEquals + 1, posSemiColon);
}

string Parser::jump() {
	int posSemiColon = currentCommand.find(';');
	if (posSemiColon != string::npos) {
		return currentCommand.substr(posSemiColon + 1);
	}
	return "";
}