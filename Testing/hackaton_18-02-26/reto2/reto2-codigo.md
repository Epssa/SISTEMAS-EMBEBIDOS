// Reto 2 - Cerradura Digital Secuencial
// Hackathon GPIO Digital - 27 Febrero 2026

// Pines
const int BOTON1 = 13;
const int BOTON2 = 12;
const int BOTON3 = 14;
const int LED_VERDE = 25;
const int LED_ROJO = 26;

const int BOTONES[3] = {BOTON1, BOTON2, BOTON3};

// Estados de la FSM
enum Estado {
  ESPERANDO_PRIMERO,
  ESPERANDO_SEGUNDO,
  ESPERANDO_TERCERO,
  EXITO,
  ERROR,
  BLOQUEADO
};

Estado estadoActual = ESPERANDO_PRIMERO;
int intentosFallidos = 0;
int secuenciaEsperada[3] = {0, 2, 1}; // Índices: botón1=0, botón2=1, botón3=2
int pasoActual = 0;

unsigned long tiempoUltimaPulsacion = 0;
unsigned long tiempoEstado = 0;
const unsigned long TIMEOUT_PULSACION = 5000; // 5 segundos
const unsigned long TIEMPO_EXITO = 2000; // 2 segundos LED verde
const unsigned long TIEMPO_ERROR = 1000; // 1 segundo LED rojo
const unsigned long TIEMPO_BLOQUEO = 10000; // 10 segundos

// Debounce
bool estadoAnterior[3] = {HIGH, HIGH, HIGH};
unsigned long tiempoDebounce[3] = {0, 0, 0};
const unsigned long DEBOUNCE_DELAY = 30;

// Para parpadeo en bloqueo
unsigned long tiempoParpadeo = 0;
bool estadoParpadeo = false;
const unsigned long PARPADEO_INTERVALO = 500;

void setup() {
  pinMode(BOTON1, INPUT_PULLUP);
  pinMode(BOTON2, INPUT_PULLUP);
  pinMode(BOTON3, INPUT_PULLUP);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
  
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_ROJO, LOW);
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

int botonPresionado() {
  for (int i = 0; i < 3; i++) {
    if (leerBoton(BOTONES[i], i)) {
      return i;
    }
  }
  return -1;
}

void reiniciarIntento() {
  pasoActual = 0;
  estadoActual = ESPERANDO_PRIMERO;
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_ROJO, LOW);
}

void loop() {
  unsigned long ahora = millis();
  int boton = botonPresionado();
  
  switch (estadoActual) {
    case ESPERANDO_PRIMERO:
    case ESPERANDO_SEGUNDO:
    case ESPERANDO_TERCERO:
      // Verificar timeout
      if (pasoActual > 0 && (ahora - tiempoUltimaPulsacion) > TIMEOUT_PULSACION) {
        reiniciarIntento();
      }
      
      if (boton != -1) {
        tiempoUltimaPulsacion = ahora;
        
        // Verificar si es el botón esperado
        if (boton == secuenciaEsperada[pasoActual]) {
          pasoActual++;
          if (pasoActual == 3) {
            estadoActual = EXITO;
            tiempoEstado = ahora;
            digitalWrite(LED_VERDE, HIGH);
            intentosFallidos = 0;
          } else {
            // Avanzar al siguiente estado
            if (pasoActual == 1) estadoActual = ESPERANDO_SEGUNDO;
            if (pasoActual == 2) estadoActual = ESPERANDO_TERCERO;
          }
        } else {
          // Error en la secuencia
          estadoActual = ERROR;
          tiempoEstado = ahora;
          digitalWrite(LED_ROJO, HIGH);
          intentosFallidos++;
        }
      }
      break;
      
    case EXITO:
      if ((ahora - tiempoEstado) >= TIEMPO_EXITO) {
        reiniciarIntento();
      }
      break;
      
    case ERROR:
      if ((ahora - tiempoEstado) >= TIEMPO_ERROR) {
        if (intentosFallidos >= 3) {
          estadoActual = BLOQUEADO;
          tiempoEstado = ahora;
          digitalWrite(LED_ROJO, LOW);
        } else {
          reiniciarIntento();
        }
      }
      break;
      
    case BLOQUEADO:
      // Parpadeo LED rojo durante bloqueo
      if ((ahora - tiempoParpadeo) >= PARPADEO_INTERVALO) {
        tiempoParpadeo = ahora;
        estadoParpadeo = !estadoParpadeo;
        digitalWrite(LED_ROJO, estadoParpadeo);
      }
      
      if ((ahora - tiempoEstado) >= TIEMPO_BLOQUEO) {
        intentosFallidos = 0;
        digitalWrite(LED_ROJO, LOW);
        reiniciarIntento();
      }
      break;
  }
  
  delay(5);
}