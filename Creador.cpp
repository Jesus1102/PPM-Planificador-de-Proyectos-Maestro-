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

        cout << "";


    }

};