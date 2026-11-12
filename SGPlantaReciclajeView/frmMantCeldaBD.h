#pragma once
#include "frmNuevaCeldaBD.h"
#include "frmEditarCeldaBD.h"

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
	/// Resumen de frmMantCeldaBD
	/// </summary>
	public ref class frmMantCeldaBD : public System::Windows::Forms::Form
	{
	public:
		frmMantCeldaBD(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->celdaController = gcnew CeldaController();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantCeldaBD()
		{
			if (components)
			{
				delete components;
			}
		}

	private: CeldaController^ celdaController;	// Instancia del controlador de celdas de proceso

	private: System::Windows::Forms::Button^ btnEliminar;
	private: System::Windows::Forms::Button^ btnEditar;
	private: System::Windows::Forms::Button^ btnNuevo;
	private: System::Windows::Forms::DataGridView^ dgvLista;






	private: System::Windows::Forms::Button^ btnListar;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colNombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colTipo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colEstado;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCapacidad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colHorasOperacion;

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->btnEditar = (gcnew System::Windows::Forms::Button());
			this->btnNuevo = (gcnew System::Windows::Forms::Button());
			this->dgvLista = (gcnew System::Windows::Forms::DataGridView());
			this->btnListar = (gcnew System::Windows::Forms::Button());
			this->colId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colNombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colTipo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEstado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCapacidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colHorasOperacion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->BeginInit();
			this->SuspendLayout();
			// 
			// btnEliminar
			// 
			this->btnEliminar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnEliminar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEliminar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnEliminar->Location = System::Drawing::Point(627, 421);
			this->btnEliminar->Margin = System::Windows::Forms::Padding(4);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(98, 34);
			this->btnEliminar->TabIndex = 24;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = false;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &frmMantCeldaBD::btnEliminar_Click);
			// 
			// btnEditar
			// 
			this->btnEditar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnEditar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEditar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnEditar->Location = System::Drawing::Point(456, 421);
			this->btnEditar->Margin = System::Windows::Forms::Padding(4);
			this->btnEditar->Name = L"btnEditar";
			this->btnEditar->Size = System::Drawing::Size(98, 34);
			this->btnEditar->TabIndex = 23;
			this->btnEditar->Text = L"Editar";
			this->btnEditar->UseVisualStyleBackColor = false;
			this->btnEditar->Click += gcnew System::EventHandler(this, &frmMantCeldaBD::btnEditar_Click);
			// 
			// btnNuevo
			// 
			this->btnNuevo->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnNuevo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNuevo->ForeColor = System::Drawing::SystemColors::Control;
			this->btnNuevo->Location = System::Drawing::Point(290, 421);
			this->btnNuevo->Margin = System::Windows::Forms::Padding(4);
			this->btnNuevo->Name = L"btnNuevo";
			this->btnNuevo->Size = System::Drawing::Size(98, 34);
			this->btnNuevo->TabIndex = 22;
			this->btnNuevo->Text = L"Nuevo";
			this->btnNuevo->UseVisualStyleBackColor = false;
			this->btnNuevo->Click += gcnew System::EventHandler(this, &frmMantCeldaBD::btnNuevo_Click);
			// 
			// dgvLista
			// 
			this->dgvLista->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvLista->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgvLista->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvLista->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->colId, this->colNombre,
					this->colTipo, this->colEstado, this->colCapacidad, this->colHorasOperacion
			});
			this->dgvLista->Location = System::Drawing::Point(13, 48);
			this->dgvLista->Margin = System::Windows::Forms::Padding(4);
			this->dgvLista->Name = L"dgvLista";
			this->dgvLista->RowHeadersWidth = 51;
			this->dgvLista->RowTemplate->Height = 24;
			this->dgvLista->Size = System::Drawing::Size(1153, 352);
			this->dgvLista->TabIndex = 25;
			// 
			// btnListar
			// 
			this->btnListar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnListar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnListar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnListar->Location = System::Drawing::Point(788, 421);
			this->btnListar->Margin = System::Windows::Forms::Padding(4);
			this->btnListar->Name = L"btnListar";
			this->btnListar->Size = System::Drawing::Size(98, 34);
			this->btnListar->TabIndex = 26;
			this->btnListar->Text = L"Listar";
			this->btnListar->UseVisualStyleBackColor = false;
			this->btnListar->Click += gcnew System::EventHandler(this, &frmMantCeldaBD::btnListar_Click);
			// 
			// colId
			// 
			this->colId->HeaderText = L"Id";
			this->colId->MinimumWidth = 6;
			this->colId->Name = L"colId";
			// 
			// colNombre
			// 
			this->colNombre->HeaderText = L"Nombre";
			this->colNombre->MinimumWidth = 6;
			this->colNombre->Name = L"colNombre";
			this->colNombre->Width = 280;
			// 
			// colTipo
			// 
			this->colTipo->HeaderText = L"Tipo";
			this->colTipo->MinimumWidth = 6;
			this->colTipo->Name = L"colTipo";
			this->colTipo->Width = 120;
			// 
			// colEstado
			// 
			this->colEstado->HeaderText = L"Estado";
			this->colEstado->MinimumWidth = 6;
			this->colEstado->Name = L"colEstado";
			this->colEstado->Width = 180;
			// 
			// colCapacidad
			// 
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleRight;
			dataGridViewCellStyle2->Format = L"N2";
			dataGridViewCellStyle2->NullValue = nullptr;
			this->colCapacidad->DefaultCellStyle = dataGridViewCellStyle2;
			this->colCapacidad->HeaderText = L"Capacidad (kg/h)";
			this->colCapacidad->Name = L"colCapacidad";
			this->colCapacidad->Width = 200;
			// 
			// colHorasOperacion
			// 
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleRight;
			dataGridViewCellStyle3->Format = L"N2";
			dataGridViewCellStyle3->NullValue = nullptr;
			this->colHorasOperacion->DefaultCellStyle = dataGridViewCellStyle3;
			this->colHorasOperacion->HeaderText = L"Horas operación";
			this->colHorasOperacion->Name = L"colHorasOperacion";
			this->colHorasOperacion->Width = 200;
			// 
			// frmMantCeldaBD
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->ClientSize = System::Drawing::Size(1181, 508);
			this->Controls->Add(this->btnListar);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnEditar);
			this->Controls->Add(this->btnNuevo);
			this->Controls->Add(this->dgvLista);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"frmMantCeldaBD";
			this->Text = L"frmMantCeldaBD";
			this->Load += gcnew System::EventHandler(this, &frmMantCeldaBD::frmMantCeldaBD_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmMantCeldaBD_Load(System::Object^ sender, System::EventArgs^ e) {
		List<Celda^>^ listaCeldas = this->celdaController->ListarCeldasSP();
		mostrarGrilla(listaCeldas);
	}

	public:	void mostrarGrilla(List<Celda^>^ listaCeldas)
	{
		this->dgvLista->Rows->Clear();
		for (int i = 0; i < listaCeldas->Count; i++)
		{
			// Obtener la celda actual de la lista
			Celda^ celda = listaCeldas[i];
			// Crear un arreglo de strings para representar la fila del DataGridView
			array<String^>^ filaGrilla = gcnew array<String^>(6);
			// Asignar los valores de las propiedades de la celda a cada columna de la fila
			filaGrilla[0] = celda->getCeldaId().ToString();
			filaGrilla[1] = celda->getNombre();
			filaGrilla[2] = celda->getTipo();
			filaGrilla[3] = celda->getEstado();
			filaGrilla[4] = celda->getCapacidad().ToString();
			filaGrilla[5] = celda->getHorasOperacion().ToString();
			// Agregar la fila al DataGridView
			this->dgvLista->Rows->Add(filaGrilla);
		}
		this->dgvLista->AutoGenerateColumns = false; // Desactivar la generación automática de columnas
		this->dgvLista->AllowUserToAddRows = false;	 // Evitar que el usuario pueda agregar filas manualmente
		this->dgvLista->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells); // Ajustar el ancho de las columnas al contenido
	}

	private: System::Void btnListar_Click(System::Object^ sender, System::EventArgs^ e) {
		List<Celda^>^ listaCeldas = this->celdaController->ListarCeldasSP();
		mostrarGrilla(listaCeldas);
	}
	private: System::Void btnNuevo_Click(System::Object^ sender, System::EventArgs^ e) {
		// Crear una nueva instancia del formulario de nueva celda
		frmNuevaCeldaBD^ nuevaCeldaForm = gcnew frmNuevaCeldaBD();
		nuevaCeldaForm->ShowDialog(this);
		// Llamar al método para cargar la lista de celdas nuevamente
		List<Celda^>^ listaCeldas = this->celdaController->ListarCeldasSP();
		mostrarGrilla(listaCeldas);
	}
	private: System::Void btnEditar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Verificar si se ha seleccionado una fila en el DataGridView
		if (this->dgvLista->SelectedRows->Count > 0)
		{
			int filaSeleccionada = this->dgvLista->SelectedRows[0]->Index;
			String^ sIid = this->dgvLista->Rows[filaSeleccionada]->Cells[0]->Value->ToString();
			int id = Int32::Parse(sIid);
			Celda^ celdaSeleccionada = this->celdaController->ConsultarCelda(id);
			if (celdaSeleccionada == nullptr)
			{
				MessageBox::Show("No se encontró la celda seleccionada.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			frmEditarCeldaBD^ editarCeldaForm = gcnew frmEditarCeldaBD(celdaSeleccionada);
			editarCeldaForm->ShowDialog();
			// Llamar al mtodo para cargar la lista de celdas nuevamente
			List<Celda^>^ listaCeldas = this->celdaController->ListarCeldasSP();
			mostrarGrilla(listaCeldas);
		}
		else
		{
			MessageBox::Show("Por favor, seleccione un operador para editar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Verificar si se ha seleccionado una fila en el DataGridView
		if (this->dgvLista->SelectedRows->Count > 0)
		{
			// Preguntar al usuario si est� seguro de eliminar el registro
			System::Windows::Forms::DialogResult respuesta = MessageBox::Show("¿Está seguro de que desea eliminar el registro seleccionado?",
				"Confirmación de eliminación", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

			// Si el usuario selecciona "No", cancelar la operaci�n
			if (respuesta == System::Windows::Forms::DialogResult::No)
			{
				return; // Salir del evento si el usuario cancela
			}

			int selectedRowIndex = this->dgvLista->SelectedRows[0]->Index;
			String^ sId = this->dgvLista->Rows[selectedRowIndex]->Cells[0]->Value->ToString();
			int id = Int32::Parse(sId);
			// Crear una instancia del controlador y eliminar el operador
			String^ resultado = this->celdaController->EliminarCeldaSP(id);
			if (resultado == "") {
				// Actualizar la lista de operadores en el DataGridView
				List<Celda^>^ listaCeldas = this->celdaController->ListarCeldasSP();
				mostrarGrilla(listaCeldas);
				MessageBox::Show("Celda eliminada exitosamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{
				MessageBox::Show("Error al eliminar la celda:" + resultado, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
		else
		{
			MessageBox::Show("Por favor, seleccione una celda para eliminar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
};
}
