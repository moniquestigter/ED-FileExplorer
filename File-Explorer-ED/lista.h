#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <iostream>
#include "archivo.h"
#include "archivoText.h"


class Lista
{
public:
    Lista();

    Archivo * agregar(Archivo * arch);
    void eliminar(Archivo * arch);
    Archivo * buscar(string ruta);

    Archivo * inicio;


    int longiLista;
};

#endif // LISTA_H
