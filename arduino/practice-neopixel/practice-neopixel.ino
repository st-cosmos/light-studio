#include <Adafruit_NeoPixel.h>
#define PIN        6
#define NUMPIXELS 24

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  pixels.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  pixels.clear();
  pixels.show();
  delay(1000);

  for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(20, 0, 100));
    pixels.show();
    delay(1000);
  }
  // pixels.fill(pixels.Color(20, 0, 100), 2, 10);
}

/**
 * TODO
 * 1. 2층(1 2 3 ... 12) 1층(1 2 3 ... 12) 이런 식으로 있을 때 1번 2층 -> 1층, 10번 2층에서 1층 따닥 켜지기
 * 2. 겨울왕국 처럼 푸른색 선이 회오리 돌면서 올라가는 연출 (4칸 정도 라인) -> 난이도 up, 꼬리 쪽이 흐리게
 * 3. 홀수 짝수 번갈아 가면서 블링크
 * 4. 1~3을 함수로 만들어서 반복시키기!
*/

// test for git usage