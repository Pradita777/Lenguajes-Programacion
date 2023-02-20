#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Code.h"

using namespace std;

string Code::dest(string mnemonic) {
	if (mnemonic == "M") {
		mnemonic = "001";
	}
	else if (mnemonic == "D") {
		mnemonic = "010";
	}
	else if (mnemonic == "MD") {
		mnemonic = "011";
	}
	else if (mnemonic == "A") {
		mnemonic = "100";
	}
	else if (mnemonic == "AM") {
		mnemonic = "101";
	}
	else if (mnemonic == "AD") {
		mnemonic = "110";
	}
	else if (mnemonic == "AMD") {
		mnemonic = "111";
	}
	else {
		mnemonic = "000";
	}
	return mnemonic;
}

string Code::comp(string mnemonic) {
	if (mnemonic == "0") {
		mnemonic = "0101010";
	}
	else if (mnemonic == "1") {
		mnemonic = "0111111";
	}
	else if (mnemonic == "-1") {
		mnemonic = "0111010";
	}
	else if (mnemonic == "D") {
		mnemonic = "0001100";
	}
	else if (mnemonic == "A") {
		mnemonic = "0110000";
	}
	else if (mnemonic == "!D") {
		mnemonic = "0001101";
	}
	else if (mnemonic == "!A") {
		mnemonic = "0110001";
	}
	else if (mnemonic == "-D") {
		mnemonic = "0001111";
	}
	else if (mnemonic == "-A") {
		mnemonic = "0110011";
	}
	else if (mnemonic == "D+1") {
		mnemonic = "0011111";
	}
	else if (mnemonic == "A+1") {
		mnemonic = "0110111";
	}
	else if (mnemonic == "D-1") {
		mnemonic = "0001110";
	}
	else if (mnemonic == "A-1") {
		mnemonic = "0110010";
	}
	else if (mnemonic == "D+A") {
		mnemonic = "0000010";
	}
	else if (mnemonic == "D-A") {
		mnemonic = "0010011";
	}
	else if (mnemonic == "A-D") {
		mnemonic = "0000111";
	}
	else if (mnemonic == "D&A") {
		mnemonic = "0000000";
	}
	else if (mnemonic == "D|A") {
		mnemonic = "0010101";
	}
	else if (mnemonic == "M") {
		mnemonic = "1110000";
	}
	else if (mnemonic == "!M") {
		mnemonic = "1110001";
	}
	else if (mnemonic == "-M") {
		mnemonic = "1110011";
	}
	else if (mnemonic == "M+1") {
		mnemonic = "1110111";
	}
	else if (mnemonic == "M-1") {
		mnemonic = "1110010";
	}
	else if (mnemonic == "D+M") {
		mnemonic = "1000010";
	}
	else if (mnemonic == "D-M") {
		mnemonic = "1010011";
	}
	else if (mnemonic == "M-D") {
		mnemonic = "1000111";
	}
	else if (mnemonic == "D&M") {
		mnemonic = "1000000";
	}
	else if (mnemonic == "D|M") {
		mnemonic = "1010101";
	}
	return mnemonic;
}

string Code::jump(string mnemonic) {
	if (mnemonic == "JGT") {
		mnemonic = "001";
	}
	else if (mnemonic == "JEQ") {
		mnemonic = "010";
	}
	else if (mnemonic == "JGE") {
		mnemonic = "011";
	}
	else if (mnemonic == "JLT") {
		mnemonic = "100";
	}
	else if (mnemonic == "JNE") {
		mnemonic = "101";
	}
	else if (mnemonic == "JLE") {
		mnemonic = "110";
	}
	else if (mnemonic == "JMP") {
		mnemonic = "111";
	}
	else if (mnemonic == "null") {
		mnemonic = "000";
	}
	return mnemonic;
}