#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>

using namespace std;

class Archivo
{
public:
    Archivo(string nombre, string ruta, string tipo);
    string tipo,ruta,nombre;
    int code;
    Archivo * sig;
    Archivo * ant;
};

#endif // ARCHIVO_H
