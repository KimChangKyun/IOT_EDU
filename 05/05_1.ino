#include "LiquidCrystal.h"        // Text LCD 라이브러리 함수

LiquidCrystal lcd(12,11,5,4,3,2); // LCD 모듈 제어선 설정

void setup() {
  lcd.begin(16,2);                // LCD 초기화
}

void loop() {
  int cdsValue = analogRead(2);   
  lcd.print("cdsValue = ");     // 문자열 출력
  lcd.print(cdsValue);
  int pwmValue = map(cdsValue, 0, 1023, 0, 255);  // 0~1023범위의 val값을 0~255 범위로 변환
  lcd.setCursor(0,1);           // lcd.setCursor(6,0);
  lcd.print("pwmValue = ");     // 문자열 출력
  lcd.print(pwmValue);
  delay(200);
  lcd.clear();
}
