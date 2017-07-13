/**
   Converte os pinos do NodeMCU para o Arduino UNO
*/
#define D0 16
#define D1 5
#define D2 4
#define D3 0
#define D4 2
#define D5 14
#define D6 12
#define D7 13
#define D8 15
#define D9 3
#define D10 1

/**
  Define o led embutido do NodeMCU como led default
*/
#define led LED_BUILTIN

/**
  Dados de conexão e autenticação no Firebase
*/
#define FIREBASE_HOST "hydroflow-f4efc.firebaseio.com"
#define FIREBASE_AUTH "NbeYMq0PTjqPLWLzABUHcMya7aKb5VdQrxrdjhmn"

/**
  Dados de conexão e autenticação Wi-Fi
*/
#define WIFI_SSID     "Yonathan"
#define WIFI_PASSWORD "88220000"

/**
  Dados do servidor HTTP
*/
#define HOST_SERVER  "hydroflow.online"
#define HOST_URL     "/http/get.php?"
#define HOST_PORT    80

/**
  Este valor tem que corresponder ao total de delay da loop() em segundos
*/
#define segundo 1;

/**
  Variáveis para o envio de leitura no servidor HTTP
*/
#define var1 "var1=+Vazao+de:+"
#define var2 "&var2=+L/min+"
#define var3 "&var3=+Consumidos:+"
#define var4 "&var4=+Litros"

