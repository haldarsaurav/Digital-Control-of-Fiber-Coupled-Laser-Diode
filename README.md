# Digital Control of Fiber Coupled Laser Diode

Developing a new digital circuit using a micro-controller to drive Laser (LED1) replacing analog methods of curent control. 

<p align="center">
  <img src="schematic/schematic1.JPG ">
</p>

<ul>
  <li>Controlling the current to a LASER thorugh digital means instead of  analog means (Variable Resistors)</li>
  <li>Reading the current drawn and power of the LASER dynamicvally using INA219 Current Sensor</li>
  <li>Interfacing an LCD to monitor the display the PWM value of micro-controller and the curreent and poweer drawn dynamically</li>
</ul>  

Additional improvent and additions

<ul>
  <li>Adding a temperature sensor to measure the ambient temperature</li>
  <li>Adding a bluetooth transreciever to control the curreent value remotely</li> 
  <li>Developing an app or webpage based GUI application</li>
  <li>Logging all the data recieved and store it on sd card or cloud</li>
  <li>Housing all the electronics in a approprite housing.</li>
</ul>  

## Prototyping the existing circuit


Made the circuit following the schematic to drive the LASER

<p align="center">
  <img width="500" height="600" src="img/1st_prototype.jpg ">
</p>

code snippet of sending increased PWM signals through A9 pin of Arduino 

    void loop() {
         analogWrite(9,100);                                           // Laser diode connected to pin A9
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

## Intefaced the LCD to show any required data

<p align="center">
  <img width="500" height="600" src="img/LCD_interfacing.jpg ">
</p>

Code with LCD initialsed:

    // include the library code:

    #include <LiquidCrystal.h>                                     // initialize the library by associating any needed LCD interface pin

    const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;    // with the arduino pin number it is connected to

    LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

    void setup() {                                                 // set up the LCD's number of columns and rows:

    lcd.begin(16, 2);

    }

    void loop() {
     analogWrite(9,100);                                           // Laser diode connected to pin A9
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
    lcd.print("   HELLO       ");
    lcd.setCursor(0,1);                                        // Set the cursor for the second line( the second 1 after comma sets the cursor at the 2 or lower line).
    lcd.print("      WORLD "); 

    }

## Interfaced the INA219 Current sensor to measure the curreent value

<p align="center">
  <img width="500" height="600" src="img/current_sensor_interfacing.jpg ">
</p>

The vale from the INA219 using the LCD LED as load :) (As I am doing this project Hochschule, I am quite restricted with parts)

<p align="center">
  <img src="img/current_sensor_data.png ">
</p>

Code for inteerfacing INA219 and measuring the current values

    #include <Wire.h>
    #include <Adafruit_INA219.h>

    Adafruit_INA219 ina219;

    void setup(void) 
    {
      Serial.begin(9600);
      while (!Serial) {
          // will pause Zero, Leonardo, etc until serial console opens
          delay(1);
      }

      uint32_t currentFrequency;

      Serial.println("Hello!");

      if (! ina219.begin()) {
        Serial.println("Failed to find INA219 chip");
        while (1) { delay(10); }
      }

      Serial.println("Measuring voltage and current with INA219 ...");
    }

    void loop(void) 
    {
      float shuntvoltage = 0;
      float busvoltage = 0;
      float current_mA = 0;
      float loadvoltage = 0;
      float power_mW = 0;

      shuntvoltage = ina219.getShuntVoltage_mV();
      busvoltage = ina219.getBusVoltage_V();
      current_mA = ina219.getCurrent_mA();
      power_mW = ina219.getPower_mW();
      loadvoltage = busvoltage + (shuntvoltage / 1000);

      Serial.print("Bus Voltage:   "); Serial.print(busvoltage); Serial.println(" V");
      Serial.print("Shunt Voltage: "); Serial.print(shuntvoltage); Serial.println(" mV");
      Serial.print("Load Voltage:  "); Serial.print(loadvoltage); Serial.println(" V");
      Serial.print("Current:       "); Serial.print(current_mA); Serial.println(" mA");
      Serial.print("Power:         "); Serial.print(power_mW); Serial.println(" mW");
      Serial.println("");

      delay(2000);
    }









