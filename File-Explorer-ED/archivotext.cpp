#include "archivotext.h"

ArchivoText::ArchivoText(string n, string r)
{
    nombre = n;
    ruta = r;
}

ArchivoText::~ArchivoText()
{
}

void ArchivoText::setContenido(string cont){
    contenido = cont;
}
