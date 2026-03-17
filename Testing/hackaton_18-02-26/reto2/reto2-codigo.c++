#define BTN1 2
#define BTN2 3
#define BTN3 4
#define LED_VERDE 5
#define LED_ROJO 6


#define DEBOUNCE_TIME 50
#define MAX_TIME_BETWEEN_PRESSES 5000  // 5 segundos
#define BLOCK_TIME 10000                // 10 segundos de bloqueo
#define CYCLE_TIME 5



enum Estado {
  ESPERANDO_PRIMER,
  ESPERANDO_SEGUNDO,
  ESPERANDO_TERCERO,
  EXITO,
  ERROR,
  BLOQUEADO
};


const int secuenciaCorrecta[3] = {1, 3, 2};


Estado estadoActual = ESPERANDO_PRIMER;
int intentosFallidos = 0;
int pasoActual = 0;
unsigned long tiempoUltimaPulsacion = 0;
unsigned long tiempoBloqueoInicio = 0;

// Estructura para botones
struct Button {
  int pin;
  int numero;  
  int estado;
  int lastReading;
  unsigned long lastDebounceTime;
};

// Inicializar botones
Button botones[3] = {
  {BTN1, 1, HIGH, HIGH, 0},
  {BTN2, 2, HIGH, HIGH, 0},
  {BTN3, 3, HIGH, HIGH, 0}
};

void setup() {
  // Configurar pines
  for(int i = 0; i < 3; i++) {
    pinMode(botones[i].pin, INPUT_PULLUP);
  }
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
  
  // Estado inicial
  apagarLEDs();
}

void loop() {
  
  actualizarFSM();
  
  // Leer botones solo si no estamos en éxito
  if(estadoActual != EXITO && estadoActual != BLOQUEADO) {
    for(int i = 0; i < 3; i++) {
      procesarBoton(&botones[i]);
    }
  }
  
  delay(CYCLE_TIME);
}

void procesarBoton(Button *btn) {
  int lectura = digitalRead(btn->pin);
  
  if(lectura != btn->lastReading) {
    btn->lastDebounceTime = millis();
  }
  
  if((millis() - btn->lastDebounceTime) > DEBOUNCE_TIME) {
    if(lectura != btn->estado) {
      btn->estado = lectura;
      
      if(btn->estado == LOW) {

        manejarPulsacion(btn->numero);
      }
    }
  }
  
  btn->lastReading = lectura;
}

void manejarPulsacion(int numeroBoton) {

  unsigned long ahora = millis();
  
  // Verificar timeout si no estamos en el primer paso
  if(estadoActual != ESPERANDO_PRIMER) {
    if(ahora - tiempoUltimaPulsacion > MAX_TIME_BETWEEN_PRESSES) {
      // Timeout - reiniciar
      estadoActual = ESPERANDO_PRIMER;
      pasoActual = 0;
      apagarLEDs();
      return;
    }
  }
  

  switch(estadoActual) {
    case ESPERANDO_PRIMER:
      if(numeroBoton == secuenciaCorrecta[0]) {
        // Primer botón correcto
        pasoActual = 1;
        estadoActual = ESPERANDO_SEGUNDO;
      } else {
        // Error en primer botón
        manejarError();
      }
      break;
      
    case ESPERANDO_SEGUNDO:
      if(numeroBoton == secuenciaCorrecta[1]) {
        // Segundo botón correcto
        pasoActual = 2;
        estadoActual = ESPERANDO_TERCERO;
      } else {
        // Error en segundo botón
        manejarError();
      }
      break;
      
    case ESPERANDO_TERCERO:
      if(numeroBoton == secuenciaCorrecta[2]) {
        // Secuencia completada correctamente
        estadoActual = EXITO;
        digitalWrite(LED_VERDE, HIGH);
      } else {
        // Error en tercer botón
        manejarError();
      }
      break;
      
    default:
      // En otros estados no procesamos pulsaciones
      break;
  }
  
  tiempoUltimaPulsacion = ahora;
}

void manejarError() {
  intentosFallidos++;
  
  if(intentosFallidos >= 3) {
    // Bloquear por 10 segundos
    estadoActual = BLOQUEADO;
    tiempoBloqueoInicio = millis();
    digitalWrite(LED_ROJO, HIGH);
  } else {
    // Error sin bloqueo
    estadoActual = ERROR;
    digitalWrite(LED_ROJO, HIGH);
  }
  
  // Reiniciar secuencia
  pasoActual = 0;
}

void actualizarFSM() {
  unsigned long ahora = millis();
  
  switch(estadoActual) {
    case ERROR:
      // El LED rojo se apaga después de 1 segundo
      if(ahora - tiempoUltimaPulsacion > 1000) {
        estadoActual = ESPERANDO_PRIMER;
        apagarLEDs();
      }
      break;
      
    case EXITO:
      // El LED verde se apaga después de 3 segundos
      if(ahora - tiempoUltimaPulsacion > 3000) {
        estadoActual = ESPERANDO_PRIMER;
        intentosFallidos = 0;  // Reiniciar contador tras éxito
        apagarLEDs();
      }
      break;
      
    case BLOQUEADO:
      // Verificar si terminó el bloqueo
      if(ahora - tiempoBloqueoInicio >= BLOCK_TIME) {
        estadoActual = ESPERANDO_PRIMER;
        intentosFallidos = 0;
        apagarLEDs();
      }
      break;
      
    case ESPERANDO_SEGUNDO:
    case ESPERANDO_TERCERO:
      // Verificar timeout entre pulsaciones
      if(ahora - tiempoUltimaPulsacion > MAX_TIME_BETWEEN_PRESSES) {
        estadoActual = ESPERANDO_PRIMER;
        pasoActual = 0;
        apagarLEDs();
      }
      break;
      
    default:
      // ESPERANDO_PRIMER no necesita verificación especial
      break;
  }
}

void apagarLEDs() {
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_ROJO, LOW);
}