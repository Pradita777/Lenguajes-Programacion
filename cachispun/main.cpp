#include <iostream>
#include <fstream>
#include <string>
#include<stdlib.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <regex>
#include "cachipun.h"

using namespace std;

const string MENSAJE_INICIAL      = "Presione [1] y [Enter] para iniciar, [0] y [Enter] para terminar: ";
const string MENSAJE_FIN_JUEGO    = "Fin del juego -- Presione [1]y [Enter] para jugar de nuevo, [0] y [Enter] para terminar: ";
const string MENSAJE_VIDAS        = "Ingrese el numero de vidas para el siguiente juego: ";
const string MENSAJE_SOLO_NUMEROS = "Por favor, ingrese solo numeros";
const string MENSAJE_SOLO_0_1     = "Por favor, ingrese solamente 0 o 1";
const string MENSAJE_TERMINA      = "Termina el juego";

void mensaje(string mensaje)
	{
		cout<<mensaje;
	}
	
void mensajeBienvenida()
	{
		mensaje("Cachipun\n\n");
		mensaje(MENSAJE_INICIAL);
	}
  /*bool esBlanco (string entrada)
	{
    cout<< entrada.length() <<endl;
    return true;
		//return (entrada == null || entrada.equals("") || entrada.equals("null") || entrada.trim().equals(""));
	}*/
  bool esNumero(string entrada)  
	{  
    regex e ("^[0-9]+$");
		bool validar = false;
		
			validar = regex_match (entrada ,e);
		
		return validar;
  }
bool validarEntrada(string entrada, string mensaje)
	{
		if(!esNumero(entrada))
		{
			cout<<(MENSAJE_SOLO_NUMEROS + "\n" + mensaje);
			return false;
		}
		return true;
	}	
int validarMenu(int opcion)
	{
		string entrada;
		bool validarSalida  = false;
		bool bolEntrada = false;
		int limiteInferior = 0;
		int limiteSuperior = 1;
		int valor = 0;
		
		validarSalida = false;
		do
		{
      cin>> entrada;
			switch(opcion)
			{
				case 1:	bolEntrada = validarEntrada(entrada, MENSAJE_INICIAL);
						break;
				case 2:	bolEntrada = validarEntrada(entrada, MENSAJE_FIN_JUEGO);
						break;
			}
			if(bolEntrada)
			{
				valor = stoi(entrada);
				if(valor < limiteInferior || valor > limiteSuperior)
				{
					mensaje(MENSAJE_SOLO_0_1 + "\n" + MENSAJE_INICIAL);
					bolEntrada = false;
				}
			}
		} while(!bolEntrada);
		
		return valor;
	}
int validarGanadorTurno(int estadoJ1, int estadoJ2)
	{
		if ((estadoJ1 == PAPEL && estadoJ2 == PIEDRA) || (estadoJ1 == PIEDRA && estadoJ2 == TIJERA) ||
		    (estadoJ1 == TIJERA && estadoJ2 == PAPEL))
			return 1;
		if ((estadoJ2 == PAPEL && estadoJ1 == PIEDRA) || (estadoJ2 == PIEDRA && estadoJ1 == TIJERA) ||
		    (estadoJ2 == TIJERA && estadoJ1 == PAPEL))
			return 2;
		return 0;
	}

void jugar(cachipun* jugador1, cachipun* jugador2){
		int ganadorTurno;
		
		while(jugador1->estoyVivo() && jugador2->estoyVivo())
		{
			jugador1->miTurno();
			jugador2->miTurno();
			ganadorTurno = validarGanadorTurno(jugador1->turnoActual(), jugador2->turnoActual());
			if(ganadorTurno == 1)
				jugador2->perdedor();
			if(ganadorTurno == 2)
				jugador1->perdedor();
			mensaje(jugador1->nombre(true) + " - " + jugador2->nombre(true) + "\n");
		}
		if(jugador1->estoyVivo())
			mensaje("Ganador: " + jugador1->nombre() + "\n");
		if(jugador2->estoyVivo())
			mensaje("Ganador: " + jugador2->nombre() + "\n");
	}
	
  	int leerVidas()
	{
		string entrada;
		
		mensaje(MENSAJE_VIDAS);
		do
		{
			cin>>entrada;
		} while(!validarEntrada(entrada, MENSAJE_VIDAS));
		return(stoi(entrada));
	}
	int validarCierre(cachipun* jugador1, cachipun* jugador2)
	{
		mensaje(MENSAJE_FIN_JUEGO);
		int continuar = validarMenu(2);
		if(continuar != 0)
		{
			int vidas = leerVidas();
			jugador1->reiniciar(vidas);
			jugador2->reiniciar(vidas);
		}
		return continuar;
	}

void mensajeFinal()
	{
		mensaje(MENSAJE_TERMINA + "\n");
	}
	
int main()
	{
		int continuar;
		cachipun* jugador1      = new cachipun("Jugador 1", 10);
		cachipun* jugador2      = new cachipun("Jugador 2", 10);
		
		mensajeBienvenida();
		continuar = validarMenu(1);
		while(continuar != 0)
		{	
			jugar(jugador1, jugador2);
			continuar = validarCierre(jugador1, jugador2);
		}
		mensajeFinal();
	}