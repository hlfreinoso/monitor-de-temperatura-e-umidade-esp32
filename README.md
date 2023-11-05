# Monitor de Temperatura e Umidade ESP32

Este é um projeto que utiliza uma placa ESP32 para monitorar a temperatura e umidade em intervalos regulares, disponibiliza-los em um página web na intranet e enviar alertas por e-mail quando a temperatura está fora dos limites definidos.

## Configuração

Antes de usar o projeto, certifique-se de configurar as informações da sua rede Wi-Fi e do servidor de e-mail nas variáveis apropriadas no código-fonte.

```cpp
// Configurações da rede Wifi
const char* ssid = "SUA_REDE_WIFI";
const char* password = "SUA_SENHA_WIFI";

// Configurações do cliente de e-mail
const char* emailServer = "smtp.servidor_de_email.com";
const int emailPort = 587;
const char* emailUser = "seu_email@email.com";
const char* emailPassword = "sua_senha_de_email";
const char* emailRecipient = "destinatario@email.com";
````

## Montagem do Hardware

Siga estas etapas para montar o hardware necessário para este projeto:

### Materiais Necessários

Certifique-se de ter os seguintes materiais à mão:

- Placa ESP32
- Sensor de Temperatura e Umidade DHT22

### Conexões

Use o seguinte diagrama para fazer as conexões entre a placa ESP32 e o sensor DHT22:

![Diagrama de Conexões](inserir link da imagem aqui)

- Conecte o pino "GND" (terra) da placa ESP32 ao pino "GND" do sensor DHT22 (fio preto).
- Conecte o pino "5V" da placa ESP32 ao pino "VCC" do sensor DHT22 (fio vermelho).
- Conecte o pino "SDA" do sensor DHT22 ao pino "26" da placa ESP32 (fio verde).

##Uso
Explique como usar o projeto, incluindo como fazer o upload do código para o ESP32 e como monitorar os dados de temperatura e umidade.

##Contribuições
Contribuições são bem-vindas! Sinta-se à vontade para abrir problemas ou enviar solicitações de pull.
