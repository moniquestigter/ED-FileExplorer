#include "fsu.h"

FSU::FSU()
{
    root = new Folder("root","root/");
}

Archivo * FSU::cargarArchivo(string nom, Folder *donde){
    Archivo * temp = donde->list->inicio;
    while(temp->nombre != nom)
        temp = temp->sig;
    return temp;
}

Archivo * FSU::crearArchivo(Folder *donde, string nomArchivo, string tipo){
   Archivo * nuevoArchivo;
    if(tipo == "Folder"){
        Folder * nuevo = new Folder(nomArchivo, donde->getPath());
        nuevoArchivo= (Archivo*)nuevo;
        nuevoArchivo->tipo = tipo;
        donde->add(nuevoArchivo,donde);
     }
    else{
        ArchivoText * nuevo = new ArchivoText(nomArchivo,donde->getPath());
        nuevoArchivo = (Archivo*)nuevo;
        nuevoArchivo->tipo = tipo;
        donde->add(nuevoArchivo,donde);
    }
    return nuevoArchivo;
}

int FSU::eliminarArchivo(string nom, Folder * donde){
    Archivo * eliminarlo = cargarArchivo(nom,donde);
      if(eliminarlo == NULL)
          return -1;
      if(donde->list->inicio == eliminarlo){
          donde->list->inicio = eliminarlo->sig;
          donde->cant--;
      }
      else if(eliminarlo->sig == NULL){
          Archivo * temp = eliminarlo->ant;
          temp->sig =NULL;
          donde->cant--;
      }
      else{
          Archivo * temp = eliminarlo->sig;
          Archivo * temp2 = eliminarlo->ant;
          temp2->sig = temp;
          temp->ant = temp2;
          donde->cant--;
      }
      return 0;
}

QList<Archivo*> FSU::listarArchivos(Folder *donde)
{
   QList<Archivo*> lista;
   Archivo * temp = donde->list->inicio;
   for(int a = 0; a < donde->cant; a++){
       lista.append(temp);
       temp = temp->sig;
   }
   return lista;
}

void FSU::copiar(string nom, Folder *donde, Folder *destino){
    Archivo * temp = destino->list->inicio;
    Archivo * copiar = cargarArchivo(nom,donde);
    for(int a = 0; a < destino->cant; a++){
        destino->add(copiar,donde);
        crearArchivo(destino,copiar->nombre,copiar->tipo);
    }
}

