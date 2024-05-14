#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

// Función para generar un hash simple de una cadena
string generarHash(const string& input){
    int hash = 0;
    for (char c : input) {
        hash += c;
    }
    return to_string(hash);
}

struct Login {
    string nombreUsuario;
    string usuarioRegistrado;
    string contraseñaRegistrada;
    string contraseña;

    void pedirDatos();
    bool verificarUsuario();
    bool contieneAtSign(); 
    void conformarContraseña();

    bool Login::contieneAtSign() {
        return usuarioRegistrado.find('@')!= string::npos; 
    }

    bool Login::verificarUsuario() {
        
        static vector<Login> usuarios = {{nombreUsuario, contraseñaRegistrada}};
        for (const auto& l : usuarios) {
            if (l.nombreUsuario == usuarioRegistrado && l.contraseña == contraseña) {
                return true;
            }
        }
        return false;
    }

    void Login::pedirDatos() {
        cout << "Por favor ingresar el correo que desea registrar en PPM: " << endl;
        cin >> usuarioRegistrado;
        cout << "Por favor ingresar la contraseña que desea registrar en PPM: " << endl;
        cin >> contraseñaRegistrada;

        cout << "Ahora, por favor ingrese el correo que registro previamente: " << endl;
        cin >> nombreUsuario;
        cout << "Ahora, por favor ingrese la contraseña que registro previamente: " << endl;
        cin >> contraseña;

        
        if (nombreUsuario == usuarioRegistrado && contraseña == contraseñaRegistrada) {
            cout << "Inicio de sesion exitoso... Bienvenido a PPM... " << endl;
        } else {
            cout << "ERROR, el usuario o contraseña son incorrectos" << endl;
        }
    }

    void Login::conformarContraseña() {
        if(strlen(contraseñaRegistrada.c_str()) < 4) {
            cout << "ERROR: La contraseña debe tener mínimo 4 caracteres." << endl;
            return; 
        }
    }
};

int main() {
    Login login;
    login.pedirDatos();
    login.conformarContraseña();

    // Verificar si el usuarioRegistrado contiene "@"
    if (login.contieneAtSign()) {
        cout << "El usuario registrado contiene '@'" << endl;
    } else {
        cout << "El usuario registrado NO contiene '@'" << endl;
    }

    // Verificar si el usuario existe
    bool usuarioExiste = login.verificarUsuario();
    if (usuarioExiste) {
        cout << "Inicio de sesión exitoso." << endl;
    } else {
        cout << "Error: Usuario o contraseña incorrectos." << endl;
    }

    return 0;
}
