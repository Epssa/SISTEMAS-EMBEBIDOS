# Reto 1 - Sistema de Votación Digital

## Descripción

Sistema de votación con 4 candidatos. Cada botón suma un voto a su respectivo candidato. El LED del candidato con mayor número de votos permanece encendido. En caso de empate en el primer lugar, todos los LEDs parpadean simultáneamente. Un botón de reset reinicia todos los votos a cero.

## Componentes

- 1 ESP32
- 5 botones (4 candidatos + reset)
- 4 LEDs
- 4 resistencias de 220Ω (para los LEDs)

## Conexiones

| Componente | Pin ESP32 |
|------------|-----------|
| Botón Candidato 1 | GPIO 13 |
| Botón Candidato 2 | GPIO 12 |
| Botón Candidato 3 | GPIO 14 |
| Botón Candidato 4 | GPIO 27 |
| Botón Reset | GPIO 26 |
| LED Candidato 1 | GPIO 25 |
| LED Candidato 2 | GPIO 33 |
| LED Candidato 3 | GPIO 32 |
| LED Candidato 4 | GPIO 15 |

## Funcionamiento

- Cada pulsación de botón incrementa el contador del candidato correspondiente
- Debounce implementado por software (30ms)
- Se identifica al candidato con mayor votación
- Si hay un único máximo, su LED se enciende
- Si hay empate en el máximo, todos los LEDs parpadean (500ms)
- Reset pone todos los contadores a cero

