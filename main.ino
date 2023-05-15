#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin(); 
  lcd.clear();
  lcd.print("Spotify");
}

void loop () {
  while (Serial.available() == 0) {}
  String teststr = Serial.readString();
  String Line1_fixed = "Spotify"; 
  teststr.trim();

  lcd.clear();
  lcd.print(Line1_fixed);
  delay(500);

  String Line2_scrolling =  "                "; 
  Line2_scrolling += teststr; 

  int Line2_length = Line2_scrolling.length(); 
  int Line2_ChunkNumber = floor(Line2_length / 16 + 2); 
  int Line2_LastChunkLength = Line2_length - ((Line2_ChunkNumber - 2) * 16); 
  int Line2_ChunkLength; 
  if (Line2_LastChunkLength == 0) { 
    Line2_ChunkNumber--;
  }
  String chunk[Line2_ChunkNumber]; 

  for (int j = 0; j < Line2_ChunkNumber - 1; j++) { 
    chunk[j] = Line2_scrolling.substring(j * 16 , j * 16 + 16);
  }

  for (int k = 0; k < Line2_ChunkNumber - 1; k++) {
    lcd.clear();
    lcd.print(Line1_fixed); 
    lcd.setCursor(0, 1);
    lcd.print(chunk[k]); 
    lcd.print(chunk[k + 1]);
    if (k != Line2_ChunkNumber - 2) { 
      Line2_ChunkLength = 16;
    }
    else if (Line2_LastChunkLength != 0) {
      Line2_ChunkLength = Line2_LastChunkLength;
    }

    for (int i = 1; i < Line2_ChunkLength + 1; i++) {
      lcd.scrollDisplayLeft();
      lcd.setCursor(i, 0); 
      lcd.print(Line1_fixed); 
      delay(300); 
    }
  }
}