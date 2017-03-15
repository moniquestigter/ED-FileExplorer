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
    void copiar(int pos, Folder * donde, Folder * destino);
    Folder * root;

private:

};

#endif // FSU_H
