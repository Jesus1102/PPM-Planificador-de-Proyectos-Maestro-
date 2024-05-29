#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <windows.h>
#include "Creador.cpp"
#include "AsignarTareasAProyectos.cpp"


class Mostrador{

    Creador c;
    Tarea1 t;
    string buscaProyec;
    public:


    void mostrarProyectos(){
           
        if(c.proyecGenerales.empty()){
            
            cout << "No hay proyectos registrados" << endl;
            cout << "Por favor, cree un proyecto" << endl;

        }

        else{

            for(auto i = c.proyecGenerales.begin(); i != c.proyecGenerales.end(); i++){

                cout << "Nombre del Proyecto: " << i->nombreProy << endl;
                cout << "Propietario del Proyecto: " << i->propietarioProy << endl;
                cout << "Estado del Proyecto: " << i->estadoProy << endl;
                cout << "Descripcion del Proyecto: " << i->descripcionProy << endl;

            }
        }
        
    }
    
    void mostrarTareasProyectos(){

        cout << "Ingrese el nombre del proyecto al que desea ver las tareas: ";
        string nombreProyecto;
        cin >> nombreProyecto;

        auto itBuscar = t.proyectosTareas.find(nombreProyecto);

        if(itBuscar == t.proyectosTareas.end()){

            cout << "No existe este proyecto" << endl;
            cout << "Por favor, cree un proyecto" << endl;

        }
        else{

            for(auto i = t.proyectosTareas[nombreProyecto].begin(); i != t.proyectosTareas[nombreProyecto].end(); i++){

                cout << "Nombre de la tarea: " << i->nombreTarea << endl;
                cout << "Descripcion de la tarea: " << i->descripcion << endl;
                cout << "Estado de la tarea: " << i->estadoTarea << endl;
                cout << "Prioridad de la tarea: " << i->prioridadTarea << endl;
                cout << "Responsable de la tarea: " << i->responsableTarea << endl;
                cout << "Fecha limite de la tarea: " << i->fechaLimiteTarea << endl;

            }
        }

    }

    string proyectosDisponibles(){

        if(c.proyecGenerales.empty()){
            
            cout << "No hay proyectos registrados" << endl;
            cout << "Por favor, cree un proyecto" << endl;

        }
        else{
            int i = 1;
            for(auto& ite : c.proyecGenerales){
                cout << i <<"Nombre del proyecto: " << ite->nombreProy << endl;
            }
        }
        cout << "Ingrese el nombre del proyecto que desea ver, de los proyectos anteriormente mostrados: ";
        string nombreProyecto;
        cin >> nombreProyecto;

        return nombreProyecto;
    }



};