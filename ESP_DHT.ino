#include <ESP8266WiFi.h>
#include <DHT.h>

// Replace with your network credentials
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// ThingSpeak API details
const char* server = "api.thingspeak.com";
String apiKey = "YOUR_WRITE_API_KEY";

// DHT sensor
#define DHTPIN D2          // Pin where the DHT sensor is connected
#define DHTTYPE DHT11      // DHT 11 type sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  
  dht.begin();  // Start the DHT sensor
}

void loop() {
  // Read temperature and humidity from DHT sensor
  float temperature = dht.readTemperature();  // Celsius
  float humidity = dht.readHumidity();

  // Check if reading is successful
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print the sensor values to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" *C ");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Send data to ThingSpeak
  WiFiClient client;
  if (client.connect(server, 80)) {
    String url = "/update?api_key=" + apiKey + "&field1=" + String(temperature) + "&field2=" + String(humidity);
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + server + "\r\n" +
                 "Connection: close\r\n\r\n");
  }
  
  // Wait 15 seconds before sending the next data
  delay(15000); // Wait for 15 seconds
}
