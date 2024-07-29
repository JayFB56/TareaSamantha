#include <iostream>
#include <iomanip> // para setw
#include <cstring> // para strcmp
using namespace std;

const int MAX = 15; // máximo de roles de pago por gestionar
const int MAX_CHARS = 50; // máximo de caracteres para nombres y apellidos

// Definición de la estructura para los roles de pago
struct RolPago {
    char cedula[9]; // incluye espacio para el formato "08xxxxxx" + '\0'
    char apellidos[MAX_CHARS];
    char nombres[MAX_CHARS];
    int ingresos;
    int egresos;
    int total;
};

// Funciones para la gestión de roles de pago

// Función para imprimir los detalles de un rol de pago
void ImprimirRolPago(RolPago rol) {
    cout << endl << "Cedula: " << rol.cedula;
    cout << endl << "Apellidos: " << rol.apellidos;
    cout << endl << "Nombres: " << rol.nombres;
    cout << endl << "Ingresos: " << rol.ingresos;
    cout << endl << "Egresos: " << rol.egresos;
    cout << endl << "Total: " << rol.total;
}

// Función para listar todos los roles de pago
void ListarRolesPago(RolPago roles[], int total) {
    cout << endl << "/////// LISTA DE ROLES DE PAGO ///////";
    for (int i = 0; i < total; ++i) {
        ImprimirRolPago(roles[i]);
    }
}

// Función para buscar un rol de pago por número de cédula
void BuscarPorCedula(RolPago roles[], int total, char cedulaBuscada[]) {
    bool encontrado = false;
    for (int i = 0; i < total; ++i) {
        if (strcmp(roles[i].cedula, cedulaBuscada) == 0) {
            ImprimirRolPago(roles[i]);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << endl << "No se encontró ningún rol de pago con la cédula proporcionada.";
    }
}

// Función para ordenar los roles de pago por apellidos (orden ascendente)
void OrdenarPorApellidos(RolPago roles[], int total) {
    for (int i = 0; i < total - 1; ++i) {
        for (int j = i + 1; j < total; ++j) {
            if (strcmp(roles[i].apellidos, roles[j].apellidos) > 0) {
                swap(roles[i], roles[j]);
            }
        }
    }
}

// Función para ordenar los roles de pago por ingresos de mayor a menor
void OrdenarPorIngresosDesc(RolPago roles[], int total) {
    for (int i = 0; i < total - 1; ++i) {
        for (int j = i + 1; j < total; ++j) {
            if (roles[i].ingresos < roles[j].ingresos) {
                swap(roles[i], roles[j]);
            }
        }
    }
}

// Función para formatear la cédula a "08xxxxxx"
void FormatearCedula(char cedula[]) {
    // Asumiendo que la cédula ingresada es válida y tiene 8 dígitos
    char cedulaFormateada[9];
    strncpy(cedulaFormateada, "08", 2); // Inicializa con "08"
    strncpy(cedulaFormateada + 2, cedula, 6); // Copia los 6 dígitos de la cédula original
    cedulaFormateada[8] = '\0'; // Terminador nulo al final
    strncpy(cedula, cedulaFormateada, 9); // Copia la cédula formateada de vuelta al arreglo original
}

int main() {
    RolPago roles[MAX];
    int totalRoles = 0; // contador de roles de pago ingresados

    // Ejemplo de datos predefinidos para pruebas
    char cedula1[] = "123456";
    char cedula2[] = "654321";

    // Formatear las cédulas según el formato "08xxxxxx"
    FormatearCedula(cedula1);
    FormatearCedula(cedula2);

    strcpy(roles[0].cedula, cedula1);
    strcpy(roles[0].apellidos, "Perez");
    strcpy(roles[0].nombres, "Juan");
    roles[0].ingresos = 5000;
    roles[0].egresos = 2000;
    roles[0].total = 3000;

    strcpy(roles[1].cedula, cedula2);
    strcpy(roles[1].apellidos, "Gomez");
    strcpy(roles[1].nombres, "Maria");
    roles[1].ingresos = 6000;
    roles[1].egresos = 2500;
    roles[1].total = 3500;

    totalRoles = 2;

    int opcion;
    char cedulaBusqueda[9];

    do {
        cout << endl << "MENU DE OPCIONES";
        cout << endl << "1. Ingreso";
        cout << endl << "2. Listado de roles de pago";
        cout << endl << "3. Buscar un rol de pago por número de cedula";
        cout << endl << "4. Ordenar por apellidos";
        cout << endl << "5. Ordenar por ingresos de mayor a menor";
        cout << endl << "6. Salir";
        cout << endl << "Ingrese la opción deseada: ";
        cin >> opcion;
        cin.ignore(); // limpiar el buffer de entrada

        switch (opcion) {
            case 1:
                // Aquí se puede implementar la función para ingresar un nuevo rol de pago
                break;
            case 2:
                ListarRolesPago(roles, totalRoles);
                break;
            case 3:
                cout << "Ingrese el número de cédula a buscar: ";
                cin.getline(cedulaBusqueda, 9);
                FormatearCedula(cedulaBusqueda);
                BuscarPorCedula(roles, totalRoles, cedulaBusqueda);
                break;
            case 4:
                OrdenarPorApellidos(roles, totalRoles);
                cout << endl << "Roles de pago ordenados por apellidos:";
                ListarRolesPago(roles, totalRoles);
                break;
            case 5:
                OrdenarPorIngresosDesc(roles, totalRoles);
                cout << endl << "Roles de pago ordenados por ingresos (de mayor a menor):";
                ListarRolesPago(roles, totalRoles);
                break;
            case 6:
                cout << endl << "Saliendo del programa...";
                break;
            default:
                cout << endl << "Opción no válida. Por favor, ingrese una opción válida.";
        }
    } while (opcion != 6);

    return 0;
}
