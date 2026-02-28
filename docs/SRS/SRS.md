# Software Requirements Specification (SRS)
## Sistema de Extracción de Texto con ESP32

**Versión:** 1.0 (Borrador)
**Fecha:** 27 de Febrero 2026
**Equipo:** Emiliano, German, Alejandro

## 1. Introducción

### 1.1 Propósito
Este documento describe los requerimientos funcionales y no funcionales para el desarrollo de un sistema embebido de extracción de texto mediante cámara y ESP32. Está dirigido al equipo de desarrollo y al profesor para validar el alcance del proyecto.

### 1.2 Alcance
El sistema permitirá capturar imágenes a través de una cámara OV2640 conectada a un ESP32, procesarlas para mejorar la calidad del reconocimiento, extraer el texto contenido mediante OCR optimizado, y almacenar los resultados en una tarjeta SD.

### 1.3 Definiciones y Acrónimos
- **ESP32:** Microcontrolador de 32 bits con WiFi y Bluetooth integrado
- **OCR:** Optical Character Recognition (Reconocimiento Óptico de Caracteres)
- **OV2640:** Sensor de imagen de 2 megapíxeles
- **SRS:** Software Requirements Specification
- **DoR:** Definition of Ready
- **DoD:** Definition of Done

## 2. Descripción General

### 2.1 Perspectiva del Producto
El producto es un sistema embebido independiente que no depende de otros sistemas para su funcionamiento básico. Opcionalmente puede utilizar conectividad WiFi para enviar imágenes a servicios externos de OCR si el procesamiento local no es suficiente.

### 2.2 Funcionalidad del Producto
- Captura de imágenes mediante cámara digital
- Procesamiento y optimización de imágenes
- Reconocimiento óptico de caracteres (OCR)
- Almacenamiento de resultados en tarjeta SD
- Indicadores visuales de estado mediante LEDs
- Opcional: comunicación WiFi para OCR externo

### 2.3 Características de los Usuarios
- **Usuarios finales:** Personas con conocimientos básicos de tecnología que necesitan digitalizar texto.
- **Desarrolladores:** Estudiantes o ingenieros que puedan modificar o extender el sistema.

### 2.4 Restricciones
- Memoria RAM del ESP32 limitada a 520 KB
- Procesamiento OCR debe ser optimizado para evitar latencias
- Alimentación: 5V vía USB o batería

## 3. Requerimientos Específicos

### 3.1 Requerimientos Funcionales

#### RF-01: Captura de Imágenes
- **Descripción:** El sistema debe capturar imágenes a través de la cámara OV2640 conectada al ESP32
- **Entradas:** Señal del botón de captura
- **Salidas:** Archivo de imagen en formato JPEG almacenado temporalmente en memoria
- **Prioridad:** Alta

#### RF-02: Almacenamiento en SD
- **Descripción:** El sistema debe guardar las imágenes capturadas en una tarjeta SD
- **Entradas:** Imagen capturada
- **Salidas:** Archivo de imagen en tarjeta SD con nombre único (timestamp)
- **Prioridad:** Alta

#### RF-03: Procesamiento de Imagen
- **Descripción:** El sistema debe aplicar técnicas de pre-procesamiento para optimizar el OCR
- **Entradas:** Imagen JPEG capturada
- **Salidas:** Imagen procesada (escala de grises, umbralizada, filtrada)
- **Prioridad:** Alta

#### RF-04: Reconocimiento de Texto (OCR)
- **Descripción:** El sistema debe extraer texto de las imágenes procesadas
- **Entradas:** Imagen procesada
- **Salidas:** Texto extraído en formato string
- **Prioridad:** Alta

#### RF-05: Almacenamiento de Resultados
- **Descripción:** El sistema debe guardar el texto extraído en la tarjeta SD
- **Entradas:** Texto extraído
- **Salidas:** Archivo de texto en tarjeta SD con nombre relacionado a la imagen
- **Prioridad:** Media

#### RF-06: Indicadores de Estado
- **Descripción:** El sistema debe usar LEDs para indicar su estado operativo
- **Entradas:** Estado interno del sistema
- **Salidas:** LEDs encendidos según estado (capturando, procesando, éxito, error)
- **Prioridad:** Media

#### RF-07: Botón de Captura
- **Descripción:** El sistema debe responder a un botón físico para iniciar la captura
- **Entradas:** Pulsación de botón
- **Salidas:** Inicio del proceso de captura y reconocimiento
- **Prioridad:** Alta

### 3.2 Requerimientos No Funcionales

#### RNF-01: Tiempo de Procesamiento
- **Descripción:** El tiempo total desde captura hasta texto extraído debe ser menor a 10 segundos
- **Prioridad:** Alta

#### RNF-02: Precisión del OCR
- **Descripción:** La precisión del reconocimiento debe ser al menos 80% en condiciones de buena iluminación
- **Prioridad:** Alta

#### RNF-03: Consumo de Memoria
- **Descripción:** El sistema debe operar dentro de los límites de memoria del ESP32 (520 KB SRAM)
- **Prioridad:** Alta

#### RNF-04: Portabilidad
- **Descripción:** El dispositivo debe ser portable y poder funcionar con batería
- **Prioridad:** Media

#### RNF-05: Robustez
- **Descripción:** El sistema debe manejar errores sin bloquearse (timeouts, memoria insuficiente, etc.)
- **Prioridad:** Media

## 4. Restricciones de Diseño

### 4.1 Hardware
- Microcontrolador: ESP32 (cualquier variante compatible)
- Cámara: OV2640 con interfaz parallel
- Almacenamiento: Módulo lector de tarjetas microSD (SPI)
- Interfaz: LEDs indicadores y botón de captura

### 4.2 Software
- Lenguaje de programación: C/C++
- Entorno de desarrollo: PlatformIO o Arduino IDE
- Librerías: ESP32 Camera, TensorFlow Lite Micro, SD card, FS
- Sistema de archivos: FAT32 para SD

### 4.3 Interfaz de Usuario
- Botón físico para iniciar captura
- LEDs para retroalimentación visual
- Opcional: Puerto serie para depuración

## 5. Requerimientos de Documentación

- Manual de usuario con instrucciones de operación
- Documentación técnica del código
- Esquemático de conexiones
- Guía de solución de problemas comunes