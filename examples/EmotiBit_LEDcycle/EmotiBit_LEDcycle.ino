#include "EmotiBit_NCP5623.h"

TwoWire myWire(&sercom1, 11, 13);
NCP5623 led;

void setup() {
	Serial.begin(9600);
	while(!Serial.available());
	myWire.begin();
	myWire.setClock(100000);
	pinPeripheral(11, PIO_SERCOM);
	pinPeripheral(13, PIO_SERCOM);
	Serial.println("flushed");
	led.begin(myWire);
	Serial.println("exiting Setup");
}


void loop() {
	led.setLED(led.LED1, 255);
	delay(500);
	led.setLED(led.LED1, 0);
	delay(500);
	led.setLED(led.LED2, 255);
	delay(500);
	led.setLED(led.LED2, 0);
	delay(500);
	led.setLED(led.LED3, 255);
	delay(500);
	led.setLED(led.LED3, 0);
	delay(500);
}