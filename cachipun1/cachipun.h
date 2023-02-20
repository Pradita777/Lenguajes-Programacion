#ifndef cachipun_h
#define cachipun_h 
#include <string>

using namespace std;

class cachipun{
	public:
		cachipun(string name, int vidas);
		~cachipun();
		void miTurno();
		int turnoActual();
		bool estoyVivo();
		void perdedor();
		string nombre();
		string nombre(bool incluyeNombre);
		string reiniciar(int vidas);
    int validarGanadorTurno(int estadoJ1, int estadoJ2);
    void jugar(cachipun jugador1, cachipun jugador2);
	private:
		int turno;
		int vidas;
		bool vivo;
		string miNombre;
};
#endif