#include <Keyboard.h>

const int UpPin = 2;
const int DownPin = 3;
const int LeftPin = 4;
const int RightPin = 5;

// スイッチ状態変数
boolean UpS = HIGH; //上
boolean DownS = HIGH; //下
boolean LeftS = HIGH; //左
boolean RightS = HIGH; //右

// スイッチ状態1つ前
boolean UpS2 = HIGH; //上
boolean DownS2 = HIGH; //下
boolean LeftS2 = HIGH; //左
boolean RightS2 = HIGH; //右

void setup() {
  Keyboard.begin();
  pinMode(UpPin,    INPUT_PULLUP);
  pinMode(DownPin,  INPUT_PULLUP);
  pinMode(LeftPin,  INPUT_PULLUP);
  pinMode(RightPin, INPUT_PULLUP);  
}

void loop() {
  // ボタン状態保存
  UpS2 = UpS;
  DownS2 = DownS;
  LeftS2 = LeftS;
  RightS2 = RightS;
  
  UpS = digitalRead(UpPin);
  DownS = digitalRead(DownPin);
  LeftS = digitalRead(LeftPin);
  RightS = digitalRead(RightPin);

  digitalWrite(17, HIGH);

  // UpPin 上ボタン
  if(UpS == LOW and UpS2 == HIGH){
    Keyboard.press(KEY_UP_ARROW);
    
    digitalWrite(17, LOW);
  }
  else if(UpS == HIGH){
    Keyboard.release(KEY_UP_ARROW);
  }
  
  // DownPin 下ボタン
  if(DownS == LOW and DownS2 == HIGH){
    Keyboard.press(KEY_DOWN_ARROW);
        
    digitalWrite(17, LOW);
  }
  else if(DownS == HIGH){
    Keyboard.release(KEY_DOWN_ARROW);
  }
  
  // LeftPin 左ボタン
  if(LeftS == LOW and LeftS2 == HIGH){
    Keyboard.press(KEY_LEFT_ARROW);

    digitalWrite(17, LOW);
  }
  else if(LeftS == HIGH){
    Keyboard.release(KEY_LEFT_ARROW);
  }
  
  // RightPin 右ボタン
  if(RightS == LOW and RightS2 == HIGH){
    Keyboard.press(KEY_RIGHT_ARROW);

    digitalWrite(17, LOW);   
  }
  else if(RightS == HIGH) {
    Keyboard.release(KEY_RIGHT_ARROW);
  }

  delay(100);
}
