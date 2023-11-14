#include <iostream>
#include <string>
const int TAM = 100;
using namespace std;
class alumno {
private:
    std::string nombre;
    std::string carrera;
    int materiasAprobadas;
    float promedio;
public:
    alumno() {};
    void operator=(alumno& x)
    {
        nombre = x.nombre;
        carrera = x.carrera;
        materiasAprobadas = x.materiasAprobadas;
        promedio = x.promedio;

    }
    friend std::ostream& operator<<(std::ostream& o, alumno& p) {
        o << "nombre: " << p.nombre << "\t carrera: " << p.carrera << "\t materias aprobadas: " << p.materiasAprobadas << "\t promedio: " << p.promedio << std::endl;
        return o;
    }
    friend std::istream& operator>>(std::istream& o, alumno& p)
    {
        std::cout << "\n inserta nombre: ";
        o >> p.nombre;
        std::cout << "\n inserta carrera: ";
        std::cin.ignore();
        o >> p.carrera;
        std::cout << "\n Materias aprobadas: ";
        std::cin.ignore();
        o >> p.materiasAprobadas;
        std::cout << "\n Promedio: ";
        std::cin.ignore();
        o >> p.promedio;
        return o;
    }
    bool operator==(alumno& p) {
        return p.nombre == nombre && p.carrera == carrera && p.materiasAprobadas == materiasAprobadas && p.promedio == promedio;
    }

};
class Cola {
private:
    alumno datos[TAM];
    int ult;
public:
    Cola() :ult(-1) {}
    bool vacia()const {
        if (ult == -1)
            return true;
        return false;
    }
    bool llena()const {
        if (ult == TAM - 1)
            return true;
        return false;
    }

    int ultimo()const {
        return ult;
    }
    friend std::ostream& operator<<(std::ostream& o, Cola& L) {
        int i = 0;
        std::cout << "\n";
        while (i <= L.ultimo()) {
            ;
            o << L.datos[i];
            i++;
        }
        return o;
    }

    void enqueue(alumno& elem) {
        inserta(elem, 0);
    }

    alumno& dequeue() {
        if (vacia()) {
            std::cout << "\n La cola esta vacia" << std::endl;
        }
        else {
            ult--;
            return datos[ult + 1];
        }
    }

    bool elimina(int pos) {
        if (vacia() || pos<0 || pos>ult) {
            std::cout << "\n Error de eliminacion" << std::endl;
            return true;
        }
        int i = pos;
        while (i < ult) {
            datos[i] = datos[i + 1];
            i++;
        }
        ult--;
        return false;
    }
    int inserta(alumno& elem, int pos)
    {
        if (llena() || pos<0 || pos>ult + 1) {
            std::cout << "\n Error de insercion";
            return 0;
        }
        int i = ult + 1;
        while (i > pos) {
            datos[i] = datos[i - 1];
            i--;
        }
        datos[pos] = elem;
        ult++;
        return 1;
    }

};

int main() {
    int opc, repite = 1;
    Cola solicitudCola;
    alumno datos;
    do {
        std::cout << "\t\tSOLICITUD DE CONSTANCIAS DE ALUMNOS" << std::endl;
        std::cout << "\n\n[1]. Agregar solicitud\n[2]. Solicitud completada\n[3]. Salir" << std::endl;
        std::cout << "\nOpcion: " << std::endl;
        std::cin >> opc;
        switch (opc) {
        case 1:
            std::cout << "\nIngrese los datos solicitados..." << std::endl;
            std::cin >> datos;
            solicitudCola.enqueue(datos);
            break;
        case 2:
            if (!solicitudCola.vacia()) {
                alumno solicitud = solicitudCola.dequeue();  // Quitar la solicitud de la cola.
                std::cout << "Solicitud completada: " << solicitud << std::endl;
            }
            else {
                std::cout << "La cola de solicitudes está vacía." << std::endl;
            }
            break;
        case 3:
            repite = 0;
            break;
        default:
            std::cout << "\nOPCION INVALIDA" << std::endl;
            break;
        }

    } while (repite);
    return 0;
}