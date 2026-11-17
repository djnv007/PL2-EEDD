#ifndef NAPOLI_H
#define NAPOLI_H
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#define N_CENTROS 10
#define N_VENTAS 30
#define N_LOCALIDADES 20

using namespace std;

<<<<<<< HEAD


=======
>>>>>>> 3eaaf0e1e385932712f38cf2a5a55667116d639e

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

venta crearVenta(int id_centro_destino);
Categoria asignarCategoria(Codigo c);
<<<<<<< HEAD
void generarFechaAleatoria(char fecha[]);
const char* codigoToString(Codigo c);
const char* categoriaToString(Categoria cat);


=======
/*-----------------------------------------------------------*/
>>>>>>> 3eaaf0e1e385932712f38cf2a5a55667116d639e

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
    lista()
{
    cabeza = NULL;
    final = NULL;
    actual = NULL;
}

    ~lista();

    void insertarNodo(venta v);


    bool listaVacia();
    void esCabeza();
    void esFinal();
    void esSiguiente();
    bool esActual();
    void vaciar();
    venta valorActual();
    void recorrerLista();
};
/*---------------------Centros-------------------------------*/

enum Localidad {Mostoles, Alcala, Leganes, Fuenlabrada, Getafe, Alcorcon, Torrejon, Parla,
Alcobendas, Coslada, Pozuelo, Rivas, Valdemoro, Majadahonda, Aranjuez, Arganda,
Boadilla, Pinto, Colmenar, TresCantos};

struct centro{
    int id_centro;
    Localidad localidad;
    lista ventas;
};

centro crearCentro(Localidad loc);
const char* localidadToString(Localidad l);
/*-------------------ABB----------------------------------*/
class NodoABB
{
private:
    centro datos;
    NodoABB* izquierda;
    NodoABB* derecha;
    friend class ABB;

public:
    NodoABB(const centro& c, NodoABB* izq = NULL, NodoABB* der = NULL);
};

class ABB
{
private:
    NodoABB* raiz;

    void insertarCentroRec(NodoABB* &nodo, const centro& c);
    void mostrarInordenRec(NodoABB* nodo);
    NodoABB* buscarCentroRec(NodoABB* nodo, int id);
    void obtenerIdsRec(NodoABB* nodo, int ids[], int& indice);
    void destruirArbolRec(NodoABB* &nodo);

public:
    ABB();
    ~ABB();

    bool arbolVacio();
    void insertarCentro(const centro& c);
    NodoABB* buscarCentro(int id);
    void mostrarInorden();
    void obtenerIds(int ids[], int& total);
};

/*-----------------------------------------------------------*/

/*---------------------Centros-------------------------------*/

enum Localidad {Mostoles, Alcala, Leganes, Fuenlabrada, Getafe, Alcorcon, Torrejon, Parla,
                Alcobendas, Coslada, Pozuelo, Rivas, Valdemoro, Majadahonda, Aranjuez, Arganda,
                Boadilla, Pinto, Colmenar, TresCantos};

struct centro{
    int id_centro;
    Localidad localidad;
    lista ventas;
};

centro crearCentro();


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
    void insertarCentroRec(NodoABB* &nodo, centro c);
    void mostrarInordenRec(NodoABB* nodo);

public:
    ABB();

    bool arbolVacio();

    void insertarCentro(centro c);

    NodoABB* buscarCentro(int id);

    void mostrarInorden();
};
/*-----------------------------------------------------------*/

#endif // NAPOLI_H
