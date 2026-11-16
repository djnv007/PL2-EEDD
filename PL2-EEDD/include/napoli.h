#ifndef NAPOLI_H
#define NAPOLI_H


enum Localidad {Móstoles, Alcalá, Leganés, Fuenlabrada, Getafe, Alcorcón, Torrejón, Parla,
Alcobendas, Coslada, Pozuelo, Rivas, Valdemoro, Majadahonda, Aranjuez, Arganda,
Boadilla, Pinto, Colmenar, Tres Cantos};

struct centro{
    int id_centro;
    Localidad localidad;
    lista ventas;
};


class NodoLista
{
private:
    int valor;
    NodoLista* siguiente;
    friend class lista;

public:
    NodoLista(int v, NodoLista*sig=NULL){
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

    void insertarNodo(int v);
    void borrarNodo(int v);
    bool listaVacia();
    void esCabeza();
    void esFinal();
    void esSiguiente();
    bool esActual();
    int valorActual();
    void recorrerLista();
};


#endif // NAPOLI_H
