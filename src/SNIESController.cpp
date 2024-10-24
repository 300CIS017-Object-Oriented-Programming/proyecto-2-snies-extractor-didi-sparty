#include "SNIESController.h"

using namespace std;

int findRightRow(int columnaUno, int columnaDos, const string &valueColumnaUno, const string &valueColumnaDos, vector<vector<string>> &data)
{

    int out = 0, i = 0;
    for (const auto &fila : data)
    {
        if (fila[columnaUno] == valueColumnaUno && fila[columnaDos] == valueColumnaDos)
        {
            out = i;
        }
        i++;
    }
    return out;
}

SNIESController::SNIESController() = default;

SNIESController::~SNIESController()
{
    for (auto &pair : programasAcademicos)
    {
        ((pair).second)->~ProgramaAcademico();
        delete pair.second;
    }
}

void SNIESController::procesarDatosCsv(string &ano1, string &ano2)
{
    vector<string> codigosSnies = CsvReaderObj.leerProgramasCsv();
    string admitidos = "admitidos" + ano1 + ".csv";
    string graduados = "graduados" + ano1 + ".csv";
    string inscritos = "inscritos" + ano1 + ".csv";
    string matriculados = "matriculados" + ano1 + ".csv";
    string admitidos2 = "admitidos" + ano2 + ".csv";
    string graduados2 = "graduados" + ano2 + ".csv";
    string inscritos2 = "inscritos" + ano2 + ".csv";
    string matriculados2 = "matriculados" + ano2 + ".csv";
    map<string, vector<vector<string>>> mapaAdmitidos = CsvReaderObj.leerArchivo(admitidos, codigosSnies);
    map<string, vector<vector<string>>> mapaGraduados = CsvReaderObj.leerArchivo(graduados, codigosSnies);
    map<string, vector<vector<string>>> mapaInscritos = CsvReaderObj.leerArchivo(inscritos, codigosSnies);
    map<string, vector<vector<string>>> mapaMatriculados = CsvReaderObj.leerArchivo(matriculados, codigosSnies);
    map<string, vector<vector<string>>> mapaAdmitidos2 = CsvReaderObj.leerArchivo(admitidos2, codigosSnies);
    map<string, vector<vector<string>>> mapaGraduados2 = CsvReaderObj.leerArchivo(graduados2, codigosSnies);
    map<string, vector<vector<string>>> mapaInscritos2 = CsvReaderObj.leerArchivo(inscritos2, codigosSnies);
    map<string, vector<vector<string>>> mapaMatriculados2 = CsvReaderObj.leerArchivo(matriculados2, codigosSnies);
    vector<ProgramaAcademico> programasAcademicos;

    for (const auto &codigo : codigosSnies){
        programasAcademicos.push_back(ProgramaAcademico(mapaAdmitidos[codigo], mapaAdmitidos["HEAD"][0]));
        vector<Consolidado *> consolidados;
        int posColSemestre = findPos("SEMESTRE", mapaAdmitidos["HEAD"][0]), posColSexo = findPos( "ID SEXO", mapaAdmitidos["HEAD"][0]);
        int HombrePrimerSemestre = findRightRow(posColSemestre, posColSexo, "1", "1", mapaAdmitidos[codigo]), MujerPrimerSemestre = findRightRow(posColSemestre, posColSexo, '1', '2') int HombreSegundoSemestre = findRightRow(posColSemestre, posColSexo, '2', '1'), MujerSegundoSemestre = findRightRow(posColSemestre, posColSexo, '2', '2');
        Consolidado* HombresPrimerSemestreConsolidadoAno1 = new Consolidado(
            1, "Hombre", stoi(ano1), 1, stoi(mapaInscritos[codigo][HombrePrimerSemestre][findPos("INSCRITOS", mapaInscritos["HEAD"])]),
            stoi(mapaAdmitidos[codigo][HombrePrimerSemestre][findPos("ADMITIDOS", mapaAdmitidos["HEAD"])]), stoi(mapaMatriculados[codigo][HombrePrimerSemestre][findPos("MATRICULADOS", mapaMatriculados["HEAD"])]),
            stoi(mapaMatriculados[codigo][HombrePrimerSemestre][findPos("MATRICULADOS", mapaMatriculados["HEAD"])]), stoi(mapaGraduados[codigo][HombrePrimerSemestre][findPos("GRADUADOS", mapaGraduados["HEAD"])]));

        Consolidado* HombresSegundoSemestreConsolidadoAno1 = new Consolidado(
            1, "Hombre", stoi(ano1), 2, stoi(mapaInscritos2[codigo][HombreSegundoSemestre][findPos("INSCRITOS", mapaInscritos2["HEAD"])]),
            stoi(mapaAdmitidos2[codigo][HombreSegundoSemestre][findPos("ADMITIDOS", mapaAdmitidos2["HEAD"])]), stoi(mapaMatriculados2[codigo][HombreSegundoSemestre][findPos("MATRICULADOS", mapaMatriculados2["HEAD"])]),
            stoi(mapaMatriculados2[codigo][HombreSegundoSemestre][findPos("MATRICULADOS", mapaMatriculados2["HEAD"])]), stoi(mapaGraduados2[codigo][HombreSegundoSemestre][findPos("GRADUADOS", mapaGraduados2["HEAD"])]);
        )

        Consolidado* MujeresPrimerSemestreConsolidadoAno1 = new Consolidado(
            2, "Mujer", stoi(ano1), 1, stoi(mapaInscritos[codigo][MujerPrimerSemestre][findPos("INSCRITOS", mapaInscritos["HEAD"])]),
            stoi(mapaAdmitidos[codigo][MujerPrimerSemestre][findPos("ADMITIDOS", mapaAdmitidos["HEAD"])]), stoi(mapaMatriculados[codigo][MujerPrimerSemestre][findPos("MATRICULADOS", mapaMatriculados["HEAD"])]),
            stoi(mapaMatriculados[codigo][MujerPrimerSemestre][findPos("MATRICULADOS", mapaMatriculados["HEAD"])]), stoi(mapaGraduados[codigo][MujerPrimerSemestre][findPos("GRADUADOS", mapaGraduados["HEAD"])]);
        )

        Consolidado* MujeresSegundoSemestreConsolidadoAno1 = new Consolidado(
            2, "Mujer", stoi(ano1), 2, stoi(mapaInscritos2[codigo][MujerSegundoSemestre][findPos("INSCRITOS", mapaInscritos2["HEAD"])]),
            stoi(mapaAdmitidos2[codigo][MujerSegundoSemestre][findPos("ADMITIDOS", mapaAdmitidos2["HEAD"])]), stoi(mapaMatriculados2[codigo][MujerSegundoSemestre][findPos("MATRICULADOS", mapaMatriculados2["HEAD"])]),
            stoi(mapaMatriculados2[codigo][MujerSegundoSemestre][findPos("MATRICULADOS", mapaMatriculados2["HEAD"])]), stoi(mapaGraduados2[codigo][MujerSegundoSemestre][findPos("GRADUADOS", mapaGraduados2["HEAD"])]);
        )

        Consolidado* HombresPrimerSemestreConsolidadoAno2 = new Consolidado(
            1, "Hombre", stoi(ano2), 1, stoi(mapaInscritos[codigo][HombrePrimerSemestre][findPos("INSCRITOS", mapaInscritos["HEAD"])]),
            stoi(mapaAdmitidos[codigo][HombrePrimerSemestre][findPos("ADMITIDOS", mapaAdmitidos["HEAD"])]), stoi(mapaMatriculados[codigo][HombrePrimerSemestre][findPos("MATRICULADOS", mapaMatriculados["HEAD"])]),
            stoi(mapaMatriculados[codigo][HombrePrimerSemestre][findPos("MATRICULADOS", mapaMatriculados["HEAD"])]), stoi(mapaGraduados[codigo][HombrePrimerSemestre][findPos("GRADUADOS", mapaGraduados["HEAD"])]));

        Consolidado* HombresSegundoSemestreConsolidadoAno2 = new Consolidado(
            1, "Hombre", stoi(ano2), 2, stoi(mapaInscritos2[codigo][HombreSegundoSemestre][findPos("INSCRITOS", mapaInscritos2["HEAD"])]),
            stoi(mapaAdmitidos2[codigo][HombreSegundoSemestre][findPos("ADMITIDOS", mapaAdmitidos2["HEAD"])]), stoi(mapaMatriculados2[codigo][HombreSegundoSemestre][findPos("MATRICULADOS", mapaMatriculados2["HEAD"])]),
            stoi(mapaMatriculados2[codigo][HombreSegundoSemestre][findPos("MATRICULADOS", mapaMatriculados2["HEAD"])]), stoi(mapaGraduados2[codigo][HombreSegundoSemestre][findPos("GRADUADOS", mapaGraduados2["HEAD"])]);
        )

        Consolidado* MujeresPrimerSemestreConsolidadoAno2 = new Consolidado(
            2, "Mujer", stoi(ano2), 1, stoi(mapaInscritos[codigo][MujerPrimerSemestre][findPos("INSCRITOS", mapaInscritos["HEAD"])]),
            stoi(mapaAdmitidos[codigo][MujerPrimerSemestre][findPos("ADMITIDOS", mapaAdmitidos["HEAD"])]), stoi(mapaMatriculados[codigo][MujerPrimerSemestre][findPos("MATRICULADOS", mapaMatriculados["HEAD"])]),
            stoi(mapaMatriculados[codigo][MujerPrimerSemestre][findPos("MATRICULADOS", mapaMatriculados["HEAD"])]), stoi(mapaGraduados[codigo][MujerPrimerSemestre][findPos("GRADUADOS", mapaGraduados["HEAD"])]);
        )

        Consolidado* MujeresSegundoSemestreConsolidadoAno2 = new Consolidado(
            2, "Mujer", stoi(ano2), 2, stoi(mapaInscritos2[codigo][MujerSegundoSemestre][findPos("INSCRITOS", mapaInscritos2["HEAD"])]),
            stoi(mapaAdmitidos2[codigo][MujerSegundoSemestre][findPos("ADMITIDOS", mapaAdmitidos2["HEAD"])]), stoi(mapaMatriculados2[codigo][MujerSegundoSemestre][findPos("MATRICULADOS", mapaMatriculados2["HEAD"])]),
            stoi(mapaMatriculados2[codigo][MujerSegundoSemestre][findPos("MATRICULADOS", mapaMatriculados2["HEAD"])]), stoi(mapaGraduados2[codigo][MujerSegundoSemestre][findPos("GRADUADOS", mapaGraduados2["HEAD"])]);
        )
        consolidados.push_back(HombresPrimerSemestreConsolidadoAno1);
        consolidados.push_back(HombresSegundoSemestreConsolidadoAno1);
        consolidados.push_back(MujeresPrimerSemestreConsolidadoAno1);
        consolidados.push_back(MujeresSegundoSemestreConsolidadoAno1);
        consolidados.push_back(HombresPrimerSemestreConsolidadoAno2);
        consolidados.push_back(HombresSegundoSemestreConsolidadoAno2);
        consolidados.push_back(MujeresPrimerSemestreConsolidadoAno2);
        consolidados.push_back(MujeresSegundoSemestreConsolidadoAno2);
        programasAcademicos.setVecConsolidados(consolidados);
    }
}

