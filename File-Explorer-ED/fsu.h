#ifndef FSU_H
#define FSU_H

#include <iostream>
#include "folder.h"
#include "archivo.h"
#include "lista.h"
#include <qlist.h>

using namespace std;


class FSU
{
public:
    FSU();
    Archivo * crearArchivo(Folder * donde, string nomArchivo,string tipo);
    QList<Archivo*> listarArchivos(Folder * donde);
    Archivo * cargarArchivo(string nom, Folder * donde);
    int eliminarArchivo(string nom,Folder * donde);
    /*void copiar(string nom, Folder * donde, Folder * destino);*/
    Folder * root;

private:

};

#endif // FSU_H
