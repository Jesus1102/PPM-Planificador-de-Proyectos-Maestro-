#include <iostream>
#include "Notas.h"
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
                m1.menuPrincipal();
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