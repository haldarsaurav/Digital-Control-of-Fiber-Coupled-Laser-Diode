// Description

// Converting an existing analog circuit to digital circuit, controlling the current range 
// thorugh digital means nand incorporating various other features
// 
// 17th June 2022
//
//

 void setup() {

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
}