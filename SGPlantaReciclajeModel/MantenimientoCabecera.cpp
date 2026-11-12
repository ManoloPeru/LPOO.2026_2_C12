#include "MantenimientoCabecera.h"

using namespace SGPlantaReciclajeModel;

MantenimientoCabecera::MantenimientoCabecera() {
    this->mantenimientoId = 0;
    this->estacionId = 0;
    this->tecnico = "";
    this->tipoMantenimiento = "";
    this->fechaMantenimiento = DateTime::Now;
    this->actividades = gcnew List<MantenimientoDetalle^>();
}

MantenimientoCabecera::MantenimientoCabecera(int estacionId, String^ tecnico, String^ tipoMantenimiento, DateTime fechaMantenimiento) {
    this->mantenimientoId = 0;
    this->estacionId = estacionId;
    this->tecnico = tecnico;
    this->tipoMantenimiento = tipoMantenimiento;
    this->fechaMantenimiento = fechaMantenimiento;
    this->actividades = gcnew List<MantenimientoDetalle^>(); // Inicializamos la lista vacía
}

MantenimientoCabecera::MantenimientoCabecera(int mantenimientoId, int estacionId, String^ tecnico, String^ tipoMantenimiento, DateTime fechaMantenimiento) {
    this->mantenimientoId = mantenimientoId;
    this->estacionId = estacionId;
    this->tecnico = tecnico;
    this->tipoMantenimiento = tipoMantenimiento;
    this->fechaMantenimiento = fechaMantenimiento;
    this->actividades = gcnew List<MantenimientoDetalle^>(); // Inicializamos la lista vacía
}

int MantenimientoCabecera::getMantenimientoId() { return mantenimientoId; }
void MantenimientoCabecera::setMantenimientoId(int id) { this->mantenimientoId = id; }

int MantenimientoCabecera::getEstacionId() { return estacionId; }
void MantenimientoCabecera::setEstacionId(int id) { this->estacionId = id; }

String^ MantenimientoCabecera::getTecnico() { return tecnico; }
void MantenimientoCabecera::setTecnico(String^ tecnico) { this->tecnico = tecnico; }

String^ MantenimientoCabecera::getTipoMantenimiento() { return tipoMantenimiento; }
void MantenimientoCabecera::setTipoMantenimiento(String^ tipo) { this->tipoMantenimiento = tipo; }

DateTime MantenimientoCabecera::getFechaMantenimiento() { return fechaMantenimiento; }
void MantenimientoCabecera::setFechaMantenimiento(DateTime fecha) { this->fechaMantenimiento = fecha; }

List<MantenimientoDetalle^>^ MantenimientoCabecera::getActividades() { return actividades; }
void MantenimientoCabecera::setActividades(List<MantenimientoDetalle^>^ listaActividades) {
    this->actividades = listaActividades;
}

// Método de conveniencia para agregar detalles sin tener que acceder directamente a la lista
void MantenimientoCabecera::agregarActividad(MantenimientoDetalle^ detalle) {
    if (detalle != nullptr) {
        this->actividades->Add(detalle);
    }
}

String^ MantenimientoCabecera::ToString() {
    return String::Format("[{0}] Estación: {1} | Técnico: {2} | Tipo: {3} | Fecha: {4} | Actividades: {5}",
        mantenimientoId, estacionId, tecnico, tipoMantenimiento, fechaMantenimiento.ToString("dd/MM/yyyy HH:mm"), actividades->Count);
}