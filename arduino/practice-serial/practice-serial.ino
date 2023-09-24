/*void setup() {
    Serial.begin(9600);
}

void loop() {
    if(Serial.available()) {
        char input = Serial.read();
        if(input == 's') {
            Serial.println("Start show!");
        }
        else {
            Serial.println("Something else");
        }
    }
}
*/

#include <Adafruit_NeoPixel.h>
#define PIN        6
#define NUMPIXELS  24

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.clear();
  pixels.show();
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
 if (Serial.available()) {
    char command = Serial.read();
    digitalWrite(13, HIGH);
    Serial.println(command);
    if (command == 's') {
      //  turnOnLights();cd
      intro_1();
      intro_2();
      intro_3();
      intro_2();
      intro_4(252,252,252);
    }
    else {
        turnOffLights();
    }
  }
}

void turnOnLights() {
  for (int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(30, 0, 100));
  }
  pixels.show();
  }

void turnOffLights() {
  pixels.clear();
  pixels.show();
}

void fountain(){
  for(int i=0; i<NUMPIXELS/2; i++){
    pixels.setPixelColor(i, pixels.Color(30, 0, 100));
    pixels.show();
    delay(100);
    pixels.setPixelColor(i+12, pixels.Color(30, 0, 100));
    pixels.show();
    delay(1000);
    pixels.clear();
  }
}

void intro_1(){
  for (int i = 0; i < 8; i++){
    pixels.setPixelColor(i, pixels.Color(0,216,255));
    pixels.show();
    delay(800);
  }
  for(int i=8; i<NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(0,216,255));
    pixels.show();
    delay(400);
  }
}

void intro_2(){
  pixels.clear();
  pixels.show();
  for(int a=0; a<4; a++) {
    turnOnOdd(0,200,200);
    turnOnEven(0,50,50);
    delay(800);
    turnOnOdd(0,50,50);
    turnOnEven(0,200,200);
    delay(800);
  }
}

void turnOnOdd(int r, int g, int b){
for(int i=0; i<12; i++) { 
    if (i%2 != 0){
      pixels.setPixelColor(i, pixels.Color(r, g, b));
      pixels.show();
    }
  }
}

void turnOnEven(int r, int g, int b){
for(int i=0; i<12; i++){
    if (i%2 == 0) {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
      pixels.show();
     }
  }
}

void intro_3(){
  pixels.clear();
  pixels.show();
  for(int a=0; a<8; a++) {
    turnOnOdd_2(200,0,200);
    turnOnEven_2(50,0,50);
    delay(400);
    turnOnOdd_2(50,0,50);
    turnOnEven_2(200,0,200);
    delay(400);
  }
}

void turnOnOdd_2(int r, int g, int b){
for(int i=12; i<24; i++) { 
    if (i%2 != 0){
      pixels.setPixelColor(i, pixels.Color(r, g, b));
      pixels.show();
    }
  }
}

void turnOnEven_2(int r, int g, int b){
for(int i=12; i<24; i++){
    if (i%2 == 0) {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
      pixels.show();
     }
  }
}

void intro_4(int r, int g, int b){
  for (int x=0; x<5; x++){
      for(int i=0; i<24; i++) { 
      pixels.setPixelColor(i, pixels.Color(r, g, b));
      pixels.show();
      }
      r -= 50;
      g -= 50;
      b -= 50;
      delay(800);  
    }
    pixels.clear();
  }

void highlight_1(){
  
}