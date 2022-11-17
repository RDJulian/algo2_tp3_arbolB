#include "Animal.h"
#include <iostream>

Animal::Animal(std::string nombre, int edad) {
    this->nombre = nombre;
    this->edad = edad;
};

bool Animal::esMenor(int edad) { return edad < this->edad; };

bool Animal::esMenor(std::string nombre) { return nombre < this->nombre; };

bool Animal::nombreMenor(Animal* otroAnimal) {
    return otroAnimal->esMenor(this->nombre);
};

bool Animal::edadMenor(Animal* otroAnimal) {
    return otroAnimal->esMenor(this->edad);
};

void Animal::imprimirNombre() { std::cout << this->nombre << " "; }

void Animal::imprimirEdad() { std::cout << this->edad << " "; }

Animal::~Animal(){};