classDiagram
    class Consolidado {
        -int idSexo
        -string sexo
        -int ano
        -int semestre
        -int inscritos
        -int admitidos
        -int matriculados
        -int matriculadosPrimerSemestre
        -int graduados

        +Consolidado()
        +Consolidado(int, string, int, int, int, int, int, int, int)

        +int getIdSexo()
        +void setIdSexo(int)

        +string getSexo()
        +void setSexo(string &)

        +int getAno()
        +void setAno(int)

        +int getSemestre()
        +void setSemestre(int)

        +int getInscritos()
        +void setInscritos(int)

        +int getAdmitidos()
        +void setAdmitidos(int)

        +int getMatriculados()
        +void setMatriculados(int)

        +int getMatriculadosPrimerSemestre()
        +void setMatriculadosPrimerSemestre(int)

        +int getGraduados()
        +void setGraduados(int)
    }

    class ProgramaAcademico {
        -int codigoDeLaInstitucion
        -int iesPadre
        -string institucionDeEducacionSuperiorIes
        -string principalOSeccional
        -int idSectorIes
        -string sectorIes
        -int idCaracter
        -string caracterIes
        -int codigoDelDepartamentoIes
        -string departamentoDeDomicilioDeLaIes
        -int codigoDelMunicipioIes
        -string municipioDeDomicilioDeLaIes
        -int codigoSniesDelPrograma
        -string programaAcademico
        -int idNivelAcademico
        -string nivelAcademico
        -int idNivelDeFormacion
        -string nivelDeFormacion
        -int idMetodologia
        -string metodologia
        -int idArea
        -string areaDeConocimiento
        -int idNucleo
        -string nucleoBasicoDelConocimientoNbc
        -int idCineCampoAmplio
        -string descCineCampoAmplio
        -int idCineCampoEspecifico
        -string descCineCampoEspecifico
        -int idCineCodigoDetallado
        -string descCineCodigoDetallado
        -int codigoDelDepartamentoPrograma
        -string departamentoDeOfertaDelPrograma
        -int codigoDelMunicipioPrograma
        -string municipioDeOfertaDelPrograma
        -vector<Consolidado*> consolidados

        +ProgramaAcademico()
        +~ProgramaAcademico()
        
        +void setCodigoDeLaInstitucion(int)
        +int getCodigoDeLaInstitucion()
        +void setIesPadre(int)
        +int getIesPadre()
        +void setInstitucionDeEducacionSuperiorIes(string &)
        +string getInstitucionDeEducacionSuperiorIes()
        +void setPrincipalOSeccional(string &)
        +string getPrincipalOSeccional()
        +void setIdSectorIes(int)
        +int getIdSectorIes()
        +void setSectorIes(string &)
        +string getSectorIes()
        +void setIdCaracter(int)
        +int getIdCaracter()
        +void setCaracterIes(string &)
        +string getCaracterIes()
        +void setCodigoDelDepartamentoIes(int)
        +int getCodigoDelDepartamentoIes()
        +void setDepartamentoDeDomicilioDeLaIes(string &)
        +string getDepartamentoDeDomicilioDeLaIes()
        +void setCodigoDelMunicipioIes(int)
        +int getCodigoDelMunicipioIes()
        +void setMunicipioDeDomicilioDeLaIes(string &)
        +string getMunicipioDeDomicilioDeLaIes()
        +void setCodigoSniesDelPrograma(int)
        +int getCodigoSniesDelPrograma()
        +void setProgramaAcademico(string &)
        +string getProgramaAcademico()
        +void setIdNivelAcademico(int)
        +int getIdNivelAcademico()
        +void setNivelAcademico(string &)
        +string getNivelAcademico()
        +void setIdNivelDeFormacion(int)
        +int getIdNivelDeFormacion()
        +void setNivelDeFormacion(string &)
        +string getNivelDeFormacion()
        +void setIdMetodologia(int)
        +int getIdMetodologia()
        +void setMetodologia(string &)
        +string getMetodologia()
        +void setIdArea(int)
        +int getIdArea()
        +void setAreaDeConocimiento(string &)
        +string getAreaDeConocimiento()
        +void setIdNucleo(int)
        +int getIdNucleo()
        +void setNucleoBasicoDelConocimientoNbc(string &)
        +string getNucleoBasicoDelConocimientoNbc()
        +void setIdCineCampoAmplio(int)
        +int getIdCineCampoAmplio()
        +void setDescCineCampoAmplio(string &)
        +string getDescCineCampoAmplio()
        +void setIdCineCampoEspecifico(int)
        +int getIdCineCampoEspecifico()
        +void setDescCineCampoEspecifico(string &)
        +string getDescCineCampoEspecifico()
        +void setIdCineCodigoDetallado(int)
        +int getIdCineCodigoDetallado()
        +void setDescCineCodigoDetallado(string &)
        +void setCodigoDelDepartamentoPrograma(int)
        +int getCodigoDelDepartamentoPrograma()
        +void setDepartamentoDeOfertaDelPrograma(string &)
        +string getDepartamentoDeOfertaDelPrograma()
        +void setCodigoDelMunicipioPrograma(int)
        +int getCodigoDelMunicipioPrograma()
        +void setMunicipioDeOfertaDelPrograma(string &)
        +string getMunicipioDeOfertaDelPrograma()

        +void setConsolidado(Consolidado *, int)
        +Consolidado *getConsolidado(int)
    }

    class GestorCsv {
        +vector<int> leerProgramasCsv()
        +vector<vector<string>> leerArchivoPrimera(string &rutaBase, string &ano, vector<int> &codigosSnies)
        +vector<vector<string>> leerArchivoSegunda(string &rutaBase, string &ano, vector<int> &codigosSnies)
        +vector<vector<string>> leerArchivo(string &rutaBase, string &ano, vector<int> &codigosSnies, int colmunaCodigoSnies)
        +bool crearArchivo(string &ruta, map<int, ProgramaAcademico*> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas)
        +bool crearArchivoBuscados(string &ruta, list<ProgramaAcademico*> &programasBuscados, vector<string> etiquetasColumnas)
        +bool crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir)
    }

    class SNIESController {
        -map<int, ProgramaAcademico*> programasAcademicos
        -GestorCsv gestorCsvObj
        -vector<string> etiquetasColumnas
        -string rutaAdmitidos
        -string rutaGraduados
        -string rutaInscritos
        -string rutaMatriculados
        -string rutaMatriculadosPrimerSemestre
        -string rutaOutput

        +SNIESController() 
        +SNIESController(string &, string &, string &, string &, string &, string &)
        +~SNIESController()

        +void procesarDatosCsv(string &, string &)
        +void calcularDatosExtra(bool)
        +void buscarProgramas(bool, string &, int)
    }

    class View {
        -SNIESController controlador

        +View()
        +~View()

        +bool mostrarPantallaBienvenido()
        +void mostrarDatosExtra()
        +void buscarPorPalabraClaveYFormacion()
        +void salir()
        +bool isConvetibleToInt(const string &)
    }

    class Settings {
        +static const fs::path BASE_PATH
        +static const fs::path PROGRAMAS_FILTRAR_FILE_PATH
        +static const fs::path INPUT_PATH
        +static const fs::path OUTPUT_PATH
        +static const char DELIMITADOR
    }

    ProgramaAcademico "1" -- "1..*" Consolidado : contiene
    SNIESController "1" o-- "0..*" ProgramaAcademico : maneja
    SNIESController "1" o-- "1" GestorCsv : usa
    View "1" o-- "1" SNIESController : controla