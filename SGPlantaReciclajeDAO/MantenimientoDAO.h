#pragma once
#include "BaseDAO.h"

namespace SGPlantaReciclajeDAO {
    using namespace System::Collections::Generic;
    using namespace System::Data::SqlClient;
    using namespace SGPlantaReciclajeModel;

    public ref class MantenimientoDAO : public BaseDAO {
    public:
        MantenimientoDAO();

        // Retorna el ID generado o 0 si falla
        int registrarCabecera(MantenimientoCabecera^ cabecera);

        // Retorna true si el detalle se insertó correctamente
        bool registrarDetalle(int mantenimientoId, MantenimientoDetalle^ detalle);

        // Retorna una lista con todos los mantenimientos registrados
        List<MantenimientoCabecera^>^ listarMantenimientos();

        // Retorna la lista de detalles (actividades) de un mantenimiento
        List<MantenimientoDetalle^>^ listarDetalles(int mantenimientoId);
    };
}