// Define LED pins
const int greenLED = 2;
const int yellowLED = 3;
const int redLED = 4;

// Counter variable
int counter = 0;

void setup() {
  // Set LED pins as OUTPUT
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  // Initialize Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // Simulate or increment the counter
  counter += 10; // You can change this increment value
  Serial.print("Counter: ");
  Serial.println(counter);

  // Turn OFF all LEDs first
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);

  // Conditional logic for LED control
  if (counter < 100) {
    digitalWrite(greenLED, HIGH);
  } else if (counter >= 101 && counter <= 200) {
    digitalWrite(yellowLED, HIGH);
  } else if (counter > 200) {
    digitalWrite(redLED, HIGH);
  }

  // Delay so you can see LED changes
  delay(1000);

  // Reset counter for demonstration
  if (counter > 250) {
    counter = 0;
  }
}
