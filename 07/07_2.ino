#include <SoftwareSerial.h>
int rxPin=2;
int txPin=3;
SoftwareSerial BTSerial(rxPin,txPin); // 소프트웨어 시리얼 설정


int ledPin = 5;       // 아두이노 보드의 PWM핀 5번에 LED연결
int vrVal;            // 가변저항 값 저장을 위한 변수
int vrPercentage;     // 가변저항 값을 100분율로 표시한 값을 저장하는 변수
int pwmVal;           // 가변저항 값을 0~255사이의 값으로 변환한 값을 저장하는 변수
char select;          //

void setup( ) {
   BTSerial.begin(9600);
}

void serialEvent() {
  select = BTSerial.read(); // 시리얼 통신 입력값이 있으면 읽어서 select 변수에 저장 (문자 '1' 혹은 '2' 중에 하나가 수신됨)
}

void loop() {
  if (select == '1') {      // 스마트 폰 엡에서 ‘수신 시작’ 명령 수신 (문자 '1'을 보냄)
    vrVal = analogRead(2);  // 아두이노 보드에 연결된 VR로 부터 값 입력
    vrPercentage = map(vrVal, 0, 1023, 0, 100); // %값으로 변환
    BTSerial.write(vrPercentage);   // 블루투스를 이용한 시리얼 통신으로 스마트 폰에 값 전달

    pwmVal = map(vrVal, 0, 1023, 0,255);  // PWM 값으로 변환
    analogWrite(ledPin,pwmVal);           //VR값에 비례한 LED 밝기 표시
    delay(1000);
  }
  if (select =='2') {       // 스마트 폰 엡에서 ‘수신 종료’ 명령 수신 (문자 '2'을 보냄)
    analogWrite(ledPin,0);  // LED OFF
    delay(20);
  }
}
