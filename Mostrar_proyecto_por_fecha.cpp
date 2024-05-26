#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm> 
#include <ctime> 

using namespace std;

class Proyecto {
public:
    string nombreProyecto;
    struct tm fechaProyecto; 

    Proyecto() {}

    Proyecto(string nombre, struct tm fecha) : nombreProyecto(nombre), fechaProyecto(fecha) {}

    static map<string, Proyecto> &getProyectos() {
        static map<string, Proyecto> proyectos;
        return proyectos;
    }

    static void pedirDatos(Proyecto &proyecto){
    cout << "Por favor escriba el nombre del proyecto:" << endl;
    cin >> proyecto.nombreProyecto;
    cout << "Ingrese la fecha que le desea asignar al proyecto en formato [DIA.MES.AÑO]" << endl;
    string fechaStr;
    cin >> fechaStr;
    char* pEnd;
    proyecto.fechaProyecto.tm_mday = strtol(fechaStr.substr(0, 2).c_str(), &pEnd, 10);
    proyecto.fechaProyecto.tm_mon = strtol(fechaStr.substr(3, 2).c_str(), &pEnd, 10) - 1; 
    proyecto.fechaProyecto.tm_year = strtol(fechaStr.substr(6, 4).c_str(), &pEnd, 10) - 1900; 
    proyecto.fechaProyecto.tm_hour = 0; 
    proyecto.fechaProyecto.tm_min = 0;
    proyecto.fechaProyecto.tm_sec = 0;
    proyecto.fechaProyecto.tm_isdst = -1; 
}

    static bool buscarProyecto(const string &nombre) {
        return getProyectos().find(nombre) != getProyectos().end();
    }

    static void mostrarProyectoPorFecha() {
        if (getProyectos().empty()) {
            cout << "No hay proyectos registrados." << endl;
            return;
        }

        vector<Proyecto> proyectosOrdenados;
        for (const auto &proyecto : getProyectos()) {
            proyectosOrdenados.push_back(proyecto.second);
        }

        sort(proyectosOrdenados.begin(), proyectosOrdenados.end(), [](const Proyecto &a, const Proyecto &b) {
            // return mktime(&a.fechaProyecto) < mktime(&b.fechaProyecto);
            struct tm fechaA = a.fechaProyecto;
            struct tm fechaB = b.fechaProyecto;
            return mktime(&fechaA) < mktime(&fechaB);
        });

        cout << "Proyectos ordenados por fecha:" << endl;
        for (const auto &proyecto : proyectosOrdenados) {
            cout << "Nombre: " << proyecto.nombreProyecto << ", Fecha: " << proyecto.fechaProyecto.tm_mday << "." << proyecto.fechaProyecto.tm_mon + 1 << "." << proyecto.fechaProyecto.tm_year + 1900 << endl;
        }
    }
};

int main() {
    int opcion;
    Proyecto nuevoProyecto;

    while (true) {
        cout << "Seleccione una opción: " << endl;
        cout << "1. Agregar proyecto\n" << endl;
        cout << "2. Mostrar proyectos por fecha\n" << endl;
        cout << "3. Salir\n" << endl;
        cin >> opcion;

        switch(opcion) {
            case 1:
                Proyecto::pedirDatos(nuevoProyecto);
                Proyecto::getProyectos()[nuevoProyecto.nombreProyecto] = nuevoProyecto;
                break;
            case 2:
                Proyecto::mostrarProyectoPorFecha();
                break;
            case 3:
                exit(0);
            default:
                cout << "Opción no válida.\n";
        }
    }

    return 0;
}
