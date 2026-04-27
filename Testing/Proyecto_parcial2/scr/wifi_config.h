#ifndef WIFI_CONFIG_H
#define WIFI_CONFIG_H

#include <WiFi.h>

// Credenciales WiFi 
const char* ssid = "TU_WIFI_SSID";      
const char* password = "TU_WIFI_PASS";  

void connectWiFi() {
  WiFi.begin(ssid, password);
  Serial.print("Conectando a WiFi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nWiFi conectado");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

#endif