#include "View.h"

int main()
{
    View menu;
    menu.tipoDeSalida();
    bool archivosParametrizados = menu.mostrarPantallaBienvenido();
    if (archivosParametrizados)
    {
        menu.mostrarDatosExtra();
        menu.buscarPorPalabraClaveYFormacion();
    }
    menu.salir();
    return 0;
}