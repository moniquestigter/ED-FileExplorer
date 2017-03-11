#include "lista.h"

Lista::Lista()
{
    longiLista = 0;
    inicio = NULL;
}

Archivo * Lista::agregar(Archivo *arch){

}

void Lista::eliminar(Archivo * arch){

}

/*Archivo* Lista::buscar(string ruta){
    Archivo * temp = inicio;
    for(int a = 0; a<longiLista; a++){
        if(temp->nombre.find(ruta))
            return temp;
        temp = temp->sig;
    }
}*/
