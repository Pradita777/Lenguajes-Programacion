#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "cachipun.h"

using namespace std;
	
	cachipun::lol (string nombre, int vidas)
	{
		reiniciar(vidas);
		miNombre = nombre;
	}

	void cachipun::miTurno()
	{
		turno = (int) (rand() % 3);
	}
	
	int cachipun::turnoActual()
	{
		return turno;
	}
	
  bool cachipun::estoyVivo()
	{
		return vivo;
	}
	
	void cachipun::perdedor()
	{
		vidas--;
		if(vidas == 0)
			vivo = false;
	}

	string cachipun::nombre()
	{
		return miNombre;
	}
	
	string cachipun::nombre(bool incluyeNombre)
	{
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
		respuesta = respuesta + " Vidas: " + to_string(vidas);
		if(vivo)
			respuesta = respuesta + " estoy vivo";
		else
			respuesta = respuesta + " perdi";
		return (respuesta);
	}
	
	string cachipun::reiniciar(int vidas)
	{
		this->vidas = vidas;
		vivo       = true;
	}