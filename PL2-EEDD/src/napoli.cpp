#include "napoli.h"

/*---------------------Centros-------------------------------*/

centro crearCentro()
{
    centro c;
    lista ventas;
    c.id_centro= 100+ rand()%900;
    c.localidad= rand()% N_LOCALIDADES;
    c.ventas= ventas;

    return c;
}


/*-----------------------------------------------------------*/

/*-------------------Ventas----------------------------------*/

venta crearVenta()
{
    venta v;

    static int contador = 10000;

    sprintf(v.id_venta, "V%05d", contador);
    contador++;

    v.cod_pizza = static_cast<Codigo>(rand()%8);

    v.categoria = asignarCategoria(v.cod_pizza);

    v.unidades = 1 + rand()%20;

    strcpy(v.fecha_venta, "01-01-2026");

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
/*-----------------------------------------------------------*/

/*-------------------Listas----------------------------------*/

lista::~lista()
{
    //dtor
}
~lista();

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
                final=anterior
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
    return (actual!=NULL;)
}
int lista::valorActual();
void lista::recorrerLista();
