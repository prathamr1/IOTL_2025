// LED Blink on Arduino UNO (Built-in LED on digital pin 13)
int ledPin = 13;  // built-in LED

void setup() {
  pinMode(ledPin, OUTPUT); // Initialize the digital pin as an output.
}

void loop() {
  digitalWrite(ledPin, HIGH);  // turn the LED on
  delay(1000);                 // wait for 1 second
  digitalWrite(ledPin, LOW);   // turn the LED off
  delay(1000);                 // wait for 1 second
}
