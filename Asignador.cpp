#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include "Creador.cpp"
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



};