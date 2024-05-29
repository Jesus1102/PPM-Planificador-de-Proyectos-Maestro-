#include <iostream>
#include "Creador.h"
#include "Asignador.h"



void Asignador::asignarTarea(string nombreProyecto){

    if(c.validarVacio() == true){
        Tarea1 ultimaTarea = c.tareasGenerales.back();
        proyectosTareas[nombreProyecto].insert( ultimaTarea);

    }
    else{
        cout << "No hay tareas registradas" << endl;
        cout << "Por favor, cree una tarea" << endl;
    }

}

void Asignador::responsablesTarea(){
    string nombreTareaBusqueda;

    cout << "Ingrese el nombre de la tarea: " << endl;
    cin >> nombreTareaBusqueda;
    if(buscarTarea(nombreTareaBusqueda) == true){
        cout << "Ingrese el nombre del para agregar un responsable: "<< endl;
        string responsable;
        cin >> responsable;
        c.task.responsableTarea.insert(responsable);
    }
    else{
        cout << "No existe esta tarea" << endl;
        cout << "Por favor, cree una tarea" << endl;
    }
}

void Asignador::cambiarEstadoTarea(){
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

bool Asignador::buscarTarea(string tareanombre){

    for (const auto& tarea : c.tareasGenerales) {
        if (tarea.nombreTarea == tareanombre) {
            return true;    
        }
    }
    return false;

}
