// Define LED pins

const int greenLED = 2;

const int yellowLED = 3;

const int redLED = 4;

char inputChar;

void setup() {

// Set LED pins as OUTPUT

pinMode(greenLED, OUTPUT);

pinMode(yellowLED, OUTPUT);

pinMode(redLED, OUTPUT);

// Initialize Serial Monitor

Serial.begin(9600);

Serial.println("Enter b, g, y, or r:");

}

void loop() {

// Check if any data is available

if (Serial.available() > 0) {

inputChar = Serial.read();



// Turn OFF all LEDs first

digitalWrite(greenLED, LOW);

digitalWrite(yellowLED, LOW);

digitalWrite(redLED, LOW);



// Act based on user input

switch (inputChar) {

  case 'b':

    // Blink green LED

    Serial.println("Blinking green LED");

    for (int i = 0; i < 5; i++) {

      digitalWrite(greenLED, HIGH);

      delay(300);

      digitalWrite(greenLED, LOW);

      delay(300);

    }

    break;



  case 'g':

    Serial.println("Green LED ON");

    digitalWrite(greenLED, HIGH);

    break;



  case 'y':

    Serial.println("Yellow LED ON");

    digitalWrite(yellowLED, HIGH);

    break;



  case 'r':

    Serial.println("Red LED ON");

    digitalWrite(redLED, HIGH);

    break;



  default:

    Serial.println("Invalid input. Use b, g, y, or r.");

    break;

}

}

} do same for this