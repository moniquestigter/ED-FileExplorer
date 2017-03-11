#include "archivotext.h"

ArchivoText::ArchivoText(string n, string r):Archivo(n,r,"File")
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
