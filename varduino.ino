#include <Adafruit_NeoPixel.h>

#define LED_PIN    6
#define LED_COUNT 120

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

void setup() {
  Serial.begin(230400);
  Serial.println("ok");
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(150); // Set BRIGHTNESS to about 1/5 (max = 255)

  Serial.println("D");
  

}

char r;
int val, npixel;

void loop() {
  if(Serial.available() > 0){
    r = Serial.read();
    //Serial.print(r);
    if(r == '\n'){
      npixel = 0;
      //Serial.println(" ");
      val = 0;
      strip.show();
      //break;
    }
    else if(r == ' '){
      //Serial.println(val);
      if(val < 100)
        strip.setPixelColor(npixel, strip.Color(0, 0, val));
      else if(val < 130)
        strip.setPixelColor(npixel, strip.Color(0, val/3.5, 30));
      else
        strip.setPixelColor(npixel, strip.Color(val/2, 0, 0));
      npixel += 1;
      //Serial.print(val);
      //Serial.print("\n");
      val = 0;
    }
    else if(r != ' '){
      //Serial.print(r - '0');
      val = val*10 + (r - '0');
      val = abs(val);
    }
  }
}
