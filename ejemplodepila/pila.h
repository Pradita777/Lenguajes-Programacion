#ifndef pila_h
#define pila_h 

class pila{ 
public:
  pila();
  ~pila();
  void push(float dato);
  float pop();

private:
  float arreglo [30];
  int elementos ;
};
#endif 