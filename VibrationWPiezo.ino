int sensorPin = A0; // Analog pin for the microphone or vibration sensor
int piezoPin = 8;    // Pin for the piezo buzzer
int threshold = 600; // Threshold for detecting a knock
int knockValue = 0;  // Value from the sensor

// Notes for the melody (Frequencies in Hz)
int melody[] = {
  262, 294, 330, 349, 392, 440, 494, 523, 587, 659, 698, 784
};

int melodyLength = sizeof(melody) / sizeof(melody[0]);

void setup() {
  pinMode(piezoPin, OUTPUT);
  Serial.begin(9600); // Begin serial communication for debugging
}

void loop() {
  knockValue = analogRead(sensorPin); // Read the value from the sensor

  // Check if the knock value exceeds the threshold
  if (knockValue > threshold) {
    Serial.println("Knock detected!");
    playTune();
  }
  
  delay(100); // Small delay to prevent rapid repeated detection
}

void playTune() {
  for (int i = 0; i < melodyLength; i++) {
    tone(piezoPin, melody[i], 500); // Play note for 500 ms
    delay(500); // Wait before playing the next note
  }
  noTone(piezoPin); // Stop the sound after the tune is played
}
