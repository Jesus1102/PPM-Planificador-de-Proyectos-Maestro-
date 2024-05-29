#ifndef CREADOR_H
#define CREADOR_H

#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

struct Proyecto1 {
    string nombreProy;
    string propietarioProy;
    string estadoProy;
    string descripcionProy;
    // Sobrecargar operador < para usar en set
    bool operator<(const Proyecto1& other) const {
        return nombreProy < other.nombreProy;
    }
};

struct Tarea1 {
    string nombreTarea;
    string estadoTarea;
    string prioridadTarea;
    set <string> responsableTarea;
    string fechaLimiteTarea;
    string resumenTarea;

    bool operator<(const Tarea1& other) const {
        return nombreTarea < other.nombreTarea;
    }
};

class Creador {
public:
    Proyecto1 pro;
    Tarea1 task;
    set<Proyecto1> proyecGenerales;
    vector<string> nombresProyectos;
    vector<Tarea1> tareasGenerales;
    string prioridad[4] = {"Urgente", "Alta", "Media", "Baja"};
    vector<string> estado = {"Pendiente", "En Proceso", "Terminada"};

    void crearProyecto();
    void crearTarea();
    void prioTarea();
    bool validarVacio();
    string definirEstado();
    void limiteFecha();
    bool fechaValida(int dia, int mes, int anio);

};

#endif // CREADOR_H
