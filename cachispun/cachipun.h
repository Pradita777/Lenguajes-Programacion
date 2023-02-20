 
#include <string>

using namespace std;
enum j{PAPEL = 0,PIEDRA = 1,TIJERA = 2};

class cachipun{
	public:
		lol(string name, int vidas);
		void miTurno();
		int turnoActual();
		bool estoyVivo();
		void perdedor();
		string nombre();
		string nombre(bool incluyeNombre);
		string reiniciar(int vidas);
	private:
		int turno;
		int vidas;
		bool vivo;
		string miNombre;
};
