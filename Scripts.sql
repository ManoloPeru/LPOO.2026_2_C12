-- 1 ELIMINAMOS LA TABLA POR SI YA EXISTIERA
DROP TABLE Usuario;

-- 2. CREAMOS LA TABLA
CREATE TABLE Usuario(
	idUsuario int PRIMARY KEY IDENTITY(1,1) NOT NULL,
	nombres varchar(50) NOT NULL,
	apellidos varchar(50) NOT NULL,
	correo varchar(50) NOT NULL,
	usuario varchar(12) NOT NULL,
	contrasenia varchar(25) NOT NULL,
	estado char(1) NOT NULL DEFAULT ('A')
);

-- 3. Aquí van todos tus INSERT generados
INSERT Usuario (nombres, apellidos, correo, usuario, contrasenia, estado) 
VALUES ('Manuel', 'Chávez', 'mhchavez@pucp.pe', 'admin', 'admin', 'A');
-- ... resto de inserts

DROP TABLE Estacion;

CREATE TABLE Estacion (
EstacionId INT PRIMARY KEY IDENTITY(1,1) NOT NULL,
Alias NVARCHAR(100),
Ubicacion NVARCHAR(100),
Estado INT,
CapacidadKgH FLOAT,
HorasOperacion FLOAT
);
-- Insertar estaciones clasificadoras de ejemplo
INSERT INTO Estacion VALUES ('Separador Magnético A', 'Zona de Extracción de Metales', 1, 480.0, 1250.5);
INSERT INTO Estacion VALUES ('Brazo Neumático B', 'Línea de Clasificación 2', 2, 320.0, 850.0);
INSERT INTO Estacion VALUES ('Estación Óptica C', 'Zona de Compactación', 1, 610.0, 3100.2);


DROP TABLE EstadoOperativo;

CREATE TABLE EstadoOperativo (
idEstadoOperativo INT PRIMARY KEY IDENTITY(1,1) NOT NULL,
descripcion NVARCHAR(100)
);
-- Insertar estaciones clasificadoras de ejemplo
INSERT INTO EstadoOperativo VALUES ('Operativo');
INSERT INTO EstadoOperativo VALUES ('En Mantenimiento');
INSERT INTO EstadoOperativo VALUES ('Falla Crítica');
INSERT INTO EstadoOperativo VALUES ('Apagado');

DROP TABLE Celda;

-- Creación de la tabla para las celdas de proceso
CREATE TABLE Celda (
    CeldaId int PRIMARY KEY IDENTITY(1,1) NOT NULL,
    Nombre NVARCHAR(100) NOT NULL,
    Tipo NVARCHAR(100) NOT NULL,
    Estado NVARCHAR(50) NOT NULL,
    Capacidad FLOAT NOT NULL,
    HorasOperacion FLOAT
);
GO

-- Inserción 1: Celda de Trituración
INSERT INTO Celda (Nombre, Tipo, Estado, Capacidad, HorasOperacion)
VALUES ('Módulo de Trituración Primaria', 'Trituración', 'Activa', 480.0, 1250.5);
-- Inserción 2: Celda de Lavado
INSERT INTO Celda (Nombre, Tipo, Estado, Capacidad, HorasOperacion)
VALUES ('Celda de Lavado por Flotación', 'Lavado', 'En Configuración', 320.0, 850.0);
-- Inserción 3: Celda de Compactación
INSERT INTO Celda (Nombre, Tipo, Estado, Capacidad, HorasOperacion)
VALUES ('Estación de Compactación C', 'Compactación', 'Activa', 610.0, 3100.2);
GO

-- =============================================================
-- 1. PROCEDIMIENTO PARA RESTRICCIÓN E INSERCIÓN DE UNA CELDA
-- =============================================================
IF OBJECT_ID('dbo.usp_AddCelda', 'P') IS NOT NULL
DROP PROCEDURE usp_AddCelda;
GO
CREATE PROCEDURE usp_AddCelda
@Nombre NVARCHAR(100),
@Tipo NVARCHAR(100),
@Estado NVARCHAR(50),
@Capacidad FLOAT,
@HorasOperacion FLOAT
AS
BEGIN
    SET NOCOUNT ON;
    -- Se inserta sin el ID, ya que es IDENTITY
    INSERT INTO Celda (Nombre, Tipo, Estado, Capacidad, HorasOperacion)
    VALUES (@Nombre, @Tipo, @Estado, @Capacidad, @HorasOperacion);
    
    -- Se retorna el ID generado (útil para tu DAO en C++/CLI)
    SELECT SCOPE_IDENTITY() AS NuevoCeldaId;
END;
GO

-- =============================================================
-- 2. PROCEDIMIENTO PARA CONSULTAR TODAS LAS CELDAS
-- =============================================================
IF OBJECT_ID('dbo.usp_QueryAllCeldas', 'P') IS NOT NULL
DROP PROCEDURE usp_QueryAllCeldas;
GO
CREATE PROCEDURE usp_QueryAllCeldas
AS
BEGIN   
    SET NOCOUNT ON;
    SELECT CeldaId, Nombre, Tipo, Estado, Capacidad, HorasOperacion
    FROM Celda;
END;
GO

