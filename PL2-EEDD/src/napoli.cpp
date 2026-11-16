#include "napoli.h"


lista::~lista()
{
    //dtor
}
~lista();

void lista:: insertarNodo(int v){
    NodoLista* aux;
    aux= new NodoLista(v);
    if(listaVacia()){
        cabeza=aux;
        final=aux;
    }
    else{
        final->siguiente=aux;
        final=aux;
    }

}

void lista::borrarNodo(int v){
    actual = cabeza;
    NodoLista* anterior;
    while((actual->siguiente!=v)&&(actual->siguiente!=NULL)){
        anterior=actual;
        actual= actual->siguiente;
    }
    if(actual->siguiente->valor==v){
        if(actual==cabeza){
            cabeza= actual->siguiente;
        }
        else{
            anterior->siguiente= actual->siguiente;
            if(actual== final){final=anterior};
        }
        actual->siguiente=NULL;
        delete actual;

    }
}

bool lista:: listaVacia(){
    return (cabeza==NULL);
}

void lista::esCabeza(){
    actual=cabeza;
}
void lista:: esFinal(){
    actual=final;
}
void lista::esSiguiente(){
    actual= actual->siguiente;
}
bool lista::esActual(){
    return (actual!=NULL;)
}
int lista::valorActual();
void lista::recorrerLista();
