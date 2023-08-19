#include <Adafruit_NeoPixel.h>
#define PIN        6
#define NUMPIXELS 24

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  pixels.begin();
  pixels.clear();
  pixels.show();
}

 void loop() {
  // put your main code here, to run repeatedly:
  // blinkOddEven();
  // tornadopotato();
  // fountain();
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

void tornadopotato() {
  pixels.begin();
  pixels.clear();
  turnOn4(202, 0, 202);
  delay(500);
}

void turnOn4(int r, int g, int b){
  int turnOffPin=0;
  for(int i=0; i<NUMPIXELS+4; i++) {
   // int x=0;

    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show();
    
    if(i >= 3) {
      delay(100);
      pixels.setPixelColor(turnOffPin, pixels.Color(0, 0, 0));
      turnOffPin++;
      r -= 10;
      b -= 10;
    }
  }  
}

void blinkOddEven() {
  pixels.clear();
  pixels.show();
  turnOnOdd();
  delay(500);
  pixels.clear();
  pixels.show();
  turnOnEven();
  delay(500);
}

void turnOnOdd() {
for(int i=0; i<NUMPIXELS; i++) { 
    if (i%2 != 0){
      pixels.setPixelColor(i, pixels.Color(2, 0, 2));
      pixels.show();
    }
  }
}

void turnOnEven() {
for(int i=0; i<NUMPIXELS; i++){
    if (i%2 == 0) {
      pixels.setPixelColor(i, pixels.Color(2, 0, 2));
      pixels.show();
     }
  }
}

/*
for(int i=0; i<NUMPIXELS/2; i++) { 
    if (i%2==0){
      pixels.setPixelColor(i, pixels.Color(20, 0, 100));
      pixels.show();
    }
    delay(1000);
  }  

  for(int i=13; i<NUMPIXELS; i++){
    if (i%2 != 0) {
      pixels.setPixelColor(i, pixels.Color(20, 0, 100));
      pixels.show();
     }
     delay(1000);
  }
*/

  // pixels.fill(pixels.Color(20, 0, 100), 2, 10);

/**
 * TODO
 * 1. 2층(1 2 3 ... 12) 1층(1 2 3 ... 12) 이런 식으로 있을 때 1번 2층 -> 1층, 10번 2층에서 1층 따닥 켜지기
 * 2. 겨울왕국 처럼 푸른색 선이 회오리 돌면서 올라가는 연출 (4칸 정도 라인) -> 난이도 up, 꼬리 쪽이 흐리게
 * 3. 홀수 짝수 번갈아 가면서 블링크
 * 4. 1~3을 함수로 만들어서 반복시키기!
*/

// test for git usage


