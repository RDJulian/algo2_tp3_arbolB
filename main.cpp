#include "Animal.h"
#include "ArbolB.h"

using namespace std;

// Es necesario pasarle estas funciones al arbol.
bool edadMenor(Animal* unAnimal, Animal* otroAnimal) {
    return unAnimal->edadMenor(otroAnimal);
}

bool nombreMenor(Animal* unAnimal, Animal* otroAnimal) {
    return unAnimal->nombreMenor(otroAnimal);
}

void mostrarNombre(Animal* animal) { animal->imprimirNombre(); }

void mostrarEdad(Animal* animal) { animal->imprimirEdad(); }

void borrarAnimal(Animal* animal) { delete animal; }

int main() {
    // Capaz se puede juntar ambas cosas en un solo template.
    ArbolB<Animal*, edadMenor>* arbolEdades = new ArbolB<Animal*, edadMenor>(3);
    ArbolB<Animal*, nombreMenor>* arbolNombres =
        new ArbolB<Animal*, nombreMenor>(3);

    vector<Animal*> animales;

    animales.push_back(new Animal("Zorro", 3));
    animales.push_back(new Animal("Toto", 11));
    animales.push_back(new Animal("Mia", 5));
    animales.push_back(new Animal("Pancho", 6));
    animales.push_back(new Animal("Firulais", 12));
    animales.push_back(new Animal("Chiqui", 2));
    animales.push_back(new Animal("Rocky", 7));
    animales.push_back(new Animal("Bruno", 10));
    animales.push_back(new Animal("Nina", 1));

    for (Animal* animal : animales) {
        arbolEdades->insertar(animal);
        arbolNombres->insertar(animal);
    }

    arbolEdades->ejecutar(mostrarEdad);
    cout << endl;

    arbolNombres->ejecutar(mostrarNombre);
    cout << endl;

    arbolEdades->ejecutar(borrarAnimal);

    delete arbolEdades;
    delete arbolNombres;
    return 0;
}