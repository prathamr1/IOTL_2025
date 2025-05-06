#include <DHT.h>

#define DHTPIN 2        // Pin where DHT11 is connected
#define DHTTYPE DHT11   // We're using a DHT11 sensor

DHT dht(DHTPIN, DHTTYPE);

float maxTempC = -1000.0;
float minTempC = 1000.0;

void setup() {
  Serial.begin(9600);
  Serial.println("Reading temperature...");
  dht.begin();
}

void loop() {
  float tempC = dht.readTemperature();       // Read Celsius
  float tempF = dht.readTemperature(true);   // Read Fahrenheit

  if (isnan(tempC) || isnan(tempF)) {
    Serial.println("Failed to read from DHT11 sensor!");
    delay(2000);
    return;
  }

  // Update max and min temperatures
  if (tempC > maxTempC) maxTempC = tempC;
  if (tempC < minTempC) minTempC = tempC;

  // Display current, max, and min temperatures
  Serial.print("Current Temperature: ");
  Serial.print(tempC);
  Serial.print(" °C / ");
  Serial.print(tempF);
  Serial.println(" °F");

  Serial.print("Maximum Temperature: ");
  Serial.print(maxTempC);
  Serial.println(" °C");

  Serial.print("Minimum Temperature: ");
  Serial.print(minTempC);
  Serial.println(" °C");

  Serial.println("------------------------------");

  delay(3000); // Wait 3 seconds before next reading
}
