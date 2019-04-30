#include <Servo.h>
 
Servo myservo;  // crea el objeto servo
 
int pos = 0;    // posicion del servo
 
void setup() {
   myservo.attach(10);  // vincula el servo al pin digital 9
}
 
void loop() {
myservo.write(180);
delay(15);

myservo.write(0);
delay(15);
}
