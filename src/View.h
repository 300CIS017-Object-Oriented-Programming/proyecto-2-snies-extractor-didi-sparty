#ifndef VIEW_H
#define VIEW_H
#include "SNIESController.h"
#include "SNIESController.h"
#include <cctype>
#include <stdexcept>
using namespace std;

class View
{
private:
    SNIESController controlador;

public:
    View();
    ~View();
    bool mostrarPantallaBienvenido();
    void mostrarDatosExtra();
    void buscarPorPalabraClaveYFormacion();
    void salir();
    bool isConvetibleToInt(const string &);
    void tipoDeSalida();
};

#endif