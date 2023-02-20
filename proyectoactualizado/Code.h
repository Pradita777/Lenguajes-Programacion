#ifndef Code_h
#define Code_h
#include <fstream>
#include <string>

using namespace std;

class Code {
public:
    Code();
    string dest(string mnemonic);
    string comp(string mnemonic);
    string jump(string mnemonic);
};

#endif