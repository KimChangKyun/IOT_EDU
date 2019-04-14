
char code[ ] = {/*도*/'C',/*레*/'D',/*미*/'E',/*파*/'F',/*솔*/'G',/*라*/'A',/*시*/'B',/*도*/'Z'};
unsigned int  freq[ ] = {262, 294, 330, 349, 392, 440, 494, 523}; //각 코드에 대한 값
char mData[ ] = "GEEGECDEDCEGZGZGZGEGDFEDC"; //음표
int mBData[ ] = {4,2,2,2,2,4,4,2,2,2,2,4,2,2,2,2,2,2,4,4,2,2,2,2,4}; //각각의 음표에 대한 박자값
int pinNum = 7; // 핀 넘버
const byte mSize = sizeof(mData);
const byte fSize = sizeof(freq);

void setup() {
  // put your setup code here, to run once:
  pinMode(pinNum, OUTPUT);
}

void loop() {
  int  playT = 250;   // 1박자를 0.5초
  for (int m = 0; m < mSize; m++) { //음표의 개수만큼 반복
      for(int k = 0; k < 8; k++) { //음 높이 search
          if( mData[m] == code[k] ) { // 배열 mData[]의 문자와 배열 code[] 의 문자 비교하여 인텍스 k 검색
                tone(pinNum, freq[k], playT * mBData[m]); //
                delay(playT * mBData[m]);   // 반박 * 설정한 박자의 값
          }
      }
  }
  noTone(pinNum);
  delay(2000);
  exit(0);
}
