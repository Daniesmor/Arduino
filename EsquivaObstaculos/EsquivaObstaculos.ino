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
if (distancia < 10) {
  servoD.write(180);
  servoI.write(0);
  delay (500);
  servoD.write(180);    //Gira hasta que la distancia sea de más de 10cm
  servoI.write(180);
  } else if (distancia >12) {
    servoD.write(0);    //Para adelante
    servoI.write(180);
  }
}
