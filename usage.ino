int analogPin = 0;
int analogValue = 0;
int ledPin = 7;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  analogValue = analogRead(analogPin);
  Serial.println(analogValue);
  if(analogValue > 300){ // Lorsque la photorésistance sera suffisamment éclairé, la LED s'éteindra
    digitalWrite(ledPin, LOW);
  }
  else{
    digitalWrite(ledPin, HIGH);  
  }
}
