#include <iostream>

#include "Mostrador.h"
#include "Asignador.h"
#include "Creador.h"
#include "colors.h"
#include "Login.h"

using namespace std;

class Menu{
    Login l;
    Mostrador m;
    Creador c;
    Asignador a;
    int opcion;
    public:
    void menuPrincipal(){
        while(true){
            cout << "Bienvenido al sistema de gestión de proyectos"<< endl;
            cout << "Por favor, inicie sesión ó registrese" << endl;
            cout << "1. Iniciar sesión" << endl << "2. Registrarse" << endl << "3. Salir" << endl;

            cin >> opcion;

            if(opcion == 1){
                if(l.iniciarSesion() == true){
                    cout << "Sesión iniciada" << endl;
                    while(true){
                        cout << "1. Crear " << endl << "2. Mostrar" << endl << "3. Asignar" << endl << "4. Salir" << endl;
                        cin >> opcion;
                        if(opcion == 1){
                            menuCrear();
                        }
                        if(opcion == 2){
                            menuMostrar();
                        }
                        if(opcion == 3){
                            a.cambiarEstadoTarea();
                        }
                        if(opcion == 4){
                            cout << "Gracias por usar el sistema de gestión de proyectos" << endl;
                            return;
                        }
                    }
                }
                break;
            }
            if(opcion == 2){
                l.registrarUsuario();
                
            }
            if(opcion == 3){
                cout << "Gracias por usar el sistema de gestión de proyectos" << endl;
                return;
            }
        }
    }


    void menuCrear(){
        while (true)
        {
            cout << "1. Crear Proyecto " << endl << "2. Crear Tarea" << endl << "3. Salir" << endl ;
            cin >> opcion;
            if(opcion == 1){
                c.crearProyecto();
            }
            if(opcion == 2){
                c.crearTarea();
            }
            if(opcion == 3){
                break;
            }
        
        }

    }

    void menuMostrar(){
        while (true)
        {
            cout << "1. Mostrar Proyectos con Detalles" << endl << "2. Mostrar Tareas de Proyectos" << endl << "3. Mostrar proyectos disponibles, para ver las tareas" << endl << "4. Mostrar Responsables de Tarea" << endl << "5. Mostrar Tareas por Prioridad" << endl << "6. Salir" << endl;
            cin >> opcion;
            if(opcion == 1){
                m.mostrarProyectos();
            }
            if(opcion == 2){
                string nombreProyecto;
                cout << "Ingrese el nombre del proyecto: " << endl;
                cin >> nombreProyecto;
                m.mostrarTareasProyectos(nombreProyecto);
            }
            if(opcion == 3){
                m.mostrarTareasProyectos(m.proyectosDisponibles());
            }
            if (opcion == 4){
                m.mostrarResponsablesTarea();
            }
            if(opcion == 5){
                m.imprimirTareasPorPrioridad();
            }
            if (opcion == 6)
            {
                break;
            }
            
        
        }
    }

    void menuAsignar(){
        while (true)
        {
            cout << "1. Asignar Tarea a Proyecto" << endl << "2. Asignar Responsable a Tarea" << endl << "3. Cambiar Estado de Tarea" << endl << "4. Salir" << endl;
            cin >> opcion;
            if(opcion == 1){
                cout << "Ingrese el nombre del proyecto: " << endl;
                string nombreProyecto;
                cin >> nombreProyecto;
                a.asignarTarea(nombreProyecto);
            }
            if(opcion == 2){
                a.responsablesTarea();
            }
            if(opcion == 3){
                a.cambiarEstadoTarea();
            }
            if(opcion == 4){
                break;
            }
        
        }
    }

};