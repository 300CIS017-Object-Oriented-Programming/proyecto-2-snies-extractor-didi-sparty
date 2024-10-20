#ifndef VIEW_H
#define VIEW_H
#include "SNIESController.h"
/*Todo el codigo va entre estas guardas*/
#include "SNIESController.h"
#include <cctype>

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
    char obtenerEntradaUsuario(const string &mensaje, const string &opcionesValidas);
    string obtenerAnoValido(const string &mensaje);
    void intercambiarAnos(string &ano1, string &ano2);
};

#endif