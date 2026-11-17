#include "napoli.h"
#include <cstdio>
#include <iostream>

using namespace std;
/*---------------------Auxiliares Texto----------------------*/
const char* localidadToString(Localidad l)
{
    const char* nombres[N_LOCALIDADES] = {
        "MOSTOLES", "ALCALA", "LEGANES", "FUENLABRADA", "GETAFE",
        "ALCORCON", "TORREJON", "PARLA", "ALCOBENDAS", "COSLADA",
        "POZUELO", "RIVAS", "VALDEMORO", "MAJADAHONDA", "ARANJUEZ",
        "ARGANDA", "BOADILLA", "PINTO", "COLMENAR", "TRES CANTOS"
    };
    if (l >= 0 && l < N_LOCALIDADES) return nombres[l];
    return "DESCONOCIDA";
}

const char* codigoToString(Codigo c)
{
    const char* codigos[8] = {"NP01", "NP02", "NP03", "NP04", "NP05", "NP06", "NP07", "NP08"};
    if (c >= 0 && c < 8) return codigos[c];
    return "NP00";
}

const char* categoriaToString(Categoria cat)
{
    const char* cats[4] = {"Tradicional", "Carne", "Verduras", "Quesos"};
    if (cat >= 0 && cat < 4) return cats[cat];
    return "Desconocida";
}


<<<<<<< HEAD
centro crearCentro(Localidad loc)
{
    centro c;
    c.id_centro = 100 + rand() % 900;
    c.localidad = loc;
    return c;
}


=======
>>>>>>> 3eaaf0e1e385932712f38cf2a5a55667116d639e

/*-------------------Ventas----------------------------------*/

void generarFechaAleatoria(char fecha[])
{
    int diasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int mes = 1 + rand() % 12;
    int dia = 1 + rand() % diasMes[mes - 1];
    sprintf(fecha, "%02d-%02d-2026", dia, mes);
}

venta crearVenta(int id_centro_destino)
{
    venta v;
    static int contador = 10000;

    v.id_centro = id_centro_destino;
    sprintf(v.id_venta, "V%05d", contador);
    contador++;

    v.cod_pizza = static_cast<Codigo>(rand() % 8);
    v.categoria = asignarCategoria(v.cod_pizza);
    v.unidades = 1 + rand() % 20;
    generarFechaAleatoria(v.fecha_venta);

    return v;
}

Categoria asignarCategoria(Codigo c)
{
    if (c==NP01 || c==NP02)
    {
        return Tradicional;
    }
    else if (c==NP03 || c==NP04)
    {
        return Carne;
    }
    else if (c==NP05 || c==NP06)
    {
        return Verduras;
    }
    else if (c==NP07 || c==NP08)
    {
        return Quesos;
    }

    return Tradicional;
}
/*-----------------------------------------------------------*/

/*-------------------Listas----------------------------------*/

lista::~lista()
{
    NodoLista* aux;
    while(cabeza!=NULL){
        aux=cabeza;
        cabeza= cabeza->siguiente;
        delete aux;
    }
}

void lista:: insertarNodo(venta v)
{
    NodoLista* aux;
    aux= new NodoLista(v);
    if(listaVacia())
    {
        cabeza=aux;
        final=aux;
    }
    else
    {
        final->siguiente=aux;
        final=aux;
    }

}

void lista::borrarNodo(venta v)
{
    actual = cabeza;
    NodoLista* anterior;
    while((strcmp(actual->valor.id_venta,v.id_venta)!=0)&&(actual->siguiente!=NULL))
    {
        anterior=actual;
        actual= actual->siguiente;
    }
    if(strcmp(actual->valor.id_venta,v.id_venta))
    {
        if(actual==cabeza)
        {
            cabeza= actual->siguiente;
        }
        else
        {
            anterior->siguiente= actual->siguiente;
            if(actual== final)
            {
                final=anterior;
            };
        }
        actual->siguiente=NULL;
        delete actual;

    }
}

bool lista:: listaVacia()
{
    return (cabeza==NULL);
}

