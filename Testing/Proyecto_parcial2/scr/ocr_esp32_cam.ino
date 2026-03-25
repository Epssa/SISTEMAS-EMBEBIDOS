#include "camera_config.h"
#include "wifi_config.h"
#include "ocr_engine.h"

void setup() {
  Serial.begin(115200);
  
  // Inicializar cámara
  if (!initCamera()) {
    Serial.println("Error al inicializar cámara");
    return;
  }
  
  // Inicializar OCR
  if (!initOCR()) {
    Serial.println("Error al inicializar OCR");
    return;
  }
  
  // Conectar WiFi
  connectWiFi();
  
  Serial.println("Sistema listo");
}

void loop() {
  // Capturar imagen
  if (captureImage()) {
    // Procesar OCR
    String text = processOCR();
    
    // Mostrar resultado
    if (text.length() > 0) {
      Serial.println("Texto detectado:");
      Serial.println(text);
      
      // Opcional: guardar en SD
      saveToSD(text);
    }
  }
  
  delay(5000);  // Esperar 5 segundos
}