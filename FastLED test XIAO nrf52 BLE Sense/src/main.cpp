#include <Arduino.h>
#include <FastLED.h>


FASTLED_USING_NAMESPACE

//#define DATA_PIN    D1 
#define DATA_PIN    3 
// #define DATA_PIN 3 is equivalent to D1 according to pin definitions for this board
// Neither 3 nor D1 compiles
// C:\Users\Tabula Rasa\AppData\Local\Arduino15\packages\Seeeduino\hardware\nrf52\1.1.8\variants\Seeed_XIAO_nRF52840_Sense\variant.h


#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    5
CRGB leds[NUM_LEDS];

#define BRIGHTNESS          40
#define FRAMES_PER_SECOND  120

void setup() {
  delay(3000);
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}


uint8_t gHue = 0; 
  
void loop(){

  fill_rainbow( leds, NUM_LEDS, gHue, 7);
  EVERY_N_MILLISECONDS( 20 ) { gHue++; } 
  FastLED.show();  
  FastLED.delay(1000/FRAMES_PER_SECOND); 

}

