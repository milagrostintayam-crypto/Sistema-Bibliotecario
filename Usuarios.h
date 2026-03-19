#ifndef USUARIOS_H
#define USUARIOS_H

#include "Usuario.h"

class Usuarios
{
private:
    /* Puntero */
    Usuario** lista;
    /* Atributos */
    int cantidad;
    int capacidad;

    void redimensionar();
public:
    /* Metodos */
    Usuarios(int cap);
    ~Usuarios();

    void mostrarUsuarios();
    void agregarUsuario(Usuario* u);
    Usuario* buscarUsuario(string dni) ;

};



#endif