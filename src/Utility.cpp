#include "Utility.h"

int Utility::findPos(const string &busqueda, vector<string> &vec)
{
    //  Devuelve la posición del vector
    int out = 0;

    vector<string>::iterator found = find(vec.begin(), vec.end(), busqueda);
    if (found == vec.end())
    {
        throw invalid_argument("Columna solicitada como filtro incorrecta");
    }
    else
    {
        out = distance(vec.begin(), found);
    }

    return out; // devuelve el indice numérico
}

vector<int> Utility::buscarPosiciones(vector<string> & headers)
{
    vector<string> palabras = {"SEXO", "AÑO", "SEMESTRE", "ADMITIDOS", "MATRICULADOS", "GRADUADOS", "INSCRITOS", "MATRICULADOS PRIMER SEMESTRE"};
    vector<int> posiciones;

    for (const string &palabra : palabras)
    {
        vector<string>::iterator it = find(headers.begin(), headers.end(), palabra);
        if (it != headers.end())
        {
            int posicion = distance(headers.begin(), it); // encuentro la distancia para hallar la posición
            posiciones.push_back(posicion);               // guardo las posiciones
        }
    }
    return posiciones;
}