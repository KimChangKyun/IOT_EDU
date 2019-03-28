/*
 * 본예제는 LED 포트번호가 순차정렬이 되어있다는 가정하에 주석을 이해하기 쉽게
 * 1234포트의 LED를 사용한다는 가정하에 주석을 사용하였습니다.
 */
int pinLED[] = {0,1,2,3}; //LED 포트 번호
int k;
int dTime = 1000; //딜레이 타임
int forLast = 3; // 연결되어있는 LED 개수 -1 (pinLED.length-1)
int half = forLast/2; // HOW RO USE FLOOR?? // LED개수의 반

void setup() {
  for (k=0; k<4; k++) {
    pinMode(pinLED[k], OUTPUT);
  } 
}

void loop() {
  //LED개수만큼 FOR문
   for (k=0; k<=forLast; k++) { 
    //01 ~ 06까지 적용하고싶은 함수 선택
    step06(k); 
  } 
}

/* 
 * TITLE : 실전과제 1 
 * PARAM : LED 포트번호
 * LOGIC : [HIGH]1234......[LOW]1234.....[HIGH]1234......[LOW]1234
 */
void step01(int pin){
   //LED 모두 켜줌
    digitalWrite(pinLED[pin],HIGH);

    //받아온 LED포트번호와 총 LED 개수가 같다면 모두 꺼줌
    if(pin == forLast){
      delay(dTime);
      for(int k_in=0; k_in<=forLast; k_in++) {
        digitalWrite(pinLED[k_in],LOW);
      }
      delay(dTime);
    }    
}

/* 
 * TITLE : 실전과제 2
 * PARAM : LED 포트번호
 * LOGIC : [HIGH]1234....[LOW]1234....[HIGH]1234....[LOW]1234
 */
void step02(int pin){
  //순차적으로 LED켜짐
   digitalWrite(pinLED[pin],HIGH);
    delay(dTime);
    //받아온 LED포트번호와 총 LED 개수가 같다면 순차적으로 하나씩 꺼짐
    if(pin == forLast){
      for(int k_in=0; k_in<=forLast; k_in++) {
        digitalWrite(pinLED[k_in],LOW);
        delay(dTime);
      }
    }    
}

/* 
 * TITLE : 실전과제 3
 * PARAM : LED 포트번호
 * LOGIC : [HIGH]1234....[LOW]4321....[HIGH]1234....[LOW]4321
 */
void step03(int pin){
  //순차적으로 LED켜짐
    digitalWrite(pinLED[pin],HIGH);
    delay(dTime);
    //받아온 LED포트번호와 총 LED 개수가 같다면 역순차적으로 하나씩 꺼짐
    if(pin == forLast){  
      while(pin>=0) {
        //pin-- 1차감 연산자(처음에 맨 마지막 번호를 꺼야하기때문에 뒤에다 --를 붙여줌)
        digitalWrite(pinLED[pin--],LOW); 
        delay(dTime);
      }
    }
}



/* 
 * TITLE : 실전과제 4
 * PARAM : LED 포트번호
 * LOGIC : [HIGH]1.[LOW]1.[HIGH]2.[LOW]2 ~~~
 */
void step04(int pin){
   digitalWrite(pinLED[pin],HIGH);
    delay(dTime);
    digitalWrite(pinLED[pin],LOW);
    delay(dTime);  
}

/* 
 * TITLE : 연습과제 1
 * PARAM : LED 포트번호
 * LOGIC : [HIGH]12....[LOW]12[HIGH]34....[LOW]34[HIGH]12
 * 설명 : 하드코딩의 단순 12,34가 아닌 나중에 *2n으로 늘어날 것을 대비해서
 *        [반켜짐] [반꺼짐]으로 구현 (이해를 위해 1,2,3,4로 설명)
 *        + LOOP() 함수에서 특별한 다른 구현체 없이
 *        step05로만 함수명을 수정해주면 사용이 가능하게 함수 제작
 */
void step05(int pin){
  delay(dTime);
  
  if(pin%2==1){ //2의 배수가 아니면
    for(int k_in=(half+1); k_in<=forLast; k_in++) {
      digitalWrite(pinLED[k_in],LOW); //3,4 꺼짐
    }
    for(int k_in=0; k_in<=half; k_in++) {
      digitalWrite(pinLED[k_in],HIGH); //1,2 꺼짐
    }
  }else{ //2의 배수가  맞으면
    for(int k_in=0; k_in<=half; k_in++) {
      digitalWrite(pinLED[k_in],LOW); //1,2 꺼짐
    }
    for(int k_in=(half+1); k_in<=forLast; k_in++) {
      digitalWrite(pinLED[k_in],HIGH); //3,4 켜짐
    }
  } 
  delay(dTime);
}

/* 
 * TITLE : 연습과제 2
 * PARAM : LED 포트번호
 * LOGIC : [HIGH]12.[LOW]1[HIGH]23....[LOW]34
 * 설명 : 하드코딩의 단순 12,34가 아닌 나중에 *1n으로 늘어날 것을 대비해서
 *        [이전 꺼짐][현재켜짐][다음켜짐]으로 구현 
 */
void step06(int pin){
  int pin_pre; // 이전 LED값 변수 선언
  int pin_next = pin+1; // 다음 LED값
  if(pin != 0){ // 현재의 핀번호가 0이 아니면 (이전 핀번호 값이 -1이 되지 않도록) 
    pin_pre = pin-1; //이전 LED값
  }
  delay(dTime);
  if(forLast != pin){ //마지막이 아니면
    digitalWrite(pinLED[pin_pre],LOW); //이전 LED를 꺼준다
    digitalWrite(pinLED[pin],HIGH); //현재의 LED를 켜준다.
    digitalWrite(pinLED[pin_next],HIGH); //다음의 LED를 켜준다.
  }else{ //마지막이면
    digitalWrite(pinLED[pin],LOW); //현재의 LED를 꺼준다
    digitalWrite(pinLED[pin_pre],LOW); //이전의 LED를 꺼준다
  }
  delay(dTime);
}
