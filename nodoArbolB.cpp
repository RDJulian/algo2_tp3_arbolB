#include "nodoArbolB.h"
#include <iostream>

using namespace std;

NodoArbolB::NodoArbolB(int orden, bool esHoja) {
    this->orden = orden;
    this->esHoja = esHoja;
}

NodoArbolB::~NodoArbolB() {
    if (!esHoja) {
        for (NodoArbolB* nodoHijo : nodosHijos) {
            delete nodoHijo;
        }
    }
}

void NodoArbolB::recorrer(int tabulacion) {
    int i;
    string tabulaciones;
    for (int i = 0; i < tabulacion; i++) {
        tabulaciones += '\t';
    }

    for (i = 0; i < claves.size(); i++) {
        if (!esHoja)
            nodosHijos[i]->recorrer(tabulacion + 1);
        cout << tabulaciones << claves[i] << endl;
    }
    if (!esHoja) {
        nodosHijos[i]->recorrer(tabulacion + 1);
    }
}

int NodoArbolB::buscarIndice(int dato) {
    int i = claves.size() - 1;
    while (i >= 0 && dato < claves[i]) {
        i--;
    }
    return i;
}

NodoArbolB* NodoArbolB::nuevaRaiz(int valorAPasar, NodoArbolB* nuevoNodo) {
    NodoArbolB* nuevaRaiz = new NodoArbolB(this->orden, false);

    nuevaRaiz->claves.push_back(valorAPasar);

    nuevaRaiz->nodosHijos.push_back(this);
    nuevaRaiz->nodosHijos.push_back(nuevoNodo);

    return nuevaRaiz;
}

void NodoArbolB::separarNodo(int& valorAPasar, NodoArbolB*& nuevoNodo) {
    nuevoNodo = new NodoArbolB(orden, false);
    valorAPasar = claves[orden / 2];

    for (int i = orden / 2 + 1; i < this->orden; i++) {
        nuevoNodo->claves.push_back(claves[i]);
    }

    claves.resize(orden / 2);

    for (int i = orden / 2 + 1; i <= orden; i++) {
        nuevoNodo->nodosHijos.push_back(nodosHijos[i]);
    }

    nodosHijos.resize(orden / 2 + 1);
}

void NodoArbolB::insertar(int dato, int& valorAPasar, NodoArbolB*& nuevoNodo) {
    int indice;
    if (!esHoja) {
        indice = buscarIndice(dato);
        this->nodosHijos[indice + 1]->insertar(dato, valorAPasar, nuevoNodo);

        // El nodo hijo no necesito separarse.
        if (nuevoNodo == nullptr) {
            return;
        }
        // El nodo puede almacenar el dato que le paso el hijo.
        if (claves.size() < orden - 1) {
            indice = buscarIndice(valorAPasar);
            claves.insert(claves.begin() + indice + 1, valorAPasar);
            nodosHijos.insert(nodosHijos.begin() + indice + 2, nuevoNodo);

            nuevoNodo = nullptr;
        } else { // El nodo actual se tiene que separar.
            indice = buscarIndice(valorAPasar);
            claves.insert(claves.begin() + indice + 1, valorAPasar);
            nodosHijos.insert(nodosHijos.begin() + indice + 2, nuevoNodo);

            separarNodo(valorAPasar, nuevoNodo);
        }
    } else {
        indice = buscarIndice(dato);
        claves.push_back(dato);

        if (claves.size() == orden) {
            nuevoNodo = new NodoArbolB(orden, true);
            valorAPasar = claves[orden / 2];

            for (int i = orden / 2 + 1; i < this->orden; i++) {
                nuevoNodo->claves.push_back(claves[i]);
            }

            claves.resize(orden / 2);
        }
    }
}