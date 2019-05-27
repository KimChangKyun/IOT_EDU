#include <SoftwareSerial.h>
int rxPin=2;
int txPin=3;
SoftwareSerial BTSerial(rxPin,txPin); // 소프트웨어 시리얼 설정
int ledPin[4] = {8,9,10,11};
int k, num;
char phoneData;

void setup( ) {
   BTSerial.begin(9600);
   for (k=0; k<4; k++) {
      pinMode(ledPin[k], OUTPUT);
   }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  phoneData = BTSerial.read( );
}

void loop() {
    if (phoneData == '1') {
         digitalWrite(ledPin[0], HIGH);
    } else if (phoneData == '2') {
         digitalWrite(ledPin[1], HIGH);
    } else if (phoneData == '3') {
         digitalWrite(ledPin[2], HIGH);
    } else if (phoneData == '4') {
         digitalWrite(ledPin[3], HIGH);
    } else if (phoneData == '6') {
      for (k=0; k<4; k++) {
        digitalWrite(ledPin[k], LOW);
      }
    }
}
