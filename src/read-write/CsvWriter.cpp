//
// Created by Samuel Bonilla on 20/10/2024.
//


#include "CsvWriter.h"

bool CsvWriter::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas)
{
    // Este bool nos ayudará a saber si se creo exitosamente el archivo
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "resultados.csv";
    ofstream archivoResultados(rutaCompleta);
    if (archivoResultados.is_open())
    {
        // Imprimimos en el archivo las etiquetas (Primera fila)
        for (int i = 0; i < etiquetasColumnas.size(); i++)
        {
            archivoResultados << etiquetasColumnas[i] << Settings::DELIMITADOR;
        }
        archivoResultados << "GRADUADOS" << Settings::DELIMITADOR <<"INSCRITOS" << Settings::DELIMITADOR <<"MATRICULADOS" << Settings::DELIMITADOR << "NEOS" << endl;

        map<int, ProgramaAcademico *>::iterator it;
        // Leemos todos los programas del mapa para imprimirlos en el archivo
        for (it = mapadeProgramasAcademicos.begin(); it != mapadeProgramasAcademicos.end(); it++)
        {
            // Imprimimos cada uno de los 8 consolidados por programa
            for (int i = 0; i < 8; i++)
            {
                // Imprimimos toda la información base del programa academico
                archivoResultados << (it->second)->getCodigoDeLaInstitucion() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getIesPadre() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getInstitucionDeEducacionSuperiorIes() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getPrincipalOSeccional() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getIdSectorIes() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getSectorIes() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getIdCaracter() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getCaracterIes() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getCodigoDelDepartamentoIes() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getDepartamentoDeDomicilioDeLaIes() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getCodigoDelMunicipioIes() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getMunicipioDeDomicilioDeLaIes() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getCodigoSniesDelPrograma() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getProgramaAcademico() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getIdNivelAcademico() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getNivelAcademico() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getIdNivelDeFormacion() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getNivelDeFormacion() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getIdMetodologia() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getMetodologia() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getIdArea() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getAreaDeConocimiento() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getIdNucleo() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getNucleoBasicoDelConocimientoNbc() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getIdCineCampoAmplio() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getDescCineCampoAmplio() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getIdCineCampoEspecifico() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getDescCineCampoEspecifico() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getIdCineCodigoDetallado() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getDescCineCodigoDetallado() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getCodigoDelDepartamentoPrograma() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getDepartamentoDeOfertaDelPrograma() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getCodigoDelMunicipioPrograma() << Settings::DELIMITADOR;
                archivoResultados << (it->second)->getMunicipioDeOfertaDelPrograma() << Settings::DELIMITADOR;

                // Imprimimos la información del consolidado: (ID SEXO;SEXO;AÑO;SEMESTRE;ADMITIDOS;GRADUADOS;INSCRITOS;MATRICULADOS;NEOS)
                Consolidado *consolidadoActual = (it->second)->getConsolidado(i);
                archivoResultados << consolidadoActual->getIdSexo() << Settings::DELIMITADOR;
                archivoResultados << consolidadoActual->getSexo() << Settings::DELIMITADOR;
                archivoResultados << consolidadoActual->getAno() << Settings::DELIMITADOR;
                archivoResultados << consolidadoActual->getSemestre() << Settings::DELIMITADOR;
                archivoResultados << consolidadoActual->getAdmitidos() << Settings::DELIMITADOR;
                archivoResultados << consolidadoActual->getGraduados() << Settings::DELIMITADOR;
                archivoResultados << consolidadoActual->getInscritos() << Settings::DELIMITADOR;
                archivoResultados << consolidadoActual->getMatriculados() << Settings::DELIMITADOR;
                archivoResultados << consolidadoActual->getMatriculadosPrimerSemestre();
                // Saltamos de linea para la siguiente fila
                archivoResultados << endl;
            }
        }

        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        estadoCreacion = true;
        // Imprimimos ruta donde quedo el archivo
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoResultados.close();
    return estadoCreacion;
}

bool CsvWriter::crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas)
{
    // Este bool nos ayudará a saber si se creo exitosamente el archivo
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "buscados.csv";
    ofstream archivoBuscados(rutaCompleta);
    if (archivoBuscados.is_open())
    {

        // Imprimimos en el archivo las etiquetas (Primera fila)
        for (int i = 0; i < etiquetasColumnas.size(); i++)
        {
            archivoBuscados << etiquetasColumnas[i] << Settings::DELIMITADOR;
        }
        archivoBuscados << "GRADUADOS" << Settings::DELIMITADOR << "INSCRITOS" << Settings::DELIMITADOR << "MATRICULADOS" << Settings::DELIMITADOR << "NEOS" << Settings::DELIMITADOR << endl;

        list<ProgramaAcademico *>::iterator it;
        // Leemos todos los programas de la lista de los programas buscados para imprimirlos
        for (it = programasBuscados.begin(); it != programasBuscados.end(); it++)
        {
            // Imprimimos los 8 consolidados del programa
            for (int i = 0; i < 8; i++)
            {
                // Imprimimos la informacion base del programa
                archivoBuscados << (*it)->getCodigoDeLaInstitucion() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getIesPadre() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getInstitucionDeEducacionSuperiorIes() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getPrincipalOSeccional() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getIdSectorIes() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getSectorIes() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getIdCaracter() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getCaracterIes() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getCodigoDelDepartamentoIes() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getDepartamentoDeDomicilioDeLaIes() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getCodigoDelMunicipioIes() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getMunicipioDeDomicilioDeLaIes() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getCodigoSniesDelPrograma() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getProgramaAcademico() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getIdNivelAcademico() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getNivelAcademico() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getIdNivelDeFormacion() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getNivelDeFormacion() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getIdMetodologia() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getMetodologia() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getIdArea() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getAreaDeConocimiento() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getIdNucleo() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getNucleoBasicoDelConocimientoNbc() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getIdCineCampoAmplio() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getDescCineCampoAmplio() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getIdCineCampoEspecifico() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getDescCineCampoEspecifico() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getIdCineCodigoDetallado() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getDescCineCodigoDetallado() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getCodigoDelDepartamentoPrograma() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getDepartamentoDeOfertaDelPrograma() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getCodigoDelMunicipioPrograma() << Settings::DELIMITADOR;
                archivoBuscados << (*it)->getMunicipioDeOfertaDelPrograma() << Settings::DELIMITADOR;

                // Imprimimos la información del consolidado: (ID SEXO;SEXO;AÑO;SEMESTRE;ADMITIDOS;GRADUADOS;INSCRITOS;MATRICULADOS;NEOS)
                Consolidado *consolidadoActual = (*it)->getConsolidado(i);
                archivoBuscados << consolidadoActual->getIdSexo() << Settings::DELIMITADOR;
                archivoBuscados << consolidadoActual->getSexo() << Settings::DELIMITADOR;
                archivoBuscados << consolidadoActual->getAno() << Settings::DELIMITADOR;
                archivoBuscados << consolidadoActual->getSemestre() << Settings::DELIMITADOR;
                archivoBuscados << consolidadoActual->getAdmitidos() << Settings::DELIMITADOR;
                archivoBuscados << consolidadoActual->getGraduados() << Settings::DELIMITADOR;
                archivoBuscados << consolidadoActual->getInscritos() << Settings::DELIMITADOR;
                archivoBuscados << consolidadoActual->getMatriculados() << Settings::DELIMITADOR;
                archivoBuscados << consolidadoActual->getMatriculadosPrimerSemestre();
            
                // Saltamos de linea para la siguiente fila
                archivoBuscados << endl;
            }
        }

        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        estadoCreacion = true;
        // Imprimimos ruta donde quedo el archivo
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoBuscados.close();
    return estadoCreacion;
}

bool CsvWriter::crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir)
{
    // Este bool nos ayudará a saber si se creo el archivo exitosamente
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "extras.csv";
    ofstream archivoExtra(rutaCompleta);
    if (archivoExtra.is_open())
    {
        // Imprimimos la matriz de datos que queremos imprimir
        for (int i = 0; i < datosAImprimir.size(); i++)
        {
            // Imprimimos cada fila
            for (int j = 0; j < datosAImprimir[i].size(); j++)
            {
                // Imprimimos cada dato separado por el delimitador
                archivoExtra << datosAImprimir[i][j];
                if (j != (datosAImprimir[i].size() - 1))
                {
                    archivoExtra << Settings::DELIMITADOR;
                }
            }
            // Saltamos de linea al terminar una fila
            archivoExtra << endl;
        }

        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        estadoCreacion = true;
        // Imprimimos ruta donde quedo el archivo
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoExtra.close();
    return estadoCreacion;
}