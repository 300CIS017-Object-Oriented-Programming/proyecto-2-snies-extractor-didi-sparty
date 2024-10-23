#include "ProgramaAcademico.h"

using namespace std;

ProgramaAcademico::ProgramaAcademico()
{
    consolidados = vector<Consolidado *>(8);
}

ProgramaAcademico::ProgramaAcademico(vector<vector<string>>& datos, vector<string>& headers)
{
    setCodigoDeLaInstitucion(stoi(datos[0][findPos("CÓDIGO DE LA INSTITUCIÓN", headers)]));          // CÓDIGO DE LA INSTITUCIÓN
    setIesPadre(stoi(datos[0][findPos("IES_PADRE", headers)]));                                      // IES_PADRE
    setInstitucionDeEducacionSuperiorIes(datos[0][findPos("INSTITUCIÓN DE EDUCACIÓN SUPERIOR (IES)", headers)]); // INSTITUCIÓN DE EDUCACIÓN SUPERIOR (IES)
    setPrincipalOSeccional(datos[0][findPos("PRINCIPAL O SECCIONAL", headers)]);                                 // PRINCIPAL O SECCIONAL
    setIdSectorIes(stoi(datos[0][findPos("ID SECTOR IES", headers)]));                                           // ID SECTOR IES
    setSectorIes(datos[0][findPos("SECTOR IES", headers)]);                                                      // SECTOR IES
    setIdCaracter(stoi(datos[0][findPos("ID CARÁCTER", headers)]));                                              // ID CARÁCTER
    setCaracterIes(datos[0][findPos("CARACTER IES", headers)]);                                                  // CARACTER IES
    setCodigoDelDepartamentoIes(stoi(datos[0][findPos("CÓDIGO DEL DEPARTAMENTO (IES)", headers)]));              // CÓDIGO DEL DEPARTAMENTO (IES)
    setDepartamentoDeDomicilioDeLaIes(datos[0][findPos("DEPARTAMENTO DE DOMICILIO DE LA IES", headers)]);        // DEPARTAMENTO DE DOMICILIO DE LA IES
    setCodigoDelMunicipioIes(stoi(datos[0][findPos("CÓDIGO DEL MUNICIPIO IES", headers)]));                      // CÓDIGO DEL MUNICIPIO IES
    setMunicipioDeDomicilioDeLaIes(datos[0][findPos("MUNICIPIO DE DOMICILIO DE LA IES", headers)]);              // MUNICIPIO DE DOMICILIO DE LA IES
    setCodigoSniesDelPrograma(stoi(datos[0][findPos("CÓDIGO SNIES DEL PROGRAMA", headers)]));                    // CÓDIGO SNIES DEL PROGRAMA
    setProgramaAcademico(datos[0][findPos("PROGRAMA ACADÉMICO", headers)]);                                      // PROGRAMA ACADÉMICO
    setIdNivelAcademico(stoi(datos[0][findPos("ID NIVEL ACADÉMICO", headers)]));                                 // ID NIVEL ACADÉMICO
    setNivelAcademico(datos[0][findPos("NIVEL ACADÉMICO", headers)]);                                            // NIVEL ACADÉMICO
    setIdNivelDeFormacion(stoi(datos[0][findPos("ID NIVEL DE FORMACIÓN", headers)]));                            // ID NIVEL DE FORMACIÓN
    setNivelDeFormacion(datos[0][findPos("NIVEL DE FORMACIÓN", headers)]);                                       // NIVEL DE FORMACIÓN
    setIdMetodologia(stoi(datos[0][findPos("ID METODOLOGÍA", headers)]));                                        // ID METODOLOGÍA
    setMetodologia(datos[0][findPos("METODOLOGÍA", headers)]);                                                   // METODOLOGÍA
    setIdArea(stoi(datos[0][findPos("ID ÁREA", headers)]));                                                      // ID ÁREA
    setAreaDeConocimiento(datos[0][findPos("ÁREA DE CONOCIMIENTO", headers)]);                                   // ÁREA DE CONOCIMIENTO
    setIdNucleo(stoi(datos[0][findPos("ID NÚCLEO", headers)]));                                                  // ID NÚCLEO
    setNucleoBasicoDelConocimientoNbc(datos[0][findPos(" NÚCLEO BÁSICO DEL CONOCIMIENTO (NBC)", headers)]);      // NÚCLEO BÁSICO DEL CONOCIMIENTO (NBC)
    setIdCineCampoAmplio(stoi(datos[0][findPos("ID CINE CAMPO AMPLIO", headers)]));                              // ID CINE CAMPO AMPLIO
    setDescCineCampoAmplio(datos[0][findPos("DESC CINE CAMPO AMPLIO", headers)]);                                // DESC CINE CAMPO AMPLIO
    setIdCineCampoEspecifico(stoi(datos[0][findPos("ID CINE CAMPO ESPECÍFICO", headers)]));                      // ID CINE CAMPO ESPECÍFICO
    setDescCineCampoEspecifico(datos[0][findPos("DESC CINE CAMPO ESPECÍFICO", headers)]);                        // DESC CINE CAMPO ESPECÍFICO
    setIdCineCodigoDetallado(stoi(datos[0][findPos("ID CINE CÓDIGO DETALLADO", headers)]));                      // ID CINE CÓDIGO DETALLADO
    setDescCineCodigoDetallado(datos[0][findPos("DESC CINE CÓDIGO DETALLADO", headers)]);                        // DESC CINE CÓDIGO DETALLADO
    setCodigoDelDepartamentoPrograma(stoi(datos[0][findPos("CÓDIGO DEL DEPARTAMENTO (PROGRAMA)", headers)]));    // CÓDIGO DEL DEPARTAMENTO (PROGRAMA)
    setDepartamentoDeOfertaDelPrograma(datos[0][findPos("DEPARTAMENTO DE OFERTA DEL PROGRAMA", headers)]);       // DEPARTAMENTO DE OFERTA DEL PROGRAMA
    setCodigoDelMunicipioPrograma(stoi(datos[0][findPos("CÓDIGO DEL MUNICIPIO (PROGRAMA)", headers)]));          // CÓDIGO DEL MUNICIPIO (PROGRAMA)
    setMunicipioDeOfertaDelPrograma(datos[0][findPos("MUNICIPIO DE OFERTA DEL PROGRAMA", headers)]);             // MUNICIPIO DE OFERTA DEL PROGRAMA
}

    void ProgramaAcademico::setCodigoDeLaInstitucion(int nuevoCodigoDeLaInstitucion)
{
    codigoDeLaInstitucion = nuevoCodigoDeLaInstitucion;
}

