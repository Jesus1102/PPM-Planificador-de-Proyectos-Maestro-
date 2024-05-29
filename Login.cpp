#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Login{

    public:
    vector <string> correos;
    vector <string> contrasenas;

    void registrarUsuario(){

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
        }
       

    }

    void iniciarSesion(){

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
                    return;
                }
            }
            cout << "Correo o contrasena incorrectos. Inténtalo de nuevo." << endl;

        }

        
        

    }

    bool validarCorreo(string correo){
        // Validar que el nombre de usuario contenga un '@'
        if (correo.find('@') == string::npos) {
            cout << "El correo debe contener un '@'. Inténtalo de nuevo." << endl;
            return;
        }
    }
    


};