void setup() {
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