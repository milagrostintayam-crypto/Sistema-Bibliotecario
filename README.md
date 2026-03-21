# Sistema Bibliotecario

Sistema de gestión bibliotecaria desarrollado en C++ que permite administrar libros, usuarios, préstamos y devoluciones de manera eficiente.

## 📋 Estado Actual del Sistema

El proyecto se encuentra en **etapa de desarrollo avanzado**, con arquitectura modular y clases base implementadas.

### ✅ Componentes Implementados

#### **Gestión de Libros**
- Clase `Libro`: Almacena información de libros (ID, título, cantidad disponible)
- Clase `Repository`: Sistema de almacenamiento de libros con capacidad configurable (máx. 100 libros)
  - Método para cargar datos
  - Consulta de libros disponibles
  - Control de cantidad de libros

#### **Gestión de Usuarios**
- Clase `Usuario`: Registro individual con DNI, nombre, teléfono y dirección
- Clase `Usuarios`: Contenedor dinámico de usuarios
  - Agregar usuarios
  - Buscar por DNI
  - Mostrar listado de usuarios
  - Redimensionamiento automático

#### **Sistema de Préstamos**
- Clase `Prestamo`: Registro de transacciones con fechas de préstamo/devolución
  - Asociación libro-usuario
  - Consulta de información de préstamo

#### **Interfaz de Usuario**
- Clase `Menu`: Sistema de menú interactivo
  - Integración con gestión de usuarios
  - Integración con repositorio de libros

### 🔄 Funcionalidades en Desarrollo

1. **Registrar Usuarios**: Sistema de registro de nuevos usuarios en el sistema
2. **Gestionar Libros**: Agregar, visualizar y controlar disponibilidad de libros
3. **Préstamo de Libros**: Registrar transacciones de préstamo a usuarios
4. **Devolución de Libros**: Procesar devoluciones y actualizar disponibilidad
5. **Reportes**: Estadísticas y consultas del sistema (estructura base en `Reportes.h`)
6. **Búsqueda**: Localizar usuarios y libros en el sistema

### 📁 Estructura del Proyecto

```
├── main.cpp                 # Entrada principal del programa
├── Menu.{h,cpp}            # Interfaz de menú interactivo
├── Usuario.{h,cpp}         # Clase de usuario individual
├── Usuarios.{h,cpp}        # Gestor de usuarios (contenedor dinámico)
├── Libro.{h,cpp}           # Clase de libro
├── Repository.{h,cpp}      # Almacén/gestor de libros
├── Prestamo.{h,cpp}        # Registro de préstamos
├── Prestamos.{h,cpp}       # Contenedor de préstamos (en desarrollo)
├── Devolucion.{h,cpp}      # Módulo de devoluciones (en desarrollo)
├── Reportes.{h,cpp}        # Generador de reportes (en desarrollo)
└── README.md
```

### 🎯 Características Técnicas

- **Lenguaje**: C++
- **Gestión de Memoria**: Punteros y asignación dinámica
- **Estructuras de Datos**: Arrays dinámicos con capacidad configurable
- **Arquitectura**: Orientada a objetos con separación de responsabilidades

## 👥 Colaboradores

- **Anfitrión**: milagrostintayam-crypto
- **Colaboradores**:
  - victor-huallpa
  - fiorelamv825-collab

## 📝 Notas de Desarrollo

- Sistema de persistencia de datos: En planificación
- Interfaz gráfica: Futura consideración
- Base de datos: Integración pendiente

## 📄 Licencia

Este proyecto no tiene licencia asignada actualmente.
