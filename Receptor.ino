#include <SoftwareSerial.h>
#include <RH_ASK.h>
#include <SPI.h>
const byte sizeData = 8;
RH_ASK askRx;

void setup() {
  Serial.begin(9600);
  askRx.init();
}

String mensajeString;
String mensajeStringOk;
char caracter;

void loop() {
  uint8_t data[sizeData];
  uint8_t dataLen = sizeof(data);

  if(askRx.recv(data, &dataLen)){
    Serial.print("Mensaje recibido: ");
    Serial.println((char*)data);
  }
  
}
