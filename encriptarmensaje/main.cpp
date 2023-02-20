#include <iostream>
#include <fstream>
#include <string>
#include<stdlib.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <regex>
#include<string.h>
#include "encriptar.h"

using namespace std;

int numInicial;
string FIN = "FIN";
string INICIAL = "Escriba el mensaje a encriptar y presione [ENTER]\nEscriba FIN y presione [ENTER] para terminar el programa.";
string MENSAJEIN = "\nEntrada : ";
string MENSAJEOUT = "\nEncriptado : ";

bool pregunteMensajeAEncriptar()
	{
		cout<<(INICIAL);
		cout<<(MENSAJEIN);
    cout<<("No dejar espacios por palabras");
		string strEntrada;
    cin>> strEntrada;
    cout<< strEntrada;
		if(strEntrada.compare(FIN) == 0){
		return true;
    }else{
		encriptar* objMensaje = new encriptar(strEntrada);
		cout<<(MENSAJEOUT + objMensaje->getMensaje())<<endl;
		return false;
    }	
	}
void incrementar()
	{
		if(numInicial == 128){
			numInicial = 1;
    }else{
			numInicial++;
    }
	}
	
  int main()
	{
		do{
			incrementar();
		}while(!pregunteMensajeAEncriptar());
	}
