#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if(!driver.init()){
    Serial.println("init failed");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  const char *msg = "Hello world!";

  driver.send((uint8_t *)msg,strlen(msg));
  driver.waitPacketSent();
  delay(1000);
}
