#include <Servo.h>
  Servo myServo; // creează un obiect servo
  void setup() {
    myServo.attach(PA0); // atașează servomotorul la pinul PA0 (sau orice alt pin PWM disponibil)
  }
void loop() {
  myServo.write(0); // poziționează la 0 grade
  delay(1000); // așteaptă 1 secundă
  myServo.write(90); // poziționează la 90 de grade
  delay(1000);
  myServo.write(180); // poziționează la 180 de grade
  delay(1000);
}
