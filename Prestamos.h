#ifndef PRESTAMOS_H
#define PRESTAMOS_H

#include <string>
#include "Prestamo.h"

class Prestamos
{
private:
    /* Puntero */
    Prestamo** lista;
    /* Atributos */
    int cantidad;
    int capacidad;

    void redimensionar();
public:
    /* Metodos */
    Prestamos(int cap);
    ~Prestamos();

    void mostrarPrestamos();
    void agregarPrestamo(Prestamo* p);
    Prestamo* buscarPrestamo(std::string id) ;
};



#endif