int ProgramaAcademico::getCodigoDeLaInstitucion()
{
    return codigoDeLaInstitucion;
}

void ProgramaAcademico::setIesPadre(int nuevoIesPadre)
{
    iesPadre = nuevoIesPadre;
}

int ProgramaAcademico::getIesPadre()
{
    return iesPadre;
}

void ProgramaAcademico::setInstitucionDeEducacionSuperiorIes(string &nuevoInstitucionDeEducacionSuperiorIes)
{
    institucionDeEducacionSuperiorIes = nuevoInstitucionDeEducacionSuperiorIes;
}
string ProgramaAcademico::getInstitucionDeEducacionSuperiorIes()
{
    return institucionDeEducacionSuperiorIes;
}

void ProgramaAcademico::setPrincipalOSeccional(string &nuevoPrincipalOSeccional)
{
    principalOSeccional = nuevoPrincipalOSeccional;
}

string ProgramaAcademico::getPrincipalOSeccional()
{
    return principalOSeccional;
}

void ProgramaAcademico::setIdSectorIes(int nuevoIdSectorIes)
{
    idSectorIes = nuevoIdSectorIes;
}

int ProgramaAcademico::getIdSectorIes()
{
    return idSectorIes;
}

void ProgramaAcademico::setSectorIes(string &nuevoSectorIes)
{
    sectorIes = nuevoSectorIes;
}

string ProgramaAcademico::getSectorIes()
{
    return sectorIes;
}

void ProgramaAcademico::setIdCaracter(int nuevoIdCaracter)
{
    idCaracter = nuevoIdCaracter;
}

int ProgramaAcademico::getIdCaracter()
{
    return idCaracter;
}

void ProgramaAcademico::setCaracterIes(string &nuevoCaracterIes)
{
    caracterIes = nuevoCaracterIes;
}

string ProgramaAcademico::getCaracterIes()
{
    return caracterIes;
}

