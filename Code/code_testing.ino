




//////////////////////////////////////////////////////////////////////////////////
//              CLOCK + TEMPERATURE + HUMIDITY METER WITH DISPLAY                /
//                      Code written and designed By:-                           /
//                      ***** SAURAV HALDAR *****                                /
//                         haldarsaurav13@gmail.com                              /
//                       electronics470.wordpress.com                            /
//                                                                               /
// Credits:- LADYADA (Limor Fried of ADAFRUIT INDUSTRIES for the DHT11 library)  /
//                                   and                                         /
//        Mr.Tom Igoe (his State change detection example as a reference)        /
//                           (for the menu system)                               /
//                                                                               /
//                               Code written                                    /
//                                   on                                          /
//                              14th JULY 2015                                   /
//                              Last modified                                    /
//                                   on                                          /
//                              18 August 2015                                   / 
//                                  PM                                       /
//                                                                               /
//                                                                               /
//////////////////////////////////////////////////////////////////////////////////



                                  /*-----( Header Files )-----*/

#include <Wire.h>                                       // This library allows you to communicate with I2C devices.
#include <RealTimeClockDS1307.h>                        // The RTC library (even though it says DS1307, I am using DS3231 it will work fine). 
#include "DHT.h"                                        // The Library for the Humidity sensor DHT11.
#include <LiquidCrystal.h>                              // The library for the LCD. 

                                  /*-----( Declare objects )-----*/

#define DHTPIN 2                                        // Gives a name to a constant value before the program is compiled (const can be used too).
                                                        // DHTPIN 2 indicates the Humidity output is connected to the Pin 2(Digital). 


#define DHTTYPE DHT11                                   // Whether it is a DHT11 or a DHT22 (refer LADYADA'S library file for this).

DHT dht(DHTPIN, DHTTYPE);                               // Initialise the DHT11.

LiquidCrystal lcd( 3, 4, 5, 6, 7, 8);                   // Initialise the LCD. To learn more --> https://www.arduino.cc/en/Reference/LiquidCrystal?from=Tutorial.LCDLibrary


 /*( Objects required for the CLOCK interface.  )*/
String tz;                                              // String for AM PM.
int hours = 0;
int minutes = 0;
int seconds = 0;
int dates = 0;
int months = 0;
int years = 0;
int ap = 0;                                            // Store 1 or 0 if it is PM or not (refer the RTC library for this). 

 /*( Objects required for the TEMPERATURE interface.  )*/
float temp;                                            // Object required for the TEMPERATURE interface. 
int tempPin = 2;                                       // LM35's output connected to Analog 2


                                                       
 /*( Objects required for the Buttons and LEDs  )*/
const int  buttonPin = A0;                             // the pin that the pushbutton is attached to
const int  buttonPin1 = A1;
const int ledPin = 11;                                 // the pin that the LED is attached to
const int ledPin1 = 12; 
const int ledPin2 = 13;

 /*( Objects required for the Virtual Menu system  )*/
int buttonPushCounter = 1;                             // counter for the number of button presses
int buttonState = 0;                                   // current state of the button
int lastButtonState = 0;                               // previous state of the button

int buttonPushCounter1 = 1;                            // counter for the number of button presses
int buttonState1 = 0;                                  // current state of the button
int lastButtonState1 = 0;                              // previous state of the button


                                      /*----( SETUP: RUNS ONCE )----*/
                                      
void setup() 
{
  Serial.begin(9600);                                  // Sets the data rate in bits per second (baud) for serial data transmission. 
                                                       // For communicating with the computer, use one of these rates.
  lcd.begin(16,2);                                     // initialize the lcd for 16 chars 2 lines, turn on backlight.
  dht.begin(); 
  lcd.setCursor(0,0);                                  // Set the cursor initailly at 0,0( at the top left corner). 

 /*( Print your message here  )*/
  lcd.print("   WELCOME       ");
  lcd.setCursor(0,1);                                  // Set the cursor for the second line( the second 1 after comma sets the cursor at the 2 or lower line).
  lcd.print("      SAURAV! ");

  /*(Leds's which light up when you click for the Temperature and Humidity )*/
  pinMode(buttonPin, INPUT);                           // Initialising the pushbutton for    as INPUT 
  pinMode(ledPin, OUTPUT);                             // Initialising the led for      as OUTPUT                        
  
  pinMode(ledPin1, OUTPUT);                            // Initialising the led for      as OUTPUT 
  pinMode(buttonPin1, INPUT);                          // Initialising the pushbutton for      as INPUT      
  
  pinMode(ledPin2, OUTPUT);                            // Initialising the led for      as OUTPUT 
  
   /*( All the led's will glow when the device is started  )*/
  digitalWrite(ledPin, HIGH);             
  digitalWrite(ledPin1, HIGH);
  

   /*(Change this number for how much you wanr the lcd to display the starting MESSEGE and all leds to stay ON )*/ 
  delay(4000);                                          // It is in milliseconds
  
  lcd.clear();                                          // after your set time the display is cleared (the starting message).
    
   /*(leds will turn OFF after the said (delay) time )*/
  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin1, LOW);
  
  
  
}/* end setup */


                                              /*----( LOOP: RUNS CONSTANTLY duh! )----*/
