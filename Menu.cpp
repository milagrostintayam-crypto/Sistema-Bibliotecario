#include <iostream>
#include "Menu.h"
#include "Usuario.h"
#include "Usuarios.h"
#include <string>

using namespace std;

//Metodo constructor que muestra el menu de opciones al usuario y lee la opcion ingresada por el usuario
//El constructor tambien inicializa el atributo usuarios con una capacidad inicial de 2 usuarios
Menu::Menu() : usuarios(2){

    cout<<"------Bienvenido a nuestro------\n";
    do
    {
        /* code */
        mostrarMenu();
        //this se usa cuando hay ambiguedad de nombres(parametro nombre y atributo nombre)
        this->opcion = leerOpcion();

        switch (opcion)
        {
        case 1:
            /* code regsitrar libros */
            break;
        case 2:
            /* code mostrar usuarios */

            registrarUsuario();
            usuarios.mostrarUsuarios();


            break;
        case 3:
            /* code devolver libro */
            break;
        case 4:
            /* code prestar libro */
            break;
        case 5:
            /* code reportes y estadisticas */
            break;
        case 6:
            /* opition salir */
            cout<<"\nGracias por usar nuestro SISTEMA de BIBLIOTECA.\n";
            break;
        
        default:
            /*opcion invalidate*/
            cout<<"Opcion invalida, Vuelve a intentarlo.\n\n";
            break;
        }
    } while (opcion != 6);
    
}

//Metodo que muestra el menu de opciones al usuario
void Menu::mostrarMenu(){
    cout<<"----SISTEMA DE BIBLIOTECA-----\n\n";
    cout<<"1: Registrar Libros."<<endl;
    cout<<"2: Mostrar usuarios."<<endl;
    cout<<"3: Devolver Libro."<<endl;
    cout<<"4: Prestar Libro."<<endl;
    cout<<"5: Reportes y estadisticas."<<endl;
    cout<<"6: salir."<<endl;
}

//Metodo que lee la opcion ingresada por el usuario
int Menu::leerOpcion(){
    int op;
    cout<<"Opcion: ";
    cin>>op;
    return op;
}

//Metodo que registra un nuevo usuario en el sistema
void Menu::registrarUsuario(){
    string name, dni, direction;
    int phone;


    cout<<"Ingrese el nombre del usuario: ";
    cin>>name;
    cout<<"Ingrese el dni del usuario: ";
    cin>>dni;
    cout<<"Ingrese la direccion del usuario: ";
    cin>>direction;
    cout<<"Ingrese el numero de celular del usuario: ";
    cin>>phone;

    //falta validar datos ingresdos por el usuario

    usuarios.agregarUsuario(new Usuario(name, dni, phone, direction));
}