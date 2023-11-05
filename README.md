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

[Diagrama de Conexões](https://github.com/hlfreinoso/monitor-de-temperatura-e-umidade-esp32/blob/main/monitor-de-temperatura-e-umidade-esp32.jpg)

- Conecte o pino "GND" (terra) da placa ESP32 ao pino "GND" do sensor DHT22 (fio preto).
- Conecte o pino "5V" da placa ESP32 ao pino "VCC" do sensor DHT22 (fio vermelho).
- Conecte o pino "SDA" do sensor DHT22 ao pino "26" da placa ESP32 (fio verde).

## Uso
Este projeto permite que você monitore dados de temperatura e umidade usando um ESP32 e um sensor DHT22. Siga as etapas abaixo para usar o projeto:

### Carregando o Código para o ESP32
1. Certifique-se de que você tenha configurado seu ambiente Arduino IDE com as bibliotecas necessárias para o ESP32 e o sensor DHT22. Se ainda não tiver feito isso, siga as instruções abaixo para configurar seu ambiente.
2. Abra o arquivo "Monitor_Temperatura_Umidade_ESP32.ino" no Arduino IDE.
3. Selecione a placa "ESP32 Dev Module" no menu "Ferramentas > Placa".
4. Selecione a porta COM correta do ESP32 no menu "Ferramentas > Porta".
5. Clique no botão "Carregar" (seta para cima) para carregar o código no ESP32.

### Monitorando os Dados de Temperatura e Umidade
1. Após carregar o código no ESP32, abra o "Monitor Serial" no Arduino IDE. Certifique-se de que a velocidade de comunicação (baud rate) seja definida como 115200.
2. Conecte o ESP32 à fonte de alimentação e aguarde até que ele se conecte à rede Wi-Fi configurada. O ESP32 exibirá seu endereço IP no "Monitor Serial".
3. Abra um navegador da web e insira o endereço IP do ESP32 na barra de endereços. Pressione "Enter".
4. A página exibirá a temperatura e umidade atuais lidas pelo sensor DHT22.

### Recebendo Alertas por E-mail (Opcional)
Este projeto também inclui a funcionalidade de envio de alertas por e-mail quando a temperatura ultrapassa os limites definidos. Certifique-se de ter configurado as informações do servidor de e-mail, seu endereço de e-mail e o destinatário no código.

- `emailServer`: Substitua pelo servidor SMTP do seu provedor de e-mail.
- `emailPort`: Substitua pela porta SMTP do seu provedor de e-mail (a porta 587 é comum para TLS).
- `emailUser`: Substitua pelo seu endereço de e-mail.
- `emailPassword`: Substitua pela senha do seu e-mail.
- `emailRecipient`: Substitua pelo endereço de e-mail do destinatário dos alertas.

Lembre-se de que a funcionalidade de envio de e-mail pode exigir que você tenha uma conta de e-mail compatível com SMTP.

Após configurar as informações do e-mail, o projeto enviará alertas por e-mail quando a temperatura ultrapassar os limites definidos.

##Contribuições
Contribuições são bem-vindas! Sinta-se à vontade para abrir problemas ou enviar solicitações de pull.
