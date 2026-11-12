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
	/// Resumen de frmNuevaCeldaBD
	/// </summary>
	public ref class frmNuevaCeldaBD : public System::Windows::Forms::Form
	{
	public:
		frmNuevaCeldaBD(void)
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
		~frmNuevaCeldaBD()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnGrabar;
	protected:
	private: System::Windows::Forms::Button^ btnCancelar;
	private: System::Windows::Forms::GroupBox^ grpBoxPrincipal;
	private: System::Windows::Forms::ComboBox^ cmbTipo;
	private: System::Windows::Forms::ComboBox^ cmbEstado;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::NumericUpDown^ txtHorasOperacion;
	private: System::Windows::Forms::NumericUpDown^ txtCapacidad;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;

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
			this->btnGrabar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->grpBoxPrincipal = (gcnew System::Windows::Forms::GroupBox());
			this->cmbTipo = (gcnew System::Windows::Forms::ComboBox());
			this->cmbEstado = (gcnew System::Windows::Forms::ComboBox());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtHorasOperacion = (gcnew System::Windows::Forms::NumericUpDown());
			this->txtCapacidad = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->grpBoxPrincipal->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtHorasOperacion))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtCapacidad))->BeginInit();
			this->SuspendLayout();
			// 
			// btnGrabar
			// 
			this->btnGrabar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnGrabar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGrabar->ForeColor = System::Drawing::Color::White;
			this->btnGrabar->Location = System::Drawing::Point(123, 355);
			this->btnGrabar->Margin = System::Windows::Forms::Padding(5);
			this->btnGrabar->Name = L"btnGrabar";
			this->btnGrabar->Size = System::Drawing::Size(173, 56);
			this->btnGrabar->TabIndex = 21;
			this->btnGrabar->Text = L"Grabar";
			this->btnGrabar->UseVisualStyleBackColor = false;
			this->btnGrabar->Click += gcnew System::EventHandler(this, &frmNuevaCeldaBD::btnGrabar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnCancelar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancelar->ForeColor = System::Drawing::Color::White;
			this->btnCancelar->Location = System::Drawing::Point(361, 355);
			this->btnCancelar->Margin = System::Windows::Forms::Padding(5);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(173, 56);
			this->btnCancelar->TabIndex = 22;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = false;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &frmNuevaCeldaBD::btnCancelar_Click);
			// 
			// grpBoxPrincipal
			// 
			this->grpBoxPrincipal->Controls->Add(this->txtHorasOperacion);
			this->grpBoxPrincipal->Controls->Add(this->txtCapacidad);
			this->grpBoxPrincipal->Controls->Add(this->label3);
			this->grpBoxPrincipal->Controls->Add(this->label2);
			this->grpBoxPrincipal->Controls->Add(this->cmbTipo);
			this->grpBoxPrincipal->Controls->Add(this->cmbEstado);
			this->grpBoxPrincipal->Controls->Add(this->txtNombre);
			this->grpBoxPrincipal->Controls->Add(this->label6);
			this->grpBoxPrincipal->Controls->Add(this->label5);
			this->grpBoxPrincipal->Controls->Add(this->label4);
			this->grpBoxPrincipal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpBoxPrincipal->Location = System::Drawing::Point(14, 14);
			this->grpBoxPrincipal->Margin = System::Windows::Forms::Padding(5);
			this->grpBoxPrincipal->Name = L"grpBoxPrincipal";
			this->grpBoxPrincipal->Padding = System::Windows::Forms::Padding(5);
			this->grpBoxPrincipal->Size = System::Drawing::Size(619, 314);
			this->grpBoxPrincipal->TabIndex = 23;
			this->grpBoxPrincipal->TabStop = false;
			this->grpBoxPrincipal->Text = L"Información general de la Celda de Procesos";
			// 
			// cmbTipo
			// 
			this->cmbTipo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbTipo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbTipo->FormattingEnabled = true;
			this->cmbTipo->Location = System::Drawing::Point(216, 91);
			this->cmbTipo->Name = L"cmbTipo";
			this->cmbTipo->Size = System::Drawing::Size(215, 30);
			this->cmbTipo->TabIndex = 3;
			// 
			// cmbEstado
			// 
			this->cmbEstado->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbEstado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbEstado->FormattingEnabled = true;
			this->cmbEstado->Location = System::Drawing::Point(216, 142);
			this->cmbEstado->Name = L"cmbEstado";
			this->cmbEstado->Size = System::Drawing::Size(215, 30);
			this->cmbEstado->TabIndex = 4;
			// 
			// txtNombre
			// 
			this->txtNombre->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtNombre->Location = System::Drawing::Point(216, 43);
			this->txtNombre->Margin = System::Windows::Forms::Padding(5);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(377, 28);
			this->txtNombre->TabIndex = 2;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(13, 142);
			this->label6->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(73, 24);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Estado:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 91);
			this->label5->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 24);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Tipo:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 43);
			this->label4->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(84, 24);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Nombre:";
			// 
			// txtHorasOperacion
			// 
			this->txtHorasOperacion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtHorasOperacion->DecimalPlaces = 2;
			this->txtHorasOperacion->Location = System::Drawing::Point(216, 245);
			this->txtHorasOperacion->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5000, 0, 0, 0 });
			this->txtHorasOperacion->Name = L"txtHorasOperacion";
			this->txtHorasOperacion->Size = System::Drawing::Size(215, 28);
			this->txtHorasOperacion->TabIndex = 15;
			// 
			// txtCapacidad
			// 
			this->txtCapacidad->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtCapacidad->DecimalPlaces = 2;
			this->txtCapacidad->Location = System::Drawing::Point(216, 198);
			this->txtCapacidad->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5000, 0, 0, 0 });
			this->txtCapacidad->Name = L"txtCapacidad";
			this->txtCapacidad->Size = System::Drawing::Size(215, 28);
			this->txtCapacidad->TabIndex = 14;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 247);
			this->label3->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(186, 24);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Horas de Operacion:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 200);
			this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(152, 24);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Capacidad Kg/H:";
			// 
			// frmNuevaCeldaBD
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->ClientSize = System::Drawing::Size(667, 453);
			this->Controls->Add(this->btnGrabar);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->grpBoxPrincipal);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->Name = L"frmNuevaCeldaBD";
			this->Text = L"frmNuevaCeldaBD";
			this->Load += gcnew System::EventHandler(this, &frmNuevaCeldaBD::frmNuevaCeldaBD_Load);
			this->grpBoxPrincipal->ResumeLayout(false);
			this->grpBoxPrincipal->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtHorasOperacion))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtCapacidad))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmNuevaCeldaBD_Load(System::Object^ sender, System::EventArgs^ e) {
		ComboHelper::LlenarComboTipoCelda(this->cmbTipo, 0);
		ComboHelper::LlenarComboEstadoCelda(this->cmbEstado, 0);
	}
	private: System::Void btnGrabar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Aquí puedes agregar la lógica para grabar la nueva EstacionClasificadora utilizando el controlador
		String^ nombre = txtNombre->Text;
		String^ sCapacidad = txtCapacidad->Text;
		String^ sHorasOperacion = txtHorasOperacion->Text;
		// Validar los campos antes de guardar
		if (nombre->Equals("") || cmbTipo->SelectedIndex == -1 || cmbEstado->SelectedIndex == -1 || sCapacidad->Equals("") || sHorasOperacion->Equals("")) {
			MessageBox::Show("Por favor, complete todos los campos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		String^ tipo = Convert::ToString(cmbTipo->Text);
		String^ estado = Convert::ToString(cmbEstado->Text);
		double capacidad = 0.0;
		double horasOperacion = 0.0;
		if (!Double::TryParse(sCapacidad, capacidad)) {
			MessageBox::Show("Error: La capacidad debe ser un valor numérico válido (ej. 23.4).",
				"Error de validación", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return; // Detiene la ejecución y evita que se guarde el registro
		}
		if (!Double::TryParse(sHorasOperacion, horasOperacion)) {
			MessageBox::Show("Error: Las horas de operación deben ser un valor numérico válido (ej. 8.0).",
				"Error de validación", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return; // Detiene la ejecución y evita que se guarde el registro
		}

		//Creando la nueva celda de proceso
		Celda^ nuevaCelda = gcnew Celda(nombre,	tipo, estado, capacidad, horasOperacion);
		// Llamando al controlador para registrar la nueva celda
		CeldaController^ celdaController = gcnew CeldaController();
		String^ resultado = celdaController->AgregarCeldaSP(nuevaCelda);
		if (resultado == "") {
			MessageBox::Show("Celda del Proceso agregada exitosamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close(); // Cierra el formulario actual
		}
		else {
			MessageBox::Show("Error al agregar la celda de proceso: " + Environment::NewLine + resultado, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
	}
	private: System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close(); // Cierra el formulario actual
	}
};
}
