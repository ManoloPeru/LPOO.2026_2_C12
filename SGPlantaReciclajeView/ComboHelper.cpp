#include "ComboHelper.h"

namespace SGPlantaReciclajeView {

    // ============================================================
    // LlenarComboTipoEstacion
    // ============================================================
    void ComboHelper::LlenarComboTipoEstacion(ComboBox^ cmbTipo, int idSeleccionado) {
        // 1. Obtener la lista de tipos desde el Controller
        TipoEstacionClasificadoraController^ tipoController = gcnew TipoEstacionClasificadoraController();
        List<TipoEstacionClasificadora^>^ listaTipos = tipoController->ListarTipos();

        // 2. Limpiar el ComboBox antes de poblarlo
        cmbTipo->Items->Clear();

        // 3. Crear la lista de pares clave-valor (ID → Descripción)
        List<KeyValuePair<String^, String^>>^ items = gcnew List<KeyValuePair<String^, String^>>();

        for each (TipoEstacionClasificadora ^ tipo in listaTipos) {
            KeyValuePair<String^, String^> option(tipo->getIdTipoEstacion().ToString(), tipo->getDescripcion());
            items->Add(option);
        }

        // 4. Asignar el DataSource y los miembros de visualización
        cmbTipo->DataSource = items;
        cmbTipo->DisplayMember = "Value";  // Muestra la descripción
        cmbTipo->ValueMember = "Key";      // Mantiene el ID como valor

        // 5. Preseleccionar el ítem correspondiente al idSeleccionado
        SeleccionarPorId(cmbTipo, idSeleccionado);
    }

    // ============================================================
    // LlenarComboEstadoEstacion
    // ============================================================
    void ComboHelper::LlenarComboEstadoEstacion(ComboBox^ cmbEstado, int idSeleccionado) {
        // 1. Obtener la lista de estados desde el Controller
        EstadoOperativoController^ estadoController = gcnew EstadoOperativoController();
        List<EstadoOperativo^>^ listaEstados = estadoController->ListarEstados();

        // 2. Limpiar el ComboBox antes de poblarlo
        cmbEstado->Items->Clear();

        // 3. Crear la lista de pares clave-valor (ID → Descripción)
        List<KeyValuePair<String^, String^>>^ items = gcnew List<KeyValuePair<String^, String^>>();

        for each (EstadoOperativo ^ estado in listaEstados) {
            items->Add(KeyValuePair<String^, String^>(estado->getIdEstadoOperativo().ToString(), estado->getDescripcion()));
        }

        // 4. Asignar el DataSource y los miembros de visualización
        cmbEstado->DataSource = items;
        cmbEstado->DisplayMember = "Value";
        cmbEstado->ValueMember = "Key";

        // 5. Preseleccionar el ítem correspondiente al idSeleccionado
        SeleccionarPorId(cmbEstado, idSeleccionado);
    }

    // ============================================================
    // LlenarComboTipoCelda
    // ============================================================
    void ComboHelper::LlenarComboTipoCelda(ComboBox^ cmbTipo, int idSeleccionado) {
        // 1. Obtener la lista de tipos desde el Controller
        TipoCeldaController^ tipoController = gcnew TipoCeldaController();
        List<TipoCelda^>^ listaTipos = tipoController->ListarTipos();

        // 2. Limpiar el ComboBox antes de poblarlo
        cmbTipo->Items->Clear();

        // 3. Crear la lista de pares clave-valor (ID → Descripción)
        List<KeyValuePair<String^, String^>>^ items = gcnew List<KeyValuePair<String^, String^>>();

        for each (TipoCelda ^ tipo in listaTipos) {
            KeyValuePair<String^, String^> option(tipo->getIdTipoCelda().ToString(), tipo->getDescripcion());
            items->Add(option);
        }

        // 4. Asignar el DataSource y los miembros de visualización
        cmbTipo->DataSource = items;
        cmbTipo->DisplayMember = "Value";  // Muestra la descripción
        cmbTipo->ValueMember = "Key";      // Mantiene el ID como valor

        // 5. Preseleccionar el ítem correspondiente al idSeleccionado
        SeleccionarPorId(cmbTipo, idSeleccionado);
    }

