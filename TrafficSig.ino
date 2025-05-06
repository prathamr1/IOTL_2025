// Pin configuration
int redLED = 13;
int yellowLED = 12;
int greenLED = 11;
int buttonPin = 8;  // Emergency vehicle or pedestrian button

// Variables to store button state
int buttonState = 0;
int lastButtonState = 0;

void setup() {
  // Set the LED pins as outputs
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  // Set the button pin as input
  pinMode(buttonPin, INPUT);
  
  // Start with all LEDs off
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  
  // Initial delay time for traffic signals
  delay(1000);  // Give time for setup
}

void loop() {
  // Read the state of the button
  buttonState = digitalRead(buttonPin);

  // If the button is pressed (simulate emergency vehicle or pedestrian request)
  if (buttonState == HIGH && lastButtonState == LOW) {
    handleButtonPress();
    delay(500);  // Debounce delay
  }
  
  // Traffic light sequence when button is not pressed
  else {
    trafficLightSequence();
  }

  lastButtonState = buttonState;  // Store the button state for the next loop
}

// Function to control traffic signal sequence
void trafficLightSequence() {
  // Red Light
  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  delay(5000);  // Red light stays for 5 seconds
  
  // Yellow Light
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(greenLED, LOW);
  delay(2000);  // Yellow light stays for 2 seconds

  // Green Light
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);
  delay(5000);  // Green light stays for 5 seconds
  
  // Yellow Light
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(greenLED, LOW);
  delay(2000);  // Yellow light stays for 2 seconds
}

// Function to handle button press (emergency vehicle or pedestrian)
void handleButtonPress() {
  // Emergency Vehicle: Immediately turn on red for all lanes and switch to green for emergency lane
  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  delay(2000);  // Wait for 2 seconds to simulate emergency vehicle passing

  // Emergency vehicle is gone, return to normal traffic sequence
  trafficLightSequence();
}
