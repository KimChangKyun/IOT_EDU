#include "LiquidCrystal.h"
LiquidCrystal lcd(12,11,5,4,3,2);


/*
  가변저항으로 LED의 밝기를 조절
  - 가변저항을 통하여 입력되는 0~1023 범위의 값을 0~255범위의 값으로 변환
*/
int pwdOut = 5;
int pinLED[4] = {8,9,10,11}; //LED PIN NUMBER
int k;
int forLast = (sizeof(pinLED)-1)/sizeof(char *); // 연결되어있는 LED 개수 -1 (pinLED.length-1)

void setup() {
  lcd.begin(16,2);
  pinMode(pwdOut, OUTPUT);  
  for(int i = 0 ; i < 4 ; i++){
    pinMode(pinLED[i], OUTPUT); //LED OUTPUT
  }
}

void loop() {
  int val1 = analogRead(2); // 아날로그입력 2번을 통하여 입력된 전압값을
                            // 0~1023범위의 값으로 읽어 val1에 저장
  int val2 = map(val1, 0, 1023, 0, 255); // 0~1023범위의 val값을 0~255 범위로 변환

  step01(val1,val2);
  //step02(val1);
                  
}

void step01(int val1, int val2){
    lcd.setCursor(0,0);           // lcd.setCursor(0,0);
    lcd.print("val1 = " + val1);      // "저항값" 출력
    lcd.setCursor(0,1);           // lcd.setCursor(0,1);
    lcd.print("val2 = " + val2);      // "저항값 0 ~ 255" 출력
    lcd.clear();  // LCD화면 지우기
}

void step02(int val1){          
  analogWrite(pwdOut, val1);     // PWM 신호로 출력

  if(val1 >= 0 && val1 <= 204){
    digitalWrite(pinLED[0],LOW);
    digitalWrite(pinLED[1],LOW);
    digitalWrite(pinLED[2],LOW);
    digitalWrite(pinLED[3],LOW);
  }else if(val1 >= 205 && val1 <= 408){
    digitalWrite(pinLED[0],HIGH);
  }else if(val1 >= 409 && val1 <= 612){
    digitalWrite(pinLED[1],HIGH);
  }else if(val1 >= 613 && val1 <= 819){
    digitalWrite(pinLED[2],HIGH);
  }else if(val1 >= 820 && val1 <= 1023){
    digitalWrite(pinLED[3],HIGH);
  }
  delay(20);
}