-- =============================================================
-- 3. PROCEDIMIENTO PARA ACTUALIZAR PARÁMETROS OPERATIVOS
-- =============================================================
IF OBJECT_ID('dbo.usp_UpdateCelda', 'P') IS NOT NULL
DROP PROCEDURE usp_UpdateCelda;
GO
CREATE PROCEDURE usp_UpdateCelda
@CeldaId INT,
@Nombre NVARCHAR(100),
@Tipo NVARCHAR(100),
@Estado NVARCHAR(50),
@Capacidad FLOAT,
@HorasOperacion FLOAT
AS
BEGIN
    SET NOCOUNT ON;
    UPDATE Celda
    SET Nombre = @Nombre,
        Tipo = @Tipo,
        Estado = @Estado,
        Capacidad = @Capacidad,
        HorasOperacion = @HorasOperacion
    WHERE CeldaId = @CeldaId;
END;
GO

-- =============================================================
-- 4. PROCEDIMIENTO PARA ELIMINAR UNA CELDA
-- =============================================================
IF OBJECT_ID('dbo.usp_DeleteCelda', 'P') IS NOT NULL
DROP PROCEDURE usp_DeleteCelda;
GO
CREATE PROCEDURE usp_DeleteCelda
@CeldaId INT
AS
BEGIN
    SET NOCOUNT ON;
    DELETE FROM Celda
    WHERE CeldaId = @CeldaId;
END;
GO

-- Verificar y eliminar tablas existentes respetando el orden de dependencia (primero el detalle)
IF OBJECT_ID('dbo.MantenimientoDetalle', 'U') IS NOT NULL
DROP TABLE MantenimientoDetalle;
GO
IF OBJECT_ID('dbo.MantenimientoCabecera', 'U') IS NOT NULL
DROP TABLE MantenimientoCabecera;
GO
-- =============================================================
-- 1. CREACIÓN DE TABLAS (MAESTRO - DETALLE)
-- =============================================================
-- Tabla Maestro: Cabecera del Mantenimiento
CREATE TABLE MantenimientoCabecera (
MantenimientoId INT PRIMARY KEY IDENTITY(1,1),
EstacionId INT,
FechaMantenimiento DATETIME DEFAULT GETDATE(),
Tecnico NVARCHAR(100),
TipoMantenimiento NVARCHAR(50), -- e.g., 'Preventivo', 'Correctivo', 'Calibración'
FOREIGN KEY (EstacionId) REFERENCES Estacion(EstacionId)
);
GO
-- Tabla Detalle: Actividades específicas ejecutadas
CREATE TABLE MantenimientoDetalle (
MantenimientoDetailId INT PRIMARY KEY IDENTITY(1,1),
MantenimientoId INT,
Actividad NVARCHAR(200), -- e.g., 'Lubricación de rodamientos', 'Calibración de home'
DuracionMinutos INT,
FOREIGN KEY (MantenimientoId) REFERENCES MantenimientoCabecera(MantenimientoId)
);
GO
-- =============================================================
-- 2. PROCEDIMIENTOS ALMACENADOS (STORED PROCEDURES)
-- =============================================================
-- Procedimiento para registrar la Cabecera (Retorna el ID generado)
IF OBJECT_ID('dbo.usp_CreateMantenimiento', 'P') IS NOT NULL
DROP PROCEDURE usp_CreateMantenimiento;
GO
CREATE PROCEDURE usp_CreateMantenimiento 
    @EstacionId INT, 
    @Tecnico NVARCHAR(100), 
    @TipoMantenimiento NVARCHAR(50), 
    @FechaMantenimiento DATETIME, 
    @MantenimientoId INT OUTPUT
AS 
BEGIN 
     INSERT INTO MantenimientoCabecera (EstacionId, FechaMantenimiento, Tecnico, TipoMantenimiento) 
     VALUES (@EstacionId, @FechaMantenimiento, @Tecnico, @TipoMantenimiento);
     SET @MantenimientoId = SCOPE_IDENTITY();
END;
GO

-- Procedimiento para insertar cada Actividad en el Detalle
IF OBJECT_ID('dbo.usp_AddMantenimientoDetail', 'P') IS NOT NULL
DROP PROCEDURE usp_AddMantenimientoDetail;
GO

CREATE PROCEDURE usp_AddMantenimientoDetail
    @MantenimientoId INT,
    @Actividad NVARCHAR(200),
    @DuracionMinutos INT
AS
BEGIN
    SET NOCOUNT ON;
    INSERT INTO MantenimientoDetalle (MantenimientoId, Actividad, DuracionMinutos)
    VALUES (@MantenimientoId, @Actividad, @DuracionMinutos);
END;
GO

IF OBJECT_ID('dbo.usp_QueryAllMantenimientos', 'P') IS NOT NULL
DROP PROCEDURE usp_QueryAllMantenimientos;
GO
CREATE PROCEDURE usp_QueryAllMantenimientos
AS
BEGIN
    SELECT MantenimientoId, EstacionId, Tecnico, TipoMantenimiento, FechaMantenimiento
    FROM MantenimientoCabecera;
END;
GO

IF OBJECT_ID('dbo.usp_QueryDetallesByMantenimiento', 'P') IS NOT NULL
DROP PROCEDURE usp_QueryDetallesByMantenimiento;
GO
CREATE PROCEDURE usp_QueryDetallesByMantenimiento
@MantenimientoId INT
AS
BEGIN
    SET NOCOUNT ON;
    SELECT MantenimientoDetailId, Actividad, DuracionMinutos
    FROM MantenimientoDetalle
    WHERE MantenimientoId = @MantenimientoId;
END;
GO