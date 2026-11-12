#include "CeldaDAO.h"
using namespace SGPlantaReciclajeDAO;

CeldaDAO::CeldaDAO() : BaseDAO() {}

// ============================================================
// READ: Listar todas las celdas
// ============================================================
List<Celda^>^ CeldaDAO::listarCeldas() {
    List<Celda^>^ lista = gcnew List<Celda^>();
    String^ sSql = "SELECT CeldaId, Nombre, Tipo, Estado, Capacidad, HorasOperacion FROM Celda";

    try {
        abrirConexion();
        SqlCommand^ comando = gcnew SqlCommand(sSql, this->getObjConexion());
        SqlDataReader^ reader = comando->ExecuteReader();

        while (reader->Read()) {
            Celda^ c = gcnew Celda(
                Convert::ToInt32(reader["CeldaId"]),
                reader["Nombre"]->ToString(),
                reader["Tipo"]->ToString(),
                reader["Estado"]->ToString(),
                Convert::ToDouble(reader["Capacidad"]),
                reader["HorasOperacion"] != DBNull::Value ? Convert::ToDouble(reader["HorasOperacion"]) : 0.0
            );
            lista->Add(c);
        }
        reader->Close();
        cerrarConexion();
    }
    catch (Exception^ ex) {
        Console::WriteLine("Error al listar celdas: " + ex->Message);
        if (this->getObjConexion()->State == System::Data::ConnectionState::Open) cerrarConexion();
    }
    return lista;
}

Celda^ CeldaDAO::consultarCelda(int celdaId) {
    String^ sSql = "SELECT CeldaId, Nombre, Tipo, Estado, Capacidad, HorasOperacion " +
        "FROM Celda WHERE CeldaId = @id";

    try {
        abrirConexion();
        SqlCommand^ comando = gcnew SqlCommand(sSql, this->getObjConexion());
        comando->Parameters->AddWithValue("@id", celdaId);

        SqlDataReader^ reader = comando->ExecuteReader();

        if (reader->Read()) {
            Celda^ c = gcnew Celda(
                Convert::ToInt32(reader["CeldaId"]),
                reader["Nombre"]->ToString(),
                reader["Tipo"]->ToString(),
                reader["Estado"]->ToString(),
                Convert::ToDouble(reader["Capacidad"]),
                reader["HorasOperacion"] != DBNull::Value ? Convert::ToDouble(reader["HorasOperacion"]) : 0.0
            );
            reader->Close();
            cerrarConexion();
            return c;
        }

        reader->Close();
        cerrarConexion();
    }
    catch (Exception^ ex) {
        Console::WriteLine("Error al consultar celda: " + ex->Message);
        if (this->getObjConexion()->State == System::Data::ConnectionState::Open) cerrarConexion();
    }
    return nullptr; // Retorna null si no la encuentra o hay error
}

// ============================================================
// CREATE: Agregar Celda
// ============================================================
int CeldaDAO::agregarCelda(Celda^ celda) {
    // Usamos @parametros para evitar inyección SQL.
    // SCOPE_IDENTITY() captura el ID generado por el IDENTITY(1,1).
    String^ sSql = "INSERT INTO Celda (Nombre, Tipo, Estado, Capacidad, HorasOperacion) " +
        "VALUES (@nombre, @tipo, @estado, @capacidad, @horas); " +
        "SELECT SCOPE_IDENTITY();";

    array<SqlParameter^>^ parametros = gcnew array<SqlParameter^>(5);
    parametros[0] = gcnew SqlParameter("@nombre", celda->getNombre());
    parametros[1] = gcnew SqlParameter("@tipo", celda->getTipo());
    parametros[2] = gcnew SqlParameter("@estado", celda->getEstado());
    parametros[3] = gcnew SqlParameter("@capacidad", celda->getCapacidad());
    parametros[4] = gcnew SqlParameter("@horas", celda->getHorasOperacion());

    // Llamamos a la sobrecarga segura de insertSql en BaseDAO
    return insertSql(sSql, parametros);
}

