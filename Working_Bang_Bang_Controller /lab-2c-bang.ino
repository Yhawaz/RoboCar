#include "DFRobotMotorShield.h"
DFRobotMotorShield motors;
float left_normal=60;
float left_delta=.3*left_normal;
float right_normal=70;
float right_delta=.3*right_normal;
float max[5]={828,833,930,750,830};
float min[5]={982,983,983,981,982};
float norm[5];
#define IR1_PIN A11
#define IR2_PIN A12
#define IR3_PIN A13
#define IR4_PIN A14
#define IR5_PIN A15
float IR1Val, IR2Val, IR3Val, IR4Val, IR5Val;
float leftSpeed,rightSpeed;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  IR1Val = analogRead(IR1_PIN);
  IR2Val = analogRead(IR2_PIN);
  IR3Val = analogRead(IR3_PIN);
  IR4Val = analogRead(IR4_PIN);
  IR5Val = analogRead(IR5_PIN);
  float irs[5]={IR1Val,IR2Val,IR3Val,IR4Val,IR5Val};
  for(int i=0;i<5;i++){
    norm[i]=round(constrain((irs[i]-min[i])/(max[i]-min[i]),0,1));
  }
  float weight=(((norm[0])+(norm[1]*2)+(norm[2]*3)+(norm[3]*4)+(norm[4]*5)));
  if(weight>3){
    leftSpeed=left_normal+left_delta;
    rightSpeed=right_normal-right_delta;
  }else{
    leftSpeed=left_normal-left_delta;
    rightSpeed=right_normal+right_delta;
  }
  motors.setM1Speed(leftSpeed);
  motors.setM2Speed(rightSpeed);
  

}
