#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int detect = 13;
String entry ="";


int switchstate;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(detect, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("     Hello      ");
  lcd.setCursor(0, 1);
  lcd.print("       :)       ");

}

void displayColor(int r, int g, int b){
    analogWrite(A1,b);
    analogWrite(A2,g);
    analogWrite(A3,r);
}


void loop() {
  entry = Serial.readStringUntil('\n');
  if(entry == "0.0"){
    lcd.setCursor(0, 0);
    lcd.print("      SAFE      ");
    lcd.setCursor(0, 1);
    lcd.print("       :)       ");
  }
  if(entry == "1.0"){
    lcd.setCursor(0, 0);
    lcd.print("    Prudence    ");
    lcd.setCursor(0, 1);
    lcd.print("       :x       ");
  }
  if(entry == "2.0"){
    lcd.setCursor(0, 0);
    lcd.print("   Attention    ");
    lcd.setCursor(0, 1);
    lcd.print("       :/       ");
  }
  if(entry == "3.0"){
    lcd.setCursor(0, 0);
    lcd.print("      DANGER    ");
    lcd.setCursor(0, 1);
    lcd.print("       :$       ");
  }
  if(entry == "4.0"){
    lcd.setCursor(0, 0);
    lcd.print("      RIP       ");
    lcd.setCursor(0, 1);
    lcd.print("       :(       ");
  }
  switchstate = digitalRead(detect);
  if(switchstate == HIGH ){
    displayColor(255,0,0);
    Serial.println("ok");
  }
  else{
    displayColor(0,0,255);
    Serial.println("warning");
  }
 delay(1000);
}
