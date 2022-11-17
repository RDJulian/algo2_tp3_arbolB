#include <vector>

struct NodoArbolB {
    int orden;
    std::vector<int> claves;
    std::vector<NodoArbolB*> nodosHijos;
    bool esHoja;

    NodoArbolB(int orden, bool esHoja);
    ~NodoArbolB();
    void recorrer(int tabulacion);
    int buscarIndice(int dato);
    NodoArbolB* nuevaRaiz(int valorAPasar, NodoArbolB* nuevoNodo);
    void separarNodo(int& valorAPasar, NodoArbolB*& nuevoNodo);
    void insertar(int dato, int& valorAPasar, NodoArbolB*& nuevoNodo);
};