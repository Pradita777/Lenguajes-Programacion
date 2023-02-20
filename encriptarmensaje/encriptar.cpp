#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "encriptar.h"

using namespace std;


encriptar::encriptar(){
  
}
encriptar::~encriptar(){

}
encriptar::encriptar(string mensaje)
{
	strMensaje = mensaje;
	encriptarMensaje();
}
string encriptar::getMensaje()
{
	return strEncriptado;
}

void encriptar::encriptarMensaje()
{
    // Tenga en cuenta que el caracter ^ en Java representa el comando XOR
    // En C++ aplica igual
	strEncriptado = "" + to_string(numInicial);
	for(int i = 0; i < strMensaje.length(); i++)
  {
	strEncriptado = strEncriptado + (char)(strMensaje.at(i) ^ (i+1)) ;
}
}
