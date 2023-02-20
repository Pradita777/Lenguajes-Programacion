#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "cachipun.h"

using namespace std;

int turno;
int vidas;
bool vivo;
string miNombre;
int PAPEL = 0;
int PIEDRA = 1;
int TIJERA = 2;

cachipun::cachipun(string name, int vidas){
	miNombre = name;
	reiniciar(vidas);
}
cachipun::~cachipun(){
	
}
void cachipun::miTurno(){
	turno = (rand() % 3) ;
}
int cachipun::turnoActual(){
	return turno;
}
bool cachipun::estoyVivo(){
	return vivo;
}
void cachipun::perdedor(){
	vidas = vidas -1;
		if(vidas == 0)
			vivo = false;
}
string cachipun::nombre(){
	return miNombre;
}
string cachipun::nombre(bool incluyeNombre){
	string respuesta = "";
		
		if(incluyeNombre)
			respuesta = miNombre + " ";
		respuesta = respuesta + "Turno :";
		if(turno == PAPEL)
			respuesta = respuesta + " Papel";
		if(turno == PIEDRA)
			respuesta = respuesta + " Piedra";
		if(turno == TIJERA)
			respuesta = respuesta + " Tijera";
		respuesta = respuesta + " Vidas: " + std::to_string(vidas);
		if(vivo)
			respuesta = respuesta + " estoy vivo";
		else
			respuesta = respuesta + " perdi";
		return (respuesta);
}
string cachipun::reiniciar(int vidas){
	this->vidas = vidas;
	vivo = true;
}
int cachipun::validarGanadorTurno(int estadoJ1, int estadoJ2)
	{
		if ((estadoJ1 == PAPEL && estadoJ2 == PIEDRA) || (estadoJ1 == PIEDRA && estadoJ2 == TIJERA) ||
		    (estadoJ1 == TIJERA && estadoJ2 == PAPEL))
			return 1;
		if ((estadoJ2 == PAPEL && estadoJ1 == PIEDRA) || (estadoJ2 == PIEDRA && estadoJ1 == TIJERA) ||
		    (estadoJ2 == TIJERA && estadoJ1 == PAPEL))
			return 2;
		return 0;
	}

void cachipun::jugar(cachipun jugador1, cachipun jugador2)
	{
		int ganadorTurno;
		
		while(jugador1.estoyVivo() && jugador2.estoyVivo())
		{
			jugador1.miTurno();
			jugador2.miTurno();
			ganadorTurno = validarGanadorTurno(jugador1.turnoActual(), jugador2.turnoActual());
			if(ganadorTurno == 1)
				jugador2.perdedor();
			if(ganadorTurno == 2)
				jugador1.perdedor();
			cout<<(jugador1.nombre(true) + " - " + jugador2.nombre(true) + "\n");
		}
		if(jugador1.estoyVivo())
			cout<<("Ganador: " + jugador1.nombre() + "\n");
		if(jugador2.estoyVivo())
			cout<<("Ganador: " + jugador2.nombre() + "\n");
	}
  int cachipun::menu(){
        int option;
            cout<<("------------------------------------------------------------------------------------------------------------------");
            cout<<("____________________________________________________________________________.");
            cout<<("|###########################################################################|");
            cout<<("|#|  ____        ___   ___________   ____      __.   __.         __.      |#|");
            cout<<("|#|  |$$$\\      /$$|   |$$$$$$$$$|   |$$$\\     |$|   |$|         |$|      |#|");
            cout<<("|#|  |$|\\$\\   /$/|$|   |$|           |$|\\$\\    |$|   |$|         |$|      |#|");
            cout<<("|#|  |$| \\$\\ /$/ |$|   |$|           |$| \\$\\   |$|   |$|         |$|      |#|");
            cout<<("|#|  |$|  \\$$$/  |$|   |$$$$$$$$$|   |$|  \\$\\  |$|   |$|         |$|      |#|");
            cout<<("|#|  |$|         |$|   |$|           |$|   \\$\\ |$|   |$|         |$|      |#|");
            cout<<("|#|  |$|         |$|   |$|           |$|    \\$\\|$|   \\$\\_________/$/  __. |#|");
            cout<<("|#|  |$|         |$|   |$$$$$$$$$|   |$|     \\$$$|    \\$$$$$$$$$$$/   |$| |#|");
            cout<<("|#|_______________________________________________________________________|#|");
            cout<<("|###########################################################################|");
            cout<<("------------------------------------------------------------------------------------------------------------------");
            cout<<("0.  Exit of the program.");
            cout<<("1.  START THE GAME... or create a new game board");
            cout<<("------------------------------------------------------------------------------------------------------------------");

            cout<<("\n Select an option: ");



            cin>>option;
        
        return option;
    }

  


	
	