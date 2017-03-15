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
    string getName();
    string getPath();
    string getTipo();
    Lista * list;
    Archivo* add(Archivo * arch, Folder * donde);
    void erase(Archivo * arch, Folder * donde);
    int cant;

};

#endif // FOLDER_H