void lista::esCabeza()
{
    actual=cabeza;
}
void lista:: esFinal()
{
    actual=final;
}
void lista::esSiguiente()
{
    actual= actual->siguiente;
}
bool lista::esActual()
{
    return (actual!=NULL);
}
venta lista::valorActual(){
    return actual->valor;
};
void lista::recorrerLista(){
    NodoLista* aux;
    aux = cabeza;
    while(aux){
        cout<<aux->valor.id_venta<<endl;
        aux= aux->siguiente;
    }
}

/*---------------------Centros-------------------------------*/

centro crearCentro()
{
    centro c;
    c.id_centro= 100+ rand()%900;
    c.localidad= static_cast<Localidad>(rand()% N_LOCALIDADES);

    return c;
}


/*-----------------------------------------------------------*/

/*-------------------ABB----------------------------------*/
NodoABB::NodoABB(centro c,
                 NodoABB* izq,
                 NodoABB* der)
{
    datos = c;

    izquierda = izq;

    derecha = der;
}
ABB::ABB()
{
    raiz = NULL;
}

bool ABB::arbolVacio()
{
    return raiz == NULL;
}
void ABB::insertarCentro(centro c)
{
    insertarCentroRec(raiz, c);
}
void ABB::insertarCentroRec(NodoABB* &nodo, centro c)
{
    if(nodo == NULL)
    {
        nodo = new NodoABB(c);
    }
    else if(c.id_centro < nodo->datos.id_centro)
    {
        insertarCentroRec(nodo->izquierda, c);
    }
    else if(c.id_centro > nodo->datos.id_centro)
    {
        insertarCentroRec(nodo->derecha, c);
    }
}
<<<<<<< HEAD
void ABB::mostrarInorden()
{
    mostrarInordenRec(raiz);
}
void ABB::mostrarInordenRec(NodoABB* nodo)
{
    if(nodo != NULL)
    {
        mostrarInordenRec(nodo->izquierda);

        cout << nodo->datos.id_centro << endl;

        mostrarInordenRec(nodo->derecha);
    }
}
NodoABB* ABB::buscarCentro(int id)
{
    return buscarCentroRec(raiz, id);
}
NodoABB* ABB::buscarCentroRec(NodoABB* nodo, int id)
{
    if(nodo == NULL)
    {
        return NULL;
    }

    if(id == nodo->datos.id_centro)
    {
        return nodo;
    }

    if(id < nodo->datos.id_centro)
    {
        return buscarCentroRec(nodo->izquierda, id);
    }

    return buscarCentroRec(nodo->derecha, id);
}
/*-----------------------------------------------------------*/

/*-------------------Listas----------------------------------*/

lista::~lista()
{
    //dtor
}


void lista:: insertarNodo(venta v)
{
    NodoLista* aux;
    aux= new NodoLista(v);
    if(listaVacia())
    {
        cabeza=aux;
        final=aux;
    }
    else
    {
        final->siguiente=aux;
        final=aux;
    }

}

/*void lista::borrarNodo(venta v)
{
    actual = cabeza;
    NodoLista* anterior;
    while((actual->siguiente!=v)&&(actual->siguiente!=NULL))
    {
        anterior=actual;
        actual= actual->siguiente;
    }
    if(actual->siguiente->valor==v)
    {
        if(actual==cabeza)
        {
            cabeza= actual->siguiente;
        }
        else
        {
            anterior->siguiente= actual->siguiente;
            if(actual== final)
            {
                final=anterior;
            };
        }
        actual->siguiente=NULL;
        delete actual;

    }
}*/

bool lista:: listaVacia()
{
    return (cabeza==NULL);
}

void lista::esCabeza()
{
    actual=cabeza;
}
void lista:: esFinal()
{
    actual=final;
}
void lista::esSiguiente()
{
    actual= actual->siguiente;
}
bool lista::esActual()
{
    return (actual!=NULL);
}
venta lista::valorActual()
{
    return actual->valor;
}

void lista::recorrerLista()
{
}
=======
/*-----------------------------------------------------------*/
>>>>>>> 3eaaf0e1e385932712f38cf2a5a55667116d639e
