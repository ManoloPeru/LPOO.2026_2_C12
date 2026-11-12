#pragma once
#include "ComboHelper.h"

namespace SGPlantaReciclajeView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SGPlantaReciclajeController;
	using namespace SGPlantaReciclajeModel;

	/// <summary>
	/// Resumen de frmMantenimiento
	/// </summary>
	public ref class frmMantenimiento : public System::Windows::Forms::Form
	{
	public:
		frmMantenimiento(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantenimiento()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DateTimePicker^ dtpFechaMantenimiento;
	private: System::Windows::Forms::ComboBox^ cmbEstacion;
	private: System::Windows::Forms::Button^ btnRegistrar;
	private: System::Windows::Forms::DataGridView^ dgvLista;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ colActividad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colDuracionMinutos;
	private: System::Windows::Forms::TextBox^ txtTipoMantenimiento;
	private: System::Windows::Forms::TextBox^ txtTecnico;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dgvCabecera;






	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colEstacion;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colTecnico;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colTipo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colFecha;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::DataGridView^ dgvDetalle;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colIdDetalle;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colActividadDetalle;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colDuracionDetalle;
	private: System::Windows::Forms::Button^ btnListar;




	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dtpFechaMantenimiento = (gcnew System::Windows::Forms::DateTimePicker());
			this->cmbEstacion = (gcnew System::Windows::Forms::ComboBox());
			this->btnRegistrar = (gcnew System::Windows::Forms::Button());
			this->dgvLista = (gcnew System::Windows::Forms::DataGridView());
			this->colActividad = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->colDuracionMinutos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->txtTipoMantenimiento = (gcnew System::Windows::Forms::TextBox());
			this->txtTecnico = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dgvCabecera = (gcnew System::Windows::Forms::DataGridView());
			this->colId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEstacion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colTecnico = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colTipo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colFecha = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->dgvDetalle = (gcnew System::Windows::Forms::DataGridView());
			this->colIdDetalle = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colActividadDetalle = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colDuracionDetalle = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnListar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCabecera))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDetalle))->BeginInit();
			this->SuspendLayout();
			// 
			// dtpFechaMantenimiento
			// 
			this->dtpFechaMantenimiento->CalendarMonthBackground = System::Drawing::SystemColors::Info;
			this->dtpFechaMantenimiento->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpFechaMantenimiento->Location = System::Drawing::Point(253, 218);
			this->dtpFechaMantenimiento->Margin = System::Windows::Forms::Padding(5);
			this->dtpFechaMantenimiento->MinDate = System::DateTime(2026, 6, 19, 0, 0, 0, 0);
			this->dtpFechaMantenimiento->Name = L"dtpFechaMantenimiento";
			this->dtpFechaMantenimiento->Size = System::Drawing::Size(140, 29);
			this->dtpFechaMantenimiento->TabIndex = 22;
			// 
			// cmbEstacion
			// 
			this->cmbEstacion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbEstacion->FormattingEnabled = true;
			this->cmbEstacion->Location = System::Drawing::Point(253, 22);
			this->cmbEstacion->Name = L"cmbEstacion";
			this->cmbEstacion->Size = System::Drawing::Size(502, 32);
			this->cmbEstacion->TabIndex = 19;
			// 
			// btnRegistrar
			// 
			this->btnRegistrar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnRegistrar->ForeColor = System::Drawing::Color::White;
			this->btnRegistrar->Location = System::Drawing::Point(244, 653);
			this->btnRegistrar->Margin = System::Windows::Forms::Padding(7);
			this->btnRegistrar->Name = L"btnRegistrar";
			this->btnRegistrar->Size = System::Drawing::Size(292, 61);
			this->btnRegistrar->TabIndex = 23;
			this->btnRegistrar->Text = L"Registrar mantenimiento";
			this->btnRegistrar->UseVisualStyleBackColor = false;
			this->btnRegistrar->Click += gcnew System::EventHandler(this, &frmMantenimiento::btnRegistrar_Click);
			// 
			// dgvLista
			// 
			this->dgvLista->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dgvLista->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvLista->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->colActividad,
					this->colDuracionMinutos
			});
			this->dgvLista->Location = System::Drawing::Point(30, 283);
			this->dgvLista->Margin = System::Windows::Forms::Padding(7);
			this->dgvLista->Name = L"dgvLista";
			this->dgvLista->RowHeadersVisible = false;
			this->dgvLista->RowHeadersWidth = 82;
			this->dgvLista->RowTemplate->Height = 28;
			this->dgvLista->Size = System::Drawing::Size(729, 334);
			this->dgvLista->TabIndex = 28;
			// 
			// colActividad
			// 
			this->colActividad->HeaderText = L"Actividad";
			this->colActividad->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Actualización del firmware del controlador",
					L"Calibración de home", L"Cambio de grasa", L"Lubricación de engranajes en eje base", L"Reajuste de sensores de proximidad"
			});
			this->colActividad->MinimumWidth = 10;
			this->colActividad->Name = L"colActividad";
			this->colActividad->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->colActividad->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->colActividad->Width = 400;
			// 
			// colDuracionMinutos
			// 
			this->colDuracionMinutos->HeaderText = L"Duracion minutos";
			this->colDuracionMinutos->MinimumWidth = 10;
			this->colDuracionMinutos->Name = L"colDuracionMinutos";
			this->colDuracionMinutos->Width = 300;
			// 
			// txtTipoMantenimiento
			// 
			this->txtTipoMantenimiento->BackColor = System::Drawing::SystemColors::Info;
			this->txtTipoMantenimiento->Location = System::Drawing::Point(253, 155);
			this->txtTipoMantenimiento->Margin = System::Windows::Forms::Padding(7);
			this->txtTipoMantenimiento->Name = L"txtTipoMantenimiento";
			this->txtTipoMantenimiento->Size = System::Drawing::Size(218, 29);
			this->txtTipoMantenimiento->TabIndex = 21;
			// 
			// txtTecnico
			// 
			this->txtTecnico->BackColor = System::Drawing::SystemColors::Info;
			this->txtTecnico->Location = System::Drawing::Point(253, 90);
			this->txtTecnico->Margin = System::Windows::Forms::Padding(7);
			this->txtTecnico->Name = L"txtTecnico";
			this->txtTecnico->Size = System::Drawing::Size(502, 29);
			this->txtTecnico->TabIndex = 20;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(41, 222);
			this->label4->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(198, 24);
			this->label4->TabIndex = 27;
			this->label4->Text = L"Fecha mantenimiento:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(41, 155);
			this->label3->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(182, 24);
			this->label3->TabIndex = 26;
			this->label3->Text = L"Tipo mantenimiento:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(41, 90);
			this->label2->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 24);
			this->label2->TabIndex = 25;
			this->label2->Text = L"Técnico:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(41, 30);
			this->label1->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(195, 24);
			this->label1->TabIndex = 24;
			this->label1->Text = L"Estación clasificadora:";
			// 
			// dgvCabecera
			// 
			this->dgvCabecera->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dgvCabecera->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCabecera->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->colId, this->colEstacion,
					this->colTecnico, this->colTipo, this->colFecha
			});
			this->dgvCabecera->Location = System::Drawing::Point(829, 56);
			this->dgvCabecera->Margin = System::Windows::Forms::Padding(7);
			this->dgvCabecera->Name = L"dgvCabecera";
			this->dgvCabecera->RowHeadersVisible = false;
			this->dgvCabecera->RowHeadersWidth = 82;
			this->dgvCabecera->RowTemplate->Height = 28;
			this->dgvCabecera->Size = System::Drawing::Size(856, 296);
			this->dgvCabecera->TabIndex = 29;
			this->dgvCabecera->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmMantenimiento::dgvCabecera_CellClick);
			// 
			// colId
			// 
			this->colId->HeaderText = L"Id";
			this->colId->Name = L"colId";
			// 
			// colEstacion
			// 
			this->colEstacion->HeaderText = L"Estación";
			this->colEstacion->MinimumWidth = 10;
			this->colEstacion->Name = L"colEstacion";
			this->colEstacion->Width = 300;
			// 
			// colTecnico
			// 
			this->colTecnico->HeaderText = L"Tecnico";
			this->colTecnico->Name = L"colTecnico";
			this->colTecnico->Width = 150;
			// 
			// colTipo
			// 
			this->colTipo->HeaderText = L"Tipo";
			this->colTipo->Name = L"colTipo";
			this->colTipo->Width = 120;
			// 
			// colFecha
			// 
			this->colFecha->HeaderText = L"Fecha";
			this->colFecha->Name = L"colFecha";
			this->colFecha->Width = 120;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(825, 25);
			this->label5->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(524, 24);
			this->label5->TabIndex = 30;
			this->label5->Text = L"Cabecera, dar clic a una fila para recargar el detalle asociado:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(825, 373);
			this->label6->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(72, 24);
			this->label6->TabIndex = 32;
			this->label6->Text = L"Detalle:";
			// 
			// dgvDetalle
			// 
			this->dgvDetalle->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dgvDetalle->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvDetalle->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->colIdDetalle,
					this->colActividadDetalle, this->colDuracionDetalle
			});
			this->dgvDetalle->Location = System::Drawing::Point(829, 404);
			this->dgvDetalle->Margin = System::Windows::Forms::Padding(7);
			this->dgvDetalle->Name = L"dgvDetalle";
			this->dgvDetalle->RowHeadersVisible = false;
			this->dgvDetalle->RowHeadersWidth = 82;
			this->dgvDetalle->RowTemplate->Height = 28;
			this->dgvDetalle->Size = System::Drawing::Size(856, 213);
			this->dgvDetalle->TabIndex = 31;
			// 
			// colIdDetalle
			// 
			this->colIdDetalle->HeaderText = L"Id";
			this->colIdDetalle->Name = L"colIdDetalle";
			// 
			// colActividadDetalle
			// 
			this->colActividadDetalle->HeaderText = L"Actividad";
			this->colActividadDetalle->MinimumWidth = 10;
			this->colActividadDetalle->Name = L"colActividadDetalle";
			this->colActividadDetalle->Width = 600;
			// 
			// colDuracionDetalle
			// 
			this->colDuracionDetalle->HeaderText = L"Duración";
			this->colDuracionDetalle->Name = L"colDuracionDetalle";
			this->colDuracionDetalle->Width = 150;
			// 
			// btnListar
			// 
			this->btnListar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnListar->ForeColor = System::Drawing::Color::White;
			this->btnListar->Location = System::Drawing::Point(1135, 653);
			this->btnListar->Margin = System::Windows::Forms::Padding(7);
			this->btnListar->Name = L"btnListar";
			this->btnListar->Size = System::Drawing::Size(292, 61);
			this->btnListar->TabIndex = 33;
			this->btnListar->Text = L"Listar Mantenimientos";
			this->btnListar->UseVisualStyleBackColor = false;
			this->btnListar->Click += gcnew System::EventHandler(this, &frmMantenimiento::btnListar_Click);
			// 
			// frmMantenimiento
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->ClientSize = System::Drawing::Size(1701, 735);
			this->Controls->Add(this->btnListar);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->dgvDetalle);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->dgvCabecera);
			this->Controls->Add(this->dtpFechaMantenimiento);
			this->Controls->Add(this->cmbEstacion);
			this->Controls->Add(this->btnRegistrar);
			this->Controls->Add(this->dgvLista);
			this->Controls->Add(this->txtTipoMantenimiento);
			this->Controls->Add(this->txtTecnico);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"frmMantenimiento";
			this->Text = L"Mantenimiento preventivo y correctivo de Estaciones";
			this->Load += gcnew System::EventHandler(this, &frmMantenimiento::frmMantenimiento_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCabecera))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDetalle))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmMantenimiento_Load(System::Object^ sender, System::EventArgs^ e) {
		this->dtpFechaMantenimiento->Value = DateTime::Now;
		try {
			// 1. Poblar el ComboBox de Estaciones llamando al Helper
			ComboHelper::LlenarComboEstaciones(cmbEstacion, 0);

			// 2. Configurar el DataGridView (esto se queda en la vista)
			dgvLista->AllowUserToAddRows = true;
			dgvLista->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al cargar el formulario: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void btnRegistrar_Click(System::Object^ sender, System::EventArgs^ e) {
		// 1. VALIDACIONES BÁSICAS
		if (cmbEstacion->SelectedIndex == -1) {
			MessageBox::Show("Debe seleccionar una estación clasificadora.", "Validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		if (String::IsNullOrWhiteSpace(txtTecnico->Text)) {
			MessageBox::Show("Debe ingresar el nombre del técnico.", "Validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		if (String::IsNullOrWhiteSpace(txtTipoMantenimiento->Text)) {
			MessageBox::Show("Debe ingresar el tipo de mantenimiento.", "Validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		if (dgvLista->Rows->Count <= 1 && dgvLista->Rows[0]->IsNewRow) {
			MessageBox::Show("Debe agregar al menos una actividad al mantenimiento.", "Validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			// 2. CREAR LA CABECERA
			int idEstacion = Convert::ToInt32(cmbEstacion->SelectedValue);
			String^ tecnico = txtTecnico->Text->Trim();
			String^ tipo = txtTipoMantenimiento->Text->Trim();
			DateTime fecha = dtpFechaMantenimiento->Value;

			MantenimientoCabecera^ cabecera = gcnew MantenimientoCabecera(idEstacion, tecnico, tipo, fecha);

			// 3. RECORRER EL DATAGRIDVIEW PARA ARMAR LOS DETALLES
			for (int i = 0; i < dgvLista->Rows->Count; i++) {
				DataGridViewRow^ fila = dgvLista->Rows[i];

				// Ignorar la fila "nueva" vacía que agrega DataGridView por defecto
				if (fila->IsNewRow) continue;

				// Obtener los valores de la fila de manera segura
				String^ actividad = "";
				if (fila->Cells[0]->Value != nullptr) {
					actividad = fila->Cells[0]->Value->ToString();
				}

				int duracion = 0;
				if (fila->Cells[1]->Value != nullptr) {
					if (!Int32::TryParse(fila->Cells[1]->Value->ToString(), duracion)) {
						MessageBox::Show("La duración en la fila " + (i + 1) + " debe ser un número entero válido.", "Validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						return;
					}
				}
				else {
					MessageBox::Show("Debe ingresar la duración en la fila " + (i + 1), "Validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}

				// Si la actividad está vacía, saltamos esta fila
				if (String::IsNullOrWhiteSpace(actividad)) continue;

				// Crear el detalle y agregarlo a la cabecera
				MantenimientoDetalle^ detalle = gcnew MantenimientoDetalle(actividad, duracion);
				cabecera->agregarActividad(detalle);
			}

			// 4. LLAMAR AL CONTROLADOR TRANSACCIONAL
			MantenimientoController^ controller = gcnew MantenimientoController();
			String^ resultado = controller->RegistrarMantenimientoCompleto(cabecera);

			// 5. MOSTRAR RESULTADO
			if (resultado == "") {
				MessageBox::Show("Mantenimiento registrado exitosamente con ID: " + cabecera->getMantenimientoId().ToString(), "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);

				// Limpiar el formulario
				this->LimpiarFormulario();
			}
			else {
				MessageBox::Show(resultado, "Error al guardar", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ocurrió un error inesperado: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: void LimpiarFormulario() {
		// 1. Limpiar los controles de la Cabecera
		cmbEstacion->SelectedIndex = -1;        // Desmarcar la estación
		txtTecnico->Clear();                    // Limpiar técnico
		txtTipoMantenimiento->Clear();          // Limpiar tipo de mantenimiento
		dtpFechaMantenimiento->Value = DateTime::Now; // Restablecer la fecha a hoy

		// 2. Limpiar el DataGridView (Detalle)
		dgvLista->Rows->Clear();

		// 3. (Opcional) Si tienes una fila vacía inicial, la agregamos de nuevo
		// para que el usuario no tenga que presionar el botón de "Agregar fila".
		dgvLista->Rows->Add();

		// 4. Poner el cursor (focus) en el primer control para facilitar el ingreso
		cmbEstacion->Focus();
	}

	private: System::Void btnListar_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// 1. Obtener la lista desde el controlador
			MantenimientoController^ controller = gcnew MantenimientoController();
			List<MantenimientoCabecera^>^ lista = controller->ListarMantenimientos();

			// 2. Limpiar la grilla antes de llenarla
			dgvCabecera->Rows->Clear();

			// 3. Configurar la grilla para que no se generen columnas extra
			dgvCabecera->AutoGenerateColumns = false;
			dgvCabecera->AllowUserToAddRows = false;

			// 4. Recorrer la lista y agregar las filas
			for each (MantenimientoCabecera ^ cab in lista) {
				// Creamos un arreglo con los datos en el mismo orden de las columnas de la grilla
				array<String^>^ fila = gcnew array<String^>(5);

				fila[0] = cab->getMantenimientoId().ToString();

				EstacionController^ estacionController = gcnew EstacionController();
				Estacion^ estacion = estacionController->ConsultarEstacion(cab->getEstacionId());
				fila[1] = estacion->getAlias(); // Mostrar el alias en lugar del ID

				fila[2] = cab->getTecnico();
				fila[3] = cab->getTipoMantenimiento();
				fila[4] = cab->getFechaMantenimiento().ToString("dd/MM/yyyy");

				dgvCabecera->Rows->Add(fila);
			}

			// 5. (Opcional) Ajustar el ancho de las columnas
			dgvCabecera->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells);

		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al listar mantenimientos: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void dgvCabecera_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		// Validar que se haya hecho clic en una fila válida (no en los encabezados)
		if (e->RowIndex >= 0) {
			try {
				// 1. Obtener el ID del mantenimiento desde la primera celda de la fila seleccionada
				if (dgvCabecera->Rows[e->RowIndex]->Cells[0]->Value == nullptr) return;

				int idMantenimiento = Convert::ToInt32(dgvCabecera->Rows[e->RowIndex]->Cells[0]->Value);

				// 2. Llamar al controlador para obtener los detalles de la BD
				MantenimientoController^ controller = gcnew MantenimientoController();
				List<MantenimientoDetalle^>^ detalles = controller->ListarDetalles(idMantenimiento);

				// 3. Limpiar la grilla de detalles antes de llenarla
				dgvDetalle->Rows->Clear();
				dgvDetalle->AutoGenerateColumns = false; // Evitar columnas generadas automáticamente

				// 4. Recorrer la lista de detalles y agregarlos a la grilla
				for each (MantenimientoDetalle ^ det in detalles) {
					// Creamos un arreglo con los 3 valores (Id, Actividad, Duracion)
					array<Object^>^ fila = gcnew array<Object^>(3);
					fila[0] = det->getMantenimientoDetailId();
					fila[1] = det->getActividad();
					fila[2] = det->getDuracionMinutos();

					// Agregamos la fila al DataGridView
					dgvDetalle->Rows->Add(fila);
				}
			}
			catch (Exception^ ex) {
				// Es mejor mostrar el error real para saber qué pasó
				MessageBox::Show("Error al cargar los detalles: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
};
}
