// Aim: Soil Moisture Monitoring System

#define BLYNK_TEMPLATE_ID "TMPL3PTzdP9Wy"
#define BLYNK_TEMPLATE_NAME "Soil Moisture ESP32"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_NAME";        // Your hotspot name
char pass[] = "YOUR_WIFI_PASSWORD";    // Your hotspot password


#define SOIL_SENSOR_PIN 34
BlynkTimer timer;

void readSoil()
{
  int value = analogRead(SOIL_SENSOR_PIN);

  Serial.print("Soil Moisture: ");
  Serial.println(value);

  // Send data to Blynk app
  Blynk.virtualWrite(V0, value);
}

void setup()
{
  Serial.begin(115200);

  Serial.println("Starting...");

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");

  Blynk.config(BLYNK_AUTH_TOKEN);

  if (Blynk.connect())
  {
    Serial.println("Blynk Connected");
  }
  else
  {
    Serial.println("Blynk Connection Failed");
  }

  timer.setInterval(2000L, readSoil);
}

void loop()
{
  Blynk.run();
  timer.run();
}
