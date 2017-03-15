#include "folder.h"

Folder::Folder(string n, string r):Archivo(n,r,"Folder")
{
    list = new Lista();
    cant = 0;
}

Folder::~Folder(){

}

string Folder::getPath(){
    return Archivo::getPath();
}

string Folder::getName(){
    return Archivo::getName();
}

string Folder::getTipo(){
    return Folder::getTipo();
}

Archivo * Folder::add(Archivo *arch, Folder * donde){
    if(donde->list->inicio == NULL){
        donde->list->inicio = arch;
        donde->cant++;
    }
    else
    {
        Archivo * temp = donde->list->inicio;
        while(temp->sig != NULL)
            temp = temp->sig;
        temp->sig = arch;
        arch->ant = temp;
        donde->cant++;
    }
    return arch;
}


