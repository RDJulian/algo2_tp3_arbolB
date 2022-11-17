#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <math.h>
#include <string>
#include <vector>

// TODO: Declarar apropiadamente.

template <typename Tipo, bool esMenor(Tipo, Tipo)> struct NodoArbolB {
    int orden;
    std::vector<Tipo> claves;
    std::vector<NodoArbolB*> nodosHijos;
    bool esHoja;

    NodoArbolB(int orden, bool esHoja) {
        this->orden = orden;
        this->esHoja = esHoja;
    }

    ~NodoArbolB() {
        if (!esHoja) {
            for (NodoArbolB* nodoHijo : nodosHijos) {
                delete nodoHijo;
            }
        }
    }

    // Los siguientes tres metodos hacen recorrido inorden.
    void recorrer(int tabulacion) {
        int i;
        std::string tabulaciones;
        for (int i = 0; i < tabulacion; i++) {
            tabulaciones += '\t';
        }

        for (i = 0; i < claves.size(); i++) {
            if (!esHoja)
                nodosHijos[i]->recorrer(tabulacion + 1);
            std::cout << tabulaciones << claves[i] << std::endl;
        }
        if (!esHoja) {
            nodosHijos[i]->recorrer(tabulacion + 1);
        }
    }

    void recorrer() {
        int i;
        for (i = 0; i < claves.size(); i++) {
            if (!esHoja)
                nodosHijos[i]->recorrer();
            std::cout << claves[i] << " ";
        }
        if (!esHoja) {
            nodosHijos[i]->recorrer();
        }
    }

    void ejecutar(void funcion(Tipo)) {
        int i;
        for (i = 0; i < claves.size(); i++) {
            if (!esHoja)
                nodosHijos[i]->ejecutar(funcion);
            funcion(claves[i]);
        }
        if (!esHoja) {
            nodosHijos[i]->ejecutar(funcion);
        }
    }

    int buscarIndice(Tipo dato) {
        int i = claves.size() - 1;
        while (i >= 0 && esMenor(dato, claves[i])) {
            i--;
        }
        return i;
    }

    NodoArbolB* nuevaRaiz(Tipo valorAPasar, NodoArbolB* nuevoNodo) {
        NodoArbolB* nuevaRaiz = new NodoArbolB(this->orden, false);

        nuevaRaiz->claves.push_back(valorAPasar);

        nuevaRaiz->nodosHijos.push_back(this);
        nuevaRaiz->nodosHijos.push_back(nuevoNodo);

        return nuevaRaiz;
    }

    void separarNodo(Tipo& valorAPasar, NodoArbolB*& nuevoNodo) {
        int indiceAPasar = std::ceil(double(orden) / 2 - 1);
        nuevoNodo = new NodoArbolB(orden, false);
        valorAPasar = claves[indiceAPasar];

        for (int i = indiceAPasar + 1; i < this->orden; i++) {
            nuevoNodo->claves.push_back(claves[i]);
        }

        claves.resize(indiceAPasar);

        for (int i = indiceAPasar + 1; i <= orden; i++) {
            nuevoNodo->nodosHijos.push_back(nodosHijos[i]);
        }

        nodosHijos.resize(indiceAPasar + 1);
    }

    void insertar(Tipo dato, Tipo& valorAPasar, NodoArbolB*& nuevoNodo) {
        int indice;
        if (!esHoja) {
            indice = buscarIndice(dato);
            this->nodosHijos[indice + 1]->insertar(dato, valorAPasar,
                                                   nuevoNodo);

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
            claves.insert(claves.begin() + indice + 1, dato);

            if (claves.size() == orden) {
                int indiceAPasar = std::ceil(double(orden) / 2 - 1);
                nuevoNodo = new NodoArbolB(orden, true);
                valorAPasar = claves[indiceAPasar];

                for (int i = indiceAPasar + 1; i < this->orden; i++) {
                    nuevoNodo->claves.push_back(claves[i]);
                }

                claves.resize(indiceAPasar);
            }
        }
    }
};

#endif