void loop()
{


   /*----( Code for your MENU system )----*/
  buttonState = digitalRead(buttonPin);                  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) 
  {                                                    
    if (buttonState == HIGH)                             // if the state has changed, increment the counter
    {
      buttonPushCounter++;                               // if the current state is HIGH then the button
                                                         // went from OFF to ON:
    }
    delay(50);                                           // Delay a little bit to avoid bouncing. For more info--> https://www.arduino.cc/en/Tutorial/Debounce.
  }                                                      // save the current state as the last state,
                                                         //for next time through the loop
  lastButtonState1 = buttonState1;
  
  buttonState1 = digitalRead(buttonPin1);                // read the pushbutton input pin:

  if (buttonState1 != lastButtonState1)                  // compare the buttonState to its previous state
  {
    if (buttonState1 == HIGH)                            // if the state has changed, increment the counter
    {
                                                         // if the current state is HIGH then the button
                                                         // wen from OFF to ON:
      buttonPushCounter1++;
    }
    else 
    delay(50);                                           // Delay a little bit to avoid bouncing
  }
                                                         // save the current state as the last state,
                                                         //for next time through the loop
  lastButtonState = buttonState;
  
  // checking the module of the button push counter.
  // the modulo function gives you the remainder of
  // the division of two numbers:

  /*( Code block for the TEMPERATURE interface )*/
  if (buttonPushCounter % 2 == 0) 
 
  {
    digitalWrite(ledPin, HIGH); 
    temp = analogRead(tempPin);

    temp = temp * 0.48828125;
    
    lcd.setCursor(0, 0);                                // Set the cursor initailly at 0,0( at the top left corner).

    /*( Printing the TEMPERATURE )*/
    lcd.print("# TEMPERATURE  #");
    lcd.setCursor(4, 1);
    lcd.print(temp);
    lcd.print((char)223);                               // for the degree sign( degree C).
    lcd.print("C");

    /*(Change this number for how much you want the lcd to display the TEMPERATURE )*/ 
    delay(5000);                                        // it is in milliseconds
    digitalWrite(ledPin, LOW);                          // light OFF the led.
    lcd.clear();                                        // Clears up the led.
    buttonPushCounter++;                                // this is the trick to make the lcd to display the CLOCK interface againg (it is basically exiting this loop).
 } 
  else 

  /*( Code block for the HUMIDITY interface )*/
  if(buttonPushCounter1 % 2 == 0)
  {
                             
    digitalWrite(ledPin1, HIGH);                       // light up the led.
    int h = dht.readHumidity();                        // getting the reading from the DHT11.
    lcd.setCursor(0,0);                                // Set the cursor initailly at 0,0( at the top left corner).

    /*( Printing the HUMIDITY )*/
    lcd.print("#   HUMIDITY   #");
    lcd.setCursor(6,1);
    lcd.print(h);
    lcd.print("%");

    
    /*(Change this number for how much you want the lcd to display the HUMIDITY )*/ 
    delay(5000);                                       // it is in milliseconds.
    digitalWrite(ledPin1, LOW);                        // Light OFF the led.
    lcd.clear();                                       // Clears the LCD.
    buttonPushCounter1++;                              // this is the trick to make the lcd to display the CLOCK interface againg (it is basically exiting this loop).
  
  }

  /*( Code block for the CLOCK interface )*/
  else
  {    
    RTC.readClock();                                   // After the clock is turned on using the Start command. 
                                                       // You need to read the data from the RTC module. 
                                                       // This is done by the readClock function. This function is essential before the latter commands can be used.
    RTC.is12hour();                                    // Toggles between the 12hour mode and 24hour mode.

   /*( to check whether it is AM or PM )*/ 
    if(ap == 1)
    {
    tz = "PM";
    }
    else
    {
    tz ="AM";
    }
    lcd.home();                                       // Positions the cursor in the upper-left of the LCD

     /*( Storing the time into the designated variables )*/ 
    hours = RTC.getHours();
    minutes = RTC.getMinutes();
    seconds = RTC.getSeconds();
    ap = RTC.isPM();
    dates = RTC.getDate();
    months = RTC.getMonth();
    years = RTC.getYear();

    /*( This is the trick I used to make the clock switch between the 12 and 24 hour mode(i cannot get the RTC.is12hour work :-(.   ) )*/ 
    if (hours>12)
    {
      hours=hours-12;
    }

    

    /*( Printing the CLOCK )*/
    lcd.print("  ");
    lcd.print(hours);
    lcd.print(":");
    lcd.print(minutes);
    lcd.print(":");
    lcd.print(seconds);
    lcd.print(" ");
    lcd.print(tz);
    lcd.setCursor(1,8);
    lcd.print(" ");
    lcd.print(dates);
    lcd.print(":");

   /*( This is the Block I made to display the month (i don't know how to print day tell me if anyone knows that :-).  ) )*/ 
   switch(months)
  {
  case 1: lcd.print("JAN ");break;
    case 2: lcd.print("FEB");break;
    case 3: lcd.print("MA ");break;
    case 4: lcd.print("APR");break;
    case 5: lcd.print("MAY");break;
    case 6: lcd.print("JUN");break;
    case 7: lcd.print("JUL");break;
    case 8: lcd.print("AUG");break;
    case 9: lcd.print("SEP");break;
    case 10: lcd.print("OCT");break;
    case 11: lcd.print("NOV");break;
    case 12: lcd.print("DEC");break;
    default: lcd.print("ERR");break;
  } 
    lcd.print(":");
    lcd.print("20");                                            // To print the year 20(constant till (2099)-----15(the variable years).
    lcd.print(years);                                                  
    delay(150);                                                 // Refresh
    lcd.clear();
    lcd.home();
  }
}                                                                         

//////////////////////////////////////////////////////////////////////////////////
//                      Code written and designed By:-                           /
//                      ***** SAURAV HALDAR *****                                /
//                         haldarsaurav13@gmail.com                              /
//                       electronics470.wordpress.com                            /
//////////////////////////////////////////////////////////////////////////////////







