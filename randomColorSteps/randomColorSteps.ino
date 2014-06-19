#include <Adafruit_NeoPixel.h>
 
const int analogInPin = A9;  // Analog input pin that the potentiometer is attached to
Adafruit_NeoPixel strip = Adafruit_NeoPixel(2, 6, NEO_GRB + NEO_KHZ800);
int sensorValue = 0;        // value read from the pot
int led = 6;
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);  
//  pinMode(9, INPUT_PULLUP);
  pinMode(led, OUTPUT);
   strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  randomSeed(analogRead(0));
 
}
 
void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);              
  // print the results to the serial monitor:
  Serial.print("sensor = " );                       
  Serial.println(sensorValue);      
  colorWipe(strip.Color(random(255), random(255), random(255)), 25);
 
if (sensorValue < 40){
  Serial.println("leds triggered");
//  digitalWrite(led, HIGH);
//  delay(3000);
//  digitalWrite(led, LOW);
}  
                    
}
 
void patriot() {

} 
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i+=3) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
  delay(1000);
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(0,0,0));
      strip.show();
      delay(wait);
  }
}