void ProgramaAcademico::setCodigoDelDepartamentoIes(int nuevoCodigoDelDepartamentoIes)
{
    codigoDelDepartamentoIes = nuevoCodigoDelDepartamentoIes;
}

int ProgramaAcademico::getCodigoDelDepartamentoIes()
{
    return codigoDelDepartamentoIes;
}

void ProgramaAcademico::setDepartamentoDeDomicilioDeLaIes(string &nuevoDepartamentoDeDomicilioDeLaIes)
{
    departamentoDeDomicilioDeLaIes = nuevoDepartamentoDeDomicilioDeLaIes;
}

string ProgramaAcademico::getDepartamentoDeDomicilioDeLaIes()
{
    return departamentoDeDomicilioDeLaIes;
}

void ProgramaAcademico::setCodigoDelMunicipioIes(int nuevoCodigoDelMunicipioIes)
{
    codigoDelMunicipioIes = nuevoCodigoDelMunicipioIes;
}

int ProgramaAcademico::getCodigoDelMunicipioIes()
{
    return codigoDelMunicipioIes;
}

void ProgramaAcademico::setMunicipioDeDomicilioDeLaIes(string &nuevoMunicipioDeDomicilioDeLaIes)
{
    municipioDeDomicilioDeLaIes = nuevoMunicipioDeDomicilioDeLaIes;
}

string ProgramaAcademico::getMunicipioDeDomicilioDeLaIes()
{
    return municipioDeDomicilioDeLaIes;
}

void ProgramaAcademico::setCodigoSniesDelPrograma(int nuevoCodigoSniesDelPrograma)
{
    codigoSniesDelPrograma = nuevoCodigoSniesDelPrograma;
}

int ProgramaAcademico::getCodigoSniesDelPrograma()
{
    return codigoSniesDelPrograma;
}

void ProgramaAcademico::setProgramaAcademico(string &nuevoProgramaAcademico)
{
    programaAcademico = nuevoProgramaAcademico;
}

string ProgramaAcademico::getProgramaAcademico()
{
    return programaAcademico;
}

void ProgramaAcademico::setIdNivelAcademico(int nuevoIdNivelAcademico)
{
    idNivelAcademico = nuevoIdNivelAcademico;
}

int ProgramaAcademico::getIdNivelAcademico()
{
    return idNivelAcademico;
}

void ProgramaAcademico::setNivelAcademico(string &nuevoNivelAcademico)
{
    nivelAcademico = nuevoNivelAcademico;
}

string ProgramaAcademico::getNivelAcademico()
{
    return nivelAcademico;
}

void ProgramaAcademico::setIdNivelDeFormacion(int nuevoIdNivelDeFormacion)
{
    idNivelDeFormacion = nuevoIdNivelDeFormacion;
}

int ProgramaAcademico::getIdNivelDeFormacion()
{
    return idNivelDeFormacion;
}

void ProgramaAcademico::setNivelDeFormacion(string &nuevoNivelDeFormacion)
{
    nivelDeFormacion = nuevoNivelDeFormacion;
}

string ProgramaAcademico::getNivelDeFormacion()
{
    return nivelDeFormacion;
}

void ProgramaAcademico::setIdMetodologia(int nuevoIdMetodologia)
{
    idMetodologia = nuevoIdMetodologia;
}

int ProgramaAcademico::getIdMetodologia()
{
    return idMetodologia;
}

void ProgramaAcademico::setMetodologia(string &nuevaMetodologia)
{
    metodologia = nuevaMetodologia;
}

string ProgramaAcademico::getMetodologia()
{
    return metodologia;
}

void ProgramaAcademico::setIdArea(int nuevoIdArea)
{
    idArea = nuevoIdArea;
}

int ProgramaAcademico::getIdArea()
{
    return idArea;
}

void ProgramaAcademico::setAreaDeConocimiento(string &areaConocimiento)
{
    areaDeConocimiento = areaConocimiento;
}
string ProgramaAcademico::getAreaDeConocimiento()
{
    return areaDeConocimiento;
}

void ProgramaAcademico::setIdNucleo(int nuevoIdNucleo)
{
    idNucleo = nuevoIdNucleo;
}
int ProgramaAcademico::getIdNucleo()
{
    return idNucleo;
}

