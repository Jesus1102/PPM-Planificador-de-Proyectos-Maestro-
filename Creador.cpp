#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>

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
    map <string, set<Tarea>> proyecGenerales;
    

    void crearProyecto(){

        cout << "Ingrese el nombre del Proyecto: " << endl;
        cin >> pro.nombreProy;

        cout << "Ingrese el propietario del Proytecto: " << endl;
        cin >> pro.propietarioProy;

        cout << "Ingrese el estado del Proyecto:" << endl;
        cin >> pro.estadoProy;

        cout << "Ingrese la descripcion del Proyecto: " << endl;
        cin >> pro.descripcionProy;

    }

    void crearTarea(){

        cout << "Ingrese el nombre de la Tarea: " << endl;
        cin >> task.nombreTarea;

        cout << "Ingrese el estado de la Tarea: " << endl;
        cin >> task.estadoTarea;

        cout << "Ingrese la prioridad de la Tarea: " << endl;
        cin >> task.prioridadTarea;

        cout << "Ingrese el responsable de la Tarea: " << endl;
        cin >> task.responsableTarea;

        cout << "Ingrese la fecha limite de la Tarea: " << endl;
        cin >> task.fechaLimiteTarea;

        cout << "Ingrese el resumen de la Tarea: " << endl;
        cin >> task.resumenTarea;

    }

    void agregarTareaProyecto(){

        proyecGenerales[pro.nombreProy].insert(task);

    }




};