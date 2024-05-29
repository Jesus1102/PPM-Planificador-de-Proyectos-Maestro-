#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include "Creador.h"
#include "Asignador.cpp"


class Mostrador{

    Creador c;
    Asignador a;
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
    
    void mostrarTareasProyectos(string nombreProyecto){


        auto itBuscar = a.proyectosTareas.find(nombreProyecto);

        if(itBuscar == a.proyectosTareas.end()){

            cout << "No existe este proyecto" << endl;
            cout << "Por favor, cree un proyecto" << endl;

        }
        else{

            for(auto i = a.proyectosTareas[nombreProyecto].begin(); i != a.proyectosTareas[nombreProyecto].end(); i++){

                cout << "Nombre de la tarea: " << i->nombreTarea << endl;
                cout << "Estado de la tarea: " << i->estadoTarea << endl;
                cout << "Prioridad de la tarea: " << i->prioridadTarea << endl;
                cout << "Responsable de la tarea: " << endl;
                for(const auto& j : i->responsableTarea){
                    cout << j << endl;
                }
                cout << "Fecha limite de la tarea: " << i->fechaLimiteTarea << endl;
                cout << "Resumen de la tarea: " << i->resumenTarea << endl;

            }
        }

    }

    string proyectosDisponibles(){

        if(c.proyecGenerales.empty()){
            
            cout << "No hay proyectos registrados" << endl;
            cout << "Por favor, cree un proyecto" << endl;

        }
        else{
            int j = 1;
            for(auto i = c.proyecGenerales.begin(); i != c.proyecGenerales.end(); i++){
                cout << j << "Nombre del proyecto: " << i->nombreProy << endl;
                j++;
            }
        }
        cout << "Ingrese el nombre del proyecto que desea ver, de los proyectos anteriormente mostrados: ";
        string nombreProyecto;
        cin >> nombreProyecto;

        return nombreProyecto;
    }

    void mostrarResponsablesTarea(){

        cout << "Ingrese el nombre de la tarea: " << endl;
        string nombreTareaBusqueda;

        cin >> nombreTareaBusqueda;

        if (a.buscarTarea(nombreTareaBusqueda) == true){
            cout << "Responsables de la tarea: " << endl;
            for (const auto& tarea : c.tareasGenerales) {

                for(const auto& j : tarea.responsableTarea){
                    cout << j << endl;
                }
                
            }
        }
        else{
            cout << "No existe esta tarea" << endl;
            cout << "Por favor, cree una tarea" << endl;
        }
        
    }

    void imprimirTareasPorPrioridad() {
        
        if(c.tareasGenerales.empty()){
            cout << "No hay tareas registradas" << endl;
            cout << "Por favor, cree una tarea" << endl;
        }
        else{
            cout << "Tareas por prioridad: " << endl;
            for (int i = 0; i < 4; i++) {
                cout << c.prioridad[i] << endl;
                for (const auto& tarea : c.tareasGenerales) {
                    if (tarea.prioridadTarea == c.prioridad[i]) {
                        cout << "Nombre de la tarea: " << tarea.nombreTarea << endl;
                        cout << "Estado de la tarea: " << tarea.estadoTarea << endl;
                        
                    }
                }
            }
        }
   
    }
};



