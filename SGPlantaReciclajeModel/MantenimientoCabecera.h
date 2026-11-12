#pragma once

#include "MantenimientoDetalle.h" // Incluimos la clase detalle

namespace SGPlantaReciclajeModel {
    using namespace System;
    using namespace System::Collections::Generic; // Para usar List<>

    public ref class MantenimientoCabecera {
    private:
        int mantenimientoId;
        int estacionId;
        String^ tecnico;
        String^ tipoMantenimiento;
        DateTime fechaMantenimiento;
        List<MantenimientoDetalle^>^ actividades;

    public:
        // ---------- CONSTRUCTORES ----------
        MantenimientoCabecera();

        // Constructor sin ID (útil para insertar en BD)
        MantenimientoCabecera(int estacionId, String^ tecnico, String^ tipoMantenimiento, DateTime fechaMantenimiento);

        // Constructor completo (útil para lectura de BD)
        MantenimientoCabecera(int mantenimientoId, int estacionId, String^ tecnico, String^ tipoMantenimiento, DateTime fechaMantenimiento);

        // ---------- GETTERS Y SETTERS ----------
        int getMantenimientoId();
        void setMantenimientoId(int id);

        int getEstacionId();
        void setEstacionId(int id);

        String^ getTecnico();
        void setTecnico(String^ tecnico);

        String^ getTipoMantenimiento();
        void setTipoMantenimiento(String^ tipo);

        DateTime getFechaMantenimiento();
        void setFechaMantenimiento(DateTime fecha);

        List<MantenimientoDetalle^>^ getActividades();
        void setActividades(List<MantenimientoDetalle^>^ listaActividades);

        // ---------- MÉTODOS AUXILIARES ----------
        void agregarActividad(MantenimientoDetalle^ detalle);
        String^ ToString() override;
    };
}