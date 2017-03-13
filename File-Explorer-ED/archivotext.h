#ifndef ARCHIVOTEXT_H
#define ARCHIVOTEXT_H

#include "archivo.h"
#include <iostream>
#include <QPushButton>
#include <QIcon>
#include <string.h>
#include <QLabel>

using namespace std;

class ArchivoText : public Archivo
{
public:
    ArchivoText(string nombre, string ruta);
    ~ArchivoText();
    string contenido;
    void setContenido(string contenido);
    string getName();
    string getPath();
    string getTipo();




};

#endif // ARCHIVOTEXT_H