// ============================================================
// UPDATE: Modificar Celda
// ============================================================
bool CeldaDAO::modificarCelda(Celda^ celda) {
    String^ sSql = "UPDATE Celda SET Nombre=@nombre, Tipo=@tipo, Estado=@estado, " +
        "Capacidad=@capacidad, HorasOperacion=@horas WHERE CeldaId=@id";

    array<SqlParameter^>^ parametros = gcnew array<SqlParameter^>(6);
    parametros[0] = gcnew SqlParameter("@nombre", celda->getNombre());
    parametros[1] = gcnew SqlParameter("@tipo", celda->getTipo());
    parametros[2] = gcnew SqlParameter("@estado", celda->getEstado());
    parametros[3] = gcnew SqlParameter("@capacidad", celda->getCapacidad());
    parametros[4] = gcnew SqlParameter("@horas", celda->getHorasOperacion());
    parametros[5] = gcnew SqlParameter("@id", celda->getCeldaId());

    return executeSql(sSql, parametros);
}

// ============================================================
// DELETE: Eliminar Celda
// ============================================================
bool CeldaDAO::eliminarCelda(int celdaId) {
    String^ sSql = "DELETE FROM Celda WHERE CeldaId = @id";

    array<SqlParameter^>^ parametros = gcnew array<SqlParameter^>(1);
    parametros[0] = gcnew SqlParameter("@id", celdaId);

    return executeSql(sSql, parametros);
}

// ============================================================
// READ: Listar todas las celdas (Usa usp_QueryAllCeldas)
// ============================================================
List<Celda^>^ CeldaDAO::listarCeldasSP() {
    List<Celda^>^ lista = gcnew List<Celda^>();

    // Ejecutamos el SP que devuelve la tabla
    DataTable^ dt = ejecutarProcedureSelect("usp_QueryAllCeldas", nullptr);

    for each (DataRow ^ row in dt->Rows) {
        Celda^ c = gcnew Celda(
            Convert::ToInt32(row["CeldaId"]),
            row["Nombre"]->ToString(),
            row["Tipo"]->ToString(),
            row["Estado"]->ToString(),
            row["Capacidad"] != DBNull::Value ? Convert::ToDouble(row["Capacidad"]) : 0.0,
            row["HorasOperacion"] != DBNull::Value ? Convert::ToDouble(row["HorasOperacion"]) : 0.0
        );
        lista->Add(c);
    }
    return lista;
}

// ============================================================
// CREATE: Agregar Celda (Usa usp_AddCelda)
// ============================================================
int CeldaDAO::agregarCeldaSP(Celda^ celda) {
    array<SqlParameter^>^ parametros = gcnew array<SqlParameter^>(5);
    parametros[0] = gcnew SqlParameter("@Nombre", celda->getNombre());
    parametros[1] = gcnew SqlParameter("@Tipo", celda->getTipo());
    parametros[2] = gcnew SqlParameter("@Estado", celda->getEstado());
    parametros[3] = gcnew SqlParameter("@Capacidad", celda->getCapacidad());
    parametros[4] = gcnew SqlParameter("@HorasOperacion", celda->getHorasOperacion());

    // usp_AddCelda retorna el ID generado por el SELECT SCOPE_IDENTITY()
    return ejecutarProcedureInsert("usp_AddCelda", parametros);
}

// ============================================================
// UPDATE: Modificar Celda (Usa usp_UpdateCelda)
// ============================================================
bool CeldaDAO::modificarCeldaSP(Celda^ celda) {
    array<SqlParameter^>^ parametros = gcnew array<SqlParameter^>(6);
    parametros[0] = gcnew SqlParameter("@CeldaId", celda->getCeldaId());
    parametros[1] = gcnew SqlParameter("@Nombre", celda->getNombre());
    parametros[2] = gcnew SqlParameter("@Tipo", celda->getTipo());
    parametros[3] = gcnew SqlParameter("@Estado", celda->getEstado());
    parametros[4] = gcnew SqlParameter("@Capacidad", celda->getCapacidad());
    parametros[5] = gcnew SqlParameter("@HorasOperacion", celda->getHorasOperacion());

    return ejecutarProcedureNonQuery("usp_UpdateCelda", parametros);
}

// ============================================================
// DELETE: Eliminar Celda (Usa usp_DeleteCelda)
// ============================================================
bool CeldaDAO::eliminarCeldaSP(int celdaId) {
    array<SqlParameter^>^ parametros = gcnew array<SqlParameter^>(1);
    parametros[0] = gcnew SqlParameter("@CeldaId", celdaId);

    return ejecutarProcedureNonQuery("usp_DeleteCelda", parametros);
}