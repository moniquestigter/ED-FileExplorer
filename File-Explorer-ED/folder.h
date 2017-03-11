#ifndef FOLDER_H
#define FOLDER_H

#include <iostream>
#include <QPushButton>
#include <QIcon>
#include <string.h>
#include <QLabel>
#include <QWidget>
#include "archivo.h"
#include "lista.h"

using namespace std;

class Folder: public Archivo
{
public:
    Folder(string nombre, string ruta);
    ~Folder();
    string nombre;
    string ruta;
    string getRuta();
    Lista * list;
    Archivo* add(Archivo * arch);
    void erase(Archivo * arch);
    int cant;

    Archivo * inicio;

    QLabel nom;
};

#endif // FOLDER_H
