#include <WiFi.h>
#include <DHT.h>
#include <ESPAsyncWebSrv.h>
#include <Wire.h>
#include <WiFiClientSecure.h>
#include <EMailSender.h>

// Configurações da rede Wifi
const char* ssid = "SUA_REDE_WIFI"; // Nome da rede Wifi
const char* password = "SUA_SENHA_WIFI"; // Senha da rede Wifi

// Configurações do cliente de e-mail
const char* emailServer = "smtp.servidor_de_email.com";
const int emailPort = 587;
const char* emailUser = "seu_email@email.com";
const char* emailPassword = "sua_senha_de_email";
const char* emailRecipient = "destinatario@email.com";
EMailSender emailSender(emailUser, emailPassword, emailUser, emailServer, emailPort);

// Configurações do sensor DHT22
const float temperaturaLimiteInferior = 20.0; // Limite inferior desejado para alertas
const float temperaturaLimiteSuperior = 30.0; // Limite superior desejado para alertas
const int intervaloLeitura = 5; // Tempo de intervalo em segundos
#define DHTPIN 26 // Pino onde o sensor DHT está conectado
#define DHTTYPE DHT22 // Tipo do sensor
DHT dht(DHTPIN, DHTTYPE); // Crie o objeto DHT
unsigned long tempoAnterior = 0;

// Configurações do servidor web
AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);

  // Iniciando rede Wifi
  Serial.println("Iniciando WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    int numRedes = WiFi.scanNetworks();
    bool redeEncontrada = false;

    for (int i = 0; i < numRedes; i++) {
      if (WiFi.SSID(i) == ssid) {
        // A rede desejada foi encontrada
        WiFi.begin(ssid, password);
        while (WiFi.status() != WL_CONNECTED) {
          delay(1000);
          Serial.println("Conectando, aguarde...");
        }
        redeEncontrada = true;
        break;
      }
    }

    if (!redeEncontrada) {
      Serial.println("A rede desejada " + String(ssid) + " não foi encontrada.");

      for (int i = 0; i < numRedes; i++) {
        Serial.print("Rede disponível: ");
        Serial.println(WiFi.SSID(i));
      }
    }
  }

  Serial.println("Conectado à rede WiFi: " + String(ssid));
  Serial.print("IP para exibir monitor: ");
  Serial.println(WiFi.localIP());

  // Inicialize o sensor DHT
  dht.begin();

  // Configura o servidor web
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    float tempC = dht.readTemperature();
    float hum = dht.readHumidity();
    String html = "Temperatura: " + String(tempC) + "°C<br>Umidade: " + String(hum) + "%";
    request->send(200, "text/html", html);
  });

  server.begin();
}

void loop() {
  unsigned long tempoAtual = millis();

  if (tempoAtual - tempoAnterior >= (intervaloLeitura * 1000)) {
    // Realize a leitura da temperatura e umidade aqui
    float tempC = dht.readTemperature();
    float hum = dht.readHumidity();
    
    // Imprima os valores no monitor serial
    Serial.print("Temperatura: ");
    Serial.print(tempC);
    Serial.print(" °C, Umidade: ");
    Serial.print(hum);
    Serial.println("%");
    
    // Verifique os limites de temperatura e envie alertas, se necessário
    if (tempC < temperaturaLimiteInferior || tempC > temperaturaLimiteSuperior) {
      // Envia um e-mail de alerta
      Serial.println("Alerta: temperatura fora dos limites");
      EMailSender::EMailMessage message;
      message.subject = "Alerta de Temperatura";
      message.message = "A temperatura atual é " + String(tempC) + " °C.";

      EMailSender::Response resp = emailSender.send(emailRecipient, message);
      if (resp.status == 1) {
        Serial.println("Email enviado com sucesso.");
      } else {
        Serial.println("Falha no envio do email.");
      }
    }
    
    tempoAnterior = tempoAtual; // Atualize o tempo anterior
  }
}