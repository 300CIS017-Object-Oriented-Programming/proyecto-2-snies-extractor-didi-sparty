#include "View.h"

View::View()
{

    controlador = SNIESController();
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
    cout << "Desea Convertir los datos a un archivo CSV?(Y/N): " << endl;
    cin >> opcionYN;
    opcionYN = tolower(opcionYN);
    cout << "\n";
    // FIXME verificar que el usuario ingrese un valor igual al esperado, return true si es Y, false si es N, y no sale si no retorna un valor válido
    // Simplificar el código de acuerdo a ese ajuste
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

  //  Menu para preguntar el tipo de salida que el usuario desea la informacion
void View::tipoDeSalida(){
    int opcion = 0;
    cout << "Desea imprimir la informacion?\n1.Si\n2.No" << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        cout << "Por favor indique el tipo de archivo que desea para su informacion"
                "1. CSV FILE\n2. JSON FILE\n3. TXT FILE" << endl;
        int opcionFile = 0;
        cin >> opcionFile;
    //     switch (opcionFile)
    //     {
    //     case 1:
    //         controlador.csvOutput();
    //         break;
    //
    //     case 2:
    //         controlador.jsonOutput();
    //         break;
    //     case 3:
    //         controlador.txtOutput();
    //     default:
    //         cout << "Opcion no valida" << endl;
    //         break;
    //     }
    //     break;
    // case 2:
    //     cout << "Entendido, te espero de vuelta !" << endl;
    //     break;
    // default:
    //     cout << "Opcion invalida, por favor verifique de nuevo";
    //     break;
     }
}