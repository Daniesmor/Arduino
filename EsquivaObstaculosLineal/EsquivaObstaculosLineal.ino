#include <Servo.h>
#include <NewPing.h>

#define TRIGGER_PIN  6
#define ECHO_PIN     5
#define MAX_DISTANCE 500

Servo servoD;
Servo servoI;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int uS, distancia;
void setup() {
  //Serial.begin(9600);
  servoD.attach(8);
  servoI.attach(7);
  servoD.write(0);
  servoI.write(180);
 

 
}


void loop() {
uS = sonar.ping_median();
distancia = (uS/ US_ROUNDTRIP_CM);
if (distancia < 20) {
  servoD.write(180);
  delay (500);
  servoI.write(180);
  delay (500);
}
}
