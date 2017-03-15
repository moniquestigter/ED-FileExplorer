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
    if(cant == 0){
        donde->list->inicio = arch;
        cant++;
        return arch;
    }
    else if(cant == 1){
        donde->list->inicio->sig = arch;
        arch->ant = donde->list->inicio;
        cant++;
        return arch;
    }
    else{
        Archivo * temp = donde->list->inicio;
        for(int a = 0; a<cant; a++){
            while(temp->sig != NULL){
                temp = temp->sig;
             }
            temp = arch;
            temp->ant = arch->ant;
            cant++;
            return arch;;
         }
     }
    return NULL;
}

void Folder::erase(Archivo *arch,Folder * donde){
    Archivo * temp = donde->list->inicio;
    for(int a = 0; a<cant; a++){
        if(temp->nombre == arch->nombre){
            while(temp->sig !=NULL){
                temp->sig->ant = temp->ant;
                temp->ant->sig = temp->sig;
            }
            cant--;
        }
        temp = temp->sig;
    }
}

