# Ambient Lighting
Adds ambient lighting to the back of a TV or monitor (when being mirrored from a computer).  

The program takes a screenshot of the computer screen, calculates an average RGB value for the sides and top of the screen, sends the RGB values to an Arduino board, which then displays those RGB values through LEDs attached to the back of the TV.  

![](https://github.com/rtedwards/Ambient-Lighting/blob/master/img/Ambient-Lighting.gif)

# Getting Started

You will need:

- [Arduino](https://www.arduino.cc/) - an Arduino Nano should be enough
- [Neopixels](https://www.adafruit.com/category/168)
- USB cable - Micro or Mini depending on Arduino board
- A computer with Mac OS
