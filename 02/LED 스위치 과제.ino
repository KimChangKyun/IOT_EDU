int sw[4] = {2,3,4,5}; //스위치 PIN NUMBER
int pinLED[4] = {8,9,10,11}; //LED PIN NUMBER
int sw_in[4] = {0,0,0,0};
int delayTime[4] = {1000,800,600,400};
int k;
int dTime = 1000; //딜레이 타임
int forLast = (sizeof(pinLED)-1)/sizeof(char *); // 연결되어있는 LED 개수 -1 (pinLED.length-1)
int half = forLast/2; // HOW RO USE FLOOR?? // LED개수의 반

void setup() {
  for(int i = 0 ; i < 4 ; i++){
    pinMode(sw[i], INPUT);  //스위치 INPUT
    pinMode(pinLED[i], OUTPUT); //LED OUTPUT
  }
}

//digitalRead(sw[i]) == (0:1)
void loop() {
  /**
   * 스위치 켜짐 파악 digitalRead(sw[i]) == (0:1)
   */
  for(int sw_i = 0; sw_i <= forLast ; sw_i++){
    sw_in[sw_i] = digitalRead(sw[sw_i]);
  }
  
  //step01(sw_in);
  step02(sw_in);
  

  
}
/**
* 스위치가 동시에 눌려졌을 때 우선순위가 높은 스위치의 제어
*/
void step01(int sw_in[]){
  int LED_TURN_ON_CHECK = 0;
   for(int i = forLast; i >= 0; i--){
    if(!LED_TURN_ON_CHECK && sw_in[i]){
      LED_TURN_ON_CHECK = 1;
      digitalWrite(pinLED[i],HIGH);
    }else{
       digitalWrite(pinLED[i], LOW);
    }
  }
}

/**
* 깜박이는 속도를 4단계로 조정하는 스케치
*/
void step02(int sw_in[]){
  int LED_TURN_ON_CHECK = 0;
  for(int i = 0; i <= forLast; i++){
    if(!LED_TURN_ON_CHECK && sw_in[i]){
      LED_TURN_ON_CHECK = 1;
      for(int j = 0; j <= forLast; j++){
        digitalWrite(pinLED[j],HIGH);
      }
      delay(delayTime[i]);
      for(int j = 0; j <= forLast; j++){
        digitalWrite(pinLED[j], LOW);
      }
      delay(delayTime[i]);
    }
  }
}

