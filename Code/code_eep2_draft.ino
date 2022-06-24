//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Description
//
// Converting an existing analog circuit to digital circuit, controlling the current range 
// thorugh digital means nand incorporating various other features
// 
// 17th June 2022
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {

// set up the LCD's number of columns and rows:
lcd.begin(16, 2);



}


void loop() {
 analogWrite(9,100); // Laser diode connected to pin A9
 delay(1000);
 analogWrite(9,150);
 delay(1000);
 analogWrite(9,200);
 delay(1000);
 analogWrite(9,250);
 delay(1000);
 analogWrite(9,0);
 delay(1000);

// LCD Message
/*( Print your message here  )*/
lcd.print("   HELLO       ");
lcd.setCursor(0,1);           // Set the cursor for the second line( the second 1 after comma sets the cursor at the 2 or lower line).
lcd.print("      WORLD "); 


}