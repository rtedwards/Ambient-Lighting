/*
 *  Arduino code for Monitor Ambient Lighting
 *  Author: Robert Edwards
 *
 *  NeoPixel Ring simple sketch (c) 2013 Shae Erisson
 *  released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
 */

#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN 3

// Number of NeoPixels on strand
#define NUMPIXELS 60

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int wait = 50; // delay for half a second
uint8_t section[7][3];

void setup() {
  pixels.begin(); // Initialize the NeoPixel library.
  pixels.show();
  
  section[0][0] = 1;
  
  //*****  Serial Code  *****//
  Serial.begin(115200);
}

void loop() {
  //pixels.setPixelColor(5, pixels.Color(125, 0, 125)); 
  //pixels.show();
  //delay(wait);
    
  while (Serial.available()) {
    //pixels.setPixelColor(7, pixels.Color(0, 0, 255));
    //pixels.show();
    //delay(wait);
    
    //if(Serial.available()) {
    //   Serial.print ("Buffer: ");
    //   Serial.println(Serial.available());
    //}
    
    if (Serial.available() >= 21) {
      for (int i=0; i<7; i++) {
        for (int j=0; j<3; j++) {
          
          //Debugging
          //pixels.setPixelColor(6, pixels.Color(0, 255, 0)); 
          //pixels.show();
          //delay(wait);
          
          section[i][j] = Serial.read();  //read rgb byte
        }//end for
      }//end for
      
        //Section 1 (Right Lower)
        for (int i=0; i<8; i++) {
          // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
          pixels.setPixelColor(i, pixels.Color(section[0][0], section[0][1], section[0][2])); 
        }//end for
        
        //Section 1 (Right Upper)
        for (int i=8; i<16; i++) {
          // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
          pixels.setPixelColor(i, pixels.Color(section[1][0], section[1][1], section[1][2])); 
        }//end for
        
        //Section 1 (Top Right)
        for (int i=16; i<24; i++) {
          // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
          pixels.setPixelColor(i, pixels.Color(section[2][0], section[2][1], section[2][2])); 
        }//end for
        
        //Section 1 (Top Middle)
        for (int i=24; i<32; i++) {
          // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
          pixels.setPixelColor(i, pixels.Color(section[3][0], section[3][1], section[3][2])); 
        }//end for
        
        //Section 1 (Top Left)
        for (int i=32; i<40; i++) {
          // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
          pixels.setPixelColor(i, pixels.Color(section[4][0], section[4][1], section[4][2])); 
        }//end for
        
        //Section 1 (Left Upper)
        for (int i=40; i<48; i++) {
          // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
          pixels.setPixelColor(i, pixels.Color(section[5][0], section[5][1], section[5][2])); 
        }//end for
        
        //Section 1 (Left Lower)
        for (int i=48; i<56; i++) {
          // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
          pixels.setPixelColor(i, pixels.Color(section[6][0], section[6][1], section[6][2])); 
        }//end for
      
      pixels.show();  //only update if new data available
    }//end if
    
    
    //delay(wait);
  }//end while  
  
  
  
  //pixels.setPixelColor(5, pixels.Color(0, 125, 0)); 
  
  //delay(wait);
  
/* 
  for (int i=0; i<7; i++) {
    Serial.print(i);
    Serial.print(": ");   
    Serial.print(section[i][0]);  //read rgb byte
    Serial.print(" ");
    Serial.print(section[i][1]);
    Serial.print(" ");
    Serial.println(section[i][2]);
  }
  Serial.println();
*/  


  /*
  for(int i=0; i<NUMPIXELS; i++){  // NeoPixels accessed starting at index 0

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
  }
  */
  
}
