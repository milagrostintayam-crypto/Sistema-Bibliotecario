#ifndef USUARIO_H
#define USUARIO_H
#include <string>

using namespace std;

class Usuario
{
private:
    /* Atributos */
    string name;
    string dni;
    int phone;
    string direction;
public:
    /* Metodos */
    Usuario(string name, string dni, int phone, string direction);

    void mostrarUsuario();
    string getDni();
};



#endif