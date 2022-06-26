# Laser-Driver

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


## Intefaced the LCD to show any required data

<p align="center">
  <img width="500" height="600" src="img/LCD_interfacing.jpg ">
</p>

## Interfaced the INA219 Current sensor to measure the curreent value

<p align="center">
  <img width="500" height="600" src="img/current_sensor_interfacing.jpg ">
</p>

The vale from the INA219 using the LCD LED as load :) (As I am doing this project Hochschule, I am quite restricted with parts)

<p align="center">
  <img src="img/current_sensor_data.png ">
</p>









