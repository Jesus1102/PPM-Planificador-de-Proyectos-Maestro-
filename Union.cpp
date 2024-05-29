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
    static map<string, set<string>> proyectosTareas;
    set<string> responsables;  // set de responsables para cada tarea
    string nombreProyecto, nombreTarea, descripcion, estadoTarea, prioridadTarea, responsableTarea, fechaLimiteTarea;

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

map<string, set<string>> Tarea::proyectosTareas;

bool ValidacionDeDatos(map<string, Tarea>& tareas){
    int decisionUsuario = 0;
    string nuevaTarea, nuevoResponsable;
    int opcion = 0;

    cout << "Ahora podrá asignar uno o varios responsables a cada tarea que desee..." << endl;

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
                cout << "La tarea no existePor favor, cree una tarea primero." << endl;
            }
        }
    }

    return true;
}

void AsignarTareas(string nombreProyecto) {
    
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
    if (Tarea::proyectosTareas.find(nombreProyecto) == Tarea::proyectosTareas.end()) {
        set<string> tareasSet = {nuevaTarea.nombreTarea};
        Tarea::proyectosTareas[nombreProyecto] = tareasSet;
    } else {
        Tarea::proyectosTareas[nombreProyecto].insert(nuevaTarea.nombreTarea);
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
        cout << "Nombre Proyecto: " << tarea.nombreProyecto << ", Nombre T" << tarea.nombreTarea << ", Prioridad: " << tarea.prioridadTarea << endl;
    }
}

void mostrarResponsables(const set<string>& responsables) {
    cout << "Los responsables ordenados alfabeticamente son:\n";
    for (const auto& responsable : responsables) {
        cout << responsable << endl;
    }
}

/*
int main(){
    int opcion;
    Tarea nuevoProyecto;
    string nombreProyecto;

    while (true) {
        cout << "Seleccione una opción: " << endl;
        cout << "1. Si desea asignar uno o varios responsables a cada tarea\n" << endl;
        cout << "2. Si desea asignar tareas a proyectos\n" << endl;
        cout << "3. Si desea cambiar el estado de la tarea. \n" << endl;
        cout << "4. Si desea organizar tareas por prioridad. " << endl;
        cout << "5. Si desea salir de la aplicación. " << endl;
        cin >> opcion;

        switch(opcion){
        case 1:
            // Asignar responsables a tarea.
            map<string, Tarea> tareas; // Crear un mapa para almacenar las tareas y sus responsables
            bool continuar = true;
            while (continuar) {
                continuar = ValidacionDeDatos(tareas);
                
                set<string> allResponsables;
            for (const auto& tarea : tareas) {
            allResponsables.insert(tarea.second.responsables.begin(), tarea.second.responsables.end());
        }
        mostrarResponsables(allResponsables);
    }
            }
            break;

        case 2:
            // Asignar tareas a proyectos.
            cout << "Por favor escribe el nombre del proyecto: " << endl;
            cin >> nombreProyecto;
            AsignarTareas(nombreProyecto);
            break;

        case 3:
            // Cambiar el estado de la tarea.
            int opcion;
            Tarea tarea;
            tarea.pedirDatos();

            tarea.mostrarEstado();
            cout <<"¿Quieres cambiar el estado de la tarea? 1. SI2. NO. Answer in spanish. " << endl;
            cin >> opcion;
            if(opcion == 1){
                tarea.cambiarEstado();
            }
            else{
                cout << "Asignaste correctamente el estado de la tarea. " << endl;
            }

            tarea.mostrarEstado();
            break;

        case 4:
            // Organizar tareas por prioridad.
            map<string, vector<Tarea>> proyectos;
            vector<string> tareasPredefinidas = {"Tarea 1", "Tarea 2", "Tarea 3"};

            cout << "Por favor escribe el nombre del proyecto: " << endl;
            cin >> nombreProyecto;

            proyectos[nombreProyecto] = vector<Tarea>();

            for (const auto& tarea : tareasPredefinidas) {
                Tarea nuevaTarea;
                nuevaTarea.nombreProyecto = nombreProyecto;
                nuevaTarea.nombreTarea = tarea;
                nuevaTarea.estadoTarea = "Pendiente";
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
            break;

        case 5:
            cout << "Saliendo... " << endl;
            return 0;
        }
    }

    return 0;
}
*/
