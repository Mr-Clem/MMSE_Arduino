int detect = 10;

int switchstate;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(detect, INPUT_PULLUP);
}

void displayColor(int r, int g, int b){
    analogWrite(A1,b);
    analogWrite(A2,g);
    analogWrite(A3,r);
}


void loop() {
  switchstate = digitalRead(detect);
  if(switchstate == HIGH ){
    displayColor(255,0,0);
  }
  else{
    displayColor(0,0,255);
  }
 
}
