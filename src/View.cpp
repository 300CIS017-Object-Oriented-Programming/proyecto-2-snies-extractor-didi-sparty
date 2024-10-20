#include "View.h"

View::View()
{
    // NEW quitar estas variables de aquí y del constructor del SNIESController
    //  estas constantes las leerá el SNIESController del archivo de Settings.h
    //  Completar el archivo con el resto de constantes necesarias
    string ruta1 = string("C:/SNIES_EXTRACTOR/inputs/programas.csv");
    string ruta2 = string("C:/SNIES_EXTRACTOR/inputs/admitidos");
    string ruta3 = string("C:/SNIES_EXTRACTOR/inputs/graduados");
    string ruta4 = string("C:/SNIES_EXTRACTOR/inputs/inscritos");
    string ruta5 = string("C:/SNIES_EXTRACTOR/inputs/matriculados");
    string ruta6 = string("C:/SNIES_EXTRACTOR/inputs/matriculadosPrimerSemestre");
    string ruta7 = string("C:/SNIES_EXTRACTOR/outputs/");
    controlador = SNIESController(ruta1, ruta2, ruta3, ruta4, ruta5, ruta6, ruta7);
}

View::~View()
{
    controlador.~SNIESController();
}

char View::obtenerEntradaUsuario(const string &mensaje, const string &opcionesValidas)
{
    char entrada;
    int i = 0;
    while (i == 0)
    {
        cout << mensaje << endl;
        cin >> entrada;
        entrada = tolower(entrada);
        if (opcionesValidas.find(entrada) != string::npos) i=1;
        else cout << "Entrada no válida. Intente de nuevo." << endl;
    }
    return entrada;
}

string View::obtenerAnoValido(const string &mensaje)
{
    string ano;
    int i = 0;
    while (i == 0)
    {
        cout << mensaje << endl;
        cin >> ano;
        if (isConvetibleToInt(ano)) i=1;
        else cout << "El valor ingresado fue invalido! Por favor ingrese un valor valido." << endl;
    }
    return ano;
}

void View::intercambiarAnos(string &ano1, string &ano2)
{
    if (stoi(ano2) < stoi(ano1))
    {
        string temp = ano1;
        ano1 = ano2;
        
        ano2 = temp;
    }
}

bool View::mostrarPantallaBienvenido()
{
    bool parametrizacionBool = false;

    cout << "Bienvenido al SNIES-Extractor!" << endl;
    cout << "=========================================" << endl;
    cout << "Recuerde que para el correcto funcionamiento del programa tuvo que haber parametrizado" << endl;
    cout << "antes la carpeta SNIES_EXTRACTOR en el disco duro C:, con sus respectivas carpetas inputs y outputs" << endl;
    cout << "y todos los archivo CSV del SNIES." << endl;
    
    char userAnswer = obtenerEntradaUsuario("Si ya hizo esto, escriba 'Y', de lo contrario 'N', y Enter: ", "yn");

    if (userAnswer == 'y')
    {
        parametrizacionBool = true;

        string userText;
        cout << "A continuacion se procesaran los datos de los programas academicos seleccionados en /programas.csv..." << endl;

        string anio1 = obtenerAnoValido("Escriba el primer ano de busqueda: ");
        string ano2 = obtenerAnoValido("Escriba el segundo ano de busqueda: ");
        
        intercambiarAnos(anio1, ano2);

        cout << "Procesando datos ..." << endl;
        controlador.procesarDatosCsv(anio1, ano2);
        cout << "Datos procesados con exito!" << endl;
    }
    return parametrizacionBool;
}

void View::salir()
{
    cout << "Cerrando programa..." << endl;
    cout << "Recuerde revisar la carpeta de outputs para los archivos .csv exportados" << endl;
    cout << "Programa Cerrado con exito!" << endl;
}

void View::mostrarDatosExtra()
{
    char opcionYN;
    cout << "A continuacion vamos a mostrar datos relevantes de los programas academicos seleccionados" << "\n"
        << endl;
    char opcionYN = obtenerEntradaUsuario("Desea Convertir los datos a un archivo CSV?(Y/N): ", "yn");
    if (opcionYN == 'y')
    {
        controlador.calcularDatosExtra(true);
    }

    else
    {
        controlador.calcularDatosExtra(false);
    }
}

void View::buscarPorPalabraClaveYFormacion()
{
    char opcionYN = 'y', opcionCSV;
    string palabraClave;
    bool convertirCSV;
    int idFormacionAcademica;

    while (opcionYN == 'y')
    {
        cout << "Desea hacer una busqueda por palabra clave del nombre del programa(Y/N): " << endl;
        cin >> opcionYN;
        cout << "\n";
        opcionYN = tolower(opcionYN);

        if (opcionYN == 'y')
        {
            cout << "Deseas convertir convertir los datos del programa academico a un CSV?(Y/N): " << endl;
            cin >> opcionCSV;
            cout << "\n";
            opcionCSV = tolower(opcionCSV);

            if (opcionCSV == 'y')
            {
                convertirCSV = true;
            }

            else
            {
                convertirCSV = false;
            }

            cout << "Escriba la palabra clave para buscar los programas por nombre:" << endl;
            cin >> palabraClave;
            cout << endl;

            cout << "Seleccione un nivel de formacion para filtrar: \n 1->Especializacion Universitaria\n 2->Maestria\n 3->Doctorado\n 4->Formacion Tecnica Profesional \n 5->Tecnologico\n 6->Universitario\n 7->Especializacion Tecnico Profesional\n 8->Especializacion Tecnologica\n 10->Especializacion Medico Quirurgica\n " << endl;
            cin >> idFormacionAcademica;
            cout << "\n";
            while ((idFormacionAcademica > 10) || (idFormacionAcademica == 9) || (idFormacionAcademica < 1))
            {
                cout << "Seleccione una opcion entre 1-10 excluyendo el 9\n"
                    << endl;
                cin >> idFormacionAcademica;
            }

            controlador.buscarProgramas(convertirCSV, palabraClave, idFormacionAcademica);
        }
    }
}

bool View::isConvetibleToInt(const string &str)
{
    try
    {
        std::size_t pos;
        int num = std::stoi(str, &pos);

        // Verificamos si se ha convertido toda la cadena
        return pos == str.length();
    }
    catch (const std::invalid_argument &)
    {
        // No se pudo convertir: la cadena no es un número válido
        return false;
    }
    catch (const std::out_of_range &)
    {
        // No se pudo convertir: el número está fuera del rango de int
        return false;
    }
}
