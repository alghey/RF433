#include <SoftwareSerial.h>
#include <DHT.h>
#include <DHT_U.h>
#include <EasyUltrasonic.h>
#include <RH_ASK.h>
#include <SPI.h>

#define TRIG_PIN 5
#define ECHO_PIN 6
#define DHT_PIN 7
#define MIC_PIN A0
#define WAT_PIN A1
#define POT_PIN A2

RH_ASK askTx;

float TEMPERATURA;
int HUMEDAD;
float DISTANCIA;
int SONIDO;
int AGUA;
long POTENCIA;

DHT dht(DHT_PIN, DHT11);
EasyUltrasonic ultrasonic;

String temperaturaString;
String humedadString;
String distanciaString;
String sonidoString;
String aguaString;
String potenciaString;

void setup(){
  Serial.begin(9600);
  ultrasonic.attach(TRIG_PIN, ECHO_PIN);
  dht.begin();
  askTx.init();
}

void loop(){
  TEMPERATURA = dht.readTemperature();
  HUMEDAD = dht.readHumidity();
  DISTANCIA = ultrasonic.getDistanceCM();
  SONIDO = analogRead(MIC_PIN);
  AGUA = analogRead(WAT_PIN);
  POTENCIA = analogRead(POT_PIN);
  
  char buf1[8];
  Serial.print("Temperatura: ");
  Serial.println(TEMPERATURA);
  temperaturaString="t "+String(TEMPERATURA,2);
  temperaturaString.toCharArray(buf1, sizeof(buf1));
  askTx.send((uint8_t *)buf1, strlen(buf1));
  askTx.waitPacketSent();

  char buf2[8];
  Serial.print("Humedad: ");
  Serial.println(HUMEDAD);
  humedadString = "h "+String(HUMEDAD);
  humedadString.toCharArray(buf2, sizeof(buf2));
  askTx.send((uint8_t *)buf2, strlen(buf2));
  askTx.waitPacketSent();

  char buf3[8];
  Serial.print("Distancia: ");
  Serial.println(DISTANCIA);
  distanciaString = "d " + String(DISTANCIA);
  distanciaString.toCharArray(buf3, sizeof(buf3));
  askTx.send((uint8_t *)buf3, strlen(buf3));
  askTx.waitPacketSent();

  char buf4[8];
  Serial.print("Sonido: ");
  Serial.println(SONIDO);
  sonidoString = "s " + String(SONIDO);
  sonidoString.toCharArray(buf4, sizeof(buf4));
  askTx.send((uint8_t *)buf4, strlen(buf4));
  askTx.waitPacketSent();

  char buf5[8];
  Serial.print("Agua: ");
  Serial.println(AGUA);
  aguaString = "a " + String(AGUA);
  aguaString.toCharArray(buf5, sizeof(buf5));
  askTx.send((uint8_t *)buf5, strlen(buf5));
  askTx.waitPacketSent();

  char buf6[8];
  Serial.print("Potencia: ");
  Serial.println(POTENCIA);
  potenciaString = "p " + String(POTENCIA);
  potenciaString.toCharArray(buf6, sizeof(buf6));
  askTx.send((uint8_t *)buf6, strlen(buf6));
  askTx.waitPacketSent();

  delay(500);

}
