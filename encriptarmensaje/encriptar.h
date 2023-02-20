#ifndef encriptar_h
#define encriptar_h 
#include <string>
using namespace std;



class encriptar{
	public:
    encriptar();
    ~encriptar();
    encriptar(string mensaje);
    string getMensaje();
	private:
};
#endif