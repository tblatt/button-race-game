#include <Adafruit_NeoPixel.h>

#define LED_PIN D4  // Pin the LED strip is connected to
#define LED_PIN2 D3  // Pin the second LED strip is connected to

#define NUM_LEDS 50  // Number of LEDs in the strip
#define BUTTON_PIN D5  // Pin the button is connected to
#define BUTTON2_PIN D2  // Pin the second button is connected to
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUM_LEDS, LED_PIN2, NEO_GRB + NEO_KHZ800);
int ledIndex = 0;  // Keeps track of the current LED
int ledIndex2 = 0;  // Keeps track of the current LED
unsigned long buttonPressTime = 0;
unsigned long buttonReleaseTime = 0;
unsigned long debounce = 25;  // Debounce time in milliseconds
bool buttonPressed = false;

unsigned long button2PressTime = 0;
unsigned long button2ReleaseTime = 0;
bool button2Pressed = false;

int i = 0;
void setup() {
  strip.begin();
  strip2.begin();
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
      strip.fill((0,0,0));
      strip2.fill((0,0,0));
      strip.show();
      strip2.show();
      for (int i = ledIndex; i < NUM_LEDS + 1; i++) {
          
          strip.setPixelColor(NUM_LEDS-i+3, 0, 0, 0);  // off
          strip.setPixelColor(NUM_LEDS-i, 5*(i), 255-(5*sqrt(i)), 0);
          strip2.setPixelColor(NUM_LEDS-i+3, 0, 0, 0);  // off
          strip2.setPixelColor(NUM_LEDS-i, 5*(i), 255-(5*sqrt(i)), 0);
        strip.show(); 
        strip2.show(); 
        delay (110);
     }

  
  strip.setPixelColor(0, 255, 0, 0);
  strip.setPixelColor(2, 0, 0, 0);  // off
  strip2.setPixelColor(0, 255, 0, 0);
  strip2.setPixelColor(2, 0, 0, 0);  // off
  delay (110);
  strip.show();  
  strip2.show();
  strip.setPixelColor(1, 0, 0, 0);  // off    
  strip2.setPixelColor(1, 0, 0, 0);  // off
  delay (110);
  strip.show();
  strip2.show();  
}


void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    if (!buttonPressed) {
      buttonPressTime = millis();
      if (buttonPressTime - buttonReleaseTime >= debounce) {
        for (int i = ledIndex; i < ledIndex + 1; i++) {
          strip.setPixelColor(i, 5*i, 255-(5*i), 0); 
          strip.setPixelColor(i-2, 0, 0, 0); 
        }
        strip.show();  
        ledIndex++;  
        if (ledIndex >= NUM_LEDS) {  
          ledIndex2 = 0;
          ledIndex = 0;
          strip.fill((0,0,0));
          strip2.fill((0,0,0));
          strip.show();
          strip2.show();
          delay (50);
          for (int j = 0; j < 20; j++){
           strip.fill((255,255,255));
           strip.show();
           delay (50);
           strip.fill((0,0,0));
           strip.show();
           delay (50);
         }  
          delay (5000);
        }
        buttonPressed = true;
      }
    }
  }
  else {
    buttonReleaseTime = millis();
    buttonPressed = false;
  }

  if (digitalRead(BUTTON2_PIN) == LOW) {
    if (!button2Pressed) {
      button2PressTime = millis();
      if (button2PressTime - button2ReleaseTime >= debounce) {
        for (int i = ledIndex2; i < ledIndex2 + 1; i++) {
          strip2.setPixelColor(i, 5*i, 255-(5*i), 0); 
          strip2.setPixelColor(i-2, 0, 0, 0); 
        }
        strip2.show();  
        ledIndex2++;  
        if (ledIndex2 >= NUM_LEDS) {  
          ledIndex2 = 0;
          ledIndex = 0;
          strip.fill((0,0,0));
          strip2.fill((0,0,0));
          strip.show();
          strip2.show();
          delay (50);
          for (int j = 0; j < 20; j++){
           strip2.fill((255,255,255));
           strip2.show();
           delay (50);
           strip2.fill((0,0,0));
           strip2.show();
           delay (50);
         }
          delay (5000);
        }
        button2Pressed = true;
      }
    }
  }
  else {
    button2ReleaseTime = millis();
    button2Pressed = false;
  }
}
