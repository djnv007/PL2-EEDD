#include "napoli.h"
#include <iostream>
#include <iomanip>

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

    int opcion;
    do
    {
        cout << "\n==========================================" << endl;
        cout << "     CONTROL DE VENTAS - PIZZA NAPOLI     " << endl;
        cout << "==========================================" << endl;
        cout << "1) Insertar un centro" << endl;
        cout << "2) Borrar un centro" << endl;
        cout << "3) Mostrar las ventas de un centro" << endl;
        cout << "4) Buscar una venta" << endl;
        cout << "5) Extraer una venta" << endl;
        cout << "6) Trasladar una venta a otro centro" << endl;
        cout << "7) Mostrar estadisticas de los centros" << endl;
        cout << "8) Generar y distribuir nuevas ventas" << endl;
        cout << "0) Salir del programa" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
            {
                int idNuevo;
                cout << "\nIntroduzca el ID del nuevo centro (3 cifras, 100-999): ";
                cin >> idNuevo;

                if (idNuevo < 100 || idNuevo > 999)
                {
                    cout << "Error: El identificador debe ser un numero de 3 cifras." << endl;
                }
                else if (arbol.buscarCentro(idNuevo) != NULL)
                {
                    cout << "Error: Ya existe un centro con el ID " << idNuevo << "." << endl;
                }
                else
                {
                    cout << "Seleccione una localidad:" << endl;
                    for (int i = 0; i < N_LOCALIDADES; ++i)
                    {
                        cout << i << ") " << localidadToString(static_cast<Localidad>(i)) << "  ";
                        if ((i + 1) % 4 == 0) cout << endl;
                    }
                    int codLoc;
                    cout << "Numero de localidad (0-" << N_LOCALIDADES - 1 << "): ";
                    cin >> codLoc;

                    if (codLoc < 0 || codLoc >= N_LOCALIDADES)
                    {
                        cout << "Error: Localidad no valida. Operacion cancelada." << endl;
                    }
                    else
                    {
                        centro nuevo;
                        nuevo.id_centro = idNuevo;
                        nuevo.localidad = static_cast<Localidad>(codLoc);
                        arbol.insertarCentro(nuevo);
                        cout << "Centro " << idNuevo << " ("
                             << localidadToString(nuevo.localidad) << ") insertado correctamente." << endl;
                    }
                }
                break;
            }
            case 3:
            {
                int idConsulta;
                cout << "\nIntroduzca el ID del centro a consultar: ";
                cin >> idConsulta;

                if (!arbol.mostrarVentasCentro(idConsulta))
                {
                    cout << "Error: No existe ningun centro con ID " << idConsulta << "." << endl;
                }
                break;
            }
            case 4:
            {
                char idBuscar[10];
                cout << "\nIntroduzca el ID de la venta a buscar (ej. V10000): ";
                cin >> setw(10) >> idBuscar;

                venta vEncontrada;
                Localidad locCentro;

                if (arbol.buscarVentaGlobal(idBuscar, vEncontrada, locCentro))
                {
                    cout << "\n--- VENTA LOCALIZADA ---" << endl;
                    cout << "ID Venta   : " << vEncontrada.id_venta << endl;
                    cout << "Centro     : " << vEncontrada.id_centro
                         << " (" << localidadToString(locCentro) << ")" << endl;
                    cout << "Pizza      : " << codigoToString(vEncontrada.cod_pizza)
                         << " (" << categoriaToString(vEncontrada.categoria) << ")" << endl;
                    cout << "Unidades   : " << vEncontrada.unidades << endl;
                    cout << "Fecha      : " << vEncontrada.fecha_venta << endl;
                }
                else
                {
                    cout << "No se ha encontrado ninguna venta con el ID " << idBuscar << "." << endl;
                }
                break;
            }

            case 0:
                cout << "\nLiberando memoria y saliendo del programa..." << endl;
                break;
            default:
                cout << "\nOpcion no implementada aun o no valida." << endl;
                break;
        }
    } while (opcion != 0);

    return 0;
}
