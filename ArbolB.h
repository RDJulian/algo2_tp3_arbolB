#include "nodoArbolB.h"

class ArbolB {
  private:
    int orden;
    NodoArbolB* raiz;

  public:
    ArbolB(int orden);

    void insertar(int dato);

    void recorrer();

    ~ArbolB();
};