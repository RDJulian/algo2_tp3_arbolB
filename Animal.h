#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>

class Animal {
  private:
    std::string nombre;
    int edad;
    // Demas parametros

  public:
    Animal(std::string nombre, int edad);
    bool esMenor(int edad);
    bool esMenor(std::string nombre);
    bool nombreMenor(Animal* otroAnimal);
    bool edadMenor(Animal* otroAnimal);
    void imprimirNombre();
    void imprimirEdad();
    ~Animal();
};

#endif