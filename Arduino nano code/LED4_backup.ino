#include <FastLED.h>
#define LED_PIN 2 //specify data pin on the board - D2
#define NUM_LEDS 50 //specify number of LED

CRGB leds[NUM_LEDS];
int pass = 0;
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
   
   if(incoming == "blue"){
      for(int j=0; j<NUM_LEDS; j++){
        leds[j] = CRGB(0,0,255);
        FastLED.show();
        delay(1.5);
      }
      pass = 0;
   }

   if(incoming == "green"){
      for(int j=0; j<NUM_LEDS; j++){
        leds[j] = CRGB(255,0,0);
        FastLED.show();
        delay(1.5);
      }
      pass = 0;
   }

   if(incoming == "red"){
      for(int j=0; j<NUM_LEDS; j++){
        leds[j] = CRGB(0,255,0);
        FastLED.show();
        delay(1.5);
      }
      pass = 0;
   }

   if(incoming == "off"){
      for(int j=0; j<NUM_LEDS; j++){
        leds[j] = CRGB(0,0,0);
        FastLED.show();
        delay(1.5);
      }
      pass = 0;
   }

   if(incoming == "white"){
      for(int j=0; j<NUM_LEDS; j++){
        leds[j] = CRGB(255,255,255);
        FastLED.show();
        delay(1.5);
      }
      pass = 0;
   }

   if(incoming == "purple"){
      for(int j=0; j<NUM_LEDS; j++){
        leds[j] = CRGB::Purple;
        FastLED.show();
        delay(1.5);
      }
      pass = 0;
   }

   if(incoming == "pink"){
      for(int j=0; j<NUM_LEDS; j++){
        leds[j] = CRGB::DeepPink;
        FastLED.show();
        delay(1.5);
      }
      pass = 0;
   }

   if(incoming == "yellow"){
      for(int j=0; j<NUM_LEDS; j++){
        leds[j] = CRGB::Yellow;
        FastLED.show();
        delay(1.5);
      }
      pass = 0;
   }

   if(incoming == "orange"){
      for(int j=0; j<NUM_LEDS; j++){
        leds[j] = CRGB::Orange;
        FastLED.show();
        delay(1.5);
      }
      pass = 0;
   }
   
   if(incoming == "rainbow"){
      rainbow_wave(1000, 10);                                      // Speed, delta hue values.
      FastLED.show();
      pass = 0;  
   }
   
   if(incoming == "whiteflow" && pass == 0){
      for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      // Turn our current led on to white, then show the leds
      leds[whiteLed] = CRGB::White;

      // Show the leds (only one of which is set to white, from above)
      FastLED.show();

      // Wait a little bit
      delay(30);

      // Turn our current led back to black for the next loop around
      leds[whiteLed] = CRGB::Black;
      }
      FastLED.show();
      pass = 1;
   }
   if(incoming == "" && pass == 1){
      for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      // Turn our current led on to white, then show the leds
      leds[whiteLed] = CRGB::White;

      // Show the leds (only one of which is set to white, from above)
      FastLED.show();

      // Wait a little bit
      delay(30);

      // Turn our current led back to black for the next loop around
      leds[whiteLed] = CRGB::Black;
      }
      FastLED.show();
   }
} 


void rainbow_wave(uint8_t thisSpeed, uint8_t deltaHue) {     // The fill_rainbow call doesn't support brightness levels.
 
// uint8_t thisHue = beatsin8(thisSpeed,0,255);                // A simple rainbow wave.
 uint8_t thisHue = beat8(thisSpeed,255);                     // A simple rainbow march.
  
 fill_rainbow(leds, NUM_LEDS, thisHue, deltaHue);            // Use FastLED's fill_rainbow routine.
 
} // rainbow_wave()

  
    
 
