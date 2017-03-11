#include "fsu.h"

FSU::FSU()
{
    root = new Folder("root","root/");
}

Archivo * FSU::cargarArchivo(int pos, Folder *donde){
    Archivo * temp = donde->list->inicio;
       for(int a = 0; a < pos; a++){
           temp = temp->sig;
       }
       return temp;
}

Archivo * FSU::crearArchivo(Folder *donde, string nomArchivo, string tipo){
   Archivo * nuevoArchivo;
    if(tipo == "Folder"){
        Folder * nuevo= new Folder(nomArchivo, donde->getRuta());
        nuevoArchivo= (Archivo*)nuevo;
        nuevoArchivo->tipo = tipo;
        nuevoArchivo->code = 1;
        donde->add(nuevoArchivo);
     }
    else{
        ArchivoText * nuevo = new ArchivoText(nomArchivo,donde->getRuta());
        Archivo * nuevoArchivo = (Archivo*)nuevo;
        nuevoArchivo->tipo = tipo;
        nuevoArchivo->code = 2;
        donde->add(nuevoArchivo);
    }
    return nuevoArchivo;
}

int FSU::eliminarArchivo(int pos, Folder * donde){
    Archivo * eliminarlo = cargarArchivo(pos,donde);
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
   QList<Archivo*> list;
   Archivo * temp = donde->inicio;
   for(int a = 0; a < donde->cant; a++){
       list.insert(a,temp);
       temp = temp->sig;
   }
   return list;
}
