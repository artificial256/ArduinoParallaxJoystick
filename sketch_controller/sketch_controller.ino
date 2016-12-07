/*Philip Vallone
2-axis joystick connected to an Arduino Micro
to output 4 pins, up, down, left & right

If you are using pull down resistors, change all the HIGHs to LOWs and LOWs to HIGH.
This skectch is using pull up resistors.

*/

#include <Keyboard.h>

int UD = 0;
int LR = 0;
/* Arduino Micro output pins*/
int DWN = 12;
int UP = 11;
int LEFT = 10;
int RT = 9;
/* Arduino Micro Input Pins */
int IUP=A0;
int ILR=A1;

int MID = 9; // 10 mid point delta arduino, use 4 for attiny
int LRMID = 0;
int UPMID = 0;

const int button1Pin = 3;  // pushbutton 1 pin
const int button2Pin = 4;
int button1State, button2State;

void setup(){
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  

  
  pinMode(DWN, OUTPUT);
  pinMode(UP, OUTPUT);  
  pinMode(LEFT, OUTPUT); 
  pinMode(RT, OUTPUT);
   
  digitalWrite(DWN, HIGH);
  digitalWrite(UP, HIGH);
  digitalWrite(LEFT, HIGH);
  digitalWrite(RT, HIGH);
  
  //calabrate center
  LRMID = analogRead(ILR);
  UPMID = analogRead(IUP);
}

void loop(){
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);

  Serial.println(button1State); 
  Serial.println(button2State); 
  

  if (button1State){
    Keyboard.press('x');
  }
  else {
    Keyboard.release('x');
  }
    if (button2State){
    Keyboard.press('c');
  }
  else {
    Keyboard.release('c');
  }

  UD = analogRead(IUP);
  LR = analogRead(ILR);
  
  // UP-DOWN
  if(UD < UPMID - MID){
    digitalWrite(DWN, LOW);
    Keyboard.press(KEY_DOWN_ARROW);
  }else{
    digitalWrite(DWN, HIGH);
    Keyboard.release(KEY_DOWN_ARROW);
  }
  
   if(UD > UPMID + MID){
    digitalWrite(UP, LOW);
    Keyboard.press(KEY_UP_ARROW);
  }else{
   digitalWrite(UP, HIGH);
   Keyboard.release(KEY_UP_ARROW); 
  }
  
  // LEFT-RIGHT
  if(LR < LRMID - MID){
    digitalWrite(LEFT, LOW);
    Keyboard.press(KEY_LEFT_ARROW);
  }else{
     digitalWrite(LEFT, HIGH);
    Keyboard.release(KEY_LEFT_ARROW);
  }
  
  if(LR > LRMID + MID){
   digitalWrite(RT, LOW);
   Keyboard.press(KEY_RIGHT_ARROW);
  }else{
   digitalWrite(RT, HIGH);
   Keyboard.release(KEY_RIGHT_ARROW);
  }
 
  delay(0);

}

