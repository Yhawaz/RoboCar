float max[5]={665,800,785,690,850};
float min[5]={980,983,982,980,981};
float norm[5];
#define IR1_PIN A11
#define IR2_PIN A12
#define IR3_PIN A13
#define IR4_PIN A14
#define IR5_PIN A15
float IR1Val, IR2Val, IR3Val, IR4Val, IR5Val;
void setup() {
  // put your setup code here, to run once:
  //grab our ranges and normalized values and shit
  Serial.begin(9600);
}

void loop() {
  IR1Val = analogRead(IR1_PIN);
  IR2Val = analogRead(IR2_PIN);
  IR3Val = analogRead(IR3_PIN);
  IR4Val = analogRead(IR4_PIN);
  IR5Val = analogRead(IR5_PIN);
  float irs[5]={IR1Val,IR2Val,IR3Val,IR4Val,IR5Val};
  for(int i=0;i<5;i++){
    if(irs[i]<960){
      norm[i]=1;
    }else{
      norm[i]=0;
    }
  }
  float weight=round((norm[0])+(norm[1]*2)+(norm[2]*3)+(norm[3]*4)+(norm[4]*5));
  // Serial.println("IR1");
  // Serial.println(norm[0]);
  // Serial.println("IR2");
  // Serial.println(norm[1]);
  // Serial.println("IR3");
  // Serial.println(norm[2]);
  // Serial.println("IR4");
  // Serial.println(norm[3]);
  // Serial.println("IR5");
  // Serial.println(norm[4]);
  // Serial.println(weight);
  Serial.println(weight);

  delay(2000);

}
