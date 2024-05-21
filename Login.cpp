#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

class Login {
public:
    string nombreUsuario;
    string usuarioRegistrado;
    string contraseñaRegistrada;
    string contraseña;
    int opcion;
    string usuarioLogueado;

    void pedirDatos();
    bool verificarUsuario();
    bool contieneAtSign(); 
    void conformarContraseña();

private:
    static vector<Login> usuarios;

    bool Login::contieneAtSign() {
        return usuarioRegistrado.find('@')!= string::npos;
    }

    bool Login::verificarUsuario() {
        for (const auto& l : usuarios) {
            if (l.nombreUsuario == usuarioRegistrado && l.contraseña == contraseña) {
                return true;
            }
        }
        return false;
    }

    void Login::pedirDatos() {
        cout << "Te damos la bienvenida a PPM, ahora digita el numero de la opcion que desees ejecutar: " << endl;
        cout << "1. Loguearse." << endl;
        cout << "2. Registrarse." << endl;
        cin >> opcion;
        if (opcion == 1) {
            cout << "Ingrese su correo: " << endl;
            cin >> usuarioLogueado;
            cout << "El correo no ha sido encontrado, por favor registrese a continuacion. " << endl;
            cout << "Por favor ingresar el correo que desea registrar en PPM: " << endl;
            cin >> usuarioRegistrado;
            cout << "Por favor ingresar la contraseña que desea registrar en PPM: " << endl;
            cin >> contraseñaRegistrada;
        } else if (opcion == 2) {
            cout << "Por favor ingresar el correo que desea registrar en PPM: " << endl;
            cin >> usuarioRegistrado;
            cout << "Por favor ingresar la contraseña que desea registrar en PPM: " << endl;
            cin >> contraseñaRegistrada;
            conformarContraseña();
            usuarios.push_back(*this); 
            cout << "Felicidades, se registro su correo y contraseña correctamente" << endl;
        }
        if (opcion == 1) {
            for (const auto& l : usuarios) {
                if (l.nombreUsuario == usuarioRegistrado && l.contraseña == contraseñaRegistrada) {
                    cout << "Inicio de sesion exitoso... Bienvenido a PPM... " << endl;
                    break;
                }
            }
        }
    }

    void Login::conformarContraseña() {
        if (contraseñaRegistrada.size() < 4) {
            cout << "ERROR: La contraseña debe tener mínimo 4 caracteres." << endl;
            return;
        }
    }
};

vector<Login> Login::usuarios;

int main() {
    Login login;
    login.usuarios.clear(); // Limpiar el vector de usuarios
    login.pedirDatos();

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
