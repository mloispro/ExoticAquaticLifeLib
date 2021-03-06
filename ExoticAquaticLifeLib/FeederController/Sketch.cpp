﻿/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

#include <_SimulateDebug.h>
#include <RTCExt.h>
#include <SerialExt.h>
using namespace Utils;

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(115200);
	while(!Serial);
	// initialize digital pin 13 as an output.
	RTCExt::Init();
	pinMode(13, OUTPUT);
	SerialExt::Debug("F");

}

// the loop function runs over and over again forever
void loop() {
	SerialExt::Debug("IsDebugging", _IsDebuging);
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
