#include "ArbolB.h"

ArbolB::ArbolB(int orden) {
    this->orden = orden;
    this->raiz = new NodoArbolB(this->orden, true);
}

void ArbolB::insertar(int dato) {
    NodoArbolB* nuevoNodo = nullptr;
    int valorAPasar = 0;

    this->raiz->insertar(dato, valorAPasar, nuevoNodo);

    if (nuevoNodo != nullptr) {
        this->raiz = this->raiz->nuevaRaiz(valorAPasar, nuevoNodo);
    }
}

void ArbolB::recorrer() { this->raiz->recorrer(0); }

ArbolB::~ArbolB() { delete this->raiz; }