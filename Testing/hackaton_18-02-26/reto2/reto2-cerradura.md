# Reto 2 - Cerradura Digital Secuencial

## Descripción

Simulación de una cerradura electrónica con 3 botones. El usuario debe presionar la secuencia correcta (1 → 3 → 2) para desbloquear el sistema. Si se equivoca, el estado se reinicia. Después de 3 intentos fallidos, el sistema se bloquea por 10 segundos. Cada pulsación debe ocurrir dentro de un tiempo máximo de 5 segundos, de lo contrario el intento se reinicia.

## Componentes

- 1 ESP32
- 3 botones
- 2 LEDs (verde y rojo)
- 2 resistencias de 220Ω

## Conexiones

| Componente | Pin ESP32 |
|------------|-----------|
| Botón 1 | GPIO 13 |
| Botón 2 | GPIO 12 |
| Botón 3 | GPIO 14 |
| LED Verde (éxito) | GPIO 25 |
| LED Rojo (error/bloqueo) | GPIO 26 |

## Funcionamiento

- Secuencia correcta: presionar botón 1 → botón 3 → botón 2
- Si la secuencia es correcta, LED verde enciende por 2 segundos
- Si la secuencia es incorrecta, LED rojo enciende por 1 segundo y se reinicia el estado
- Después de 3 intentos fallidos, sistema se bloquea 10 segundos (LED rojo parpadea)
- Timeout de 5 segundos entre pulsaciones: si pasa más tiempo, el intento se reinicia
- Implementado con máquina de estados

## Código

- [codigo.ino](./codigo.ino)
- [diagram.json](./diagram.json)