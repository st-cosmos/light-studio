const uint64_t BEAT_INTERVAL = 397; //in millisecond
uint32_t beat_counter = 1;
uint64_t time_counter = 0;
// const uint32_t beat;
#include <Adafruit_NeoPixel.h>
#define PIN        6
#define NUMPIXELS  24

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    /*
     * TODO - Adafruit Neopixel 등 필요한 코드 넣기
    */
    pixels.begin();
    pixels.clear();
    pixels.show();
    Serial.begin(9600);
    pinMode(13, OUTPUT);
    // prepare(beat_counter);

    while (true)
    {
        if(Serial.available()) {
            char input = Serial.read();
            if(input == 's') {
                break;
            }
        }
    }
    delay(200);
}

void loop() {
    time_counter = millis();
    if(time_counter < 64000) {
        prepare(beat_counter);
        show();
        beat_counter++;
        prepare(beat_counter);
        delay_until_next_beat(time_counter, millis());
    }
    else {
        pixels.clear();
        pixels.show();
    }
}

void prepare(const uint32_t beat) {
    switch (beat)
    {
    case 1: func1(); break;
    case 2: func1(); break;
    case 3: func1(); break;
    case 4: func2(); break;
    case 5: func2(); break;
    case 6: func3(); break;
    case 7: func3(); break;
    case 8: func4(); break;
    case 9: func4(); break;
    case 10: func5(); break;
    case 11: func5(); break;
    case 12: func6(); break;
    case 13: func6(); break;
    case 14: func7(); break;
    case 15: func7(); break;
    case 16: func8(); break;
    case 17: func8(); break;
    case 18: func9(); break;
    case 19: func10(); break;
    case 20: func11(); break;
    case 21: func12(); break;
    case 22: func13(); break;
    case 23: func14(); break;
    case 24: func15(); break;
    case 25: func16(); break;
    case 26: func17(); break;
    case 27: func18(); break;
    case 28: func19(); break;
    case 29: func20(); break;
    case 30: func21(); break;
    case 31: func22(); break;
    case 32: func23(); break;
    case 33: func24(); break;
    case 34: pixels.clear(); pixels.show(); func_OddEven_1(); break;
    case 35: func_OddEven_1(); break;
    case 36: func_OddEven_2(); break;
    case 37: func_OddEven_2(); break;
    case 38: func_OddEven_1(); break;
    case 39: func_OddEven_1(); break;
    case 40: func_OddEven_2(); break;
    case 41: func_OddEven_2(); break;
    case 42: func_OddEven_1(); break;
    case 43: func_OddEven_1(); break;
    case 44: func_OddEven_2(); break;
    case 45: func_OddEven_2(); break;
    case 46: func_OddEven_1(); break;
    case 47: func_OddEven_1(); break;
    case 48: func_OddEven_2(); break;
    case 49: func_OddEven_2(); break;
    case 50: pixels.clear(); pixels.show(); func_OddEven_3(); break;
    case 51: func_OddEven_4(); break;
    case 52: func_OddEven_3(); break;
    case 53: func_OddEven_4(); break;
    case 54: func_OddEven_3(); break;
    case 55: func_OddEven_4(); break;
    case 56: func_OddEven_3(); break;
    case 57: func_OddEven_4(); break;
    case 58: func_OddEven_3(); break;
    case 59: func_OddEven_4(); break;
    case 60: func_OddEven_3(); break;
    case 61: func_OddEven_4(); break;
    case 62: func_OddEven_3(); break;
    case 63: func_OddEven_4(); break;
    case 64: func_OddEven_3(); break;
    case 65: func_OddEven_4(); break;
    case 66: pixels.clear(); pixels.show(); func_OddEven_1(); break;
    case 67: func_OddEven_1(); break;
    case 68: func_OddEven_2(); break;
    case 69: func_OddEven_2(); break;
    case 70: func_OddEven_1(); break;
    case 71: func_OddEven_1(); break;
    case 72: func_OddEven_2(); break;
    case 73: func_OddEven_2(); break;
    case 74: func_OddEven_1(); break;
    case 75: func_OddEven_1(); break;
    case 76: func_OddEven_2(); break;
    case 77: func_OddEven_2(); break;
    case 78: func_OddEven_1(); break;
    case 79: func_OddEven_1(); break;
    case 80: func_OddEven_2(); break;
    case 81: func_OddEven_2(); break;
    case 82: pixels.clear(); pixels.show(); turnOnAll(252,252,252); break;
    case 83: turnOnAll(252,252,252); break;
    case 84: turnOnAll(202,202,202); break;
    case 85: turnOnAll(202,202,202); break;
    case 86: turnOnAll(152,152,152); break;
    case 87: turnOnAll(152,152,152); break;
    case 88: turnOnAll(102,102,102); break;
    case 89: turnOnAll(102,102,102); break;
    case 90: turnOnAll(52,52,52); break;
    case 91: turnOnAll(52,52,52); break;
    case 92: turnOnAll(2,2,2); break;
    case 93: turnOnAll(2,2,2); break;
    case 94: turnOnAll(0,0,0); break;
    case 95: turnOnAll(0,0,0); break;
    case 96: turnOnAll(0,0,0); break;
    case 97: turnOnAll(0,0,0); break;
    case 98: turnOnAll(252,0,150); break;
    case 99: turnOnAll(150,252,0); break;
    case 100: turnOnAll(0,150,252); break;
    case 101: turnOnAll(0,0,0); break;
    case 102: turnOnAll(252,0,150); break;
    case 103: turnOnAll(150,252,0); break;
    case 104: turnOnAll(0,150,252); break;
    case 105: turnOnAll(0,0,0); break;
    case 106: turnOnAll(252,0,150); break;
    case 107: turnOnAll(252,0,150); break;
    case 108: turnOnAll(150,252,0); break;
    case 109: turnOnAll(150,252,0); break;
    case 110: turnOnAll(0,150,252); break;
    case 111: turnOnAll(0,150,252); break;
    case 112: turnOnAll(0,0,0); break;
    case 113: turnOnAll(0,0,0); break;
    case 114: turnOnAll(252,0,150); break;
    case 115: turnOnAll(150,252,0); break;
    case 116: turnOnAll(0,150,252); break;
    case 117: turnOnAll(0,0,0); break;
    case 118: turnOnAll(252,0,150); break;
    case 119: turnOnAll(150,252,0); break;
    case 120: turnOnAll(0,150,252); break;
    case 121: turnOnAll(0,0,0); break;
    case 122: turnOnAll(252,0,150); break;
    case 123: turnOnAll(252,0,150); break;
    case 124: turnOnAll(150,252,0); break;
    case 125: turnOnAll(150,252,0); break;
    case 126: turnOnAll(0,150,252); break;
    case 127: turnOnAll(0,150,252); break;
    case 128: turnOnAll(0,0,0); break;
    case 129: turnOnAll(0,0,0); break;
    case 130: turnOnAll(0,0,0); break;
    case 131: turnOnhalf_1(100,0,70); break;
    case 132: turnOnhalf_1(100,140,0); break;
    case 133: turnOnhalf_1(0,200,250); break;
    case 134: turnOnAll(0,0,0); break;
    case 135: turnOnhalf_2(100,0,70); break;
    case 136: turnOnhalf_2(100,140,0); break;
    case 137: turnOnhalf_2(0,200,250); break;
    case 138: turnOnAll(0,0,0); break;
    case 139: turnOnAll(210,30,30); break;
    case 140: turnOnAll(210,60,60); break;
    case 141: turnOnAll(210,90,90); break;
    case 142: turnOnAll(210,120,120); break;
    case 143: turnOnAll(210,150,150); break;
    case 144: turnOnAll(210,180,180); break;
    case 145: turnOnAll(210,210,210); break;
    case 146: turnOnAll(0,0,0); break;
    case 147: turnOnAll(210,210,210); break;
    case 148: turnOnAll(0,0,0); break;
    case 149: turnOnAll(210,210,210); break;
    case 150: turnOnAll(0,0,0); break;
    case 151: turnOnAll(210,210,210); break;
    case 152: turnOnAll(0,0,0); break;
    case 153: turnOnAll(210,210,210); break;
    case 154: turnOnAll(0,0,0); break;
    case 155: turnOnAll(210,210,210); break;
    case 156: turnOnAll(0,0,0); break;
    case 157: turnOnAll(210,210,210); break;
    case 158: turnOnAll(0,0,0); break;
    case 159: turnOnAll(210,210,210); break;
    case 160: turnOnAll(0,0,0); break;
    case 161: turnOnAll(210,210,210); break;
    case 162: turnOnAll(0,0,0); break;

    default: break;
    }
}

