#include <iostream>
#include <string>
#include "Prestamo.h"

using namespace std;

Prestamo::Prestamo(std::string fechaPrestamo, std::string fechaDevolucion, std::string libroId, std::string usuarioId){
    this->fechaPrestamo = fechaPrestamo;
    this->fechaDevolucion = fechaDevolucion;
    this->libroId = libroId;
    this->usuarioId = usuarioId;
}

void Prestamo::mostrarPrestamo() const{
    cout << "Información del Prestamo:\n";
    cout << "Fecha de Prestamo: " << fechaPrestamo << endl;
    cout << "Fecha de Devolucion: " << fechaDevolucion << endl;
    cout << "ID del Libro: " << libroId << endl;
    cout << "ID del Usuario: " << usuarioId << endl;
}

string Prestamo::getFechaPrestamo() const{
    return fechaPrestamo;
}

string Prestamo::getFechaDevolucion() const{
    return fechaDevolucion;
}

string Prestamo::getLibro() const{
    return libroId;
}

string Prestamo::getUsuario() const{
    return usuarioId;
}

Prestamo::~Prestamo(){
    // No hay recursos dinámicos que liberar, por lo que el destructor está vacío
}