#include<napoli.h>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    cout << "Cargando los datos iniciales del programa ..." << endl;
    cout<< "Creando el ABB con 10 centros:\n";
    cout<<"Arbol inicial:"<<endl;
    for(int i=0; i<N_CENTROS; ++i){
        centro c;
        c= crearCentro();
    }
    cout <<"\n Ventas Nuevas:\n";
    for(int i=0; i<N_VENTAS; ++i){
        venta v;
        v= crearVenta();
    }

    return 0;
}
