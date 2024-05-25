#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

class Tarea {
public:
    string nombreProyecto;
    string nombreTarea;
    string estado;
    string prioridad;

    void pedirDatos(){
        cout << "Por favor escribe el nombre del proyecto: " << endl;
        cin >> nombreProyecto;
        cout <<  "Por favor escribe el nombre de la tarea: " << endl;
        cin >> nombreTarea;
        
        cout << "Seleccione la prioridad de la tarea (urgente, alta, media, baja): " << endl;
        cin >> prioridad;
    }
    
    Tarea(string nombreProyecto, string nombreTarea, string estado, string prioridad)
        : nombreProyecto(nombreProyecto), nombreTarea(nombreTarea), estado(estado), prioridad(prioridad) {}

    bool operator<(const Tarea& otra) const {
        if (prioridad == otra.prioridad) {
            return nombreTarea > otra.nombreTarea; 
        }
        return prioridad > otra.prioridad; 
    }
    Tarea(){};
};


void mostrarTareas(const vector<Tarea>& tareas) {
    for (const auto& tarea : tareas) {
        cout << "Nombre Proyecto: " << tarea.nombreProyecto << ", Nombre Tarea: " << tarea.nombreTarea << ", Prioridad: " << tarea.prioridad << endl;
    }
}

int main() {
    map<string, vector<Tarea>> proyectos;
    vector<string> tareasPredefinidas = {"Tarea 1", "Tarea 2", "Tarea 3"};

    string nombreProyecto;
    cout << "Por favor escribe el nombre del proyecto: " << endl;
    cin >> nombreProyecto;

    proyectos[nombreProyecto] = vector<Tarea>();

    for (const auto& tarea : tareasPredefinidas) {
        Tarea nuevaTarea;
        nuevaTarea.nombreProyecto = nombreProyecto;
        nuevaTarea.nombreTarea = tarea;
        nuevaTarea.estado = "Pendiente";
        nuevaTarea.pedirDatos();
        proyectos[nombreProyecto].push_back(nuevaTarea);
    }

    // Ordenar las tareas por prioridad de mayor a menor
    for (auto& proyecto : proyectos) {
        sort(proyecto.second.begin(), proyecto.second.end());
    }

    // Mostrar las tareas ordenadas
    for (const auto& proyecto : proyectos) {
        cout << "Proyecto: " << proyecto.first << endl;
        mostrarTareas(proyecto.second);
    }

    return 0;
}