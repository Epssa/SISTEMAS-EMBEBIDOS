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
      "id": "btn1",
      "top": -40,
      "left": 150,
      "attrs": { "label": "1" }
    },
    {
      "type": "wokwi-pushbutton",
      "id": "btn2",
      "top": -40,
      "left": 210,
      "attrs": { "label": "2" }
    },
    {
      "type": "wokwi-pushbutton",
      "id": "btn3",
      "top": -40,
      "left": 270,
      "attrs": { "label": "3" }
    },
    {
      "type": "wokwi-led",
      "id": "ledVerde",
      "top": 60,
      "left": 150,
      "attrs": { "color": "green", "label": "Exito" }
    },
    {
      "type": "wokwi-led",
      "id": "ledRojo",
      "top": 60,
      "left": 210,
      "attrs": { "color": "red", "label": "Error" }
    }
  ],
  "connections": [
    ["esp:GND.1", "btn1:GND.1", "black"],
    ["esp:GND.1", "btn2:GND.1", "black"],
    ["esp:GND.1", "btn3:GND.1", "black"],
    ["esp:GND.1", "ledVerde:C", "black"],
    ["esp:GND.1", "ledRojo:C", "black"],
    ["esp:13", "btn1:VCC", "green"],
    ["esp:12", "btn2:VCC", "green"],
    ["esp:14", "btn3:VCC", "green"],
    ["esp:25", "ledVerde:A", "green"],
    ["esp:26", "ledRojo:A", "red"]
  ]
}