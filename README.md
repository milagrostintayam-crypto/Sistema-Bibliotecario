# Sistema Bibliotecario

Sistema de gestión bibliotecaria desarrollado en C++ que permite administrar libros, usuarios, préstamos y devoluciones de manera eficiente.

## 📋 Estado Actual del Sistema

El proyecto se encuentra en **etapa funcional**, con todas las características principales implementadas y operativas.

### ✅ Componentes Implementados

#### **Gestión de Libros**
- Clase `Libro`: Almacena información de libros (ID, título, cantidad disponible)
- Clase `Repository`: Sistema de almacenamiento de libros con capacidad configurable (máx. 100 libros)
  - ✅ Carga de datos de ejemplo
  - ✅ Visualización de libros disponibles
  - ✅ Decremento automático de stock al prestar
  - ✅ Incremento automático de stock al devolver
  - ✅ Consulta de cantidad disponible por libro

#### **Gestión de Usuarios**
- Clase `Usuario`: Registro individual con DNI, nombre, teléfono y dirección
- Clase `Usuarios`: Contenedor dinámico de usuarios
  - ✅ Agregar usuarios
  - ✅ Buscar por DNI
  - ✅ Mostrar listado completo de usuarios
  - ✅ Redimensionamiento automático de capacidad

#### **Sistema de Préstamos**
- Clase `Prestamo`: Registro individual de transacciones con fechas
  - ✅ Asociación libro-usuario
  - ✅ Consulta de información del préstamo
  - ✅ Acceso a fechas (préstamo y devolución)
  
- Clase `Prestamos`: Contenedor dinámico de préstamos
  - ✅ Agregar nuevos préstamos
  - ✅ Buscar préstamo por libro y usuario
  - ✅ Mostrar todos los préstamos activos
  - ✅ Eliminar préstamos (al devolver)
  - ✅ Redimensionamiento automático

#### **Sistema de Devoluciones**
- Clase `Devolucion`: Módulo de gestión de devoluciones
  - ✅ Procesar devoluciones de libros
  - ✅ Actualizar inventario automáticamente
  - ✅ Búsqueda de usuario por DNI con reintentos
  - ✅ Historial de devoluciones por fecha
  - ✅ Validación de préstamos activos

#### **Interfaz de Usuario**
- Clase `Menu`: Sistema de menú interactivo con 6 opciones funcionales
  - ✅ Ver libros disponibles
  - ✅ Registrar nuevos usuarios
  - ✅ Devolver libros
  - ✅ Prestar libros
  - ✅ Ver reportes y estadísticas
  - ✅ Salir del programa
  - Validación de entrada de datos
  - Confirmación de registro de usuarios durante préstamo
  - Manejo robusto de errores

### 🎮 Funcionalidades Operativas

1. **Mostrar Libros Disponibles**: Visualizar catálogo con ID, título y cantidad
2. **Registrar Usuarios**: Captura de DNI, nombre, teléfono y dirección
3. **Prestar Libros**: Selección de libro y usuario, con validación de disponibilidad
4. **Devolver Libros**: Procesamiento de devoluciones con búsqueda de usuario
5. **Reportes**: Visualización de prestamos activos e historial de devoluciones
6. **Gestión Automática**: Actualización de inventario en tiempo real

### 📁 Estructura del Proyecto

```
├── main.cpp                 # Punto de entrada del programa
├── Menu.{h,cpp}            # Sistema de menú interactivo
├── Usuario.{h,cpp}         # Clase de usuario individual
├── Usuarios.{h,cpp}        # Contenedor dinámico de usuarios
├── Libro.{h,cpp}           # Clase de libro
├── Repository.{h,cpp}      # Almacén/gestor de libros
├── Prestamo.{h,cpp}        # Registro individual de préstamo
├── Prestamos.{h,cpp}       # Contenedor dinámico de préstamos
├── Devolucion.{h,cpp}      # Módulo de devoluciones
├── Reportes.{h,cpp}        # Base para futuras estadísticas
└── README.md
```

### 🎯 Características Técnicas

- **Lenguaje**: C++ (Estándar C++98 compatible)
- **Gestión de Memoria**: Punteros y asignación dinámica con destructores
- **Estructuras de Datos**: Arrays dinámicos con redimensionamiento automático
- **Arquitectura**: Orientada a objetos con separación clara de responsabilidades
- **Validaciones**: Verificación de entrada de datos y manejo de casos especiales
- **Stack**: Sin dependencias externas, compilación directa

### 🚀 Cómo Ejecutar

1. Compilar el proyecto (dependiendo del compilador):
   ```bash
   g++ -o biblioteca *.cpp
   ```

2. Ejecutar:
   ```bash
   ./biblioteca
   ```

3. Seguir las opciones del menú interactivo

### 📊 Ejemplo de Uso

El sistema carga automáticamente 5 libros de ejemplo:
- Sistemas and Software (5 copias)
- 1984 (5 copias)
- Vampirito (2 copias)
- El Principito (3 copias)
- Orgullo y prejuicio (2 copias)

## 👥 Colaboradores

- **Anfitrión**: milagrostintayam-crypto
- **Colaboradores**:
  - victor-huallpa
  - fiorelamv825-collab

## 📝 Notas de Desarrollo

- **Datos**: Actualmente almacenados en memoria (sin persistencia en archivo)
- **Futuras mejoras**: 
  - Persistencia de datos en archivos
  - Base de datos integrada
  - Interfaz gráfica
  - Validación de fechas
  - Cálculo de multas por retrasos

## 📄 Licencia

Este proyecto no tiene licencia asignada actualmente.
