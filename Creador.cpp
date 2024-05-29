#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <windows.h>

#define color SetConsoleTextAttribute

using namespace std;

struct Proyecto1{
    
    string nombreProy;
    string propietarioProy;
    string estadoProy;
    string descripcionProy;

};

struct Tarea1{

    string nombreTarea;
    string estadoTarea;
    string prioridadTarea;
    string responsableTarea;
    string fechaLimiteTarea;
    string resumenTarea;

}; 

class Creador{

    public:
    Proyecto1 pro;
    Tarea1 task;
    set <Proyecto1> proyecGenerales;
    set <Tarea1> tareasGenerales;
    map <string, set<Tarea1>> proyecTareas;
    int color1 [4] = {4,12,14,10};
    vector <string> estado = {"Pendiente", "En Proceso", "Terminada"};
    

    

    void crearProyecto(){

        cout << "Ingrese el nombre del Proyecto: " << endl;
        cin >> pro.nombreProy;


        cout << "Ingrese el propietario del Proytecto: " << endl;
        cin >> pro.propietarioProy;

        pro.estadoProy = definirEstado();;

        cout << "Ingrese la descripcion del Proyecto: " << endl;
        cin >> pro.descripcionProy;

        proyecGenerales.insert(pro);

    }

    void crearTarea(){

        cout << "Ingrese el nombre de la Tarea: " << endl;
        cin >> task.nombreTarea;

        task.estadoTarea = definirEstado();

        prioTarea();

        cout << "Ingrese el responsable de la Tarea: " << endl;
        cin >> task.responsableTarea;

        limiteFecha();

        cout << "Ingrese el resumen(comentarios) de la Tarea: " << endl;
        cin >> task.resumenTarea;

        tareasGenerales.insert(task);

    }

    void prioTarea(){

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        string prioridad [4] = {"Urgente","Alta","Media","Baja"};
        int opc;

        for(int i = 0; i < 4; i++){

            color(hConsole, color1[i]);
            cout << to_string(i+1) << prioridad[i] << endl;

        }

        cout << "Ingrese la prioridad de la tarea: " << endl;
        cin >> opc;
        opc--;

        task.prioridadTarea = prioridad[opc];

    }

    string definirEstado(){

        int opcion;
        string opEstado;

        while (true){

            cout << "1. para crear un estado " << endl << "2. para asignar un estado" << endl; 
            cin >> opcion;

            if(opcion == 1){
                    
                cout << "Los estados disponibles son: " << endl;
                for(int i = 0; i < estado.size(); i ++){

                    cout << to_string(i+1) << estado[i] << endl;

                }
                cout << "Ingrese el nuevo estado" << endl;
                cin >> opEstado;

                estado.push_back(opEstado); 

            }
            if(opcion == 2){
                int opcion1;
                cout << "Los estados disponibles son: " << endl;
                for(int i = 0; i < estado.size(); i ++){

                    cout << to_string(i+1) << estado[i] << endl;

                }
                cout << "Ingrese el estado de la tarea/proyecto" << endl;
                cin >> opcion1;
                return estado[opcion1-1];
                
            }

        }

    }

    void limiteFecha(){

        int dia1, mes1, anio1;

        while(true){

            cout << "A continuacion ingresara la fecha limite de la tarea " << endl;
            cout << "Ingrese el dia" << endl;
            cin >> dia1;

            cout << "Ingrese el mes" << endl;
            cin >> mes1;

            cout << "Ingrese el anio" << endl;
            cin >> anio1;

            if(fechaValida(dia1, mes1, anio1)){

                string fecha = to_string(dia1) + "/" + to_string(mes1) + "/" + to_string(anio1);
                task.fechaLimiteTarea = fecha;

            }
            else{
                
                cout << "Fecha no valida" << endl;
                cout << "Ingrese otra fecha" << endl;
            }

        }

    }


    bool fechaValida(int dia, int mes, int anio){
        
        if (dia < 1 || dia > 31)
        {
            return false;
        }
        
        if (mes < 1 || mes > 12)
        {
            return false;
        }
        
        if (anio < 2023)
        {
            return false;
        }
        
        return true;
    }

};