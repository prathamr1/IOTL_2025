#include <LiquidCrystal.h>

// Pins for the buttons
int startButton = 8;
int stopButton = 9;
int resetButton = 10;

// Variables to manage timer state
unsigned long startTime = 0;
unsigned long elapsedTime = 0;
unsigned long stopTime = 0;
bool isRunning = false;

// LCD Setup
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Start the LCD and set the dimensions
  lcd.begin(16, 2);
  lcd.print("Stopwatch");

  // Set button pins as input
  pinMode(startButton, INPUT_PULLUP);
  pinMode(stopButton, INPUT_PULLUP);
  pinMode(resetButton, INPUT_PULLUP);
  
  // Display the initial time (0 seconds)
  lcd.setCursor(0, 1);
  lcd.print("00:00");
}

void loop() {
  // Read button states
  if (digitalRead(startButton) == LOW && !isRunning) {
    startTimer();  // Start the stopwatch
  }

  if (digitalRead(stopButton) == LOW && isRunning) {
    stopTimer();   // Stop the stopwatch
  }

  if (digitalRead(resetButton) == LOW) {
    resetTimer();  // Reset the stopwatch
  }

  // If the timer is running, update the time display
  if (isRunning) {
    elapsedTime = millis() - startTime;
    updateDisplay(elapsedTime);
  }
}

// Function to start the stopwatch
void startTimer() {
  startTime = millis() - elapsedTime;  // Adjust for any previous elapsed time
  isRunning = true;
  lcd.clear();
  lcd.print("Running...");
  delay(200);  // Debounce delay
}

// Function to stop the stopwatch
void stopTimer() {
  stopTime = millis() - startTime;  // Calculate the time elapsed
  isRunning = false;
  lcd.clear();
  lcd.print("Stopped");
  delay(200);  // Debounce delay
}

// Function to reset the stopwatch
void resetTimer() {
  startTime = 0;
  elapsedTime = 0;
  lcd.clear();
  lcd.print("Reset");
  updateDisplay(elapsedTime);
  delay(200);  // Debounce delay
}

// Function to update the display with elapsed time
void updateDisplay(unsigned long time) {
  unsigned long seconds = time / 1000;
  unsigned long minutes = seconds / 60;
  seconds = seconds % 60;

  lcd.setCursor(0, 1);
  if (minutes < 10) {
    lcd.print("0");  // Leading zero for minutes
  }
  lcd.print(minutes);
  lcd.print(":");

  if (seconds < 10) {
    lcd.print("0");  // Leading zero for seconds
  }
  lcd.print(seconds);
}
