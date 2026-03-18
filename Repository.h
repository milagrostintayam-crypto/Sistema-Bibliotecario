#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <string>
 
 //archivo de cabecera -Que puede hacer la clase (contrato)
class Repository
{
private:
    //atributos
    int IDlibro;
    string Titulos[50];
    int Cantdlibros [50];
public:
    //contructor
    Repository();

    //metodos
    void mostrarCantLibros();
    void reductrCantLibros();

#endif