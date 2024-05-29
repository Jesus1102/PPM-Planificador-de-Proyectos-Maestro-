#include "Creador.cpp"                    /*Jesus.*/
#include "Login.cpp"                      /*Cristian.*/
#include "Mostrador.cpp"                  /*Jesus.*/
#include "Mostrar_proyecto_por_fecha.cpp" /*Cristian.*/
#include "Notas.cpp"                      /*Samuel.*/
#include "Union.cpp"                      /*Cristian.*/

using namespace std;

int main()
{
    Creador creador;
    Login login;
    Mostrador mostrador;
    Proyecto proyecto;
    Notas notas;
    Tarea un1on;

    int opcion;

    login.pedirDatos();

    bool usuarioExiste = login.verificarUsuario();

    if (usuarioExiste)
    {
        cout << "Inicio de sesion exitoso." << endl;
        cout << "Bienvenido a PPM.\nPor favor, seleccione una opcion:" << endl;
        cout << "1. Proyectos." << endl;
        cout << "2. Tareas." << endl;
        cout << "3. Notas." << endl;
        cout << "4. Salir." << endl;
        cin >> opcion;

        while (opcion != 0)
        {
            switch (opcion)
            {
            case 1:
                cout << "Por favor, seleccione una opcion:" << endl;
                cout << "1. Crear un proyecto." << endl;
                cout << "2. Mostar proyectos." << endl;
                cout << "3. Mostrar proyectos por fechas." << endl;
                cout << "4. Mostrar proyectos disponibles." << endl;
                cin >> opcion;
                switch (opcion)
                {
                case 1:
                    creador.crearProyecto();
                    break;
                case 2:
                    mostrador.mostrarProyectos();
                    break;
                case 3:
                    proyecto.mostrarProyectoPorFecha();
                    break;
                case 4:
                    mostrador.proyectosDisponibles();
                    break;
                break;
                }
            case 2:
                cout << "1. Crear tareas." << endl;
                cout << "2. Mostrar tareas de proyectos." << endl;
                cin >> opcion;
                switch (opcion)
                {
                case 1:
                    creador.crearTarea();
                    break;
                case 2:
                    mostrador.mostrarTareasProyectos();
                    break;
                break;
                }
            case 3:
                cout << "1. Crear notas." << endl;
                cout << "2. Mostrar notas." << endl;
                cout << "3. Reaccionar a notas." << endl;
                cin >> opcion;
                switch (opcion)
                {
                case 1:
                    notas.crearNota();
                    break;
                case 2:
                    notas.mostrarNotas();
                    break;
                case 3:
                    notas.reaccionarNota();
                    break;
                break;
                }
            case 4:
                cout << "Gracias por usar PPM." << endl;
                break;
            default:
                cout << "Error: Opción inválida." << endl;
                break;
            }
        }
    }
    else
    {
        cout << "Error: Usuario o contraseña incorrectos." << endl;
    }

    return 0;
}