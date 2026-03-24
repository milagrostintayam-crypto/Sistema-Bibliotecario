#ifndef MENU_H
#define MENU_H  
#include "Usuarios.h"
#include "Repository.h"
#include "Prestamos.h"
#include "Devolucion.h"
#include "Reportes.h"

class Menu
{
private:
    //atributos
    int opcion;
    Usuarios usuarios;//atributo de clase
    Repository repo;//objeto creado como atributo
    Prestamos prestamos;
    Devolucion devolucion;
    Reportes reportes;
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