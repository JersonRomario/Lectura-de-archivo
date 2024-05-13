#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
int main() {
    std::string nombreArchivoEntrada = "notas.txt";
    std::string nombreArchivoSalida = "promedio.txt";
    std::ifstream archivoEntrada(nombreArchivoEntrada.c_str());
    std::ofstream archivoSalida(nombreArchivoSalida.c_str());
    if (!archivoEntrada.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivoEntrada << std::endl;
        return 1;
    }
    if (!archivoSalida.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivoSalida << std::endl;
        return 1;
    }
    double suma = 0.0;
    int cantidadDatos = 0;
    std::string nota;
    int numeronota = 1;
    archivoSalida << "Datos del archivo:\n" << std::endl;
    while (std::getline(archivoEntrada, nota)) {
        std::istringstream ss(nota);
        double valor;
        archivoSalida << "Nota " << numeronota << ": " << nota << std::endl;
        while (ss >> valor) {
            suma += valor;
            cantidadDatos++;
        }
        numeronota++;
    }
    archivoEntrada.close();
    if (cantidadDatos > 0) {
        double promedio = suma / cantidadDatos;
        archivoSalida << "\nEl promedio de las notas es: " << promedio << std::endl;
    } else {
        archivoSalida << "No se encontraron datos en el archivo." << std::endl;
    }
    archivoSalida.close();
    std::cout << "Se ha generado el archivo '" << nombreArchivoSalida << "' con el listado de datos y el promedio." << std::endl;
    return 0;
}
