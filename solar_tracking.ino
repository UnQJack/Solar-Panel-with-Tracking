#include <Servo.h>
// Pini
  const int light1Pin = PA0;
  const int light2Pin = PA1;
  const int solarPin = PA2;
  const int servoPin = PA7;
  Servo servo1;
  int margin = 50; // prag diferență lumină
  int angle = 90; // poziție virtuală între 0–180
  int step = 1; // pas la fiecare ciclu (echivalent mișcare)
  unsigned long moveDuration = 100; // cât timp să ruleze motorul pe ciclu (ms)
void setup() {
  servo1.attach(servoPin);
  servo1.write(90); // stop
  Serial.begin(9600);
}
void loop() {
  int light1Reading = analogRead(light1Pin);
  int light2Reading = analogRead(light2Pin) - 120;
  int difference = light2Reading - light1Reading;
// Citire panou solar
int solarReading = analogRead(solarPin);
float solarVoltage = solarReading * 5.0 / 1023.0;
Serial.print("Sensor 1: ");
Serial.print(light1Reading);
Serial.print(" Sensor 2: ");
Serial.print(light2Reading);
Serial.print(" Voltage: ");
Serial.print(solarVoltage);
Serial.print("V Virtual angle: ");
Serial.println(angle);
// Rotație spre dreapta (crește unghiul)
if (difference > margin && angle < 360) {
  servo1.write(100); // rotire dreapta
  delay(moveDuration);
  servo1.write(90); // stop
  angle += step;
}
// Rotație spre stânga (scade unghiul)
else if (difference < -margin && angle > 0) {
  servo1.write(80); // rotire stânga
  delay(moveDuration);
  servo1.write(90); // stop
  angle -= step;
}
// Dacă diferența e mică => stai pe loc
  else {
    servo1.write(90); // stop
  }
  delay(100); // pauză între cicluri
}
