#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

class Tarea1 {
public:
    string descripcion;
    string nombreTarea;
    string estadoTarea;
    string prioridadTarea;
    string responsableTarea;
    string fechaLimiteTarea; 
    map<string, set<Tarea1>> proyectosTareas; 

    Tarea1() {
        descripcion = "";
        nombreTarea = "";
        estadoTarea = "";
        prioridadTarea = "";
        responsableTarea = "";
        fechaLimiteTarea = ""; 
    }
};

void AsignarTareas(string nombreProyecto) {
    
    cout << "Ahora, podrá agregar las tareas que desee a sus proyectos: " << endl;
    cout << "A continuación escriba el nombre del proyecto: " << endl;
    cin.ignore(); 
    getline(cin, nombreProyecto); 

    // Crear una nueva tarea y agregarla al proyecto especificado
    Tarea1 nuevaTarea;
    cout << "Ingrese la descripción de la tarea: " << endl;
    cin.ignore();
    getline(cin, nuevaTarea.descripcion);
    cout <<"Ingrese el nombre de la tarea: " << endl;
    cin.ignore();
    getline(cin, nuevaTarea.nombreTarea);
    cout <<"Ingrese el estado de la tarea: " << endl;
    cin.ignore();
    getline(cin, nuevaTarea.estadoTarea);
    cout <<"Ingrese la prioridad de la tarea: " << endl;
    cin.ignore();
    getline(cin, nuevaTarea.prioridadTarea);
    cout <<"Ingrese el responsable de la tarea: " << endl;
    cin.ignore();
    getline(cin, nuevaTarea.responsableTarea);
    cout <<"Ingrese la fecha limite de la tarea: " << endl;
    cin.ignore();
    getline(cin, nuevaTarea.fechaLimiteTarea); 
    
    // Agregar la tarea al proyecto
    proyectosTareas[nombreProyecto].insert(nuevaTarea); 

    // Mostrar las tareas asignadas al proyecto
    cout << "Las tareas asignadas al proyecto '" << nombreProyecto << "' son:" << endl;
    for (const auto& tarea : proyectosTareas[nombreProyecto]) {
        cout << "- " << tarea.nombreTarea << endl;
    }
}

int main() {
    AsignarTareas("PROYECTO:");

    return 0;
}