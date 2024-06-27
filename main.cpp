void setup() {
    //31250  UART TX / UART RX
    Serial3.begin(31250, SERIAL_8N1);
}

void loop() {
    for(uint8_t note = 0x1E; note < 0x5A; note++) {
        Serial3.write(0x90);
        Serial3.write(note);
        Serial3.write(0x45);
        delay(100);
        Serial3.write(0x90);
        Serial3.write(note);
        Serial3.write(0x00);
        delay(100);
    }
}
