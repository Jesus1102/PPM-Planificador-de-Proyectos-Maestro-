#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Tarea {
public:
    vector<string> responsables;
    string tarea;

    Tarea() {};
};

bool pedirYValidarDatos(map<string, Tarea>& tareas) {
    int desicionUsuario = 0;
    string nuevaTarea;
    string nuevoResponsable;
    int opcion = 0;

    cout << "Ahora podra asignar uno o varios responsables a cada tarea que desee..." << endl;

    while (true) {
        cout << "Ahora por favor digite el numero de la opcion que desea escoger: " << endl;
        cout << "1. Crear nueva tarea\n2. Agregar responsables a tarea\n" << endl;
        cin >> desicionUsuario;

        cin.ignore(); 

        if (desicionUsuario == 1) {
            cout << "Escribe el nombre de la tarea que desea crear: " << endl;
            cin >> nuevaTarea;

            // Crear una nueva tarea y agregarla al mapa
            tareas[nuevaTarea] = Tarea();
            cout << "Tarea creada: " << nuevaTarea << endl;
            continue;
        }

        if (desicionUsuario == 2) {
            cout << "Introduce el nombre de la tarea: " << endl;
            cin >> nuevaTarea;

            // Verificar si la tarea existe
            if (tareas.find(nuevaTarea)!= tareas.end()) {
                cout << "Ahora escriba el nombre del responsable que desea asignar a: " << nuevaTarea << endl;
                cin >> nuevoResponsable;

                
                tareas[nuevaTarea].responsables.push_back(nuevoResponsable);

                
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

int main() {
    map<string, Tarea> tareas; 
    bool continuar = true;
    while (continuar) {
        continuar = pedirYValidarDatos(tareas);
    }
    return 0;
}