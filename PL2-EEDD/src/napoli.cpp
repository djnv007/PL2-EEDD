#include "napoli.h"

/*---------------------Centros-------------------------------*/

centro crearCentro(){
    centro c;
    lista ventas;
    c.id_centro= 100+ rand()%900;
    c.localidad= rand()% N_LOCALIDADES;
    c.ventas= ventas;

    return c;
}


/*-----------------------------------------------------------*/

/*-------------------Ventas----------------------------------*/

venta crearVenta(){
    venta v;
    v.id_centro
    v.id_venta
    v.cod_pizza= rand()%8;
    v.categoria= asignarCategoria();
    v.unidades= 1+ rand()%20;
    v.fecha_venta;

    return v;
}

Categoria asignarCategoria(Codigo c){
    if (c==NP01 || c==NP02){
        return Tradicional;
    }
    else if (c==NP03 || c=NP04){
        return Carne;
    }
    else if (c==NP05 || c=NP06){
        return Verduras;
    }
    else if (c==NP07 || c=NP08){
        return Quesos;
    }
    else{return NULL;}

}

/*-----------------------------------------------------------*/

/*-------------------Listas----------------------------------*/

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