void SNIESController::buscarProgramas(bool flag, string &palabraClave, int idComparacion)
{
    list<ProgramaAcademico *> listaProgramas;
    for (map<int, ProgramaAcademico *>::iterator it = programasAcademicos.begin(); it != programasAcademicos.end(); ++it)
    {
        ProgramaAcademico *programa = it->second;
        string nombre = programa->getProgramaAcademico();
        int id = programa->getIdNivelDeFormacion();
        if (nombre.find(palabraClave) != string::npos && id == idComparacion)
        {
            listaProgramas.push_back(programa);
            // codigo SNIES, nombre del programa, codigo de la institucion, nombre de la institucion y metodología
            cout << programa->getCodigoSniesDelPrograma() << ";" << programa->getProgramaAcademico() << ";" << programa->getCodigoDeLaInstitucion() << ";" << programa->getInstitucionDeEducacionSuperiorIes() << ";" << programa->getMetodologia() << endl;
        }
    }

    if (flag)
    {
        bool creado;
        creado = csvWriter.crearArchivoBuscados(rutaOutput, listaProgramas, etiquetasColumnas);
    }
}

void SNIESController::calcularDatosExtra(bool flag)
{
    vector<vector<string>> matrizFinal;
    vector<vector<string>> matrizEtiquetas1;
    vector<vector<string>> matrizEtiquetas2;
    vector<vector<string>> matrizEtiquetas3;
    vector<string> etiquetas1 = {"Suma Estudiantes Matriculados de Programas Seleccionados (Presencial o Virtual) Primer año", "Suma Estudiantes Matriculados de Programas Seleccionados (Presencial o Virtual)"};
    matrizEtiquetas1.push_back(etiquetas1);
    vector<string> etiquetas2 = {"Codigo Snies", "Nombre del Programa", "Nombre del Institucion", "Diferencial porcentual anual de NEOS"};
    matrizEtiquetas2.push_back(etiquetas2);
    vector<string> etiquetas3 = {"Codigo Snies", " Nombre del Programa sin NEOS en los ultimos 3 semestres"};
    matrizEtiquetas3.push_back(etiquetas3);
    vector<string> datosEtiquetas1;
    vector<string> datosEtiquetas2;
    int sumaPrimerAno = 0;
    int sumaSegundoAno = 0;

    for (map<int, ProgramaAcademico *>::iterator it = programasAcademicos.begin(); it != programasAcademicos.end(); ++it)
    {
        int neosPrimerAno = 0;
        int neosSegundoAno = 0;
        int diferenciaNeos = 0;
        ProgramaAcademico *programa = it->second;
        int idMetodologiaBuscada = programa->getIdMetodologia();
        if (idMetodologiaBuscada == 1 || idMetodologiaBuscada == 3)
        {
            for (int i = 0; i < 4; ++i)
            {
                Consolidado *consolidado = programa->getConsolidado(i);
                int matriculados = consolidado->getMatriculados();
                sumaPrimerAno += matriculados;
            }

            for (int i = 0; i < 4; ++i)
            {
                Consolidado *consolidado = programa->getConsolidado(i + 4);
                int matriculados = consolidado->getMatriculados();
                sumaSegundoAno += matriculados;
            }
        }
        for (int i = 0; i < 4; ++i)
        {
            Consolidado *consolidado = programa->getConsolidado(i);
            int numNeos = consolidado->getMatriculadosPrimerSemestre();
            neosPrimerAno += numNeos;
        }

        for (int i = 0; i < 4; ++i)
        {
            Consolidado *consolidado = programa->getConsolidado(i + 4);
            int numNeos = consolidado->getMatriculadosPrimerSemestre();
            neosSegundoAno += numNeos;
        }

        if (neosPrimerAno != 0)
        {
            diferenciaNeos = ((neosSegundoAno - neosPrimerAno) * 100) / neosPrimerAno;
        }
        else
        {
            diferenciaNeos = 0;
        }
        datosEtiquetas2 = {to_string(programa->getCodigoSniesDelPrograma()), programa->getProgramaAcademico(), programa->getInstitucionDeEducacionSuperiorIes(), to_string(diferenciaNeos)};
        matrizEtiquetas2.push_back(datosEtiquetas2);
        int SumaNeosPrimerSemestre;
        int SumaNeosSegundoSemestre;
        int SumaNeosTercerSemestre;
        int SumaNeosCuartoSemestre;
        for (int i = 0; i < 4; ++i)
        {
            Consolidado *consolidados[8];
            if (i == 0)
            {
                consolidados[0] = programa->getConsolidado(i);
                consolidados[1] = programa->getConsolidado(i + 2);
                int neosHombres = consolidados[0]->getMatriculadosPrimerSemestre();
                int neosMujeres = consolidados[1]->getMatriculadosPrimerSemestre();
                SumaNeosPrimerSemestre = neosHombres + neosMujeres;
            }
            else if (i == 1)
            {
                consolidados[2] = programa->getConsolidado(i);
                consolidados[3] = programa->getConsolidado(i + 2);
                int neosHombres = consolidados[2]->getMatriculadosPrimerSemestre();
                int neosMujeres = consolidados[3]->getMatriculadosPrimerSemestre();
                SumaNeosSegundoSemestre = neosHombres + neosMujeres;
            }
            else if (i == 2)
            {
                consolidados[4] = programa->getConsolidado(i + 2);
                consolidados[5] = programa->getConsolidado(i + 4);
                int neosHombres = consolidados[4]->getMatriculadosPrimerSemestre();
                int neosMujeres = consolidados[5]->getMatriculadosPrimerSemestre();
                SumaNeosTercerSemestre = neosHombres + neosMujeres;
            }
            else if (i == 3)
            {
                consolidados[6] = programa->getConsolidado(i + 2);
                consolidados[7] = programa->getConsolidado(i + 4);
                int neosHombres = consolidados[6]->getMatriculadosPrimerSemestre();
                int neosMujeres = consolidados[7]->getMatriculadosPrimerSemestre();
                SumaNeosCuartoSemestre = neosHombres + neosMujeres;
            }
        }

        if ((SumaNeosPrimerSemestre == 0 && SumaNeosSegundoSemestre == 0 && SumaNeosTercerSemestre == 0) || (SumaNeosSegundoSemestre == 0 && SumaNeosTercerSemestre == 0 && SumaNeosCuartoSemestre == 0))
        {
            etiquetas3 = {to_string(programa->getCodigoSniesDelPrograma()),
                          programa->getProgramaAcademico()};
        }
    }
    etiquetas1 = {to_string(sumaPrimerAno), to_string(sumaSegundoAno)};
    matrizEtiquetas1.push_back(etiquetas1);
    matrizFinal.insert(matrizFinal.end(), matrizEtiquetas1.begin(), matrizEtiquetas1.end());
    matrizFinal.insert(matrizFinal.end(), matrizEtiquetas2.begin(), matrizEtiquetas2.end());
    matrizFinal.insert(matrizFinal.end(), matrizEtiquetas3.begin(), matrizEtiquetas3.end());

    for (const auto &fila : matrizFinal)
    {
        for (size_t i = 0; i < fila.size(); ++i)
        {
            cout << fila[i];
            if (i < fila.size() - 1)
            {
                cout << ";";
            }
        }
        cout << endl;
    }

    if (flag)
    {
        bool creado;
        creado = csvWriter.crearArchivoExtra(rutaOutput, matrizFinal);
    }
}

void SNIESController::consolidados(vector<string> &headers, vector<vector<string>> &information)
{
    vector<int> posiciones = buscarPosiciones(headers);

    // Iterar sobre cada fila del vector de vectores information
    for (size_t i = 0; i < information.size(); i++)
    {
        const vector<string> &fila = information[i];
        // Crear un objeto de tipo Consolidado
        Consolidado *consolidado = new Consolidado();
        // Iterar sobre las posiciones de los datos que necesitamos
        for (int i = 0; i < posiciones.size(); ++i)
        {
            // Dependiendo de la posición, asignar el valor correspondiente al objeto consolidado
            switch (posiciones[i])
            {
            case 0:
                consolidado->setIdSexo(stoi(fila[i]));
                break;
            case 1:
                consolidado->setSexo(fila[i]);
                break;
            case 2:
                consolidado->setAno(stoi(fila[i]));
                break;
            case 3:
                consolidado->setSemestre(stoi(fila[i]));
                break;
            case 4:
                consolidado->setAdmitidos(stoi(fila[i]));
                break;
            default:
                break;
            }
        }
        // Agregar el objeto consolidado al programa académico correspondiente
        programasAcademicos[stoi(fila[0])]->setConsolidado(consolidado, stoi(fila[0]));
    }
}