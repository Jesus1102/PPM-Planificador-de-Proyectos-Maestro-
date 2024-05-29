#include <iostream>

#include "Mostrador.h"
#include "Asignador.h"
#include "Creador.h"
#include "colors.h"
#include "Login.h"
#include "Menus.cpp"

using namespace std;


int main(){

    Menu m1;
    Login l;

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
                        m1.menuCrear();
                    }
                    if(opcion == 2){
                        m1.menuMostrar();
                    }
                    if(opcion == 3){
                        m1.menuAsignar();
                    }
                    if(opcion == 4){
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