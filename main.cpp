#include <iostream>
#include <fstream>

using namespace std;

typedef struct propiedad {
    int idpropiead;
    char ubicacion[30];
    char tipopropiedad[2]; /* S = Solar, C = Casa, A = Apartamento, V = Villa */
    float metrossolar;
    float metrosconstruccion;
    float precio;
} propiedad;

void agregarPropiedad();
void mostrarPropiedades();

int main() {

    int option;
    while (true) {
        cout << "1. Agregar nueva propiedad" << endl;
        cout << "2. Listar propiedades" << endl;
        cout << "3. Salir" << endl;

        cin >> option;
        switch (option) {
        case 1:
            agregarPropiedad();
            break;
        case 2:
            mostrarPropiedades();
            break;
        case 3:
            cout << "Exit" << endl;
            return 0;
        default:
            cout << "Invalid option" << endl;
        }

        cout << endl;
    }

    return 0;
}


// save properties to binary file starling.txt
void agregarPropiedad() {
    propiedad propiedad = {};

    cout << "ID: ";
    cin >> propiedad.idpropiead;

    cout << "Ubicacion: ";
    cin >> propiedad.ubicacion;

    while (
        propiedad.tipopropiedad[0] != 'S' &&
        propiedad.tipopropiedad[0] != 'C' &&
        propiedad.tipopropiedad[0] != 'A' &&
        propiedad.tipopropiedad[0] != 'V'
    ) {
        cout << "Tipo de propiedad: ";
        cin >> propiedad.tipopropiedad;
    }

    cout << "Metros de solares: ";
    cin >> propiedad.metrossolar;

    cout << "Metros de construccion: ";
    cin >> propiedad.metrosconstruccion;

    cout << "Precio: ";
    cin >> propiedad.precio;


    ofstream archivo;
    archivo.open("starling.txt", ios::app);
    if (archivo.fail()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    archivo << propiedad.idpropiead << " " << propiedad.ubicacion << " " << propiedad.tipopropiedad << " "
        << propiedad.metrossolar << " " << propiedad.metrosconstruccion << " " << propiedad.precio << endl;
    archivo.close();
}

void mostrarPropiedades() {
    ifstream archivo;
    archivo.open("starling.txt", ios::in);
    if (archivo.fail()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }

    propiedad propiedad;
    while (archivo >> propiedad.idpropiead >> propiedad.ubicacion >> propiedad.tipopropiedad >> propiedad.metrossolar >>
           propiedad.metrosconstruccion >> propiedad.precio) {
        cout << "ID: " << propiedad.idpropiead << endl;
        cout << "Ubicacion: " << propiedad.ubicacion << endl;
        cout << "Tipo: " << propiedad.tipopropiedad << endl;
        cout << "Metros Solar: " << propiedad.metrossolar << endl;
        cout << "Metros Construccion: " << propiedad.metrosconstruccion << endl;
        cout << "Precio: " << propiedad.precio << endl;
        cout << endl;
    }

    archivo.close();
}
