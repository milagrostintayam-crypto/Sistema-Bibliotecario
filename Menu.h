#ifndef MENU_H
#define MENU_H  
#include "Usuarios.h"

class Menu
{
private:
    //atributos
    int opcion;
    Usuarios usuarios;//atributo de clase
public:
    //contructor
    Menu();
    //destructor
    // ~Menu();

    //metodos
    void mostrarMenu();

    int leerOpcion();

    void registrarUsuario();
};

#endif