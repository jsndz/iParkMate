#include <Wire.h>
#include <TimeLib.h>
#include <RTClib.h>

RTC_DS3231 rtc;
const int irSensorPin = 2; // Replace with your IR sensor pin

void setup() {
  Serial.begin(9600);

  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  pinMode(irSensorPin, INPUT);
}

void loop() {
  if (digitalRead(irSensorPin) == HIGH) {
    // IR sensor detected, get and print the current time
    DateTime now = rtc.now();
    printTime(now);

    // Send time data over the serial port
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    delay(1000); // Adjust the delay as needed
  }
}

void printTime(DateTime time) {
  Serial.print(time.year(), DEC);
  Serial.print('/');
  Serial.print(time.month(), DEC);
  Serial.print('/');
  Serial.print(time.day(), DEC);
  Serial.print(" ");
  Serial.print(time.hour(), DEC);
  Serial.print(':');
  Serial.print(time.minute(), DEC);
  Serial.print(':');
  Serial.print(time.second(), DEC);
  Serial.println();
}
