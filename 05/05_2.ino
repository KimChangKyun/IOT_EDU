int ECHO_pin = 7;     // 반사 신호 수신 핀
int TRIG_pin = 8;     // 트리거 신호 발생 핀 
int time; 
unsigned int  freq[ ] = {262, 294, 330, 349, 392, 440, 494, 523}; //각 코드에 대한 값
int playTime = 1000;
int soundPin = 12;

void setup( ){
    pinMode(ECHO_pin, INPUT);   // 반사 신호 수신 핀 입력모드 설정
    pinMode(TRIG_pin, OUTPUT);  // 트리거 신호 발생 핀 출력모드 설정
    Serial.begin(9600);         // 시리얼 통신을 위한 전송속도 9600 설정 
    pinMode(soundPin , OUTPUT);
}

void loop() {
    digitalWrite(TRIG_pin, LOW); 
    delayMicroseconds(2);       // 트리거 핀을 2μ초 동안 “LOW”
    digitalWrite(TRIG_pin, HIGH); 
    delayMicroseconds(10);      // 트리거하기 위하여 10μ초 동안 “HIGH”
    digitalWrite(TRIG_pin, LOW); // 트리거 핀을 다시 “LOW”

    time = pulseIn(ECHO_pin, HIGH); // 반사펄스 시간 읽기
    int distance = time/58;         // 펄스 시간을 거리로 계산 (cm 단위)

    int pwmVal = map(distance, 0, 200, 0, 255);  // pwm 출력값으로 변환
    //analogWrite(5, pwmVal);                       // 5번에 연결된 led에 pwmVal 출력
    //Serial.println(pwmVal);
    delay(100); 
    if(distance >= 0 && distance <= 10){
      tone(soundPin, freq[0] , playTime); //
      delay(100); 
    }else if(distance >= 11 && distance <= 20){
      tone(soundPin, freq[1] , playTime); //
    }else if(distance >= 21 && distance <= 30){
      tone(soundPin, freq[2] , playTime); //
    }else if(distance >= 31 && distance <= 40){
      tone(soundPin, freq[3] , playTime); //
    }else if(distance >= 41 && distance <= 50){
      tone(soundPin, freq[4] , playTime); //
    }else if(distance >= 51 && distance <= 60){
      tone(soundPin, freq[5] , playTime); //
    }else if(distance >= 61 && distance <= 70){
      tone(soundPin, freq[6] , playTime); //
    }else if(distance >= 71 && distance <= 80){
      tone(soundPin, freq[7] , playTime); //
    }
}
