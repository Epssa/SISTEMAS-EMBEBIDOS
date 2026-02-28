{
  "version": 1,
  "author": "Equipo Sistemas Embebidos",
  "editor": "wokwi",
  "parts": [
    {
      "type": "wokwi-esp32-devkit-v1",
      "id": "esp",
      "top": 0,
      "left": 0,
      "attrs": {}
    },
    {
      "type": "wokwi-pushbutton",
      "id": "btnPeatonal",
      "top": -40,
      "left": 200,
      "attrs": { "label": "Peatón" }
    },
    {
      "type": "wokwi-led",
      "id": "ledVerde",
      "top": 60,
      "left": 150,
      "attrs": { "color": "green", "label": "Verde" }
    },
    {
      "type": "wokwi-led",
      "id": "ledAmarillo",
      "top": 60,
      "left": 210,
      "attrs": { "color": "yellow", "label": "Amarillo" }
    },
    {
      "type": "wokwi-led",
      "id": "ledRojo",
      "top": 60,
      "left": 270,
      "attrs": { "color": "red", "label": "Rojo" }
    }
  ],
  "connections": [
    ["esp:GND.1", "btnPeatonal:GND.1", "black"],
    ["esp:GND.1", "ledVerde:C", "black"],
    ["esp:GND.1", "ledAmarillo:C", "black"],
    ["esp:GND.1", "ledRojo:C", "black"],
    ["esp:13", "btnPeatonal:VCC", "green"],
    ["esp:27", "ledVerde:A", "green"],
    ["esp:26", "ledAmarillo:A", "yellow"],
    ["esp:25", "ledRojo:A", "red"]
  ]
}