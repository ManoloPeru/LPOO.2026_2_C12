#include "Celda.h"

using namespace SGPlantaReciclajeModel;

Celda::Celda() {
    this->celdaId = 0;
    this->nombre = "";
    this->tipo = "";
    this->estado = "";
    this->capacidad = 0.0;
    this->horasOperacion = 0.0;
}

Celda::Celda(String^ nombre, String^ tipo, String^ estado, double capacidad, double horasOperacion) {
    this->celdaId = 0;
    this->nombre = nombre;
    this->tipo = tipo;
    this->estado = estado;
    this->capacidad = capacidad;
    this->horasOperacion = horasOperacion;
}

Celda::Celda(int celdaId, String^ nombre, String^ tipo, String^ estado, double capacidad, double horasOperacion) {
    this->celdaId = celdaId;
    this->nombre = nombre;
    this->tipo = tipo;
    this->estado = estado;
    this->capacidad = capacidad;
    this->horasOperacion = horasOperacion;
}

int Celda::getCeldaId() { return celdaId; }
void Celda::setCeldaId(int id) { this->celdaId = id; }

String^ Celda::getNombre() { return nombre; }
void Celda::setNombre(String^ nombre) { this->nombre = nombre; }

String^ Celda::getTipo() { return tipo; }
void Celda::setTipo(String^ tipo) { this->tipo = tipo; }

String^ Celda::getEstado() { return estado; }
void Celda::setEstado(String^ estado) { this->estado = estado; }

double Celda::getCapacidad() { return capacidad; }
void Celda::setCapacidad(double capacidad) { this->capacidad = capacidad; }

double Celda::getHorasOperacion() { return horasOperacion; }
void Celda::setHorasOperacion(double horas) { this->horasOperacion = horas; }

String^ Celda::ToString() {
    return String::Format("[{0}] {1} | Tipo: {2} | Estado: {3} | Capacidad: {4} kg/h",
        celdaId, nombre, tipo, estado, capacidad);
}