# Project Overview: Sistema de Extracción de Texto con ESP32

**Universidad:** Cuauhtémoc
**Curso:** Sistemas Embebidos
**Fecha:** Febrero 2026

## Descripción del Proyecto

Imagina que tienes un documento impreso, un letrero o cualquier texto físico y quisieras extraer todo su contenido de manera digital para guardarlo, traducirlo o procesarlo. Eso es exactamente lo que hace este proyecto, pero en pequeño.

Estamos desarrollando un sistema embebido que utiliza un microcontrolador ESP32 (un pequeño cerebro electrónico) conectado a una cámara para capturar imágenes de textos y luego, mediante algoritmos especiales, identificar y extraer las letras, números y caracteres que aparecen en ellas. Básicamente, le enseñamos a un microcontrolador a "leer".

Lo interesante es que esto normalmente se hace en computadoras con muchos recursos, pero nosotros queremos demostrar que se puede lograr en hardware más limitado, optimizando cada parte del proceso. El sistema puede funcionar de manera independiente o enviar los resultados a otro dispositivo.

## Objetivo del Proyecto

**Objetivo General**

Desarrollar un prototipo funcional de extracción de texto desde imágenes en tiempo real utilizando un microcontrolador ESP32, optimizando el consumo de recursos y demostrando la integración de hardware embebido con algoritmos de procesamiento digital de imagen.

**Objetivos Específicos**

1. **Adquisición de Imágenes:** Integrar una cámara digital (OV2640) al ESP32 para capturar imágenes de documentos y textos en formato JPEG, validando la calidad y resolución necesarias para el reconocimiento.

2. **Procesamiento de Imagen:** Preparar las imágenes para el reconocimiento aplicando técnicas como conversión a escala de grises, ajuste de contraste y optimización considerando las limitaciones de memoria del ESP32.

3. **Reconocimiento Óptico de Caracteres (OCR):** Integrar un sistema OCR eficiente (valorando opciones como TensorFlow Lite, Tesseract o una API externa) para extraer el texto identificado validando su precisión.

4. **Interfaz y Visualización:** Crear un sistema de almacenamiento de resultados en tarjeta SD o memoria interna, y desarrollar una forma accesible de visualizar el texto extraído mediante comunicación USB, Bluetooth o WiFi.

## Factibilidad del Proyecto

**Factibilidad Técnica**

El equipo cuenta con conocimientos en programación de microcontroladores, electrónica básica y procesamiento de imágenes. Los componentes seleccionados son accesibles y cuentan con amplia documentación y soporte por parte de la comunidad:

- El ESP32 es un microcontrolador ampliamente utilizado con suficiente capacidad de procesamiento y memoria para tareas de visión básica.
- La cámara OV2640 es compatible directamente con el ESP32 a través de librerías existentes.
- Existen versiones ligeras de frameworks de IA (TensorFlow Lite) diseñadas específicamente para microcontroladores.
- En caso de que el procesamiento local sea muy limitado, se puede implementar una solución híbrida enviando las imágenes a un servidor externo vía WiFi.

**Factibilidad Económica**

El proyecto utiliza componentes de bajo costo y ampliamente disponibles:

| Componente | Costo Aproximado |
|------------|------------------|
| ESP32 | $5 - $10 USD |
| Cámara OV2640 | $5 - $8 USD |
| Tarjeta MicroSD | $3 - $5 USD |
| Pantalla (opcional) | $5 - $10 USD |
| Componentes pasivos | $2 - $3 USD |
| **Total estimado** | **$20 - $36 USD** |

El laboratorio de la universidad proporciona acceso a herramientas de medición y estaciones de trabajo, y todo el software necesario es de código abierto, lo que hace el proyecto totalmente viable económicamente.

## Stakeholders

- **Jenny Grizel Luna Cercero** - Profesora de Sistemas Embebidos, evaluador del proyecto
- **Compañeros de clase** - Usuarios potenciales de la documentación y posibles evaluadores
- **Equipo de desarrollo** - Emiliano, German y Alejandro, responsables de la implementación
- **Futuros usuarios** - Personas interesadas en sistemas embebidos con visión por computadora

## Definición de Roles

**Emiliano López García**

- **Product Owner:** Define los requerimientos del proyecto, prioriza las tareas en el backlog y representa la visión del cliente durante el desarrollo.
- **Scrum Master:** Elimina bloqueos técnicos y administrativos, da seguimiento al proceso ágil y cuida que se cumpla la metodología.
- **Development Team:** Responsable técnico del firmware del ESP32 y del diseño e integración del hardware.

**Daniel German Ugalde Mata**

- **Development Team:** Responsable del desarrollo de firmware para la cámara y el procesamiento de imágenes.
- Encargado de implementar las pruebas unitarias y de integración del sistema.
- Coordina la arquitectura del software y define los estándares de código.
- Responsable de la documentación técnica del proyecto.

**Gerardo Alejandro Pardinez Sosa**

- **Development Team:** Responsable del hardware, incluyendo el diseño del circuito y la integración de componentes.
- Encargado de las pruebas funcionales del sistema completo.
- Soporte en la integración de todos los módulos.
- Responsable de la documentación de usuario y manuales.

## Tecnología y Componentes a Utilizar

**Hardware**

- ESP32 (microcontrolador principal)
- Cámara OV2640 (sensor de imagen)
- Módulo lector de tarjetas MicroSD
- Pantalla LCD/OLED opcional
- Cable USB para alimentación y programación
- Fuente de alimentación de 5V

**Software y Librerías**

- Arduino IDE / PlatformIO (programación)
- OpenCV versión lightweight (procesamiento)
- TensorFlow Lite for Microcontrollers (modelos de IA)
- Tesseract OCR o API externa (reconocimiento de texto)
- WiFi/HTTP (comunicación)

## Resultados Esperados

Al finalizar el proyecto, el equipo habrá:

- Desarrollado un prototipo funcional de extracción de texto desde imágenes
- Demostrado comprensión profunda de sistemas embebidos y procesamiento digital
- Optimizado algoritmos para hardware con recursos limitados
- Documentado el proceso técnico y los aprendizajes obtenidos
- Creado una base para futuras mejoras como soporte multi-idioma o mejor precisión

## Referencias

- [Documentación Oficial ESP32](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)
- [TensorFlow Lite for Microcontrollers](https://www.tensorflow.org/lite/microcontrollers)
- [Documentación OpenCV](https://docs.opencv.org/)
- [Datasheet Cámara OV2640](https://www.ov.com.cn/)