#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Nota
{
    string nombreProyecto;
    string nombreResponsable;
    string nombreMiembro;
    string nota;
    string reaccion;
};

class Notas
{
private:
    int opcion;
    Nota nota;
    vector<Nota> almacenarNotas;

public:

    vector<Nota> getNotas()
    {
        return almacenarNotas;
    }

    Notas(){};

    void anadirNota(string proyecto)
    {
        while (true)
        {

            nota.nombreProyecto = proyecto;
            cout << "Ingresa tu nombre: " << endl;
            cin >> nota.nombreResponsable;
            cout << "Ingresa el miembro para el que va la nota: " << endl;
            cin >> nota.nombreMiembro;
            cout << "Ingresa la nota que deseas añadir a " << proyecto << ": " << endl;
            cin >> nota.nota;
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

    void mostrarNotas()
    {
        for (int i = 0; i < almacenarNotas.size(); i++)
        {
            cout << "Proyecto: " << almacenarNotas[i].nombreProyecto << endl;
            cout << "Responsable: " << almacenarNotas[i].nombreResponsable << endl;
            cout << "Miembro: " << almacenarNotas[i].nombreMiembro << endl;
            cout << "Nota: " << almacenarNotas[i].nota << endl;
            cout << "Reaccion: " << almacenarNotas[i].reaccion << endl;
            cout << "--------------------------------" << endl;
        }
    }

    void reaccionarNota(string proyecto)
    {
        string nombreProyecto;
        string reaccion;
        while (true)
        {
            cout << "Ingresa el nombre del proyecto al que deseas reaccionar: " << endl;
            cin >> nombreProyecto;
            cout << "Ingresa la reaccion que deseas anadir al proyecto:" /*\n1. Entusiasmado.\n2. Confiado.\n3. Tranquilo.\n4. Preocupado.\n5. Estresado.*/ << endl;
            cin >> reaccion;
            int size = almacenarNotas.size();
            for (int i = 0; i < size; i++)
            {
                if (almacenarNotas[i].nombreProyecto == nombreProyecto)
                {
                    cout << "Proyecto: " << almacenarNotas[i].nombreProyecto << endl;
                    cout << "Responsable: " << almacenarNotas[i].nombreResponsable << endl;
                    cout << "Miembro: " << almacenarNotas[i].nombreMiembro << endl;
                    cout << "Nota: " << almacenarNotas[i].nota << endl;
                    cout << "Reaccion: " << reaccion << endl;
                    cout << "----------------------" << endl;
                }
            }
        }
    }
};