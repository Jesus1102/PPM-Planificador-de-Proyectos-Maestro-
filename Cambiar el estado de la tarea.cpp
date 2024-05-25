#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

class Tarea {
public:
    string nombreProyecto;
    string nombreTarea;
    string estado; 

    public:
    void pedirDatos();
    void mostrarEstado(); 
    void cambiarEstado(); 
};

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
    cin >> estado;
}

void Tarea::mostrarEstado() {
    cout << "El estado de la tarea '" << nombreTarea << "' es: " << estados[estado] << endl;
}

void Tarea::cambiarEstado() {
    cout << "Ingrese el nuevo estado para la tarea '" << nombreTarea << "': (pendiente, en-proceso, lista-para-revision)" << endl;
    cin.ignore(); 
    getline(cin, estado);
    cout << "Estado cambiado a: " << estados[estado] << endl;
}

int main() {
    int opcion;
    Tarea tarea;
    tarea.pedirDatos();

    tarea.mostrarEstado();
    cout <<"¿Quieres cambiar el estado de la tarea? 1. SI\n2. NO" << endl;
    cin >> opcion;
    if(opcion == 1){
    tarea.cambiarEstado();
    }
    else{
        cout << "Asignaste correctamente el estado de la tarea. " << endl;
    }

    tarea.mostrarEstado();

    return 0;
}
