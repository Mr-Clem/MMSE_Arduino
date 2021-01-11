#include <LiquidCrystal.h>
LiquidCrystal ecran(12,11,5,4,3,2);
int analogPin = 0;
int analogValue = 0;
String entry ="";

void setup() {
  Serial.begin(9600);
  ecran.begin(16, 2);
  ecran.setCursor(0, 0);
  ecran.print("     Hello      ");
  ecran.setCursor(0, 1);
  ecran.print("       :)       ");
}

void loop() {
  analogValue = analogRead(analogPin);
  entry = Serial.readStringUntil('\n');
  if(entry == "0.0"){
    ecran.setCursor(0, 0);
    ecran.print("      SAFE    ");
  }
  if(entry == "1.0"){
    ecran.setCursor(0, 0);
    ecran.print("    Prudence    ");
  }
  if(entry == "2.0"){
    ecran.setCursor(0, 0);
    ecran.print("   Attention    ");
  }
  if(entry == "3.0"){
    ecran.setCursor(0, 0);
    ecran.print("      DANGER    ");
  }
  if(entry == "4.0"){
    ecran.setCursor(0, 0);
    ecran.print("      RIP       ");
  }
  if(analogValue>400){
    Serial.println("ok");
  }else{
    Serial.println("warning");
  }
  delay(1000);
}
