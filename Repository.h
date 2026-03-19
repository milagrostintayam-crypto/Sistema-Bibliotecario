#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <string>

//#include "Libro.h"
 
 //archivo de cabecera -Que puede hacer la clase (contrato)
class Repository
{
private:
    Libro**Libros;
    int size;
    int capacidad;
public:
    //contructor
    Repository(int capacidad);
    ~Repository();


    //metodos
    void librosDisponibles();
    void mostrarCantLibros();
    void reductrCantLibros();
};
#endif