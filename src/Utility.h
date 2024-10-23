#ifndef UTILITY_H
#define UTILITY_H
#include "ProgramaAcademico.h"
#include "SNIEScontroller.h"
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


/*
   * input un string y un vector que contenga ese string
   * output si el string no esta en el vector thhow excepcion invalud argument si lo encuentra el indice de donde esta
   */
    int findPos(const string &busqueda, vector<string> &vec);

    vector<int> buscarPosiciones(vector<string> &);
    /*
     * input recibe un mapa un vector con las llaves del mapa de vectores que tambien recibe y una posicion
     * output saca un vector con el elemento de indice pos de los vectores de los mapas con el orden del vector orden
     */
    vector<string> returnFila(map<string, vector<string>> &data, vector<string> &orden, int pos);

#endif