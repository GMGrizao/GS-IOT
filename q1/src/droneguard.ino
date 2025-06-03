#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>

// Configurações do Wi-Fi
const char *ssid = "iPhone de Guilherme";
const char *password = "guilherme";

// Configurações do MQTT
const char *mqtt_server = "test.mosquitto.org";
const char *mqtt_topic = "droneguard/sensores";

// Inicialização de objetos
WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(4, DHT22);   // DHT no pino GPIO4
Adafruit_BMP280 bmp; // BMP280 I2C

void setup_wifi()
{
  delay(10);
  Serial.println("Conectando ao WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println(WiFi.localIP());
}

void reconnect()
{
  while (!client.connected())
  {
    Serial.print("Conectando ao MQTT...");
    if (client.connect("ESP32Client"))
    {
      Serial.println("Conectado!");
    }
    else
    {
      Serial.print("Falha, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}

void setup()
{
  Serial.begin(115200);
  dht.begin();
  bmp.begin(0x76); // Endereço I2C do BMP280
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop()
{
  if (!client.connected())
  {
    reconnect();
  }
  client.loop();

  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();
  float pressao = bmp.readPressure() / 100.0F;
  float altitude = bmp.readAltitude(1013.25); // Pressão ao nível do mar
  float inclinacao = random(0, 30);           // Simulação de inclinômetro

  if (isnan(temperatura) || isnan(umidade))
  {
    Serial.println("Falha ao ler do sensor DHT!");
    return;
  }

  String payload = "{";
  payload += "\"temperatura\":" + String(temperatura, 2) + ",";
  payload += "\"umidade\":" + String(umidade, 2) + ",";
  payload += "\"pressao\":" + String(pressao, 2) + ",";
  payload += "\"altitude\":" + String(altitude, 2) + ",";
  payload += "\"inclinacao\":" + String(inclinacao);
  payload += "}";

  client.publish(mqtt_topic, payload.c_str());
  Serial.println("Dados enviados: " + payload);

  delay(5000); // A cada 5 segundos
}
