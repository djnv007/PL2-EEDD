#include<napoli.h>
<<<<<<< HEAD
#include <iostream>
=======
#include<iostream>
>>>>>>> 3eaaf0e1e385932712f38cf2a5a55667116d639e
using namespace std;

int main()
{
    ABB arbol;
    cout << "Hello world!" << endl;
    cout << "Cargando los datos iniciales del programa ..." << endl;
    cout<< "Creando el ABB con 10 centros:\n";
    cout<<"Arbol inicial:"<<endl;
    for(int i=0; i<N_CENTROS; ++i)
{
    centro c;

    c = crearCentro();

    arbol.insertarCentro(c);
}
cout << "\nARBOL EN INORDEN\n";

arbol.mostrarInorden();
    cout <<"\n Ventas Nuevas:\n";
    for(int i=0; i<N_VENTAS; ++i){
        venta v;
        v= crearVenta();
    }

    return 0;
}