    void ComboHelper::LlenarComboTipoCelda(ComboBox^ cmbTipo, String^ sSeleccionado) {
        // 1. Obtener la lista de tipos desde el Controller
        TipoCeldaController^ tipoController = gcnew TipoCeldaController();
        List<TipoCelda^>^ listaTipos = tipoController->ListarTipos();

        // 2. Limpiar el ComboBox antes de poblarlo
        cmbTipo->Items->Clear();

        // 3. Crear la lista de pares clave-valor (ID → Descripción)
        List<KeyValuePair<String^, String^>>^ items = gcnew List<KeyValuePair<String^, String^>>();

        for each (TipoCelda ^ tipo in listaTipos) {
            KeyValuePair<String^, String^> option(tipo->getIdTipoCelda().ToString(), tipo->getDescripcion());
            items->Add(option);
        }

        // 4. Asignar el DataSource y los miembros de visualización
        cmbTipo->DataSource = items;
        cmbTipo->DisplayMember = "Value";  // Muestra la descripción
        cmbTipo->ValueMember = "Key";      // Mantiene el ID como valor

        // 5. Preseleccionar el ítem correspondiente al idSeleccionado
        SeleccionarPorText(cmbTipo, sSeleccionado);
    }

    // ============================================================
    // LlenarComboEstadoCelda
    // ============================================================
    void ComboHelper::LlenarComboEstadoCelda(ComboBox^ cmbEstado, int idSeleccionado) {
        // 1. Obtener la lista de estados desde el Controller
        EstadoCeldaController^ estadoController = gcnew EstadoCeldaController();
        List<EstadoCelda^>^ listaEstados = estadoController->ListarEstados();

        // 2. Limpiar el ComboBox antes de poblarlo
        cmbEstado->Items->Clear();

        // 3. Crear la lista de pares clave-valor (ID → Descripción)
        List<KeyValuePair<String^, String^>>^ items = gcnew List<KeyValuePair<String^, String^>>();

        for each (EstadoCelda ^ estado in listaEstados) {
            items->Add(KeyValuePair<String^, String^>(estado->getIdEstadoCelda().ToString(), estado->getDescripcion()));
        }

        // 4. Asignar el DataSource y los miembros de visualización
        cmbEstado->DataSource = items;
        cmbEstado->DisplayMember = "Value";
        cmbEstado->ValueMember = "Key";

        // 5. Preseleccionar el ítem correspondiente al idSeleccionado
        SeleccionarPorId(cmbEstado, idSeleccionado);
    }

    void ComboHelper::LlenarComboEstadoCelda(ComboBox^ cmbEstado, String^ sSeleccionado) {
        // 1. Obtener la lista de estados desde el Controller
        EstadoCeldaController^ estadoController = gcnew EstadoCeldaController();
        List<EstadoCelda^>^ listaEstados = estadoController->ListarEstados();

        // 2. Limpiar el ComboBox antes de poblarlo
        cmbEstado->Items->Clear();

        // 3. Crear la lista de pares clave-valor (ID → Descripción)
        List<KeyValuePair<String^, String^>>^ items = gcnew List<KeyValuePair<String^, String^>>();

        for each (EstadoCelda ^ estado in listaEstados) {
            items->Add(KeyValuePair<String^, String^>(estado->getIdEstadoCelda().ToString(), estado->getDescripcion()));
        }

        // 4. Asignar el DataSource y los miembros de visualización
        cmbEstado->DataSource = items;
        cmbEstado->DisplayMember = "Value";
        cmbEstado->ValueMember = "Key";

        // 5. Preseleccionar el ítem correspondiente al idSeleccionado
        SeleccionarPorText(cmbEstado, sSeleccionado);
    }

    // ============================================================
    // ObtenerIdSeleccionado
    // ============================================================
    int ComboHelper::ObtenerIdSeleccionado(ComboBox^ cmb) {
        if (cmb->SelectedIndex == -1 || cmb->SelectedItem == nullptr) {
            return -1;
        }
        KeyValuePair<String^, String^> item = safe_cast<KeyValuePair<String^, String^>>(cmb->SelectedItem);
        return Convert::ToInt32(item.Key);
    }

