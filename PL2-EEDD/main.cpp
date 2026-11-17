#include "napoli.h"
#include <iostream>

using namespace std;

int main()
{
    srand(time(NULL));
    ABB arbol;
    cout << "Cargando los datos iniciales del programa..." << endl;
    cout << "Creando el ABB con " << N_CENTROS << " centros:\n\n";

    bool locUsada[N_LOCALIDADES] = {false};
    int centrosCreados = 0;

    while (centrosCreados < N_CENTROS)
    {
        int idxLoc = rand() % N_LOCALIDADES;
        if (!locUsada[idxLoc])
        {
            centro c = crearCentro(static_cast<Localidad>(idxLoc));
            if (arbol.buscarCentro(c.id_centro) == NULL)
            {
                arbol.insertarCentro(c);
                locUsada[idxLoc] = true;
                centrosCreados++;
            }
        }
    }

    cout << "ARBOL INICIAL EN INORDEN:\n";
    arbol.mostrarInorden();
    int idsDisponibles[100];
    int totalCentros = 0;
    arbol.obtenerIds(idsDisponibles, totalCentros);

    venta loteVentas[N_VENTAS];
    cout << "\nNUEVAS VENTAS GENERADAS (" << N_VENTAS << "):\n";
    for (int i = 0; i < N_VENTAS; ++i)
    {
        int idAleatorio = idsDisponibles[rand() % totalCentros];
        loteVentas[i] = crearVenta(idAleatorio);

        cout << loteVentas[i].id_venta
             << " | Centro: " << loteVentas[i].id_centro
             << " | Pizza: " << codigoToString(loteVentas[i].cod_pizza)
             << " (" << categoriaToString(loteVentas[i].categoria) << ")"
             << " | Uds: " << loteVentas[i].unidades
             << " | Fecha: " << loteVentas[i].fecha_venta << endl;
    }
    cout << "\nPulse ENTER para distribuir las ventas en los centros...";
    cin.get();

    for (int i = 0; i < N_VENTAS; ++i)
    {
        arbol.insertarVentaEnCentro(loteVentas[i].id_centro, loteVentas[i]);
    }

    cout << "\nRESUMEN DEL ARBOL TRAS DISTRIBUIR VENTAS:\n";
    arbol.mostrarInorden();

    return 0;
}
