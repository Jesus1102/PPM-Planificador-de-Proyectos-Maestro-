#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include "Creador.cpp"
#include "Union.cpp"
#include "Login.cpp"
#include "Mostrador.cpp"

class Asignador{
    
    Creador c;
    Mostrador m;
    public:
    map <string, set<Tarea1>> proyectosTareas;

    void asignarTarea(string nombreProyecto){

        Tarea1 tarea = c.crearTarea();
        proyectosTareas[nombreProyecto].insert(tarea);

    }



};