#include <LiquidCrystal.h>
#include <SPI.h> // SPI
#include <MFRC522.h> // RFID

#define SS_PIN 10
#define RST_PIN 9
    
// Déclaration 
MFRC522 rfid(SS_PIN, RST_PIN); 

// Tableau contentent l'ID
byte nuidPICC[4];
bool goodTag = false;
LiquidCrystal lcd(7,6,5,4,3,2);
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  // Init SPI bus
  SPI.begin(); 
  
  // Init MFRC522 
  rfid.PCD_Init(); 
}

void loop() {
  // Initialisé la boucle si aucun badge n'est présent 
  if ( !rfid.PICC_IsNewCardPresent())
    return;

  // Vérifier la présence d'un nouveau badge 
  if ( !rfid.PICC_ReadCardSerial())
    return;

  // Enregistrer l'ID du badge (4 octets) 
  for (byte i = 0; i < 4; i++) 
  {
    nuidPICC[i] = rfid.uid.uidByte[i];
  }

  if(nuidPICC[0]==134)
    if(nuidPICC[1]==58)
      if(nuidPICC[2]==209)
        if(nuidPICC[3]==92)
          goodTag = true;
  // Re-Init RFID
  rfid.PICC_HaltA(); // Halt PICC
  rfid.PCD_StopCrypto1(); // Stop encryption on PCD
  

   if (goodTag == true)
   {
       Serial.println("Good Tag");
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Good Tag");
       goodTag = false;

   }
}
