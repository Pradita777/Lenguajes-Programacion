#ifndef bichos_h
#define bichos_h 
#include <string>
using namespace std;

class bichos{
	public:
    bichos();
    ~bichos();
		bichos(string name, int health);
    string getName();
    void setName(string name);
    int getHealth ();
    void setHealth (int health);
    string toString(string name, int health);
    void attack();
	private:
    string name;
    int health;
};
#endif