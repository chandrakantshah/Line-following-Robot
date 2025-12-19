// Code for the Line Following Robot

// Define sensor pins
const int leftSensor = 2;
const int rightSensor = 3;

// Define motor pins
const int leftMotorForward = 5;
const int leftMotorBackward = 6;
const int rightMotorForward = 9;
const int rightMotorBackward = 10;

void setup() {
  // Set sensor pins as input
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  // Set motor pins as output
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);
}

void loop() {
  int leftState = digitalRead(leftSensor);
  int rightState = digitalRead(rightSensor);

  // Both sensors on line
  if (leftState == HIGH && rightState == HIGH) {
    moveForward();
  }
  // Left sensor off line
  else if (leftState == LOW && rightState == HIGH) {
    turnRight();
  }
  // Right sensor off line
  else if (leftState == HIGH && rightState == LOW) {
    turnLeft();
  }
  // Both sensors off line
  else {
    stopMotors();
  }
}

void moveForward() {
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, HIGH);
  digitalWrite(rightMotorBackward, LOW);
}

void turnLeft() {
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, HIGH);
  digitalWrite(rightMotorBackward, LOW);
}

void turnRight() {
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, LOW);
}

void stopMotors() {
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, LOW);
}
