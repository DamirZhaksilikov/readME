#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(108, PIN, NEO_GRB + NEO_KHZ800);
int god[] = {11, 12, 13, 14, 15, 20, 23, 30, 31, 32, 33, 48, 49, 50, 51, 56, 59, 66, 67, 68, 69, 83, 84, 86, 87, 88, 92, 96, 101, 102, 103, 104, 105};
int xgod[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 16, 17, 18, 19, 21, 22, 24, 25, 26, 27, 28, 29, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 52, 53, 54, 55, 57, 58, 60, 61,
62, 63, 64, 65, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 89, 90, 91, 93, 94, 95, 97, 98, 99, 100, 106, 107};


int lust[] =  {7, 10, 11, 12, 13, 14, 15, 19, 20, 21, 25, 30, 32, 34, 37, 39, 40, 41, 55, 56, 57, 58, 70, 73, 74, 75, 76, 92, 100, 101, 102, 103, 104, 105};
int xlust[] = {0, 1, 2, 3, 4, 5, 6, 8, 9, 16, 17, 18, 22, 23, 24, 26, 27, 28, 29, 31, 33, 35, 36, 38, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 59, 60, 61, 62, 63, 64,
65, 66, 67, 69, 71, 72, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 93, 94, 95, 96, 97, 98, 99, 106, 107};

int no[] = {86, 85, 84, 77, 66, 59, 58, 57, 39, 40, 41, 30, 23, 22, 21, 32};
int xno[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 24, 25, 26, 27, 28, 29, 31, 33, 34, 35, 36, 37, 38, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 
56, 60, 61, 62, 63, 64, 65, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 78, 79, 80, 81, 82, 83, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107};

int count = 0;
int hoodSum = 0;
int zipSum = 0;
int pocketSum = 0;


// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  Serial.begin(9600);
  // End of trinket special code
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
    if(count < 5) {
      hoodSum += analogRead(A0);
      zipSum += analogRead(A1);
      pocketSum = analogRead(A2);
      count++;
    } else {
       boolean hood; boolean pocket; boolean zip;

       if(hoodSum / 5 <= 5) {
          hood = true;
       } 

       if(zipSum / 5 <= 5) {
          zip = true;
       }

       if(pocketSum / 5 >= 5) {
          pocket = true;
       }

     
      if(hood) {
        VIOLENT();
      } else if (pocket) {
        RESERVED();
      } else if (zip) {
        DISSATISFIED();
      } else {
       for(int i = 0; i < strip.numPixels(); i++) {
          strip.setPixelColor(i, 0);
        }
        strip.show(); 
      }
      
      delay(10000);    
      count = 0; 
    }
}



void VIOLENT() { 
    for(int i = 0; i < sizeof(god); i++) {
      strip.setPixelColor(god[i], strip.Color(127, 0, 0));
    }
    for(int i = 0; i < sizeof(xgod); i++) {
        strip.setPixelColor(xgod[i], 0);
    }
    strip.show();
}

void RESERVED() {
  for(int i = 0; i < sizeof(no); i++) {
    strip.setPixelColor(no[i], strip.Color(127, 127, 127));
  }
  for(int i = 0; i < sizeof(xno); i++) {
    strip.setPixelColor(xno[i], 0);
  }
  strip.show(); 
}

void DISSATISFIED() {
        for(int i = 0; i < sizeof(lust); i++) {
      strip.setPixelColor(lust[i], strip.Color(127, 127, 127));
    }

    for(int i = 0; i < sizeof(xlust); i++) {
      strip.setPixelColor(xlust[i], 0);
    }
    strip.show();
  
}

