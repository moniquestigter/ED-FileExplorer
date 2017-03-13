#include "archivo.h"

Archivo::Archivo(string n,string r,string t)
{
    nombre = n;
    ruta = r;
    tipo = t;
    sig = NULL;
    ant = NULL;

}

string Archivo::getName(){
    return nombre;
}

string Archivo::getPath(){
    return ruta;
}

string Archivo::getTipo(){
    return tipo;
}


