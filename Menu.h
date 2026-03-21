#ifndef MENU_H
#define MENU_H  
#include "Usuarios.h"
#include "Repository.h"

class Menu
{
private:
    //atributos
    int opcion;
    Usuarios usuarios;//atributo de clase
    Repository repo;//objeto creado como atributo
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