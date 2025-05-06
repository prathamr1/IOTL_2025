// Potentiometer pins
const int potRed = A0;
const int potGreen = A1;
const int potBlue = A2;

// RGB LED pins (PWM capable)
const int ledRed = 9;
const int ledGreen = 10;
const int ledBlue = 11;

void setup() {
  // Set LED pins as OUTPUT
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
}

void loop() {
  // Read analog values from potentiometers (0 to 1023)
  int redValue = analogRead(potRed);
  int greenValue = analogRead(potGreen);
  int blueValue = analogRead(potBlue);

  // Map analog values to PWM range (0 to 255)
  redValue = map(redValue, 0, 1023, 0, 255);
  greenValue = map(greenValue, 0, 1023, 0, 255);
  blueValue = map(blueValue, 0, 1023, 0, 255);

  // Write values to RGB LED
  analogWrite(ledRed, redValue);
  analogWrite(ledGreen, greenValue);
  analogWrite(ledBlue, blueValue);

  delay(50); // Smooth out updates
}
