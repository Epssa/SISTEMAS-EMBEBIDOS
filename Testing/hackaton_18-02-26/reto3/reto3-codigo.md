// Reto 3 - Semáforo con Botón Peatonal
// Hackathon GPIO Digital - 27 Febrero 2026

// Pines
const int LED_ROJO = 25;
const int LED_AMARILLO = 26;
const int LED_VERDE = 27;
const int BOTON_PEATONAL = 13;

// Estados del semáforo
enum EstadoSemaforo {
  VERDE,
  AMARILLO,
  ROJO
};

EstadoSemaforo estadoActual = VERDE;
unsigned long tiempoCambioEstado = 0;
bool solicitudPeatonal = false;

// Tiempos en milisegundos
const unsigned long TIEMPO_VERDE = 5000;
const unsigned long TIEMPO_AMARILLO = 2000;
const unsigned long TIEMPO_ROJO = 5000;

// Debounce
bool estadoAnteriorBoton = HIGH;
unsigned long tiempoDebounce = 0;
const unsigned long DEBOUNCE_DELAY = 30;

void setup() {
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(BOTON_PEATONAL, INPUT_PULLUP);
  
  // Estado inicial: Verde
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_AMARILLO, LOW);
  digitalWrite(LED_ROJO, LOW);
  tiempoCambioEstado = millis();
}

bool leerBoton() {
  bool lectura = digitalRead(BOTON_PEATONAL);
  
  if (lectura != estadoAnteriorBoton) {
    tiempoDebounce = millis();
  }
  
  if ((millis() - tiempoDebounce) > DEBOUNCE_DELAY) {
    if (lectura != estadoAnteriorBoton) {
      estadoAnteriorBoton = lectura;
      if (lectura == LOW) {
        return true;
      }
    }
  }
  return false;
}

void cambiarEstado(EstadoSemaforo nuevoEstado) {
  // Apagar todos
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARILLO, LOW);
  digitalWrite(LED_ROJO, LOW);
  
  // Encender el correspondiente
  switch (nuevoEstado) {
    case VERDE:
      digitalWrite(LED_VERDE, HIGH);
      break;
    case AMARILLO:
      digitalWrite(LED_AMARILLO, HIGH);
      break;
    case ROJO:
      digitalWrite(LED_ROJO, HIGH);
      break;
  }
  
  estadoActual = nuevoEstado;
  tiempoCambioEstado = millis();
}

void loop() {
  unsigned long ahora = millis();
  
  // Leer botón peatonal
  if (leerBoton()) {
    solicitudPeatonal = true;
  }
  
  // Máquina de estados del semáforo
  switch (estadoActual) {
    case VERDE:
      if ((ahora - tiempoCambioEstado) >= TIEMPO_VERDE) {
        cambiarEstado(AMARILLO);
      }
      break;
      
    case AMARILLO:
      if ((ahora - tiempoCambioEstado) >= TIEMPO_AMARILLO) {
        cambiarEstado(ROJO);
      }
      break;
      
    case ROJO:
      if ((ahora - tiempoCambioEstado) >= TIEMPO_ROJO) {
        // Al terminar el rojo, verificamos si hay solicitud peatonal
        if (solicitudPeatonal) {
          // Fase peatonal completada, reiniciamos ciclo normal
          solicitudPeatonal = false;
        }
        cambiarEstado(VERDE);
      }
      break;
  }
  
  delay(5);
}