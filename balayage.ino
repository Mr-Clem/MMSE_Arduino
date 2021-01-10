#include <LiquidCrystal.h>
#include <Servo.h>

Servo monservo;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String entry ="";
const byte TRIGGER = 8;
const byte ECHO = 9;
float SOUND_SPEED = 340.0 / 1000;
int rot = 1;
int angle = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("     Hello      ");
  lcd.setCursor(0, 1);
  lcd.print("       :)       ");
  
  monservo.attach(7);
  monservo.write(0);
  
  pinMode(TRIGGER, OUTPUT);
  digitalWrite(TRIGGER, LOW);
  pinMode(ECHO, INPUT);
}


void loop() {
  
  //Serial input checking
  entry = Serial.readStringUntil('\n');
  if(entry == "0.0"){
    lcd.setCursor(0, 0);
    lcd.print("SAFE");
  }
  if(entry == "1.0"){
    lcd.setCursor(0, 0);
    lcd.print("    Prudence    ");
  }
  if(entry == "2.0"){
    lcd.setCursor(0, 0);
    lcd.print("   Attention    ");
  }
  if(entry == "3.0"){
    lcd.setCursor(0, 0);
    lcd.print("      DANGER    ");
  }
  if(entry == "4.0"){
    lcd.setCursor(0, 0);
    lcd.print("      RIP       ");
  }
  
  angle += rot;
  monservo.write(angle);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  
  long measure = pulseIn(ECHO, HIGH);

  float distance = measure / 2.0 * SOUND_SPEED;
  
  if(angle == 180){
    rot = -1;
  }
  if (angle == 0){
    rot = 1;
  }
  
  //Serial output
  if(distance<100){
    Serial.println("warning");
  }else{
    Serial.println("ok");
  }  
}
