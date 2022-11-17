#include "ArbolB.h"

int main() {
    ArbolB* arbol = new ArbolB(3);

    arbol->insertar(1);
    arbol->insertar(2);
    arbol->insertar(3);
    arbol->insertar(4);
    arbol->insertar(5);
    arbol->insertar(6);
    arbol->insertar(7);

    arbol->recorrer();

    delete arbol;
    return 0;
}