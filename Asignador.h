#ifndef ASIGNADOR_H
#define ASIGNADOR_H

#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include "Creador.h"

class Asignador{
    
    Creador c;
    public:
    map <string, set<Tarea1>> proyectosTareas;

    void asignarTarea(string nombreProyecto);

    void responsablesTarea();

    void cambiarEstadoTarea();

    bool buscarTarea(string tareanombre);
};

#endif // ASIGNADOR_H