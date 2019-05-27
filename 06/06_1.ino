int ledPin = 8;       // 아두이노 보드의 디지털입출력 핀 8번에 LED연결
char r_data;          //블루투스 전송 데이터 읽기


void setup( ) {
   Serial.begin(9600);      // BT 모듈의 통신 속도 9600bps 설정
   pinMode(ledPin, OUTPUT); // 디지털입출력 핀 8번을 출력으로 설정
}

void loop() {
  char r_data;
  if (Serial.available( )> 0) { // BT 모듈을 통한 시리얼 통신 입력 발생 검사
    r_data = Serial.read( );    // 시리얼 통신 문자 입력 값 저장, (시리얼 통신으로 수신되는 데이터의 타입이 문자형 임을 가정)

    if( r_data == '1') {        // 스마트 폰의 앱 “BT_ONOFFSW.apk”의 "Switch ON"이 터치될 때, 문자 '1'이 전송됨
         digitalWrite(ledPin, HIGH);  // LED 켜기
    }
    if( r_data == '2') {        // 스마트 폰의 앱 “BT_ONOFFSW.apk”의 "Switch OFF"이 터치될 때, 문자 '2'가 전송됨
         digitalWrite(ledPin, LOW);   // LED 끄기
    }
  }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  r_data = Serial.read( );
}
