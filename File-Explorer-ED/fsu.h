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
    Archivo * cargarArchivo(int pos, Folder * donde);
    int eliminarArchivo(int pos,Folder * donde);
    void copiar(string rutaOrigen, string rutaDestino);
    Folder * root;

};

#endif // FSU_H
