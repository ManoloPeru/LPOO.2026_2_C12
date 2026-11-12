#pragma once

namespace SGPlantaReciclajeController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SGPlantaReciclajeModel;
    using namespace SGPlantaReciclajeDAO;

    public ref class CeldaController {
    private:
        CeldaDAO^ dao;

    public:
        CeldaController();
		// Métodos para trabajar con SQL CRUD
        List<Celda^>^ ListarCeldas();
        Celda^ ConsultarCelda(int celdaId);
        String^ AgregarCelda(Celda^ celda);
        String^ ModificarCelda(Celda^ celda);
        String^ EliminarCelda(int celdaId);

		// Métodos para trabajar con Stored Procedures
        List<Celda^>^ ListarCeldasSP();
        String^ AgregarCeldaSP(Celda^ celda);
        String^ ModificarCeldaSP(Celda^ celda);
        String^ EliminarCeldaSP(int celdaId);
    };
}