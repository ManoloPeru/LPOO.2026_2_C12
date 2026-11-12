#pragma once

namespace SGPlantaReciclajeModel {
    using namespace System;

    public ref class Celda {
    private:
        int celdaId;            // PK (Identity en SQL)
        String^ nombre;
        String^ tipo;
        String^ estado;
        double capacidad;
        double horasOperacion;

    public:
        // ---------- CONSTRUCTORES ----------
        Celda();

        // Constructor sin ID (Útil para INSERT, SQL genera el ID)
        Celda(String^ nombre, String^ tipo, String^ estado, double capacidad, double horasOperacion);

        // Constructor completo (Útil para SELECT / UPDATE)
        Celda(int celdaId, String^ nombre, String^ tipo, String^ estado, double capacidad, double horasOperacion);

        // ---------- GETTERS Y SETTERS ----------
        int getCeldaId();
        void setCeldaId(int id);

        String^ getNombre();
        void setNombre(String^ nombre);

        String^ getTipo();
        void setTipo(String^ tipo);

        String^ getEstado();
        void setEstado(String^ estado);

        double getCapacidad();
        void setCapacidad(double capacidad);

        double getHorasOperacion();
        void setHorasOperacion(double horas);

        // ---------- MÉTODOS AUXILIARES ----------
        String^ ToString() override;
    };
}