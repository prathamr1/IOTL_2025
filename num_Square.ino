void setup() {
  // Start serial communication
  Serial.begin(9600);
  Serial.println("Enter a number to square:");
}

void loop() {
  // Check if user entered anything
  if (Serial.available() > 0) {
    // Read the input as an integer
    int number = Serial.parseInt();

    // Clear remaining input buffer
    while (Serial.available() > 0) {
      Serial.read();
    }

    // Calculate square
    int square = number * number;

    // Display result
    Serial.print("Square of ");
    Serial.print(number);
    Serial.print(" is: ");
    Serial.println(square);

    Serial.println("Enter another number to square:");
  }
}
