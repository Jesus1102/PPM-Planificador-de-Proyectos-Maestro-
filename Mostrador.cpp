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
    
    void mostrarTareasProyectos(string nombreProyecto){

        auto itBuscar = t.proyectosTareas.find(nombreProyecto);



    }

};