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
      "attrs": { "label": "C1" }
    },
    {
      "type": "wokwi-pushbutton",
      "id": "btn2",
      "top": -40,
      "left": 210,
      "attrs": { "label": "C2" }
    },
    {
      "type": "wokwi-pushbutton",
      "id": "btn3",
      "top": -40,
      "left": 270,
      "attrs": { "label": "C3" }
    },
    {
      "type": "wokwi-pushbutton",
      "id": "btn4",
      "top": -40,
      "left": 330,
      "attrs": { "label": "C4" }
    },
    {
      "type": "wokwi-pushbutton",
      "id": "btnReset",
      "top": 20,
      "left": 150,
      "attrs": { "label": "Reset" }
    },
    {
      "type": "wokwi-led",
      "id": "led1",
      "top": 70,
      "left": 150,
      "attrs": { "color": "red", "label": "C1" }
    },
    {
      "type": "wokwi-led",
      "id": "led2",
      "top": 70,
      "left": 210,
      "attrs": { "color": "green", "label": "C2" }
    },
    {
      "type": "wokwi-led",
      "id": "led3",
      "top": 70,
      "left": 270,
      "attrs": { "color": "blue", "label": "C3" }
    },
    {
      "type": "wokwi-led",
      "id": "led4",
      "top": 70,
      "left": 330,
      "attrs": { "color": "yellow", "label": "C4" }
    }
  ],
  "connections": [
    ["esp:GND.1", "btn1:GND.1", "black"],
    ["esp:GND.1", "btn2:GND.1", "black"],
    ["esp:GND.1", "btn3:GND.1", "black"],
    ["esp:GND.1", "btn4:GND.1", "black"],
    ["esp:GND.1", "btnReset:GND.1", "black"],
    ["esp:GND.1", "led1:C", "black"],
    ["esp:GND.1", "led2:C", "black"],
    ["esp:GND.1", "led3:C", "black"],
    ["esp:GND.1", "led4:C", "black"],
    ["esp:13", "btn1:VCC", "green"],
    ["esp:12", "btn2:VCC", "green"],
    ["esp:14", "btn3:VCC", "green"],
    ["esp:27", "btn4:VCC", "green"],
    ["esp:26", "btnReset:VCC", "green"],
    ["esp:25", "led1:A", "red"],
    ["esp:33", "led2:A", "green"],
    ["esp:32", "led3:A", "blue"],
    ["esp:15", "led4:A", "yellow"]
  ]
}