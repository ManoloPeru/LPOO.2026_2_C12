#include "MantenimientoController.h"

namespace SGPlantaReciclajeController {

    MantenimientoController::MantenimientoController() {
        dao = gcnew MantenimientoDAO();
    }

    String^ MantenimientoController::RegistrarMantenimientoCompleto(MantenimientoCabecera^ cabecera) {
        // Validaciones básicas
        if (cabecera == nullptr) return "La cabecera es nula.";
        if (cabecera->getActividades()->Count == 0) return "Debe agregar al menos una actividad al mantenimiento.";

        try {
            // 1. Iniciar transacción
            dao->iniciarTransaccion();

            // 2. Insertar Cabecera
			// El método registrarCabecera devuelve el ID generado o 0 si falla
            int idMantenimiento = dao->registrarCabecera(cabecera);
            if (idMantenimiento <= 0) {
                throw gcnew Exception("No se pudo obtener el ID generado de la cabecera.");
            }

            // 3. Insertar Detalles Iterativamente
            for each (MantenimientoDetalle ^ detalle in cabecera->getActividades()) {
				// Insertar cada detalle asociado al mantenimiento
                bool exito = dao->registrarDetalle(idMantenimiento, detalle);
				// Si falla la inserción de algún detalle, lanzamos excepción para hacer rollback
                if (!exito) {
                    throw gcnew Exception("Error al registrar la actividad: " + detalle->getActividad());
                }
            }

            // 4. Si todo salió bien, confirmar
            dao->confirmarTransaccion();

            // Asignamos el ID generado al objeto para que la vista lo use si lo necesita
            cabecera->setMantenimientoId(idMantenimiento);
            return "";
        }
        catch (Exception^ ex) {
            // 5. Si algo falla, revertir los cambios
            dao->revertirTransaccion();
            return "Error al guardar el mantenimiento: " + ex->Message;
        }
    }

    List<MantenimientoCabecera^>^ MantenimientoController::ListarMantenimientos() {
        return dao->listarMantenimientos();
    }

    List<MantenimientoDetalle^>^ MantenimientoController::ListarDetalles(int mantenimientoId) {
        return dao->listarDetalles(mantenimientoId);
    }
}