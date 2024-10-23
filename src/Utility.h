#ifndef UTILITY_H
#define UTILITY_H
#include "ProgramaAcademico.h"
#include "SNIEScontroller.h"

using namespace std;

class Utility
{
public:
    int findPos(const string &busqueda, vector<string> &vec);
    vector<int> buscarPosiciones(vector<string> &);
};

#endif