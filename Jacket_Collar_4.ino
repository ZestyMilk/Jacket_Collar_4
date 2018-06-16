#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 12

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(112, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code


  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() { //Colour, background, start pos, speed
  row1(strip.Color(30, 20, 0), strip.Color(1, 0, 0), 0, 1000);
  //row2(strip.Color(30, 20, 0), strip.Color(20, 0, 0), 29, 400);
  //row3(strip.Color(30, 20, 0), strip.Color(20, 0, 0), 29, 400);
  //row4(strip.Color(30, 20, 0), strip.Color(20, 0, 0), 29, 400);
}

//Row 1
void row1(uint32_t c, uint32_t b, uint32_t p, uint8_t wait) {
  for (int j=0; j<2; j++) {  //do 2 cycles of chasing
    for (int q=0; q < 14; q++) {
      for (uint16_t i=14; i < 28; i=i+14) {
        strip.setPixelColor(i+q, c);
        strip.setPixelColor(i-q, c);
        strip.setPixelColor(i+q-5, b);
        strip.setPixelColor(i-q+5, b);
      }
      strip.show();
      delay(wait);
      }
    }
  }

