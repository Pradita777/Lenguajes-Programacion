<<<<<<< HEAD

#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <algorithm>

using namespace std;

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

string toBinary(int value) {
	string binary;
	for (int i = 0; i < 16; i++) {
		binary += to_string(value % 2);
		value /= 2;
	}
	reverse(binary.begin(),binary.end());
	return binary;
}

int main(){
  int o;
  string temp0 = "20";
  if(isNumber(temp0)){
    o = atoi(temp0.c_str());
    cout<<toBinary(o);
  }
}
=======
#include <iostream>
using namespace std;
int main() {
    int extNum, sumDigit = 0, numEntero;
    cout << "Ingrese un numero entero: ";
    cin >> numEntero;
    while(numEntero != 0) {
        extNum = numEntero % 10;
        numEntero /= 10;
        sumDigit += extNum;
    }
    cout << "La suma de los digitos es: " << sumDigit << endl;
    return 0;
}
>>>>>>> f91276a4d42addeaca4611d7d6a688954cfaa0c7
