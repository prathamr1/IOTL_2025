#include <DHT.h>

// Define DHT type and pin
#define DHTPIN 2     // DHT data pin connected to pin 2
#define DHTTYPE DHT11

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Reading from DHT11...");
  dht.begin();
}

void loop() {
  // Read temperature as Celsius
  float tempC = dht.readTemperature();

  // Check if reading was successful
  if (isnan(tempC)) {
    Serial.println("Failed to read from DHT11 sensor!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.println(" °C");
  }

  delay(2000); // DHT11 takes readings every ~2 seconds
}
