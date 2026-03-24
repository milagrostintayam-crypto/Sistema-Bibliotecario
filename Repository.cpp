//archivo de implementacion - Como lo hace (implementacion)
#include "Repository.h"
#include "Libro.h"
#include "Usuarios.h"
#include "Usuario.h"
#include <iostream>
using namespace std;

// Constructor
Repository::Repository(int capacidad) {
    this->capacidad = capacidad; //"this apunta al objeto actual, y se usa para diferenciar atributos de parámetros."
    this->size = 0;//representa cuántos libros existen actualmente en el repositorio
    Libros = new Libro*[capacidad];//libros esta recepcionando un puntero va a tomar el valor del libro que es arreglo
}//Libros es un arreglo de punteros a objetos Libro

Repository::~Repository() { //Libera la memoria creada con new
    for (int i = 0; i < size; i++) {
        delete Libros[i];
    }
    delete[] Libros;
}

void Repository::cargarDatos() {
    Libros[0] = new Libro(1,"Sistemas and Software",5);
    Libros[1] = new Libro(2, "1984", 5);
    Libros[2] = new Libro(3, "Vampirito", 2);
    Libros[3] = new Libro(4, "El Principito", 3);
    Libros[4] = new Libro(5, "Orgullo y prejuicio", 2);

    size = 5; // IMPORTANTÍSIMO
}

void Repository::librosDisponibles() {
    cout<<"====================================="<<endl;
    cout<<"LIBROS DISPONIBLES:"<<endl;
    cout<<"====================================="<<endl;
    for (int i = 0; i < size; i++ ) {
    cout<<"_____________________________________"<<endl;
        cout<<"ID:                  "<<Libros[i]->getID()<<endl;
        cout<<"Titulo:              "<<Libros[i]->getTitulo()<<endl;
        cout<<"Cantidad disponible: "<<Libros[i]->getCant()<<endl;
        }
}

// NUEVO: Método para reducir stock cuando se presta un libro
bool Repository::decrementarCantidadLibro(int libroId){
    for (int i = 0; i < size; i++) {
        if (Libros[i]->getID() == libroId) {
            if (Libros[i]->getCant() > 0) {
                Libros[i]->setCant(Libros[i]->getCant() - 1);
                // int nuevaCant = Libros[i]->getCant() - 1;
                // *Libros[i] = Libro(Libros[i]->getID(), Libros[i]->getTitulo(), nuevaCant);
                return true;
            }
            return false;
        }
    }
    return false;
}

// NUEVO: Método para aumentar stock cuando se devuelve un libro
bool Repository::incrementarCantidadLibro(int libroId){
    for (int i = 0; i < size; i++) {
        if (Libros[i]->getID() == libroId) {
            Libros[i]->setCant(Libros[i]->getCant() + 1);
            // int nuevaCant = Libros[i]->getCant() + 1;
            // *Libros[i] = Libro(Libros[i]->getID(), Libros[i]->getTitulo(), nuevaCant);
            return true;
        }
    }
    return false;
}

// NUEVO: Método para consultar la cantidad disponible de un libro
int Repository::obtenerCantidadLibro(int libroId) const {
    for (int i = 0; i < size; i++) {
        if (Libros[i]->getID() == libroId) {
            return Libros[i]->getCant();
        }
    }
    return -1;
}
//METODO: Para el uso de un analisis general en reportes

int Repository::totalLibros() const {
    return size;
    }

int Repository::contarDisponibles() const{
    int cont = 0;

    for (int i = 0; i < size; i++) {
        if (Libros[i]->getCant() > 0) {
            cont++;
        }
    }
    return cont;    
}

int Repository::contarAgotados() const{
    int cont = 0;

    for (int i = 0; i < size; i++) {
        if (Libros[i]->getCant() == 0) {
            cont++;
        }
    }
    return cont;
}