void show() {
    pixels.show();
    // pixels.clear();
}

void delay_until_next_beat(const uint64_t prev_time, const uint64_t curr_time) {
    uint64_t delay_time = prev_time + BEAT_INTERVAL - curr_time;
    delay(delay_time);
}

void func1(){
    pixels.setPixelColor(0, pixels.Color(0,216,255));
    pixels.show();
    }

void func2(){
    pixels.setPixelColor(1, pixels.Color(0,216,255));
    pixels.show();
}
void func3(){
    pixels.setPixelColor(2, pixels.Color(0,216,255));
    pixels.show();
    }

void func4(){
    pixels.setPixelColor(3, pixels.Color(0,216,255));
    pixels.show();
}
void func5(){
    pixels.setPixelColor(4, pixels.Color(0,216,255));
    pixels.show();
    }

void func6(){
    pixels.setPixelColor(5, pixels.Color(0,216,255));
    pixels.show();
}
void func7(){
    pixels.setPixelColor(6, pixels.Color(0,216,255));
    pixels.show();
    }

void func8(){
    pixels.setPixelColor(7, pixels.Color(0,216,255));
    pixels.show();
}
void func9(){
    pixels.setPixelColor(8, pixels.Color(0,216,255));
    pixels.show();
}
void func10(){
    pixels.setPixelColor(9, pixels.Color(0,216,255));
    pixels.show();
}
void func11(){
    pixels.setPixelColor(10, pixels.Color(0,216,255));
    pixels.show();
}
void func12(){
    pixels.setPixelColor(11, pixels.Color(0,216,255));
    pixels.show();
}
void func13(){
    pixels.setPixelColor(12, pixels.Color(0,216,255));
    pixels.show();
}
void func14(){
    pixels.setPixelColor(13, pixels.Color(0,216,255));
    pixels.show();
}
void func15(){
    pixels.setPixelColor(14, pixels.Color(0,216,255));
    pixels.show();
}
void func16(){
    pixels.setPixelColor(15, pixels.Color(0,216,255));
    pixels.show();
}
void func17(){
    pixels.setPixelColor(16, pixels.Color(0,216,255));
    pixels.show();
}
void func18(){
    pixels.setPixelColor(17, pixels.Color(0,216,255));
    pixels.show();
}
void func19(){
    pixels.setPixelColor(18, pixels.Color(0,216,255));
    pixels.show();
}
void func20(){
    pixels.setPixelColor(19, pixels.Color(0,216,255));
    pixels.show();
}
void func21(){
    pixels.setPixelColor(20, pixels.Color(0,216,255));
    pixels.show();
}
void func22(){
    pixels.setPixelColor(21, pixels.Color(0,216,255));
    pixels.show();
}
void func23(){
    pixels.setPixelColor(22, pixels.Color(0,216,255));
    pixels.show();
}
void func24(){
    pixels.setPixelColor(23, pixels.Color(0,216,255));
    pixels.show();
}

void func_OddEven_1() {
    turnOnOdd(0,100,100);
    turnOnEven(0,10,10);
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

void func_OddEven_2(){
    turnOnOdd(0,10,10);
    turnOnEven(0,100,100);
}

void func_OddEven_3() {
    turnOnOdd_2(100,0,100);
    turnOnEven_2(10,0,10);
}

void func_OddEven_4() {
    turnOnOdd_2(10,0,10);
    turnOnEven_2(100,0,100);
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

void turnOnAll(int r, int g, int b){
    for(int i=0; i<24; i++){
        pixels.setPixelColor(i, pixels.Color(r, g, b));
        pixels.show();
    }
}
void turnOnhalf_1(int r, int g, int b){
    for(int i=0; i<12; i++){
        pixels.setPixelColor(i, pixels.Color(r, g, b));
        pixels.show();
    }
}
void turnOnhalf_2(int r, int g, int b){
    for(int i=12; i<24; i++){
        pixels.setPixelColor(i, pixels.Color(r, g, b));
        pixels.show();
    }
}
