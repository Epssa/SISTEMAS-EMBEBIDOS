# OCR con ESP32-CAM

Sistema de reconocimiento óptico de caracteres (OCR) embebido en ESP32-CAM.

## Descripción
Sistema que permite capturar imágenes de texto y extraer caracteres utilizando 
un ESP32-CAM con procesamiento local mediante TensorFlow Lite.

## Hardware Requerido
- ESP32-CAM (con cámara OV2640)
- Fuente de alimentación 5V/2A
- (Opcional) Tarjeta MicroSD

## Configuración
1. Clonar repositorio
2. Abrir `src/ocr-esp32-cam.ino` en Arduino IDE
3. Configurar WiFi en `src/wifi_config.h`
4. Compilar y subir a ESP32-CAM

## Autores
- Emiliano López García
- Daniel German Ugalde Mata
- Gerardo Alejandro Pardinez Sosa

## Licencia
MIT