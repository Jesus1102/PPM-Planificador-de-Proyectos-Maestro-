#include "Notas.h"

void Notas::crearNota()
{
    while (true)
    {
        cout << "Ingresa el nombre del proyecto: " << endl;
        cin >> nota.nombreProyecto;
        cout << "Ingresa tu nombre: " << endl;
        cin >> nota.nombreResponsable;
        cout << "Ingresa el miembro para el que va la nota: " << endl;
        cin >> nota.nombreMiembro;
        cout << "Ingresa la nota que deseas añadir a " << nota.nombreProyecto << ": " << endl;
        cin >> nota.nuevaNota;
        almacenarNotas.push_back(nota);
        cout << "Nota añadida exitosamente" << endl;
        cout << "Deseas anadir otra nota?\n1. Si.\n2. No." << endl;
        cin >> opcion;
        if (opcion == 2)
        {
            break;
        }
    }
}

void Notas::mostrarNotas()
{
    int size = almacenarNotas.size();
    for (int i = 0; i < size; i++)
    {
        cout << "Proyecto: " << almacenarNotas[i].nombreProyecto << endl;
        cout << "Responsable: " << almacenarNotas[i].nombreResponsable << endl;
        cout << "Miembro: " << almacenarNotas[i].nombreMiembro << endl;
        cout << "Nota: " << almacenarNotas[i].nuevaNota << endl;
        cout << "Reaccion: " << almacenarNotas[i].reaccion << endl;
        cout << "--------------------------------" << endl;
    }
}

void Notas::reaccionarNota()
{
    string nombreProyecto;
    string reaccion;
    while (true)
    {
        cout << "Ingresa el nombre del proyecto al que deseas reaccionar: " << endl;
        cin >> nombreProyecto;
        cout << "Ingresa la reaccion que deseas anadir al proyecto:" << endl;
        cin >> reaccion;
        int size = almacenarNotas.size();
        for (int i = 0; i < size; i++)
        {
            if (almacenarNotas[i].nombreProyecto == nombreProyecto)
            {
                cout << "Proyecto: " << almacenarNotas[i].nombreProyecto << endl;
                cout << "Responsable: " << almacenarNotas[i].nombreResponsable << endl;
                cout << "Miembro: " << almacenarNotas[i].nombreMiembro << endl;
                cout << "Nota: " << almacenarNotas[i].nuevaNota << endl;
                cout << "Reaccion: " << reaccion << endl;
                cout << "----------------------" << endl;
                break;
            }
        }
    }
}
