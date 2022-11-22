#include <FastLED.h>
#define LED_PIN 2 //specify data pin on the board - D2
#define NUM_LEDS 50 //specify number of LED

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5,500);
  FastLED.clear();
  FastLED.show();
  Serial.begin(9600);
  int r = 0;
  int g = 0;
  int b = 0;
}

void loop() {
   String incoming = Serial.readString();
   Serial.println(incoming);
   // Get serial data
   // Check if serial data equal any color name
   if(incoming == "blue"){
      for(int j=0; j<NUM_LEDS; j++){
        leds[j] = CRGB(0,0,255);
        FastLED.show();
        delay(1.5);
      }
   }

   if(incoming == "green"){
      for(int j=0; j<NUM_LEDS; j++){
        leds[j] = CRGB(255,0,0);
        FastLED.show();
        delay(1.5);
      }
   }

   if(incoming == "red"){
      for(int j=0; j<NUM_LEDS; j++){
        leds[j] = CRGB(0,255,0);
        FastLED.show();
        delay(1.5);
      }
   }

   if(incoming == "off"){
      for(int j=0; j<NUM_LEDS; j++){
        leds[j] = CRGB(0,0,0);
        FastLED.show();
        delay(1.5);
      }
   }

   if(incoming == "white"){
      for(int j=0; j<NUM_LEDS; j++){
        leds[j] = CRGB(255,255,255);
        FastLED.show();
        delay(1.5);
      }
   }

   if(incoming == "yellow"){
      for(int j=0; j<NUM_LEDS; j++){
        leds[j] = CRGB::Yellow;
        FastLED.show();
        delay(1.5);
      }
   }
}




