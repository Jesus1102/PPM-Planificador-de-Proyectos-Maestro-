#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;


class Login{

    public:
    vector <string> correos;
    vector <string> contrasenas;

    bool registrarUsuario();
    bool iniciarSesion();
    bool validarCorreo(string correo);
    


};

#endif // lOGIN_H