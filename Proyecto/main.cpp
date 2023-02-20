#include <iostream>
#include "parser.h"
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "symboltable.h"
#include "code.h"
 
using namespace std;

vector <SymbolTable> tablasimbolos;

bool SymbolTable::contains(string _symbol){
  bool temp = false;
  for(int i = 0; i<= tablasimbolos.size() ; i++){
    if(_symbol== tablasimbolos[i].getSymbol()){
      temp = true;  
    }
  }
  return temp;
}

parser* inicializar(string filename){
  SymbolTable R0 = SymbolTable("R0",0);
  SymbolTable R1 = SymbolTable("R1",1);
  SymbolTable R2 = SymbolTable("R2",2);
  SymbolTable R3 = SymbolTable("R3",3);
  SymbolTable R4 = SymbolTable("R4",4);
  SymbolTable R5 = SymbolTable("R5",5);
  SymbolTable R6 = SymbolTable("R6",6);
  SymbolTable R7 = SymbolTable("R7",7);
  SymbolTable R8 = SymbolTable("R8",8);
  SymbolTable R9 = SymbolTable("R9",9);
  SymbolTable R10 = SymbolTable("R10",10);
  SymbolTable R11 = SymbolTable("R11",11);
  SymbolTable R12 = SymbolTable("R12",12);
  SymbolTable R13 = SymbolTable("R13",13);
  SymbolTable R14 = SymbolTable("R14",14);
  SymbolTable R15 = SymbolTable("R15",15);
  SymbolTable SCREEN = SymbolTable("SCREEN",16384);
  SymbolTable KBD = SymbolTable("KBD",24576);
  SymbolTable SP = SymbolTable("SP",0);
  SymbolTable LCL = SymbolTable("LCL",1);
  SymbolTable ARG = SymbolTable("ARG",2);
  SymbolTable THIS = SymbolTable("THIS",3);
  SymbolTable THAT = SymbolTable("THAT",4);
  SymbolTable WRITE = SymbolTable("WRITE",18);
  SymbolTable END = SymbolTable("END",22);
  SymbolTable i = SymbolTable("i",16);
  SymbolTable sum = SymbolTable("sum",17);
  tablasimbolos.push_back (R0);
  tablasimbolos.push_back (R1);
  tablasimbolos.push_back (R2);
  tablasimbolos.push_back (R3);
  tablasimbolos.push_back (R4);
  tablasimbolos.push_back (R5);
  tablasimbolos.push_back (R6);
  tablasimbolos.push_back (R7);
  tablasimbolos.push_back (R8);
  tablasimbolos.push_back (R9);
  tablasimbolos.push_back (R10);
  tablasimbolos.push_back (R11);
  tablasimbolos.push_back (R12);
  tablasimbolos.push_back (R13);
  tablasimbolos.push_back (R14);
  tablasimbolos.push_back (R15);
  tablasimbolos.push_back (SCREEN);
  tablasimbolos.push_back (KBD);
  tablasimbolos.push_back (SP);
  tablasimbolos.push_back (LCL);
  tablasimbolos.push_back (ARG);
  tablasimbolos.push_back (THIS);
  tablasimbolos.push_back (THAT);
  tablasimbolos.push_back (WRITE);
  tablasimbolos.push_back (END);
  tablasimbolos.push_back (i);
  tablasimbolos.push_back (sum);
  parser* program = new parser(filename);
  return program;
}

bool contains(string _symbol){
  bool temp = false;
  for(int i = 0; i<= tablasimbolos.size() ; i++){
    if(_symbol == tablasimbolos[i].getSymbol()){
      return true;  
    }
  }
  return temp;
}

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}


parser* primera_pasada(parser* program,string filname){
  int contador = 0;
  string n,m;
  while(program->hasMoreCommands()){
      program->advance();
    if(program->commandType() == "L_COMMAND"){
      n = program->etiqueta();
      if(contains(n)==0){
      SymbolTable temp = SymbolTable(n,contador);
      tablasimbolos.push_back (temp);
      }
    }else if(program->commandType() == "A_COMMAND"){
      contador++;
      
    }else if(program->commandType() == "C_COMMAND"){
      contador++;
    }
  }
  parser* program2 = new parser(filname);
  return program2;
}

void segunda_pasada(parser* program,string filename) {
    ofstream nuevo;
    nuevo.open(filename+".hack",ios::out);
    string temp,temp0, temp1,temp2,temp3,m;
    int j,o;
    int contador = 16;
	  while (program->hasMoreCommands()) {
      if(program->advance()){
	    if(program->commandType() =="A_COMMAND"){
        temp2 = program->symbol();
        if(contains(temp2)==0 && isNumber(temp2) == 0){
          contador++;
          m = program->symbol();
          SymbolTable temp = SymbolTable(m,contador);
          tablasimbolos.push_back (temp);
          o = temp.getAddress();
          short binario[16];
          for(int i = 0;i<16;i++){
            binario[i] = o%2;
            o /= 2;
          }
          for(int j = 15;j>=0; j--){
            if(j>0){
              nuevo<<binario[j];
            }else{
              nuevo<<binario[j]<<endl;
            }
          } 
        }else if(isNumber(temp2)==1){
          int r = atoi(temp2.c_str());
          short binario[16];
          for(int i = 0;i<16;i++){
          binario[i] = r%2;
          r /= 2;
          }
          for(int j = 15;j>=0; j--){
            if(j>0){
              nuevo<<binario[j];
            }else{
              nuevo<<binario[j]<<endl;
            }
          }
         }else if(contains(temp2)==1){
           for(int j = 0; j<= tablasimbolos.size() ; j++){
            if(temp2 == tablasimbolos[j].getSymbol()){
              o = tablasimbolos[j].getAddress();
              short binario[16];
              for(int i = 0;i<16;i++){
                binario[i] = o%2;
                o /= 2;
              }
              for(int e = 15;e>=0; e--){
                if (e>0){
                  nuevo<<binario[e];
                }else{
                  nuevo<<binario[e]<<endl;
                }
              }   
              
            } 
           }
          } 
      }else if(program->commandType() == "C_COMMAND"){
        nuevo<<"111";
        nuevo<<program->comp();
        nuevo<<program->dest();
        nuevo<<program->jump()<<endl;
		  }
      }
    }
}




int main(){
  cout<<"ingrese el nombre del archivo"<<endl;
  string name;
  cin>> name;
  parser* program = inicializar(name);
  parser* program1;
  int pos = name.find('.');
  string temp = name.substr(0,pos);
  program1 = primera_pasada(program,name);
  segunda_pasada(program1,temp);
}