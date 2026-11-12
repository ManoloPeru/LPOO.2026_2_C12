#include "CeldaController.h"

namespace SGPlantaReciclajeController {

    CeldaController::CeldaController() {
        dao = gcnew CeldaDAO();
    }
	
    // Métodos para trabajar con SQL CRUD
    List<Celda^>^ CeldaController::ListarCeldas() {
        return dao->listarCeldas();
    }

    Celda^ CeldaController::ConsultarCelda(int celdaId) {
        if (celdaId <= 0) {
            // Si el ID no es válido, devolvemos null inmediatamente
            return nullptr;
        }
        return dao->consultarCelda(celdaId);
    }

    String^ CeldaController::AgregarCelda(Celda^ celda) {
        // Validaciones de negocio
        if (celda == nullptr) return "La celda es nula.";
        if (String::IsNullOrWhiteSpace(celda->getNombre())) return "El nombre es obligatorio.";
        if (String::IsNullOrWhiteSpace(celda->getTipo())) return "El tipo es obligatorio.";
        if (String::IsNullOrWhiteSpace(celda->getEstado())) return "El estado es obligatorio.";
        if (celda->getCapacidad() <= 0) return "La capacidad debe ser mayor a 0.";
        if (celda->getHorasOperacion() <= 0) return "Las horas de operación deben ser mayor a 0.";
        int idGenerado = dao->agregarCelda(celda);
        if (idGenerado > 0) {
            // Asignamos el ID generado al objeto por si se necesita después
            celda->setCeldaId(idGenerado);
            return "";
        }
        return "Ocurrió un error al agregar la celda en la base de datos.";
    }

    String^ CeldaController::ModificarCelda(Celda^ celda) {
        if (celda == nullptr) return "La celda es nula.";
        if (celda->getCeldaId() <= 0) return "El ID de la celda no es válido.";
        if (String::IsNullOrWhiteSpace(celda->getNombre())) return "El nombre es obligatorio.";
        if (celda->getCapacidad() <= 0) return "La capacidad debe ser mayor a 0.";
        if (celda->getHorasOperacion() <= 0) return "Las horas de operación deben ser mayor a 0.";
        bool exito = dao->modificarCelda(celda);
        return exito ? "" : "Ocurrió un error al modificar la celda en la base de datos.";
    }

    String^ CeldaController::EliminarCelda(int celdaId) {
        if (celdaId <= 0) return "El ID de la celda no es válido.";

        bool exito = dao->eliminarCelda(celdaId);
        return exito ? "" : "Ocurrió un error al eliminar la celda en la base de datos.";
    }

    List<Celda^>^ CeldaController::ListarCeldasSP() {
        return dao->listarCeldasSP();
    }

	// Métodos para trabajar con Stored Procedures
    String^ CeldaController::AgregarCeldaSP(Celda^ celda) {
        // Validaciones de negocio
        if (celda == nullptr) return "La celda es nula.";
        if (String::IsNullOrWhiteSpace(celda->getNombre())) return "El nombre es obligatorio.";
        if (String::IsNullOrWhiteSpace(celda->getTipo())) return "El tipo es obligatorio.";
        if (String::IsNullOrWhiteSpace(celda->getEstado())) return "El estado es obligatorio.";
        if (celda->getCapacidad() <= 0) return "La capacidad debe ser mayor a 0.";
        if (celda->getHorasOperacion() <= 0) return "Las horas de operación deben ser mayor a 0.";
        int idGenerado = dao->agregarCeldaSP(celda);
        if (idGenerado > 0) {
            // Asignamos el ID generado al objeto por si se necesita después
            celda->setCeldaId(idGenerado);
            return "";
        }
        return "Ocurrió un error al agregar la celda en la base de datos.";
    }

    String^ CeldaController::ModificarCeldaSP(Celda^ celda) {
        if (celda == nullptr) return "La celda es nula.";
        if (celda->getCeldaId() <= 0) return "El ID de la celda no es válido.";
        if (String::IsNullOrWhiteSpace(celda->getNombre())) return "El nombre es obligatorio.";
        if (celda->getCapacidad() <= 0) return "La capacidad debe ser mayor a 0.";
        if (celda->getHorasOperacion() <= 0) return "Las horas de operación deben ser mayor a 0.";
        bool exito = dao->modificarCeldaSP(celda);
        return exito ? "" : "Ocurrió un error al modificar la celda en la base de datos.";
    }

    String^ CeldaController::EliminarCeldaSP(int celdaId) {
        if (celdaId <= 0) return "El ID de la celda no es válido.";

        bool exito = dao->eliminarCeldaSP(celdaId);
        return exito ? "" : "Ocurrió un error al eliminar la celda en la base de datos.";
    }
}