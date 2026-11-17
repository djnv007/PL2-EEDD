#ifndef NAPOLI_H
#define NAPOLI_H
#include<cstring>
#include<ctime>
#include<cstdlib>
#define N_CENTROS 10
#define N_VENTAS 30
#define N_LOCALIDADES 20


/*---------------------Centros-------------------------------*/

enum Localidad {Mostoles, Alcala, Leganes, Fuenlabrada, Getafe, Alcorcon, Torrejon, Parla,
Alcobendas, Coslada, Pozuelo, Rivas, Valdemoro, Majadahonda, Aranjuez, Arganda,
Boadilla, Pinto, Colmenar, Tres Cantos};

struct centro{
    int id_centro;
    Localidad localidad;
    lista ventas;
};

centro crearCentro();


/*-----------------------------------------------------------*/

/*-------------------Ventas----------------------------------*/

enum Codigo{NP01,NP02,NP03,NP04,NP05,NP06,NP07,NP08};
enum Categoria{Tradicional,Carne,Verduras,Quesos};

struct venta{
    int id_centro;
    char id_venta[7];
    Codigo cod_pizza;
    Categoria categoria;
    int unidades;
    char fecha_venta[11];
};

venta crearVenta();

Categoria asignarCategoria(Codigo c);
/*-----------------------------------------------------------*/

/*-------------------ABB----------------------------------*/
class NodoABB
{
private:
    centro datos;

    NodoABB* izquierda;
    NodoABB* derecha;

    friend class ABB;

public:
    NodoABB(centro c,
            NodoABB* izq = NULL,
            NodoABB* der = NULL);
};



class ABB
{
private:
    NodoABB* raiz;

public:
    ABB();

    bool arbolVacio();

    void insertarCentro(centro c);

    NodoABB* buscarCentro(int id);
};
/*-----------------------------------------------------------*/

/*-------------------Listas----------------------------------*/

class NodoLista
{
private:
    venta valor;
    NodoLista* siguiente;
    friend class lista;

public:
    NodoLista(venta v, NodoLista*sig=NULL){
        valor=v;
        siguiente=sig;
    }
};

class lista
{
private:
    NodoLista* cabeza;
    NodoLista* final;
    NodoLista* actual;
public:
    lista(){
        NodoLista* cabeza=NULL;
        NodoLista* final=NULL;
        NodoLista* actual=NULL;
    }
    ~lista();

    void insertarNodo(venta v);
    void borrarNodo(venta v);
    bool listaVacia();
    void esCabeza();
    void esFinal();
    void esSiguiente();
    bool esActual();
    bool buscarVenta(venta v);
    venta valorActual();
    void recorrerLista();
};

/*-----------------------------------------------------------*/

#endif // NAPOLI_H
