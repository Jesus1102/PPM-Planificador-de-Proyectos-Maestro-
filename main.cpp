#include <iostream>

#include "Mostrador.h"
#include "Asignador.h"
#include "Creador.h"
#include "colors.h"
#include "Login.h"

using namespace std;


int main(){

    Login l;
    Mostrador m;
    Creador c;
    Asignador a;

    int opcion;

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
                        c.crearTarea();
                    }
                    if(opcion == 2){
                        a.responsablesTarea();
                    }
                    if(opcion == 3){
                        a.cambiarEstadoTarea();
                    }
                    if(opcion == 4){
                      
                    }
                    if(opcion == 5){
                        cout << "Gracias por usar el sistema de gestión de proyectos" << endl;
                        return 0;
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
            return 0;
        }

    }

}