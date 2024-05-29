#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Tarea {
public:
    set<string> responsables; 
    string tarea, nombreProyecto;
    string descripcion;
    string nombreTarea;
    string estadoTarea;
    string prioridadTarea;
    string responsableTarea;
    string fechaLimiteTarea; 

    Tarea() {
        descripcion = "";
        nombreTarea = "";
        estadoTarea = "";
        prioridadTarea = "";
        responsableTarea = "";
        fechaLimiteTarea = ""; 
    }

    Tarea(string nombreProyecto, string nombreTarea, string estado, string prioridad)
        : nombreProyecto(nombreProyecto), nombreTarea(nombreTarea), estadoTarea(estado), prioridadTarea(prioridad) {}

    bool operator<(const Tarea& otra) const {
    if (prioridadTarea == otra.prioridadTarea) {
        return nombreTarea > otra.nombreTarea; 
    }
    return prioridadTarea > otra.prioridadTarea; 
}

    void pedirDatos();
    void mostrarEstado(); 
    void cambiarEstado(); 
    void AsignarTareas();
    
};

bool ValidacionDeDatos(map<string, Tarea>& tareas){
    int decisionUsuario = 0;
    string nuevaTarea;
    string nuevoResponsable;
    int opcion = 0;

    cout << "Ahora podra asignar uno o varios responsables a cada tarea que desee..." << endl;

    while (true) {
        cout << "Ahora por favor digite el numero de la opcion que desea escoger: " << endl;
        cout << "1. Crear nueva tarea\n2. Agregar responsables a tarea\n" << endl;
        cin >> decisionUsuario;

        cin.ignore();

        if (decisionUsuario == 1) {
            cout << "Escribe el nombre de la tarea que desea crear: " << endl;
            cin >> nuevaTarea;

            // Crear una nueva tarea y agregarla al mapa
            tareas[nuevaTarea] = Tarea();
            cout << "Tarea creada: " << nuevaTarea << endl;
            continue;
        }

        if (decisionUsuario == 2) {
            cout << "Introduce el nombre de la tarea: " << endl;
            cin >> nuevaTarea;

            // Verificar si la tarea existe
            if (tareas.find(nuevaTarea)!= tareas.end()) {
                cout << "Ahora escriba el nombre del responsable que desea asignar a: " << nuevaTarea << endl;
                cin >> nuevoResponsable;

                set<string> responsablesSet = {nuevoResponsable};
                tareas[nuevaTarea].responsables.insert(responsablesSet.begin(), responsablesSet.end());

                // Pregunta si desea agregar más responsables
                cout << "¿Desea agregar más responsables a la tarea? (1. Sí, 2. No): ";
                cin >> opcion;
                cin.ignore(); 

                if (opcion == 1) {
                    continue; 
                } else {
                    cout << "Felicidades, se han asignado correctamente los responsables a la tarea: " << nuevaTarea << endl;
                    break; 
                }
            } else {
                cout << "La tarea no existe. Por favor, cree una tarea primero." << endl;
            }
        }
    }
}

void AsignarTareas(string nombreProyecto) {
    map<string, set<Tarea>> proyectosTareas; 
    cout << "Ahora, podrá agregar las tareas que desee a sus proyectos: " << endl;
    cout << "A continuación escriba el nombre del proyecto: " << endl;
    cin.ignore(); 
    getline(cin, nombreProyecto); 

    // Crear una nueva tarea y agregarla al proyecto especificado
    Tarea nuevaTarea;
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

// Mapa para almacenar los estados posibles y sus descripciones
map<string, string> estados = {
    {"pendiente", "Pendiente"},
    {"en-proceso", "En Proceso"},
    {"lista-para-revision", "Lista Para Revision"}
};

void Tarea::pedirDatos() {
    cout << "Por favor escriba el nombre del proyecto:" << endl;
    cin >> nombreProyecto;
    cout << "Por favor escriba el nombre de la Tarea:" << endl;
    cin >> nombreTarea;
    cout << "No olvide poner el guion en cada espacio del estado." << endl;
    cout << "Por favor seleccione el estado inicial de la tarea (pendiente, en-proceso, lista-para-revision):" << endl;
    cin >> estadoTarea;
    cout << "Seleccione la prioridad de la tarea (urgente, alta, media, baja): " << endl;
    cin >> prioridadTarea;
}

void Tarea::mostrarEstado() {
    cout << "El estado de la tarea '" << nombreTarea << "' es: " << estados[estadoTarea] << endl;
}

void Tarea::cambiarEstado() {
    cout << "Ingrese el nuevo estado para la tarea '" << nombreTarea << "': (pendiente, en-proceso, lista-para-revision)" << endl;
    cin.ignore(); 
    getline(cin, estadoTarea);
    cout << "Estado cambiado a: " << estados[estadoTarea] << endl;
}

void mostrarTareas(const vector<Tarea>& tareas) {
    for (const auto& tarea : tareas) {
        cout << "Nombre Proyecto: " << tarea.nombreProyecto << ", Nombre Tarea: " << tarea.nombreTarea << ", Prioridad: " << tarea.prioridadTarea << endl;
    }
}

