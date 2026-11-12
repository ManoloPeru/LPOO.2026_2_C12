#pragma once

namespace SGPlantaReciclajeDAO {

	using namespace System;
	using namespace System::IO;  // ← Necesario para DirectoryInfo, Directory, Path, File
	//Agregar las referencias: System y System::Data
	using namespace System::Data; // ← Necesario para SqlConnection, SqlCommand, etc.
	using namespace System::Data::SqlClient; // ← Necesario para SqlConnection, SqlCommand, etc.

	// ============================================================
	// CLASE: BaseDAO
	// ============================================================
	// Clase base para todos los DAO del sistema SGPlantaReciclaje.

	public ref class BaseDAO {

		protected:
			// Ruta absoluta de la carpeta donde se almacenan los TXT.
			// Termina siempre con el separador de directorio.
			// La ruta se calcula como: <Raíz del proyecto>\BD\TXT\. 
			String^ rutaCarpeta;

			// Es el atributo que va a ayudarnos a establecer la conexion con la BD
			SqlConnection^ objConexion; 

			// Es el atributo que va a ayudarnos a manejar las transacciones con la BD
			SqlTransaction^ objTransaccion;

		public:
			// Constructor: calcula y almacena la ruta de la carpeta TXT.
			BaseDAO();

			// ============================================================
			// Métodos para el manejo de rutas de archivos y carpetas
			// ============================================================

			// getRutaCarpeta: devuelve la ruta absoluta de la carpeta TXT o BIN.
			String^ getRutaCarpeta();

			// ------------------------------------------------------------
			// Método auxiliar protegido: obtiene la ruta absoluta de la
			// carpeta BD\TXT\ subiendo desde StartupPath hasta encontrar
			// la raíz del proyecto (donde está el .sln).
			// ------------------------------------------------------------
			String^ ObtenerRutaCarpetaTXT();

			// ObtenerRutaCarpetaBIN: devuelve la ruta absoluta de BD\BIN
			String^ ObtenerRutaCarpetaBIN();

			// ---------- MÉTODOS AUXILIARES PARA LOS DAO HIJOS ----------
			// ObtenerRutaArchivo: devuelve la ruta completa de un archivo
			// dentro de la carpeta BD\TXT\. Ejemplo:
			//   ObtenerRutaArchivo("Estaciones.txt")
			//     → "C:\...\SGPlantaReciclaje\BD\TXT\Estaciones.txt"
			String^ ObtenerRutaArchivo(String^ nombreArchivo);

			// AsegurarExistenciaCarpeta: verifica que la carpeta BD\TXT\
				// exista; si no, la crea. Útil antes de escribir un archivo.
			void AsegurarExistenciaCarpeta();

			// ===============================================================
			// Métodos para el manejo de base de datos (SQL Server) y conexión
			// ===============================================================
			// Metodo para obtener el objeto de conexion
			SqlConnection^ getObjConexion(); 

			// Metodo para abrir la conexion
			void abrirConexion();	

			// Metodo para ejecutar sentencias INSERT SQL en la Base de Datos
			int insertSql(String^ sSql, array<SqlParameter^>^ parametros);

			// Metodo para ejecutar sentencias UPDATE/DELETE SQL en la Base de Datos
			bool executeSql(String^ sSql, array<SqlParameter^>^ parametros); 

			// Metodo para cerrar la conexion
			void cerrarConexion(); 

			// ===============================================================
			// Métodos para ejecutar Stored Procedures
			// ===============================================================

			// Ejecuta un SP que devuelve un ID generado (SCOPE_IDENTITY)
			int ejecutarProcedureInsert(String^ nombreSP, array<SqlParameter^>^ parametros);

			// Ejecuta un SP que devuelve una tabla de datos (SELECT)
			DataTable^ ejecutarProcedureSelect(String^ nombreSP, array<SqlParameter^>^ parametros);

			// Ejecuta un SP que no devuelve datos (UPDATE/DELETE)
			bool ejecutarProcedureNonQuery(String^ nombreSP, array<SqlParameter^>^ parametros);

			// Stored Procedures que usan la transacción activa
			int ejecutarProcedureInsertTransaccional(String^ nombreSP, array<SqlParameter^>^ parametros);
			bool ejecutarProcedureNonQueryTransaccional(String^ nombreSP, array<SqlParameter^>^ parametros);

			// ===============================================================
			// NUEVOS MÉTODOS: Manejo de Transacciones
			// ===============================================================
			// Inicia una transacción en la conexión actual.
			void iniciarTransaccion();
			// Confirma (commit) la transacción actual.
			void confirmarTransaccion();
			// Revierte (rollback) la transacción actual.
			void revertirTransaccion();
			// Devuelve el objeto SqlTransaction actual.
			SqlTransaction^ getObjTransaccion();



	};
}