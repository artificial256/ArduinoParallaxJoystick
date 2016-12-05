/*Philip Vallone
2-axis joystick connected to an Arduino Micro
to output 4 pins, up, down, left & right

If you are using pull down resistors, change all the HIGHs to LOWs and LOWs to HIGH.
This skectch is using pull up resistors.

*/

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
void setup(){
  
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

  UD = analogRead(IUP);
  LR = analogRead(ILR);
  // UP-DOWN
  if(UD < UPMID - MID){
   digitalWrite(DWN, LOW);
  }else{
   digitalWrite(DWN, HIGH);
  }
  
  if(UD > UPMID + MID){
   digitalWrite(UP, LOW);
  }else{
   digitalWrite(UP, HIGH);
  }
  // LEFT-RIGHT
  if(LR < LRMID - MID){
   digitalWrite(LEFT, LOW);
  }else{
   digitalWrite(LEFT, HIGH);
  }
  
  if(LR > LRMID + MID){
   digitalWrite(RT, LOW);
  }else{
   digitalWrite(RT, HIGH);
  }
 
  delay(400);


}

