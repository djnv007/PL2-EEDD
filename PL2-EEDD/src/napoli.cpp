#include "napoli.h"
#include <cstdio>
#include <iostream>

using namespace std;

/*---------------------Auxiliares Texto----------------------*/
const char* localidadToString(Localidad l) {
    const char* nombres[N_LOCALIDADES] = {
        "MOSTOLES", "ALCALA", "LEGANES", "FUENLABRADA", "GETAFE",
        "ALCORCON", "TORREJON", "PARLA", "ALCOBENDAS", "COSLADA",
        "POZUELO", "RIVAS", "VALDEMORO", "MAJADAHONDA", "ARANJUEZ",
        "ARGANDA", "BOADILLA", "PINTO", "COLMENAR", "TRES CANTOS"
    };
    if (l >= 0 && l < N_LOCALIDADES) return nombres[l];
    return "DESCONOCIDA";
}

const char* codigoToString(Codigo c) {
    const char* codigos[8] = {"NP01", "NP02", "NP03", "NP04", "NP05", "NP06", "NP07", "NP08"};
    if (c >= 0 && c < 8) return codigos[c];
    return "NP00";
}

const char* categoriaToString(Categoria cat) {
    const char* cats[4] = {"Tradicional", "Carne", "Verduras", "Quesos"};
    if (cat >= 0 && cat < 4) return cats[cat];
    return "Desconocida";
}

/*---------------------Centros-------------------------------*/
centro crearCentro(Localidad loc) {
    centro c;
    c.id_centro = 100 + rand() % 900;
    c.localidad = loc;
    return c;
}

/*-------------------Ventas----------------------------------*/
void generarFechaAleatoria(char fecha[]) {
    int diasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int mes = 1 + rand() % 12;
    int dia = 1 + rand() % diasMes[mes - 1];
    sprintf(fecha, "%02d-%02d-2026", dia, mes);
}

venta crearVenta(int id_centro_destino) {
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

Categoria asignarCategoria(Codigo c) {
    if (c == NP01 || c == NP02) return Tradicional;
    if (c == NP03 || c == NP04) return Carne;
    if (c == NP05 || c == NP06) return Verduras;
    return Quesos;
}

/*-------------------ABB-------------------------------------*/
NodoABB::NodoABB(const centro& c, NodoABB* izq, NodoABB* der) {
    datos = c;
    izquierda = izq;
    derecha = der;
}

ABB::ABB() {
    raiz = NULL;
}

ABB::~ABB() {
    destruirArbolRec(raiz);
}

void ABB::destruirArbolRec(NodoABB* &nodo) {
    if (nodo != NULL) {
        destruirArbolRec(nodo->izquierda);
        destruirArbolRec(nodo->derecha);
        nodo->datos.ventas.vaciar();
        delete nodo;
        nodo = NULL;
    }
}

bool ABB::arbolVacio() {
    return raiz == NULL;
}

void ABB::insertarCentro(const centro& c) {
    insertarCentroRec(raiz, c);
}

void ABB::insertarCentroRec(NodoABB* &nodo, const centro& c) {
    if (nodo == NULL) {
        nodo = new NodoABB(c);
    } else if (c.id_centro < nodo->datos.id_centro) {
        insertarCentroRec(nodo->izquierda, c);
    } else if (c.id_centro > nodo->datos.id_centro) {
        insertarCentroRec(nodo->derecha, c);
    }
}

void ABB::mostrarInorden() {
    mostrarInordenRec(raiz);
}

void ABB::mostrarInordenRec(NodoABB* nodo)
{
    if (nodo != NULL)
    {
        mostrarInordenRec(nodo->izquierda);
        cout << "Centro " << nodo->datos.id_centro
             << " (" << localidadToString(nodo->datos.localidad) << ")"
             << " -> Ventas: " << nodo->datos.ventas.contarVentas() << endl;
        mostrarInordenRec(nodo->derecha);
    }
}

NodoABB* ABB::buscarCentro(int id) {
    return buscarCentroRec(raiz, id);
}

NodoABB* ABB::buscarCentroRec(NodoABB* nodo, int id) {
    if (nodo == NULL) return NULL;
    if (id == nodo->datos.id_centro) return nodo;
    if (id < nodo->datos.id_centro) return buscarCentroRec(nodo->izquierda, id);
    return buscarCentroRec(nodo->derecha, id);
}

void ABB::obtenerIds(int ids[], int& total) {
    total = 0;
    obtenerIdsRec(raiz, ids, total);
}

void ABB::obtenerIdsRec(NodoABB* nodo, int ids[], int& indice) {
    if (nodo != NULL) {
        obtenerIdsRec(nodo->izquierda, ids, indice);
        ids[indice] = nodo->datos.id_centro;
        indice++;
        obtenerIdsRec(nodo->derecha, ids, indice);
    }
}
bool ABB::insertarVentaEnCentro(int id_centro, venta v)
{
    NodoABB* nodo = buscarCentro(id_centro);
    if (nodo == NULL) return false;
    nodo->datos.ventas.insertarNodo(v);
    return true;
}

void ABB::mostrarResumen()
{
    mostrarInordenRec(raiz);
}
/*-------------------Listas----------------------------------*/
lista::~lista() {
    vaciar();
}

void lista::vaciar() {
    NodoLista* aux;
    while (cabeza != NULL) {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
    final = NULL;
    actual = NULL;
}

void lista::insertarNodo(venta v) {
    NodoLista* aux = new NodoLista(v);
    if (listaVacia()) {
        cabeza = aux;
        final = aux;
    } else {
        final->siguiente = aux;
        final = aux;
    }
}

bool lista::listaVacia() {
    return (cabeza == NULL);
}

void lista::esCabeza() {
    actual = cabeza;
}

void lista::esFinal() {
    actual = final;
}

void lista::esSiguiente() {
    if (actual != NULL) actual = actual->siguiente;
}

bool lista::esActual() {
    return (actual != NULL);
}

venta lista::valorActual() {
    return actual->valor;
}
int lista::contarVentas()
{
    int contador = 0;
    NodoLista* aux = cabeza;
    while (aux != NULL)
    {
        contador++;
        aux = aux->siguiente;
    }
    return contador;
}
