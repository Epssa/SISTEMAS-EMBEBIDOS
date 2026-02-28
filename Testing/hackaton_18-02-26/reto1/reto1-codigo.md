// Reto 1 - Sistema de Votación Digital
// Hackathon GPIO Digital - 27 Febrero 2026

// Pines de botones
const int BOTON_C1 = 13;
const int BOTON_C2 = 12;
const int BOTON_C3 = 14;
const int BOTON_C4 = 27;
const int BOTON_RESET = 26;

// Pines de LEDs
const int LED_C1 = 25;
const int LED_C2 = 33;
const int LED_C3 = 32;
const int LED_C4 = 15;

// Arreglos para facilitar iteraciones
const int BOTONES[5] = {BOTON_C1, BOTON_C2, BOTON_C3, BOTON_C4, BOTON_RESET};
const int LEDS[4] = {LED_C1, LED_C2, LED_C3, LED_C4};

// Variables de votos
int votos[4] = {0, 0, 0, 0};

// Variables para debounce
bool estadoAnterior[5] = {HIGH, HIGH, HIGH, HIGH, HIGH};
unsigned long tiempoDebounce[5] = {0, 0, 0, 0, 0};
const unsigned long DEBOUNCE_DELAY = 30;

// Variables para parpadeo
bool estadoParpadeo = false;
unsigned long tiempoParpadeo = 0;
const unsigned long PARPADEO_INTERVALO = 500;

void setup() {
  // Configurar pines de botones como entrada con pull-up
  for (int i = 0; i < 5; i++) {
    pinMode(BOTONES[i], INPUT_PULLUP);
  }
  
  // Configurar pines de LEDs como salida
  for (int i = 0; i < 4; i++) {
    pinMode(LEDS[i], OUTPUT);
    digitalWrite(LEDS[i], LOW);
  }
}

int leerBoton(int pin, int indice) {
  bool lectura = digitalRead(pin);
  
  if (lectura != estadoAnterior[indice]) {
    tiempoDebounce[indice] = millis();
  }
  
  if ((millis() - tiempoDebounce[indice]) > DEBOUNCE_DELAY) {
    if (lectura != estadoAnterior[indice]) {
      estadoAnterior[indice] = lectura;
      if (lectura == LOW) {
        return 1;
      }
    }
  }
  
  return 0;
}

void procesarVotos() {
  for (int i = 0; i < 4; i++) {
    if (leerBoton(BOTONES[i], i)) {
      votos[i]++;
      if (votos[i] > 999) votos[i] = 999;
    }
  }
}

void procesarReset() {
  if (leerBoton(BOTON_RESET, 4)) {
    for (int i = 0; i < 4; i++) {
      votos[i] = 0;
    }
  }
}

int encontrarMaximo(int &maxValor, bool &hayEmpate) {
  maxValor = votos[0];
  int indiceMax = 0;
  hayEmpate = false;
  
  for (int i = 1; i < 4; i++) {
    if (votos[i] > maxValor) {
      maxValor = votos[i];
    }
  }
  
  int contadorMax = 0;
  for (int i = 0; i < 4; i++) {
    if (votos[i] == maxValor) {
      contadorMax++;
      if (contadorMax == 1) {
        indiceMax = i;
      }
    }
  }
  
  hayEmpate = (contadorMax > 1);
  return indiceMax;
}

void actualizarLEDs() {
  int maxValor;
  bool hayEmpate;
  int indiceMax = encontrarMaximo(maxValor, hayEmpate);
  
  for (int i = 0; i < 4; i++) {
    digitalWrite(LEDS[i], LOW);
  }
  
  if (maxValor == 0) {
    return;
  }
  
  if (hayEmpate) {
    if (millis() - tiempoParpadeo >= PARPADEO_INTERVALO) {
      tiempoParpadeo = millis();
      estadoParpadeo = !estadoParpadeo;
    }
    
    for (int i = 0; i < 4; i++) {
      digitalWrite(LEDS[i], estadoParpadeo);
    }
  } else {
    digitalWrite(LEDS[indiceMax], HIGH);
  }
}

void loop() {
  procesarVotos();
  procesarReset();
  actualizarLEDs();
  delay(5);
}