#include "Login.h"



bool  Login::registrarUsuario(){

    string correo;
    string contrasena;

    cout << "Ingrese el correo: " << endl;
    cin >> correo;
    
    if(validarCorreo(correo) == false){
        cout << "Correo invalido. Inténtalo de nuevo." << endl;

    }
    else{
        cout << "Ingrese la contrasena: " << endl;
        cin >> contrasena;
        correos.push_back(correo);
        contrasenas.push_back(contrasena);
        cout << "Usuario registrado" << endl;
        return true;    
    }

    return false;
}

bool Login::iniciarSesion(){

    string correo;
    string contrasena;

    cout << "Ingrese el correo: " << endl;
    cin >> correo;
    if(validarCorreo(correo) == false){
        cout << "Correo invalido. Inténtalo de nuevo." << endl;
    }
    else{
        cout << "Ingrese la contrasena: " << endl;
        cin >> contrasena;
        for(int i = 0; i < correos.size(); i++){

            if(correo == correos[i] && contrasena == contrasenas[i]){
                cout << "Sesion iniciada" << endl;
                return true;
            }
        }
        cout << "Correo o contrasena incorrectos. Inténtalo de nuevo." << endl;
    }
    return false;

}

bool Login::validarCorreo(string correo){
    // Validar que el nombre de usuario contenga un '@'
    if (correo.find('@') == string::npos) {
        cout << "El correo debe contener un '@'. Inténtalo de nuevo." << endl;
        return false;
    }
    return true;
}
