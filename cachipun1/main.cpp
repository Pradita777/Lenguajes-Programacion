#include <iostream>
#include <fstream>
#include <string>
#include<stdlib.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include "cachipun.h"

using namespace std;

int main(){
  int option1;
	do{
    
    option1 = cachipun::menu();
    switch(option1){
      case 0:
      cout<<("\n------------------------------------------------------------------------------------------------------------------");
                    cout<<("\nYOU ARE LEAVING THE PROGRAM...");
                    cout<<("THE PROGRAM IS CLOSED CORRECTLY.");

                    cout<<("\n____________________________________________________________");
                    cout<<("|##########################################################|");
                    cout<<("|#|  ___________   ____      __.   ____________.         |#|");
                    cout<<("|#|  |$$$$$$$$$|   |$$$\\     |$|   |$$$$$$$$$$$$\\        |#|");
                    cout<<("|#|  |$|           |$|\\$\\    |$|   |$|          |$|      |#|");
                    cout<<("|#|  |$|           |$| \\$\\   |$|   |$|          |$|      |#|");
                    cout<<("|#|  |$$$$$$$$$|   |$|  \\$\\  |$|   |$|          |$|      |#|");
                    cout<<("|#|  |$|           |$|   \\$\\ |$|   |$|          |$|      |#|");
                    cout<<("|#|  |$|           |$|    \\$\\|$|   |$\\_________/$/  __.  |#|");
                    cout<<("|#|  |$$$$$$$$$|   |$|     \\$$$|   |$$$$$$$$$$$/    |$|  |#|");
                    cout<<("|#|______________________________________________________|#|");
                    cout<<("|##########################################################|");

                    cout<<("\n------------------------------------------------------------------------------------------------------------------");
                    cout<<("------------------------------------------------------------------------------------------------------------------");
                    cout<<("------------------------------------------------------------------------------------------------------------------");
                    break;
      case 1:
      cout<<"ingrese el nombre del jugador 1:"<<endl;
      string name1;
      cin>>name1;
      cout<<"ingrese el nombre del jugador 2:"<<endl;
      string name2;
      cin>>name2;
      cout<<"ingrese el numero de vidas de ambos jugadores:"<<endl;
      int vidas;
      cin>>vidas;
      cachipun* jugador1 = new cachipun(name1 , vidas);
      cachipun* jugador2 = new cachipun(name2 , vidas);

      jugar(jugador1*,jugador2*);
      break;
    }

	}while(option1 != 0);
	
}