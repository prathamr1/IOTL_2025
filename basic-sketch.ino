
//Basic **Arduino UNO Sketch** for an ideal task using **DHT11 sensor, piezoelectric sensor, and potentiometer-based LED control

#include <DHT.h>

#define DHTPIN 2        // Digital pin connected to DHT11
#define DHTTYPE DHT11   // Define DHT11 sensor
#define PIEZO_PIN A0    // Analog pin for piezoelectric sensor
#define POT_PIN A1      // Analog pin for potentiometer
#define LED_PIN 9       // PWM pin for LED brightness control

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(9600);
    dht.begin();
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    // Read DHT11 sensor
    float temp = dht.readTemperature();
    float humidity = dht.readHumidity();

    // Read piezoelectric sensor value
    int piezoValue = analogRead(PIEZO_PIN);

    // Read potentiometer value
    int potValue = analogRead(POT_PIN);
    int ledBrightness = map(potValue, 0, 1023, 0, 255); // Map potentiometer value to LED brightness

    // Output readings
    Serial.print("Temp: "); Serial.print(temp); Serial.print(" °C, ");
    Serial.print("Humidity: "); Serial.print(humidity); Serial.print("%, ");
    Serial.print("Piezo Value: "); Serial.print(piezoValue); Serial.print(", ");
    Serial.print("LED Brightness: "); Serial.println(ledBrightness);

    // Control LED brightness
    analogWrite(LED_PIN, ledBrightness);

    delay(1000); // Wait 1 second before next reading
}
