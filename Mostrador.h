#ifndef MOSTRADOR_H
#define MOSTRADOR_H

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


    void mostrarProyectos();
    void mostrarTareasProyectos(string nombreProyecto);

    string proyectosDisponibles();

    void mostrarResponsablesTarea();

    void imprimirTareasPorPrioridad();
};

#endif // MOSTRADOR_H