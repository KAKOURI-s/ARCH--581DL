#include<Servo.h>
Servo myServo;

int SensorValue;
int SensorLow = 1023;
int SensorHigh = 0;
int angle;

const int LED_PIN = 13; //build-in LED

void setup() {
  myServo.attach (10);
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  while (millis() < 5000){
    SensorValue = analogRead(A1);
    if (SensorValue > SensorHigh){
      SensorHigh = SensorValue;
    }
    if (SensorValue < SensorLow){
      SensorLow = SensorValue;
    }
  }
  digitalWrite(LED_PIN, LOW);
}

void loop (){
  SensorValue = analogRead(A1);
  
  angle = map(SensorValue, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);
  myServo.write(angle);

  delay(10);
}
