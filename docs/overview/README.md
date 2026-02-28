# Project Vision: Sistema de Extracción de Texto con ESP32

**Universidad:** Cuauhtémoc
**Curso:** Sistemas Embebidos
**Fecha:** 27 de Febrero 2026
**Versión:** 1.0

## High-Level Project Overview

### Business Problem
En la actualidad, extraer texto de imágenes o documentos físicos requiere el uso de computadoras con software especializado o servicios en la nube, lo que limita su aplicación en entornos donde no se dispone de estos recursos. Existe la necesidad de un sistema portátil, de bajo costo y autónomo que pueda capturar imágenes y extraer texto de ellas sin depender de una computadora o conexión a internet constante.

### Problem Statement
El problema que aborda este proyecto es la falta de una solución embebida, accesible y de bajo costo para la extracción de texto a partir de imágenes. Los stakeholders afectados incluyen estudiantes, investigadores, y profesionales que necesitan digitalizar texto de documentos impresos, letreros o cualquier superficie en entornos con recursos limitados. El impacto actual es la dependencia de equipos costosos o conexiones a internet. Una solución exitosa significaría tener un dispositivo portátil, autónomo y de bajo costo capaz de capturar y extraer texto de imágenes, democratizando el acceso a esta tecnología.

### Project Position
Este proyecto desarrollará un sistema embebido basado en ESP32 con cámara integrada, capaz de realizar reconocimiento óptico de caracteres (OCR) de manera local o asistida. A diferencia de soluciones basadas en computadoras o servicios en la nube, nuestra solución es portátil, de bajo costo y puede operar sin conexión a internet, siendo ideal para entornos con recursos limitados o aplicaciones de campo.

### Organizational Position
La Universidad Cuauhtémoc, a través del curso de Sistemas Embebidos, busca formar ingenieros capaces de desarrollar soluciones tecnológicas innovadoras con recursos limitados. Este proyecto demuestra la aplicación práctica de conceptos de sistemas embebidos, procesamiento de imágenes y optimización de recursos, alineándose con la misión de la universidad de formar profesionales competentes y socialmente responsables.

## User Description

### User Profiles
- **Estudiantes:** Usuarios con conocimientos técnicos básicos que desean digitalizar apuntes o textos para su estudio. Requieren una interfaz simple y resultados confiables.
- **Investigadores:** Profesionales que necesitan extraer texto de documentos, letreros o muestras en trabajo de campo. Valoran la portabilidad y autonomía del dispositivo.
- **Desarrolladores:** Usuarios con conocimientos avanzados que podrían querer modificar o extender las capacidades del sistema.

### User Environment
Los usuarios operarán en entornos variados: laboratorios, bibliotecas, trabajo de campo, etc. El dispositivo debe ser portátil, alimentado por batería, con interfaz simple y capaz de almacenar resultados para su posterior recuperación.

### Current User Needs
Actualmente, los usuarios deben usar escáneres, cámaras de teléfonos y software en computadora o servicios en la nube para extraer texto. Esto requiere múltiples dispositivos, conexión a internet y conocimientos técnicos. Los usuarios necesitan una solución todo-en-uno, simple y autónoma.

### Alternative Solutions
- **Alternativa 1 (Smartphone + App):** Usar teléfono inteligente con aplicaciones de OCR. Requiere teléfono costoso y depende de la calidad de la cámara.
- **Alternativa 2 (Escáner + Computadora):** Usar escáner y computadora con software OCR. Equipo costoso, no portátil.
- **Alternativa 3 (Servicios en la nube):** Enviar imágenes a servicios como Google Cloud Vision. Requiere conexión a internet constante y puede tener costos por uso.

Nuestra solución es la única que combina bajo costo, portabilidad y funcionamiento autónomo.

## Application Overview

### Application Perspective
El sistema es independiente y autónomo. Consta de un ESP32 con cámara, almacenamiento en tarjeta SD, y opcionalmente conectividad WiFi para enviar resultados a un servidor externo si se requiere procesamiento más avanzado.
[ Cámara OV2640 ] → [ ESP32 ] → [ Almacenamiento SD ]
↓
[ WiFi (opcional) ] → [ Servidor OCR ]


### Summary of Application Capabilities

| Función | Beneficio Clave |
|---------|-----------------|
| Captura de imágenes | Adquisición autónoma de documentos/textos |
| Procesamiento local de imagen | Optimización para OCR sin depender de la nube |
| Reconocimiento de texto (OCR) | Extracción de caracteres de las imágenes |
| Almacenamiento en SD | Guardado local de resultados sin conexión |
| Conectividad WiFi (opcional) | Envío a servicios externos si es necesario |
| Interfaz LED/Botón | Control básico sin pantalla costosa |

### Assumptions and Dependencies
- Se asume disponibilidad del ESP32 y cámara OV2640 en el mercado local.
- Se depende de las librerías de código abierto para ESP32 y procesamiento de imágenes.
- El rendimiento del OCR local dependerá de la optimización de algoritmos para el ESP32.

## Application Features

### Feature 1: Captura de Imágenes
El sistema debe ser capaz de capturar imágenes a través de la cámara OV2640 conectada al ESP32, con resolución suficiente para reconocimiento de texto (mínimo 320x240).

### Feature 2: Procesamiento de Imagen
El sistema debe aplicar técnicas de pre-procesamiento como conversión a escala de grises, umbralización y filtrado para mejorar la calidad del OCR.

