#include "napoli.h"



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
void sABB::mostrarInorden()
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
/*-----------------------------------------------------------*/
