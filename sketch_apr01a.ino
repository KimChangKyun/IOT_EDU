int sw[4] = {2,3,4,5}; //스위치 PIN NUMBER
int le[4] = {8,9,10,11}; //LED PIN NUMBER

void setup() {
  for(int i = 0 ; i < 4 ; i++){
    pinMode(sw[i], INPUT);  //스위치 INPUT
    pinMode(le[i], OUTPUT); //LED OUTPUT
  }
}

//digitalRead(sw[i]) == (0:1)
void loop() {
  for(int i = 0 ; i < 4 ; i++){
    digitalRead(sw[i])?digitalWrite(le[i],HIGH):digitalWrite(le[i],LOW);
  }
}
