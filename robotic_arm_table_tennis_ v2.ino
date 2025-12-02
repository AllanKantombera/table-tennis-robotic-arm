#include <Servo.h>

const int trigPin = 5;
const int echoPin = 4;

Servo posServo;     // Servo that chooses position
Servo kickServo;    // Servo that kicks the ball

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  posServo.attach(2);
  kickServo.attach(0);

  // Start servos at rest
  posServo.write(45);
  kickServo.write(0);
}

void loop() {
  float distance = measureDistance();
  Serial.println(distance);

  if (distance < 6) {
    // Position 1
    posServo.write(3);
    delay(80);
    kickBall();
  }
  else if (distance < 8) {
    // Position 2
    posServo.write(45);
    delay(80);
    kickBall();
  }
  else if (distance < 10) {
    // Position 3
    posServo.write(90);
    delay(80);
    kickBall();
  }

  delay(50);
}

void kickBall() {
  kickServo.write(0);
  delay(80);

  kickServo.write(70);   // Kick forward
  delay(120);

  kickServo.write(0);    // Return to rest
  delay(350);
}

// Ultrasonic measurement
float measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(3);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 25000); // timeout 25ms

  float distance = duration * 0.034 / 2;
  return distance;
}