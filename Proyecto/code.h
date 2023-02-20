#ifndef code_h
#define code_h
#include <fstream>
#include <string>

using namespace std;

class Code {
	public:
    Code();
    Code(string mnemonic);
		string dest0(string mnemonic);
		string comp0(string mnemonic);
		string jump0(string mnemonic);
  private:
    string simbolo;
};

#endif