#include <iostream>
#include <string.h>

using namespace std;
struct Login{
    string nombreUsuario;
    string usuarioRegistrado;
    string contraseñaRegistrada;
    string contraseña;

    void PedirDatos();


void PedirDatos(string usuarioRegistrado, string nombreUsuario ,string contraseñaRegistrada, string contraseña, bool f = false){
    cout << "Por favor ingresar el correo que desea registrar en PPM: " << endl;
    cin >> usuarioRegistrado;
    cout << "Por favor ingresar la contraseña que desea registrar en PPM: " << endl;
    cin >> contraseñaRegistrada;

    cout << "Ahora, por favor ingrese el correo que registro previamente: " << endl;
    cin >> nombreUsuario;
    cout << "Ahora, por favor ingrese la contraseña que registro previamente: " << endl;
    cin >> contraseña;

    if (usuarioRegistrado == nombreUsuario && contraseñaRegistrada == contraseña){
            f=true;
            if(f==true){
                cout << "Inicio de sesion exitoso... " << endl;
            }
            }
            else 
            cout << "ERROR, el usuario o contraseña son incorrectos" << endl; 
}
};
    

int main(){
    Login login;
    login.PedirDatos();



    return 0;
}