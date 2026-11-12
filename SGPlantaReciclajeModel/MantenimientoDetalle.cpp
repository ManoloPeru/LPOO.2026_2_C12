#include "MantenimientoDetalle.h"

using namespace SGPlantaReciclajeModel;

MantenimientoDetalle::MantenimientoDetalle() {
    this->mantenimientoDetailId = 0;
    this->actividad = "";
    this->duracionMinutos = 0;
}

MantenimientoDetalle::MantenimientoDetalle(String^ actividad, int duracionMinutos) {
    this->mantenimientoDetailId = 0;
    this->actividad = actividad;
    this->duracionMinutos = duracionMinutos;
}

MantenimientoDetalle::MantenimientoDetalle(int mantenimientoDetailId, String^ actividad, int duracionMinutos) {
    this->mantenimientoDetailId = mantenimientoDetailId;
    this->actividad = actividad;
    this->duracionMinutos = duracionMinutos;
}

int MantenimientoDetalle::getMantenimientoDetailId() { return mantenimientoDetailId; }
void MantenimientoDetalle::setMantenimientoDetailId(int id) { this->mantenimientoDetailId = id; }

String^ MantenimientoDetalle::getActividad() { return actividad; }
void MantenimientoDetalle::setActividad(String^ actividad) { this->actividad = actividad; }

int MantenimientoDetalle::getDuracionMinutos() { return duracionMinutos; }
void MantenimientoDetalle::setDuracionMinutos(int duracion) { this->duracionMinutos = duracion; }

String^ MantenimientoDetalle::ToString() {
    return String::Format("[{0}] {1} | Duración: {2} min",
        mantenimientoDetailId, actividad, duracionMinutos);
}