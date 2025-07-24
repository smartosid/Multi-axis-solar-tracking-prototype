#include <Servo.h>

int ldrLeft = A0;    // Left LDR (vertical)
int ldrRight = A1;   // Right LDR (vertical)
int ldrTop = A2;     // Top LDR (horizontal)
int ldrBottom = A3;  // Bottom LDR (horizontal)

Servo myServoV; // Vertical movement
Servo myServoH; // Horizontal movement

int currentV = 90; // current vertical position
int currentH = 90; // current horizontal position

void setup() {
  Serial.begin(9600);
  myServoV.attach(9);   // Vertical servo
  myServoH.attach(10);  // Horizontal servo

  myServoV.write(currentV);
  myServoH.write(currentH);
}

void loop() {
  int leftValue = analogRead(ldrLeft);
  int rightValue = analogRead(ldrRight);
  int topValue = analogRead(ldrTop);
  int bottomValue = analogRead(ldrBottom);

  Serial.print("Left: "); Serial.print(leftValue);
  Serial.print(" | Right: "); Serial.print(rightValue);
  Serial.print(" | Top: "); Serial.print(topValue);
  Serial.print(" | Bottom: "); Serial.println(bottomValue);

  int targetV = 90;
  int targetH = 90;

  // Vertical control
  if (leftValue < 100 && rightValue >= 100) {
    Serial.println("Light on LEFT");
    targetV = 0;
  } else if (rightValue < 100 && leftValue >= 100) {
    Serial.println("Light on RIGHT");
    targetV = 180;
  } else {
    targetV = 90;
  }

  // Horizontal control (less movement)
  if (topValue < 100 && bottomValue >= 100) {
    Serial.println("Light on TOP");
    targetH = 0;
  } else if (bottomValue < 100 && topValue >= 100) {
    Serial.println("Light on BOTTOM");
    targetH = 120;
  } else {
    targetH = 60;
  }

  // Smooth vertical servo movement
  if (currentV < targetV) {
    for (int i = currentV; i <= targetV; i++) {
      myServoV.write(i);
      delay(5);
    }
  } else if (currentV > targetV) {
    for (int i = currentV; i >= targetV; i--) {
      myServoV.write(i);
      delay(5);
    }
  }

  // Smooth horizontal servo movement
  if (currentH < targetH) {
    for (int i = currentH; i <= targetH; i++) {
      myServoH.write(i);
      delay(5);
    }
  } else if (currentH > targetH) {
    for (int i = currentH; i >= targetH; i--) {
      myServoH.write(i);
      delay(5);
    }
  }

  currentV = targetV;
  currentH = targetH;

  Serial.println("----------------------------");
  delay(500);
}
