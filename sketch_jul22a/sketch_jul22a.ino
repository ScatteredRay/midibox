#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel led(1, 8);

void setup() {
    led.begin();
    led.setPixelColor(0, 127, 0, 0);
    led.show();
    //31250  UART TX / UART RX
    Serial3.begin(31250, SERIAL_8N1);
}

void loop() {
    for(uint8_t note = 0x1E; note < 0x5A; note++) {
        led.begin();
        led.setPixelColor(0, 0, 127, 0);
        led.show();
        Serial3.write(0x90);
        Serial3.write(note);
        Serial3.write(0x45);
        delay(100);
        led.begin();
        led.setPixelColor(0, 0, 0, 127);
        led.show();
        Serial3.write(0x90);
        Serial3.write(note);
        Serial3.write(0x00);
        delay(100);
    }
}
