#include <iostream>
#include "Usuario.h"

using namespace std;

Usuario::Usuario(string name, string dni, int phone, string direction){
    this->name = name;
    this->dni= dni;
    this->phone = phone;
    this->direction = direction;
}

void Usuario::mostrarUsuario(){
    cout<<"Nombre: "<<name<<endl;
    cout<<"DNI: "<<dni<<endl;
    cout<<"Celular: "<<phone<<endl;
    cout<<"Direccion: "<<direction<<endl;
}

string Usuario::getDni(){
    return dni;
}