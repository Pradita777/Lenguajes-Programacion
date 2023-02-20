
#include <iostream>
#include <fstream>
#include <string>
#include<stdlib.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <regex>
#include<string.h>
#include "bichos.h"

using namespace std;

int menu()
    {
      int option;
      cout<<("0.  Exit of the program.")<<endl;
      cout<<("1.  START THE GAME... or create a new game board")<<endl;
      cout<<("2.  You can shoot a bug of you choice.")<<endl;
      cout<<(" Select an option: ")<<endl;
      cin>>option;
        
    return option;
  }

int main()
{
  int option1;
  bichos bugs[2][2] = {}; 
  do 
  {
    option1 = menu();

    
  
      if(option1 == 0)
      {
        cout<<("YOU ARE LEAVING THE PROGRAM...")<<endl;
        cout<<("THE PROGRAM IS CLOSED CORRECTLY.")<<endl;
        break;
      }

      if(option1 == 1)
      {
        for (int index = 0; index < 2; index++)
        {
          for (int jIndex = 0; jIndex < 2; jIndex++)
          {
            bugs[index][jIndex] =  bichos("", 0);
          }
        }

        int amountOfBugs = (int) (rand() % 4)+1;

        
        cout<<("\nOh no!!!!!!! they have appeared " + to_string(amountOfBugs) + " bugs, PLEASEE  exterminate them all before they eat us")<<endl;

        int limit = 0;

        for (int i = 0; i < 2; i++)
        {
          for (int j = 0; j < 2; j++)
          {
            int creatorOfBugs = (int) ((rand() % 2) + 1);
            if (limit == amountOfBugs)
            {
              break;
            }
            else if (creatorOfBugs == 1)
            {
            bichos bugs1 =  bichos("BN", 10);
            limit++;
            bugs[i][j] = bugs1;
        }
        else if(creatorOfBugs == 2)
        {
          bichos bugs2 = bichos("BA", 20);
          limit++;
          bugs[i][j] = bugs2 ;
         
      }
        }

        cout<<(" BOARD GAME")<<endl;
        cout<<("-------------")<<endl;
        for(int index1 = 0; index1 < 2; index1++)
        {
          cout<<("|");
          for (int jIndex1 = 0; jIndex1 < 2; jIndex1++)
          {
            if (bugs[index1][jIndex1].getName().compare(""))
            {
             cout<<("     |")<<endl;
            }
            else
            {
              cout<<(bugs[index1][jIndex1].getName());
              /*cout<<(bugs[index1][jIndex1].getName() + to_string(bugs[index1][jIndex1].getHealth()) + "|");*/
            }
          }

        }
        cout<<("")<<endl;
        break;
      }

    
    }
    if(option1 == 2)
    {
      int fila;
      int columna;
      cout<<("Ingrese el numero de la fila:")<<endl;
      cin>>fila;
      cout<<("Ingrese el numero de la columna:")<<endl;
      cin>>columna;
      bugs[fila][columna].attack();
      if(bugs[fila][columna].getHealth() == 0)
      {
        cout<<("El bicho está muerto")<<endl;
      }
      cout<<(" BOARD GAME")<<endl;
      cout<<("-------------")<<endl;
      for (int i = 0; i < 2; i++)
      {
        cout<<("|");
        for (int j = 0; j < 2; j++)
        {
          if (bugs[i][j].getName().compare("")==0)
          {
            cout<<("     |")<<endl;
          }
          else
          {
            cout<<(bugs[i][j].getName(),to_string(bugs[i][j].getHealth()) + "|")<<endl;
          }
        }
        cout<<("-------------")<<endl;
      }
      cout<<("");
      if ((bugs[0][0].getHealth() == 0) && (bugs[0][1].getHealth() == 0) && (bugs[1][0].getHealth() == 0) && (bugs[1][1].getHealth() == 0))
      {
      cout<<("Felicidades usted ha matado todos los bichos.")<<endl;
      cout<<("Esta terminado el juego...")<<endl;
      cout<<("Juego terminado correctamente.")<<endl;
      option1 = 0;
      break;
      }
    }
    
  
}while (option1 != 0);
}