    // ============================================================
    // Método privado: SeleccionarPorId
    // ============================================================
    void ComboHelper::SeleccionarPorId(ComboBox^ cmb, int idSeleccionado) {
        if (idSeleccionado <= 0) {
            cmb->SelectedIndex = -1;
            return;
        }

        for (int i = 0; i < cmb->Items->Count; i++) {
            KeyValuePair<String^, String^> item = safe_cast<KeyValuePair<String^, String^>>(cmb->Items[i]);
            if (Convert::ToInt32(item.Key) == idSeleccionado) {
                cmb->SelectedIndex = i; //Retorna la posición en donde esta ubicado el elemento, dentro del Combo
                return;
            }
        }
        // Si no se encontró, no seleccionar nada
        cmb->SelectedIndex = -1;
    }

    void ComboHelper::SeleccionarPorText(ComboBox^ cmb, String^ textSeleccionado) {
        if (String::IsNullOrEmpty(textSeleccionado)) {
            cmb->SelectedIndex = -1;
            return;
        }

        for (int i = 0; i < cmb->Items->Count; i++) {
            KeyValuePair<String^, String^> item = safe_cast<KeyValuePair<String^, String^>>(cmb->Items[i]);
            if (item.Value->Equals(textSeleccionado)) {
                cmb->SelectedIndex = i; //Retorna la posición en donde esta ubicado el elemento, dentro del Combo
                return;
            }
        }
        // Si no se encontró, no seleccionar nada
        cmb->SelectedIndex = -1;
    }

    // ============================================================
    // LlenarComboEstadoEstacionBD
    // ============================================================
    void ComboHelper::LlenarComboEstadoEstacionBD(ComboBox^ cmbEstado, int idSeleccionado) {
        // 1. Obtener la lista de estados desde el Controller
        EstadoOperativoController^ estadoController = gcnew EstadoOperativoController();
        List<EstadoOperativo^>^ listaEstados = estadoController->ListarEstadosSQL();

        // 2. Limpiar el ComboBox antes de poblarlo
        cmbEstado->Items->Clear();

        // 3. Crear la lista de pares clave-valor (ID → Descripción)
        List<KeyValuePair<String^, String^>>^ items = gcnew List<KeyValuePair<String^, String^>>();

        for each (EstadoOperativo ^ estado in listaEstados) {
            items->Add(KeyValuePair<String^, String^>(estado->getIdEstadoOperativo().ToString(), estado->getDescripcion()));
        }

        // 4. Asignar el DataSource y los miembros de visualización
        cmbEstado->DataSource = items;
        cmbEstado->DisplayMember = "Value";
        cmbEstado->ValueMember = "Key";

        // 5. Preseleccionar el ítem correspondiente al idSeleccionado
        SeleccionarPorId(cmbEstado, idSeleccionado);
    }

    // ============================================================
    // LlenarComboEstaciones
    // ============================================================
    void ComboHelper::LlenarComboEstaciones(ComboBox^ cmbEstacion, int idSeleccionado) {
        // 1. Obtener la lista de estaciones desde el Controller
        EstacionController^ estacionCtrl = gcnew EstacionController();
        List<Estacion^>^ listaEstaciones = estacionCtrl->ListarEstaciones();

        // 2. Limpiar el ComboBox antes de poblarlo
        cmbEstacion->Items->Clear();

        // 3. Crear la lista de pares clave-valor (ID → Alias)
        List<KeyValuePair<String^, String^>>^ items = gcnew List<KeyValuePair<String^, String^>>();

        for each (Estacion ^ est in listaEstaciones) {
            items->Add(KeyValuePair<String^, String^>(est->getEstacionId().ToString(), est->getAlias()));
        }

        // 4. Asignar el DataSource y los miembros de visualización
        cmbEstacion->DataSource = items;
        cmbEstacion->DisplayMember = "Value"; // Muestra el Alias
        cmbEstacion->ValueMember = "Key";     // Mantiene el ID oculto

        // 5. Preseleccionar el ítem correspondiente al idSeleccionado
        SeleccionarPorId(cmbEstacion, idSeleccionado);
    }
}