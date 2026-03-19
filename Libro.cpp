#include <iostream>
//llamando a  la cabecera
#include "Libro.h"

using namespace std;

Libro::Libro() {}
Libro::Libro(int ID, std::string Titulo, int Cant) {
    this->ID = ID;
    this->Titulo = Titulo;
    this->Cant = Cant;
}
int Libro::getID() { 
    return ID; 
}
std::string Libro::getTitulo() { 
    return Titulo; 
}
int Libro::getCant() { 
    return Cant; 
}