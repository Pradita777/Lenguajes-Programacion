#include <iostream>
#include "pila.h"
using namespace std;
int main() {
  int sumar, restar, mutiplicar, dvidir;
  float num1,num2;
  cout << "ingrese un numero\n";
  cin >>num1;
  cout << "ingrese un numero\n";
  cin >>num2;
  pila *pila1 = new pila(); 
  pila1->push(num1);
  pila1->push(num2);
  
}