# Reto 3 - Semáforo con Botón Peatonal

## Descripción

Control de un semáforo con ciclo normal (Verde → Amarillo → Rojo) y un botón peatonal. Cuando se presiona el botón, se activa una fase peatonal en el siguiente ciclo, sin reiniciar el ciclo abruptamente.

## Componentes

- 1 ESP32
- 3 LEDs (rojo, amarillo, verde)
- 1 botón peatonal
- 3 resistencias de 220Ω

## Conexiones

| Componente | Pin ESP32 |
|------------|-----------|
| LED Rojo | GPIO 25 |
| LED Amarillo | GPIO 26 |
| LED Verde | GPIO 27 |
| Botón Peatonal | GPIO 13 |

## Funcionamiento

- Ciclo normal: Verde (5s) → Amarillo (2s) → Rojo (5s) → Verde...
- Si se presiona el botón, se activa una bandera
- La fase peatonal se activa al finalizar el ciclo actual, después del rojo
- Fase peatonal: Verde (5s) → Amarillo (2s) → Rojo (5s) → Verde... (igual, pero con la bandera)
- No se reinicia el ciclo abruptamente, se respeta el tiempo restante

## Código

- [codigo.ino](./codigo.ino)
- [diagram.json](./diagram.json)