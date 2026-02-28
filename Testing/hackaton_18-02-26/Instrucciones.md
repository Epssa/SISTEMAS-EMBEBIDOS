# Hackathon GPIO Digital

**Universidad:** Cuauhtémoc
**Curso:** Sistemas Embebidos
**Fecha:** 27 de Febrero 2026
**Plataforma:** Wokwi (ESP32)

## Reglas Generales

- Solo uso de GPIO digitales
- Prohibido usar interrupciones
- Prohibido usar ADC o PWM
- No usar delay() mayores a 5 ms
- Código obligatorio modular (funciones separadas)

## Retos

### [Reto 1 - Sistema de Votación Digital]
Sistema con 4 botones (candidatos), 4 LEDs y botón de reset. Cada botón suma un voto, el LED del candidato con más votos se enciende, y en caso de empate todos parpadean.

### [Reto 2 - Cerradura Digital Secuencial]
Cerradura con 3 botones y secuencia 1→3→2. Implementa máquina de estados, 3 intentos fallidos bloquean 10 segundos, timeout de 5 segundos entre pulsaciones.

### [Reto 3 - Semáforo con Botón Peatonal]
Semáforo con ciclo Verde→Amarillo→Rojo y botón peatonal que activa fase en el siguiente ciclo sin reiniciar abruptamente.

## Equipo

- Emiliano López García
- Daniel German Ugalde Mata
- Gerardo Alejandro Pardinez Sosa