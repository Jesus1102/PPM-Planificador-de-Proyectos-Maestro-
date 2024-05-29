#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include "Creador.h"
#include "Login.cpp"


class Asignador{
    
    Creador c;
    public:
    map <string, set<Tarea1>> proyectosTareas;

    void asignarTarea(string nombreProyecto){

        if(c.validarVacio() == true){
            Tarea1 ultimaTarea = c.tareasGenerales.back();
            proyectosTareas[nombreProyecto].insert( ultimaTarea);

        }
        else{
            cout << "No hay tareas registradas" << endl;
            cout << "Por favor, cree una tarea" << endl;
        }

    }

    void responsablesTarea(){
        string nombreTareaBusqueda;

        cout << "Ingrese el nombre de la tarea: " << endl;
        cin >> nombreTareaBusqueda;
        if(buscarTarea(nombreTareaBusqueda) == true){
            cout << "Ingrese el nombre del responsable: " << endl;
            cin >> c.task.responsableTarea;
        }
        else{
            cout << "No existe esta tarea" << endl;
            cout << "Por favor, cree una tarea" << endl;
        }
    }

    void cambiarEstadoTarea(){
        string nombreTareaBusqueda;

        cout << "Ingrese el nombre de la tarea: " << endl;
        cin >> nombreTareaBusqueda;
        if(buscarTarea(nombreTareaBusqueda) == true){
            cout << "Ingrese el nuevo estado de la tarea: " << endl;
            cin >> c.task.estadoTarea;
        }
        else{
            cout << "No existe esta tarea" << endl;
            cout << "Por favor, cree una tarea" << endl;
        }
    }

    bool buscarTarea(string tareanombre){

        for (const auto& tarea : c.tareasGenerales) {
            if (tarea.nombreTarea == tareanombre) {
                return true;    
            }
        }
        return false;

    }



};