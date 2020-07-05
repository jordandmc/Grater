#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(7, 8); //CNS, CE

const byte address[6] = "00001";

void setup(){
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW); //recommended to use bypass capaciters between ground and 3.3v for higher settings
  radio.stopListening();
}

void loop(){
  const char text[] = "hello world!";
  radio.write(&text, sizeof(text));
  delay(1000);
}
