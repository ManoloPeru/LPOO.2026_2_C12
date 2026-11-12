#pragma once

#include "BaseDAO.h"

namespace SGPlantaReciclajeDAO {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace System::Data::SqlClient;
    using namespace SGPlantaReciclajeModel;

    public ref class CeldaDAO : public BaseDAO {
    public:
        CeldaDAO();

		// ============================================================
        // CRUD SQL
        // ============================================================
        List<Celda^>^ listarCeldas();
        Celda^ consultarCelda(int celdaId);
        int agregarCelda(Celda^ celda); // Retorna el ID generado o 0 si falla
        bool modificarCelda(Celda^ celda);
        bool eliminarCelda(int celdaId);

        // ============================================================
        // Stored Procedures
        // ============================================================
        List<Celda^>^ listarCeldasSP();
        int agregarCeldaSP(Celda^ celda);
        bool modificarCeldaSP(Celda^ celda);
        bool eliminarCeldaSP(int celdaId);
    };
}