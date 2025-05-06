#include <DHT.h>

#define DHTPIN 2        // Data pin
#define DHTTYPE DHT11   // DHT11 sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);   // For Serial Plotter
  dht.begin();
  delay(1000);
  Serial.println("Time(s)\tTemp(C)");
}

void loop() {
  float tempC = dht.readTemperature();

  if (!isnan(tempC)) {
    // Print data in a tab-separated format for plotting
    Serial.print(millis() / 1000); // Time in seconds
    Serial.print("\t");
    Serial.println(tempC);         // Temperature in °C
  } else {
    Serial.println("0\t0"); // Plot blank if read fails
  }

  delay(1000); // Read every second
}
