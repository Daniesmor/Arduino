#include <Arduino.h>
#include <Servo.h>

Servo servoD;
Servo servoI;
const int sensorPinI = 9;
const int sensorPinD = 3;
const int buzzer = 2;

void setup() {
  servoD.attach(8);
  servoI.attach(7);
  pinMode(sensorPinD, INPUT);
  pinMode(sensorPinI, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
int valueD = 0;
int valueI = 0;
valueD = digitalRead(sensorPinD);
valueI = digitalRead(sensorPinI);

if (valueD == LOW ) {
  servoD.write(0);
  servoI.write(0);
  tone(buzzer, 440);
} else if (valueI == LOW) {
  servoD.write(180);
  servoI.write(180);
  tone(buzzer, 440);
} else if (valueI && valueD == HIGH) {
  servoD.write(0);
  servoI.write(180); 
  noTone(buzzer);
} else {
  servoD.write(90);
  servoI.write(90);
  tone(buzzer, 700);
  delay(500);
  noTone(buzzer);
  delay(500);
}
}