### Feature 3: Reconocimiento de Texto
El sistema debe extraer texto de las imágenes procesadas utilizando un motor OCR optimizado para microcontroladores (TensorFlow Lite o similar).

### Feature 4: Almacenamiento de Resultados
El sistema debe guardar los textos extraídos en una tarjeta SD junto con metadatos como fecha y hora.

### Feature 5: Interfaz de Usuario
El sistema debe proporcionar retroalimentación visual mediante LEDs para indicar estados: capturando, procesando, texto encontrado, error, etc.

## Additional Application Requirements

### Constraints
- Memoria limitada del ESP32 (~520 KB SRAM) obliga a optimizar algoritmos.
- Procesamiento local de OCR debe ser eficiente para evitar latencias prolongadas.
- El dispositivo debe funcionar con alimentación de batería o USB.

### Quality Ranges
- Precisión del OCR: mínimo 80% en condiciones de iluminación adecuadas.
- Tiempo de procesamiento por imagen: menos de 10 segundos.
- Autonomía: mínimo 2 horas de operación continua.

### Precedence and Priority
| Feature | Prioridad |
|---------|-----------|
| Captura de imágenes | Alta |
| Procesamiento de imagen | Alta |
| Reconocimiento de texto | Alta |
| Almacenamiento en SD | Media |
| Interfaz de usuario | Media |
| Conectividad WiFi | Baja |

### Applicable Standards
- Formato de imagen: JPEG
- Sistema de archivos: FAT32 para tarjeta SD
- Comunicación: UART para depuración, WiFi para opción externa

## System Requirements
Los requerimientos detallados del sistema se encuentran en el [Software Requirements Specification (SRS)](../SRS/SRS.md).

## Definición de Roles

| Participante | Rol Principal | Responsabilidades | Áreas Técnicas |
|--------------|---------------|-------------------|-----------------|
| **Emiliano López García** | Product Owner / Scrum Master | Define requerimientos, prioriza backlog, representa al cliente, elimina bloqueos, da seguimiento al proceso, cuida la metodología | Firmware, Hardware |
| **Daniel German Ugalde Mata** | Development Team Lead | Define estándares de código, revisa calidad técnica, coordina arquitectura | Firmware, Testing, Integración, Documentación técnica |
| **Gerardo Alejandro Pardinez Sosa** | Development Team | Integración de sistemas, pruebas funcionales, documentación de usuario | Hardware, Integración, Testing, Documentación de usuario |

## Definition of Ready (DoR) y Definition of Done (DoD)

### DEFINITION OF READY (DoR)
Una historia está lista para ser trabajada cuando:
- Tiene descripción clara y comprensible por todo el equipo
- Criterios de aceptación definidos y verificables
- Dependencias identificadas y resueltas
- Estimación en story points asignada
- Hardware necesario disponible y probado

### DEFINITION OF DONE (DoD)
Una historia está terminada cuando:
- El código compila sin warnings en el entorno de desarrollo
- Sigue el coding standard definido por el equipo
- Tiene pruebas unitarias que pasan correctamente
- Está integrado en la rama main del repositorio
- Está documentado (código comentado y documentación de usuario)
- Demo funcional probada por al menos otro miembro del equipo

## Planeación de Sprints (6 Sprints)

### Sprint 0: Definición del Producto
**Objetivo:** Entender QUÉ se va a construir y establecer la base del proyecto
**Duración:** 1 semana
**Entregables:**
- Project Vision (este documento)
- Problem Statement
- Stakeholders identificados
- Product Backlog inicial
- Arquitectura propuesta
- Selección de HW/SW
- Definición de DoR y DoD

### Sprint 1: Configuración de Hardware y Captura de Imágenes
**Objetivo:** Integrar la cámara con el ESP32 y lograr captura de imágenes
**Duración:** 1 semana
**Entregables:**
- ESP32 configurado y funcionando
- Cámara OV2640 integrada
- Captura de imágenes exitosa
- Almacenamiento básico en tarjeta SD

### Sprint 2: Procesamiento de Imagen
**Objetivo:** Implementar algoritmos de pre-procesamiento para mejorar calidad OCR
**Duración:** 1 semana
**Entregables:**
- Conversión a escala de grises
- Umbralización y filtrado
- Optimización de memoria
- Pruebas de calidad

### Sprint 3: Integración de OCR Local
**Objetivo:** Implementar reconocimiento de texto en el ESP32
**Duración:** 1 semana
**Entregables:**
- TensorFlow Lite integrado
- Modelo de OCR funcionando
- Extracción de texto básica
- Pruebas de precisión

### Sprint 4: Almacenamiento y Resultados
**Objetivo:** Guardar resultados y mejorar interfaz de usuario
**Duración:** 1 semana
**Entregables:**
- Texto extraído guardado en SD
- LEDs indicadores de estado
- Mejoras en precisión OCR
- Pruebas de integración

### Sprint 5: Integración y Pruebas Finales
**Objetivo:** Integrar todos los módulos y realizar pruebas exhaustivas
**Duración:** 1 semana
**Entregables:**
- Sistema completo integrado
- Pruebas de rendimiento
- Documentación técnica
- Preparación de demo final

### Sprint 6: Documentación y Presentación
**Objetivo:** Completar documentación y preparar presentación final
**Duración:** 1 semana
**Entregables:**
- Documentación completa
- Manual de usuario
- Video demo
- Presentación final