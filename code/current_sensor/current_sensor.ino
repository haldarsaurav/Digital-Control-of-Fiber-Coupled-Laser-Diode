/////////////////////////////////////
// DC-Current-Voltage-Sensor-Module//
/////////////////////////////////////

#include <Wire.h>
#include <Adafruit_INA219.h>
Adafruit_INA219 ina219;

void setup(void) 
{
  
  Serial.begin(9600);
  while (!Serial) {
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
  

  
  Serial.print("Bus Voltage:   "); Serial.print(busvoltage); Serial.println(" V");
  Serial.print("Shunt Voltage: "); Serial.print(shuntvoltage); Serial.println(" mV");
  Serial.print("Load Voltage:  "); Serial.print(loadvoltage); Serial.println(" V");
  Serial.print("Current:       "); Serial.print(current_mA); Serial.println(" mA");
  Serial.print("Power:         "); Serial.print(power_mW); Serial.println(" mW");
  Serial.println("");

  delay(1000);
}
