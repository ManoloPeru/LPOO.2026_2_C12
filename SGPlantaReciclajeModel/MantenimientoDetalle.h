#pragma once

namespace SGPlantaReciclajeModel {
    using namespace System;

    public ref class MantenimientoDetalle {
    private:
        int mantenimientoDetailId;
        String^ actividad;
        int duracionMinutos;

    public:
        // ---------- CONSTRUCTORES ----------
        MantenimientoDetalle();

        // Constructor sin ID (útil para insertar en BD, ya que el ID lo genera la BD)
        MantenimientoDetalle(String^ actividad, int duracionMinutos);

        // Constructor completo
        MantenimientoDetalle(int mantenimientoDetailId, String^ actividad, int duracionMinutos);

        // ---------- GETTERS Y SETTERS ----------
        int getMantenimientoDetailId();
        void setMantenimientoDetailId(int id);

        String^ getActividad();
        void setActividad(String^ actividad);

        int getDuracionMinutos();
        void setDuracionMinutos(int duracion);

        // ---------- MÉTODOS AUXILIARES ----------
        String^ ToString() override;
    };
}