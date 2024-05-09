#include <iostream>
#include <string>

using namespace std;

struct Login {
    string nombreUsuario;
    string usuarioRegistrado;
    string contraseñaRegistrada;
    string contraseña;

    void pedirDatos();
};

void Login::pedirDatos() {
    cout << "Por favor ingresar el correo que desea registrar en PPM: " << endl;
    cin >> usuarioRegistrado;
    cout << "Por favor ingresar la contraseña que desea registrar en PPM: " << endl;
    cin >> contraseñaRegistrada;

    cout << "Ahora, por favor ingrese el correo que registro previamente: " << endl;
    cin >> nombreUsuario;
    cout << "Ahora, por favor ingrese la contraseña que registro previamente: " << endl;
    cin >> contraseña;

    // Convertir a minúsculas para comparación insensible a mayúsculas y minúsculas
    if (nombreUsuario == usuarioRegistrado && contraseña == contraseñaRegistrada) {
        cout << "Inicio de sesion exitoso... Bienvenido a PPM... " << endl;
    } else {
        cout << "ERROR, el usuario o contraseña son incorrectos" << endl;
    }
}

int main() {
    Login login;
    login.pedirDatos();

    return 0;
}
