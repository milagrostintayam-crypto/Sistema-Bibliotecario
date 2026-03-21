#include <iostream>
#include "Prestamos.h"

using namespace std;
//Constructor(crea el arreglo dinamico de punteros a Usuario "objeto")
Prestamos::Prestamos(int cap){
    capacidad = cap;
    cantidad = 0;
    //creacion de arreglo dinamico de punteros a Usuario
    lista = new Prestamo*[capacidad];
}

//Destructor(libera espacio de memoria ocupado por el arreglo dinamico de punteros a Usuario "objeto")
Prestamos::~Prestamos(){
    for (int i = 0; i < cantidad; i++)
    {
        /* eliminando cada usuario de la lista */
        delete lista[i];
    }
    delete[] lista;// elimina lista de punteros a Usuario
    
}

//Metodo que redimenciona el arreglo dinamico cuando se llena la capacidad
void Prestamos::redimensionar(){
    capacidad *= 2;
    Prestamo** nuevo = new Prestamo*[capacidad];

    for(int i = 0; i < cantidad; i++){
        
        nuevo[i] = lista[i];
    }

    delete[] lista;
    lista = nuevo;
}

//Metodo que agrega un nuevo usuario a la lista de usuarios
void Prestamos::agregarPrestamo(Prestamo* p){
    if (cantidad == capacidad)
    {
        redimensionar();
    }

    lista[cantidad] = p;
    cantidad++;
}

//Metodo que muestra la informacion de todos los usuarios registrados
void Prestamos::mostrarPrestamos(){
    if (cantidad == 0)
    {
        cout<<"No hay prestamos registrados\n";
        return;
    }
    for (int i = 0; i < cantidad; i++)
    {
        cout<<"\nPrestamo "<<i+1<<":\n";
        lista[i]->mostrarPrestamo();
    }
}

//Metodo que busca un usuario por su DNI y devuelve un puntero al usuario encontrado o nullptr si no se encuentra
Prestamo* Prestamos::buscarPrestamo(string id){
    for (int i = 0; i < cantidad; i++)
    {
        if (lista[i]->getLibro() == id)
        {
            return lista[i];
        }
    }
    return nullptr;
}