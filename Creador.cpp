#include "Creador.h"
#include "colors.h"

void Creador::crearProyecto() {
    cout << "Ingrese el nombre del Proyecto: " << endl;
    cin >> pro.nombreProy;

    nombresProyectos.push_back(pro.nombreProy);

    cout << "Ingrese el propietario del Proyecto: " << endl;
    cin >> pro.propietarioProy;

    pro.estadoProy = definirEstado();

    cout << "Ingrese la descripcion del Proyecto: " << endl;
    cin.ignore();  // Para ignorar el carácter de nueva línea restante
    getline(cin, pro.descripcionProy);

    proyecGenerales.insert(pro);
}

void Creador::crearTarea() {
    cout << "Ingrese el nombre de la Tarea: " << endl;
    cin >> task.nombreTarea;

    task.estadoTarea = definirEstado();

    prioTarea();

    cout << "Ingrese el responsable de la Tarea: " << endl;
    cin >> task.responsableTarea;

    limiteFecha();

    cout << "Ingrese el resumen(comentarios) de la Tarea: " << endl;
    cin.ignore();  // Para ignorar el carácter de nueva línea restante
    getline(cin, task.resumenTarea);

    tareasGenerales.push_back(task);
}

void Creador::prioTarea() {
    string prioridad[4] = {"Urgente", "Alta", "Media", "Baja"};
    int opc;
    

    cout << "Las prioridades disponibles son: " << endl;
    cout << RED << "1. Urgente" << endl;
    cout << ORANGE << "2. Alta" << endl;
    cout << YELLOW << "3. Media" << endl;
    cout << GREEN << "4. Baja" << endl;

    cout << "Ingrese la prioridad de la tarea: " << endl;
    cin >> opc;
    opc--;

    task.prioridadTarea = prioridad[opc];
}

bool Creador::validarVacio() {
    return !tareasGenerales.empty();
}

string Creador::definirEstado() {
    int opcion;
    string opEstado;

    while (true) {
        cout << "1. para crear un estado " << endl << "2. para asignar un estado" << endl;
        cin >> opcion;

        if (opcion == 1) {
            cout << "Los estados disponibles son: " << endl;
            for (int i = 0; i < estado.size(); i++) {
                cout << to_string(i + 1) << ". " << estado[i] << endl;
            }
            cout << "Ingrese el nuevo estado: " << endl;
            cin >> opEstado;
            estado.push_back(opEstado);
        }
        if (opcion == 2) {
            int opcion1;
            cout << "Los estados disponibles son: " << endl;
            for (int i = 0; i < estado.size(); i++) {
                cout << to_string(i + 1) << ". " << estado[i] << endl;
            }
            cout << "Ingrese el estado de la tarea/proyecto: " << endl;
            cin >> opcion1;
            return estado[opcion1 - 1];
        }
    }
}

void Creador::limiteFecha() {
    int dia1, mes1, anio1;

    while (true) {
        cout << "A continuación ingresará la fecha límite de la tarea" << endl;
        cout << "Ingrese el día: " << endl;
        cin >> dia1;

        cout << "Ingrese el mes: " << endl;
        cin >> mes1;

        cout << "Ingrese el año: " << endl;
        cin >> anio1;

        if (fechaValida(dia1, mes1, anio1)) {
            string fecha = to_string(dia1) + "/" + to_string(mes1) + "/" + to_string(anio1);
            task.fechaLimiteTarea = fecha;
            break;
        } else {
            cout << "Fecha no válida. Ingrese otra fecha." << endl;
        }
    }
}

bool Creador::fechaValida(int dia, int mes, int anio) {
    if (dia < 1 || dia > 31) {
        return false;
    }
    if (mes < 1 || mes > 12) {
        return false;
    }
    if (anio < 2023) {
        return false;
    }
    return true;
}
