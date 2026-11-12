#pragma once

namespace SGPlantaReciclajeController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SGPlantaReciclajeModel;
    using namespace SGPlantaReciclajeDAO;

    public ref class MantenimientoController {
    private:
        MantenimientoDAO^ dao;
    public:
        MantenimientoController();

        // Retorna "" si el guardado fue exitoso, o un mensaje de error.
        String^ RegistrarMantenimientoCompleto(MantenimientoCabecera^ cabecera);

        // Devuelve la lista de mantenimientos
        List<MantenimientoCabecera^>^ ListarMantenimientos();

        // Devuelve la lista de detalles
        List<MantenimientoDetalle^>^ ListarDetalles(int mantenimientoId);
    };
}