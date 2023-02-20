#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "bichos.h"

using namespace std;
   bichos::bichos(){
   }
   bichos::~bichos(){
   }
    
    bichos::bichos(string name, int health)
    {
        this->name = name;
        this->health = health;
    }

    string bichos::getName()
    {
        return this->name;
    }

    void bichos::setName(string name)
    {
        this->name = name;
    }

    int bichos::getHealth()
    {
        return this->health;
    }

    void bichos::setHealth (int health)
    {
        this->health = health;
    }

    string bichos::toString(string name, int health)
    {
        return name + "-" + to_string(health);
    }

    void bichos::attack()
    {
      if(getHealth() > 0){
      cout<<("El bicho ha sufrido 5 de daño");
      setHealth(getHealth()-5);
    }
    } 
