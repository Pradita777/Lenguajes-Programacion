#include <iostream>
#include "pila.h"
 
using namespace std;


pila::pila(){
  float arreglo [30];
  int elementos = 0;

}
pila::~pila(){

}
void pila::push(float dato){
  arreglo[elementos++] = dato;
  cout<<arreglo[elementos-1]<<endl;
}
float pila::pop(){
  return arreglo[--elementos];
}