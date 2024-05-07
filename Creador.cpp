#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <windows.h>

#define color SetConsoleTextAttribute

using namespace std;

struct Proyecto{
    string nombreProy;
    string propietarioProy;
    string estadoProy;
    string descripcionProy;

};

struct Tarea{

    string nombreTarea;
    string estadoTarea;
    string prioridadTarea;
    string responsableTarea;
    string fechaLimiteTarea;
    string resumenTarea;

}; 



class Creador{

    public:
    Proyecto pro;
    Tarea task;
    set<Proyecto> proyecGenerales;
    set <Tarea> tareasGenerales;
    map <string, set<Tarea>> proyecTareas;
    int color1 [4] = {4,12,14,10};

    

    void crearProyecto(){

        cout << "Ingrese el nombre del Proyecto: " << endl;
        cin >> pro.nombreProy;

        cout << "Ingrese el propietario del Proytecto: " << endl;
        cin >> pro.propietarioProy;

        cout << "Ingrese el estado del Proyecto:" << endl;
        cin >> pro.estadoProy;

        cout << "Ingrese la descripcion del Proyecto: " << endl;
        cin >> pro.descripcionProy;

        proyecGenerales.insert(pro);

    }

    void crearTarea(){

        cout << "Ingrese el nombre de la Tarea: " << endl;
        cin >> task.nombreTarea;

        cout << "Ingrese el estado de la Tarea: " << endl;
        cin >> task.estadoTarea;

        prioTarea();

        cout << "Ingrese el responsable de la Tarea: " << endl;
        cin >> task.responsableTarea;

        cout << "Ingrese la fecha limite de la Tarea: " << endl;
        cin >> task.fechaLimiteTarea;

        cout << "Ingrese el resumen de la Tarea: " << endl;
        cin >> task.resumenTarea;

        tareasGenerales.insert(task);

    }

    void prioTarea(){

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        string prioridad [4] = {"Urgente","Alta","Media","Baja"};
        int opc;

        for(int i = 0; i < 4; i++){

            color(hConsole, color1[i]);
            cout << to_string(i+1) << prioridad[i] << endl;

        }

        cout << "Ingrese la prioridad de la tarea: " << endl;
        cin >> opc;
        opc--;

        task.prioridadTarea = prioridad[opc];

    }

    void agregarTareaProyecto(){

        proyecTareas[pro.nombreProy].insert(task);

    }




};