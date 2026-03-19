#include <iostream>
#include "Usuarios.h"

using namespace std;
//Constructor(crea el arreglo dinamico de punteros a Usuario "objeto")
Usuarios::Usuarios(int cap){
    capacidad = cap;
    cantidad = 0;
    //creacion de arreglo dinamico de punteros a Usuario
    lista = new Usuario*[capacidad];
}

//Destructor(libera espacio de memoria ocupado por el arreglo dinamico de punteros a Usuario "objeto")
Usuarios::~Usuarios(){
    for (int i = 0; i < cantidad; i++)
    {
        /* eliminando cada usuario de la lista */
        delete lista[i];
    }
    delete[] lista;// elimina lista de punteros a Usuario
    
}

//Metodo que redimenciona el arreglo dinamico cuando se llena la capacidad
void Usuarios::redimensionar(){
    capacidad *= 2;
    Usuario** nuevo = new Usuario*[capacidad];

    for(int i = 0; i < cantidad; i++){
        nuevo[i] = lista[i];
    }

    delete[] lista;
    lista = nuevo;
}

//Metodo que agrega un nuevo usuario a la lista de usuarios
void Usuarios::agregarUsuario(Usuario* u){
    if (cantidad == capacidad)
    {
        redimensionar();
    }

    lista[cantidad] = u;
    cantidad++;
}

//Metodo que muestra la informacion de todos los usuarios registrados
void Usuarios::mostrarUsuarios(){
    if (cantidad == 0)
    {
        cout<<"No hay usuarios registrados\n";
        return;
    }
    for (int i = 0; i < cantidad; i++)
    {
        lista[i]->mostrarUsuario();
    }
}

//Metodo que busca un usuario por su DNI y devuelve un puntero al usuario encontrado o nullptr si no se encuentra
Usuario* Usuarios::buscarUsuario(string dni){
    for (int i = 0; i < cantidad; i++)
    {
        if (lista[i]->getDni() == dni)
        {
            return lista[i];
        }
    }
    return nullptr;
}