#ifndef NOTAS_H
#define NOTAS_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Nota
{
    string nombreProyecto;
    string nombreResponsable;
    string nombreMiembro;
    string nuevaNota;
    string reaccion;
};

class Notas
{
private:
    int opcion;
    Nota nota;
    vector<Nota> almacenarNotas;

public:
    void crearNota();
    void mostrarNotas();
    void reaccionarNota();
};

#endif