int ledPin[4] = {8,9,10,11};  //핀 번호
int k, num;                   //TEMP
           

void setup( ) {
   Serial.begin(9600);
   for (k=0; k<4; k++) {
      pinMode(ledPin[k], OUTPUT);
   }
}


void loop() {
  char phoneData;  //블루투스 통신 데이터
   
   if (Serial.available( )> 0) { // BT 모듈을 통한 시리얼 통신 입력 발생 검사
      phoneData = Serial.read(); // 실제 값 받는곳
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
}
