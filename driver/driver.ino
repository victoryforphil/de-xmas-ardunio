/*
 * Displays text sent over the serial port (e.g. from the Serial Monitor) on
 * an attached LCD.
 * YWROBOT
 *Compatible with the Arduino IDE 1.0
 *Library version:1.1
 */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Serial.begin(9600);
}
byte msgBuffer[64];
int charCount = 0;
int offset = 0;
bool scrolling = false;
void loop()
{
  
  
  lcd.setCursor(0,1);
  // when characters arrive over the serial port...
  loadSerial();
  writeBottomLine();
  
}

void loadSerial(){
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    //lcd.clear();
    // read all the available characters
    charCount = 0;
    while (Serial.available() > 0) {
      msgBuffer[charCount] = Serial.read();
      charCount++;

      if(charCount > 16){
        scrolling = true;
      }

      //lcd.write(msgBuffer[charCount]);
    }

    
  }

  
}

void writeBottomLine(){
  byte toPrint[16];
  for(int i=0;i<16;i++){
    toPrint[i] = msgBuffer[i+offset];
    lcd.write(toPrint[i]);
  }
  if(scrolling){
    delay(400);
    offset++;
    if(offset > charCount){
      offset =0;
    }
  }
  
}
