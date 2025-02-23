#include <Arduino.h>

/*!
* @file  SEN0230.ino
* @brief  Two phase quadrature encoder(Incremental)
* @n  To determine motor with encode （CW OR CCW）
* @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
* @license  The MIT License (MIT)
* @author  Dongzi(1185787528@qq.com)
* @version  V1.0
* @date  2016-5-26
*/

#define  A_PHASE 2
#define  B_PHASE 3
int encoderPosition = 0;
/** *  */

void interrupt()// Interrupt function
{ 
  uint8_t i;
  i = digitalRead( B_PHASE);
  if (i == 1)
    encoderPosition ++;
  else
    encoderPosition--;
}

void setup() {
  pinMode(A_PHASE, INPUT);
  pinMode(B_PHASE, INPUT);
  Serial.begin(9600);   //Serial Port Baudrate: 9600
  attachInterrupt(digitalPinToInterrupt( A_PHASE), interrupt, RISING); //Interrupt trigger mode: RISING
}
void loop() {

  Serial.print("position:  ");
  Serial.println(encoderPosition);
  delay(100);// Direction judgement

}
