#include "archivotext.h"

ArchivoText::ArchivoText(string n, string r):Archivo(n,r,"File")
{

}

ArchivoText::~ArchivoText()
{

}

void ArchivoText::setContenido(string cont){
    contenido = cont;
}

string ArchivoText::getName(){
    return Archivo::getName();
}

string ArchivoText::getPath(){
    return Archivo::getPath();
}

string ArchivoText::getTipo(){
    return Archivo::getTipo();
}
