#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>

using namespace std;

class Archivo
{
public:
    Archivo(string nombre, string ruta, string tipo);
    string tipo,ruta,nombre;
    Archivo * sig;
    Archivo * ant;
protected:
    string getName();
    string getPath();
    string getTipo();

};

#endif // ARCHIVO_H
