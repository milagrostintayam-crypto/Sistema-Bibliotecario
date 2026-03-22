#include <iostream>
#include <limits>
#include <cstdlib>
#include "Menu.h"
#include "Usuario.h"
#include "Usuarios.h"
#include "Libro.h"
#include "Libro.h"
#include "Repository.h"
#include <string>

using namespace std;

// Función para limpiar la pantalla
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

//Metodo constructor que muestra el menu de opciones al usuario y lee la opcion ingresada por el usuario
//El constructor tambien inicializa el atributo usuarios con una capacidad inicial de 2 usuarios
Menu::Menu() : usuarios(2), repo(10), prestamos(10), devolucion(&prestamos, &repo) {

    cout<<"------Bienvenido a nuestro------\n";
    do
    {
        mostrarMenu();
        this->opcion = leerOpcion();

        switch (opcion)
        {
        case 1:
        {
            clearScreen();
            repo.cargarDatos();
            repo.librosDisponibles();
            cout << "\nPresione Enter para continuar...";
            cin.get();
            cin.ignore();
            break;
        }
        case 2:
        {
            clearScreen();
            registrarUsuario();
            usuarios.mostrarUsuarios();
            cout << "\nPresione Enter para continuar...";
            cin.get();
            cin.ignore();
            break;
        }
        case 3:
        {
            clearScreen();
            string libroId, fechaDev;

            cout << "Ingrese ID del libro a devolver: ";
            cin >> libroId;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Ingrese fecha de devolucion (dd/mm/aaaa): ";
            getline(cin, fechaDev);

            devolucion.devolverLibroConReintentos(libroId, &usuarios, fechaDev);
            cout << "\nPresione Enter para continuar...";
            cin.get();
            break;
        }
        case 4:
        {
            clearScreen();
            string libroId, usuarioDni;

            cout << "Ingrese ID del libro a prestar: ";
            cin >> libroId;

            cout << "Ingrese DNI del usuario: ";
            cin >> usuarioDni;

            Usuario* usuario = usuarios.buscarUsuario(usuarioDni);
            if (!usuario) {
                cout << "Usuario no encontrado.\n";
                cout << "¿Desea registrar el usuario? (s/n): ";
                char opcionRegistro;
                cin >> opcionRegistro;
                if (opcionRegistro == 's' || opcionRegistro == 'S') {
                    clearScreen();
                    registrarUsuario();
                    usuario = usuarios.buscarUsuario(usuarioDni); // Buscar nuevamente después del registro
                    if (!usuario) {
                        cout << "Error al registrar el usuario. Intente nuevamente.\n";
                        cout << "\nPresione Enter para continuar...";
                        cin.get();
                        cin.ignore();
                        break;
                    }
                } else {
                    cout << "Prestamo cancelado.\n";
                    cout << "\nPresione Enter para continuar...";
                    cin.get();
                    cin.ignore();
                    break;
                }
            }

            int idNum;
            try {
                idNum = stoi(libroId);
            } catch (...) {
                cout << "ID de libro invalido.\n";
                cout << "\nPresione Enter para continuar...";
                cin.get();
                cin.ignore();
                break;
            }

            if (!repo.decrementarCantidadLibro(idNum)) {
                cout << "No hay ejemplares disponibles para el libro ID " << libroId << ".\n";
                cout << "\nPresione Enter para continuar...";
                cin.get();
                cin.ignore();
                break;
            }

            string fechaPrest = "hoy";
            string fechaDevol = "pendiente";
            prestamos.agregarPrestamo(new Prestamo(fechaPrest, fechaDevol, libroId, usuarioDni));
            cout << "Prestamo registrado con exito.\n";
            cout << "\nPresione Enter para continuar...";
            cin.get();
            cin.ignore();
            break;
        }
        case 5:
        {
            clearScreen();
            cout << "===== Reportes y Estadisticas =====\n";
            prestamos.mostrarPrestamos();
            devolucion.mostrarHistorial();
            cout << "\nPresione Enter para continuar...";
            cin.get();
            break;
        }
        case 6:
        {
            clearScreen();
            cout<<"\nGracias por usar nuestro SISTEMA de BIBLIOTECA.\n";
            break;
        }
        
        default:
        {
            clearScreen();
            cout<<"Opcion invalida, Vuelve a intentarlo.\n\n";
            break;
        }
        }
    } while (opcion != 6);
    
}

//Metodo que muestra el menu de opciones al usuario
void Menu::mostrarMenu(){
    cout<<"----SISTEMA DE BIBLIOTECA-----\n\n";
    cout<<"1: Mostrar libros disponibles ."<<endl;
    cout<<"2: registrar usuarios."<<endl;
    cout<<"3: Devolver Libro."<<endl;
    cout<<"4: Prestar Libro."<<endl;
    cout<<"5: Reportes y estadisticas."<<endl;
    cout<<"6: salir."<<endl;
}

//Metodo que lee la opcion ingresada por el usuario
int Menu::leerOpcion(){
    int op;
    cout<<"Opcion: ";
    
    while (!(cin >> op)) {
        cout<<"Entrada invalida. Intente de nuevo: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return op;
}

//Metodo que registra un nuevo usuario en el sistema
void Menu::registrarUsuario(){
    string name, dni, direction;
    int phone;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 🔥 LIMPIA BUFFER

    cout<<"Ingrese el nombre del usuario: ";
    getline(cin, name);

    cout<<"Ingrese el dni del usuario: ";
    getline(cin, dni);

    cout<<"Ingrese la direccion del usuario: ";
    getline(cin, direction);

    cout<<"Ingrese el numero de celular del usuario: ";
    while (!(cin >> phone)) {
        cout<<"Entrada invalida. Intente de nuevo: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    usuarios.agregarUsuario(new Usuario(name, dni, phone, direction));
    cout << "Usuario registrado exitosamente.\n";
}
    