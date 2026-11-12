#include "MantenimientoDAO.h"

using namespace SGPlantaReciclajeDAO;

MantenimientoDAO::MantenimientoDAO() : BaseDAO() {}

// ============================================================
// CREATE: Cabecera (Usa parámetro de salida OUTPUT)
// ============================================================
int MantenimientoDAO::registrarCabecera(MantenimientoCabecera^ cabecera) {
    int idGenerado = 0;
    try {
        SqlCommand^ comando = gcnew SqlCommand("usp_CreateMantenimiento", this->getObjConexion(), this->getObjTransaccion());
        comando->CommandType = CommandType::StoredProcedure;

        // Parámetros de entrada
        comando->Parameters->AddWithValue("@EstacionId", cabecera->getEstacionId());
        comando->Parameters->AddWithValue("@Tecnico", cabecera->getTecnico());
        comando->Parameters->AddWithValue("@TipoMantenimiento", cabecera->getTipoMantenimiento());
        comando->Parameters->AddWithValue("@FechaMantenimiento", cabecera->getFechaMantenimiento());

        // Parámetro de salida (OUTPUT)
        SqlParameter^ paramId = gcnew SqlParameter("@MantenimientoId", SqlDbType::Int);
        paramId->Direction = ParameterDirection::Output;
        comando->Parameters->Add(paramId);

        // Ejecutamos sin consulta (no retorna SELECT)
        comando->ExecuteNonQuery();

        // Recuperamos el ID del parámetro de salida
        if (paramId->Value != nullptr && paramId->Value != DBNull::Value) {
            idGenerado = Convert::ToInt32(paramId->Value);
        }
    }
    catch (SqlException^ ex) {
        throw gcnew Exception("Error al insertar Cabecera: " + ex->Message);
    }
    return idGenerado;
}

// ============================================================
// CREATE: Detalle (Invocado iterativamente)
// ============================================================
bool MantenimientoDAO::registrarDetalle(int mantenimientoId, MantenimientoDetalle^ detalle) {
    try {
        SqlCommand^ comando = gcnew SqlCommand("usp_AddMantenimientoDetail", this->getObjConexion(), this->getObjTransaccion());
        comando->CommandType = CommandType::StoredProcedure;

        comando->Parameters->AddWithValue("@MantenimientoId", mantenimientoId);
        comando->Parameters->AddWithValue("@Actividad", detalle->getActividad());
        comando->Parameters->AddWithValue("@DuracionMinutos", detalle->getDuracionMinutos());

        comando->ExecuteNonQuery();
        return true;
    }
    catch (SqlException^ ex) {
        throw gcnew Exception("Error al insertar Detalle: " + ex->Message);
    }
}

List<MantenimientoCabecera^>^ MantenimientoDAO::listarMantenimientos() {
    List<MantenimientoCabecera^>^ lista = gcnew List<MantenimientoCabecera^>();
    DataTable^ dt = ejecutarProcedureSelect("usp_QueryAllMantenimientos", nullptr);

    for each (DataRow ^ row in dt->Rows) {
        MantenimientoCabecera^ cab = gcnew MantenimientoCabecera(
            Convert::ToInt32(row["MantenimientoId"]),
            Convert::ToInt32(row["EstacionId"]),
            row["Tecnico"]->ToString(),
            row["TipoMantenimiento"]->ToString(),
            Convert::ToDateTime(row["FechaMantenimiento"])
        );
        lista->Add(cab);
    }
    return lista;
}

List<MantenimientoDetalle^>^ MantenimientoDAO::listarDetalles(int mantenimientoId) {
    List<MantenimientoDetalle^>^ lista = gcnew List<MantenimientoDetalle^>();

    // Parámetro para filtrar por el ID de la cabecera
    array<SqlParameter^>^ parametros = gcnew array<SqlParameter^>(1);
    parametros[0] = gcnew SqlParameter("@MantenimientoId", mantenimientoId);

    // Asumimos que creaste el SP: usp_QueryDetallesByMantenimiento
    DataTable^ dt = ejecutarProcedureSelect("usp_QueryDetallesByMantenimiento", parametros);

    for each (DataRow ^ row in dt->Rows) {
        MantenimientoDetalle^ det = gcnew MantenimientoDetalle(
            Convert::ToInt32(row["MantenimientoDetailId"]),
            row["Actividad"]->ToString(),
            Convert::ToInt32(row["DuracionMinutos"])
        );
        lista->Add(det);
    }
    return lista;
}