void ProgramaAcademico::setNucleoBasicoDelConocimientoNbc(string &nuevoNucleoBasicoDelConocimientoNbc)
{
    nucleoBasicoDelConocimientoNbc = nuevoNucleoBasicoDelConocimientoNbc;
}
string ProgramaAcademico::getNucleoBasicoDelConocimientoNbc()
{
    return nucleoBasicoDelConocimientoNbc;
}

void ProgramaAcademico::setIdCineCampoAmplio(int nuevoIdCineCampoAmplio)
{
    idCineCampoAmplio = nuevoIdCineCampoAmplio;
}
int ProgramaAcademico::getIdCineCampoAmplio()
{
    return idCineCampoAmplio;
}

void ProgramaAcademico::setDescCineCampoAmplio(string &nuevoDescCineCampoAmplio)
{
    descCineCampoAmplio = nuevoDescCineCampoAmplio;
}
string ProgramaAcademico::getDescCineCampoAmplio()
{
    return descCineCampoAmplio;
}

void ProgramaAcademico::setIdCineCampoEspecifico(int nuevoIdCineCampoEspecifico)
{
    idCineCampoEspecifico = nuevoIdCineCampoEspecifico;
}
int ProgramaAcademico::getIdCineCampoEspecifico()
{
    return idCineCampoEspecifico;
}

void ProgramaAcademico::setDescCineCampoEspecifico(string &nuevoDescCineCampoEspecifico)
{
    descCineCampoEspecifico = nuevoDescCineCampoEspecifico;
}

string ProgramaAcademico::getDescCineCampoEspecifico()
{
    return descCineCampoEspecifico;
}

void ProgramaAcademico::setIdCineCodigoDetallado(int nuevoIdCineCodigoDetallado)
{
    idCineCodigoDetallado = nuevoIdCineCodigoDetallado;
}
int ProgramaAcademico::getIdCineCodigoDetallado()
{
    return idCineCodigoDetallado;
}

void ProgramaAcademico::setDescCineCodigoDetallado(string &nuevoDescCineCodigoDetallado)
{
    descCineCodigoDetallado = nuevoDescCineCodigoDetallado;
}
string ProgramaAcademico::getDescCineCodigoDetallado()
{
    return descCineCodigoDetallado;
}

void ProgramaAcademico::setCodigoDelDepartamentoPrograma(int nuevoCodigoDelDepartamentoPrograma)
{
    codigoDelDepartamentoPrograma = nuevoCodigoDelDepartamentoPrograma;
}
int ProgramaAcademico::getCodigoDelDepartamentoPrograma()
{
    return codigoDelDepartamentoPrograma;
}

void ProgramaAcademico::setDepartamentoDeOfertaDelPrograma(string &nuevoDepartamentoDeOfertaDelPrograma)
{
    departamentoDeOfertaDelPrograma = nuevoDepartamentoDeOfertaDelPrograma;
}
string ProgramaAcademico::getDepartamentoDeOfertaDelPrograma()
{
    return departamentoDeOfertaDelPrograma;
}

void ProgramaAcademico::setCodigoDelMunicipioPrograma(int nuevoCodigoDelMunicipioPrograma)
{
    codigoDelMunicipioPrograma = nuevoCodigoDelMunicipioPrograma;
}
int ProgramaAcademico::getCodigoDelMunicipioPrograma()
{
    return codigoDelMunicipioPrograma;
}

void ProgramaAcademico::setMunicipioDeOfertaDelPrograma(string &nuevoMunicipioDeOfertaDelPrograma)
{
    municipioDeOfertaDelPrograma = nuevoMunicipioDeOfertaDelPrograma;
}
string ProgramaAcademico::getMunicipioDeOfertaDelPrograma()
{
    return municipioDeOfertaDelPrograma;
}

void ProgramaAcademico::setConsolidado(Consolidado *nuevoConsolidado, int pos)
{
    consolidados[pos] = nuevoConsolidado;
}

Consolidado *ProgramaAcademico::getConsolidado(int posicionConsolidado)
{
    return consolidados[posicionConsolidado];
}

ProgramaAcademico::~ProgramaAcademico()
{
    for (Consolidado *consolidado : consolidados)
    {
        delete consolidado;
    }
}

int ProgramaAcademico::findPos(const string &busqueda, vector<string> &vec)
{ //  Devuelve la posición del vector
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

    return out;  // devuelve el indice numérico
}