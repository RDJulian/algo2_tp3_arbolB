#ifndef ARBOL_H
#define ARBOL_H

#include "nodoArbolB.h"

// TODO: Declarar apropiadamente.

template <typename Tipo, bool esMenor(Tipo, Tipo)> class ArbolB {
  private:
    int orden;
    NodoArbolB<Tipo, esMenor>* raiz;

  public:
    ArbolB(int orden) {
        this->orden = orden;
        this->raiz = new NodoArbolB<Tipo, esMenor>(this->orden, true);
    }

    void insertar(Tipo dato) {
        NodoArbolB<Tipo, esMenor>* nuevoNodo = nullptr;
        Tipo valorAPasar;

        this->raiz->insertar(dato, valorAPasar, nuevoNodo);

        if (nuevoNodo != nullptr) {
            this->raiz = this->raiz->nuevaRaiz(valorAPasar, nuevoNodo);
        }
    }

    void ejecutar(void funcion(Tipo)) { this->raiz->ejecutar(funcion); }

    // Ambos metodos recorren inorden, por lo tanto en pantalla quedan
    // ordenados.
    void recorrer() { this->raiz->recorrer(0); }

    void listar() { this->raiz->recorrer(); }

    ~ArbolB() { delete this->raiz; }
};

#endif