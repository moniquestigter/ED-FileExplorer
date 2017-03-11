#include "folder.h"

Folder::Folder(string n, string r):Archivo(n,r,"Folder")
{
    nombre = n;
    ruta = r;
    list = new Lista();
    cant = 0;

}

Folder::~Folder(){

}

string Folder::getRuta(){
    return ruta;
}

Archivo * Folder::add(Archivo *arch){
    if(cant == 0){
        this->inicio = arch;
        cant++;
        return arch;
    }
    else{
        Archivo * temp = this->inicio;
        for(int a = 0; a<cant; a++){
            if(temp == NULL){
                temp = arch;
                temp->ant = arch->ant;
                cant++;
                return arch;;
             }
             temp = temp->sig;
         }
     }
    return NULL;
}

void Folder::erase(Archivo *arch){
    Archivo * temp = this->inicio;
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

