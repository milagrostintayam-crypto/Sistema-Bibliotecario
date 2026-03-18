#include <iostream>
#include "Menu.h"

using namespace std;

Menu::Menu(){
    cout<<"------Bienvenido a nuesro------\n";
    do
    {
        /* code */
        mostrarMenu();
        //this se usa cuando hai ambiguedad de nombres(parametro nombre y atributo nombre)
        this->opcion = leerOpcion();

        switch (opcion)
        {
        case 1:
            /* code regsitrar libros*/
            break;
        case 2:
            /* code mostrar usuarios*/
            break;
        case 3:
            /* code devolver libro*/
            break;
        case 4:
            /* code prestar libro*/
            break;
        case 5:
            /* code reportes y estadisticas*/
            break;
        case 6:
            /* opition salir*/
            cout<<"\nGracias por usar nuestro SISTEMA de BIBLIOTECA.\n";
            break;
        
        default:
            /*opcion invalidate*/
            cout<<"Opcion invalida, Vuelve a intentarlo.\n\n";
            break;
        }
    } while (opcion != 6);
    
}

void Menu::mostrarMenu(){
    cout<<"----SISTEMA DE BIBLIOTECA-----\n\n";
    cout<<"1: Registrar Libros."<<endl;
    cout<<"2: Mostrar usuarios."<<endl;
    cout<<"3: Devolver Libro."<<endl;
    cout<<"4: Prestar Libro."<<endl;
    cout<<"5: Reportes y estadisticas."<<endl;
    cout<<"6: salir."<<endl;
}

int Menu::leerOpcion(){
    int op;
    cout<<"Opcion: ";
    cin>>op;
    return op;
}