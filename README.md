# Digital Electronica XMas Projet - Arudino

## What is the project
As a semester 1 final for Digital Electronics (DE), the class is making a countdown tower. This will consist of a larger tower with a coundown clock located at the top (LCD driven via I2C controller) and adressable LED strips.

## What is this code
This code is the direct controller for the electronics hardware. This will run on a Arudunio Uno and will drive the LCD and LEDs. To manage such hardware, the Ardunio will communicate with a server project (https://github.com/victoryforphil/de-xmas-controller) running NodeJS over Serial Port.

## Progress
O = Open  
X = Done   

X - Drive LCD over i2c
O - Drive LED Strips   
O - Connect to serial port     
O - Display Data on LCD from Serial      
O - Scrolling text for longer text   
O - LED Patterns over Serial   
