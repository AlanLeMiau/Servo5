/******************************************************************************
 *
 *      ---- VIVOXIE ----
 *
 *  Fecha: 15 - enero - 2020
 *  Desarrolladores:
 *          --> Alan Fuentes
 *	servo5
 *	Modifies Timer5 on ATMEGA2560 to generates servo signals 
 *	on pins 44, 45 or 46 with values between the following limits:
 *	Servo limits:
 * 	  0° -> 0.481 ms = 15
 *  180° -> 2.528 ms = 79
 *	To move a Servo, use the function Write(pin, value)
 *****************************************************************************/
#include "Servo5.h"
#include <avr/io.h>

const uint8_t grip_Max = 150;
const uint8_t grip_min = 50;

int i = 0;
int err = 0;

Servo5 wrist;
Servo5 gripper;

void setup()
{
	Serial.begin(9600);

	Serial.print("Wrist.attach: \t");
	err = wrist.attach(44);
	Serial.println(err);

	Serial.print("gripper.attach: \t");
	err = gripper.attach(45);
	Serial.println(err);

}

void loop()
{
    Serial.println("Girando a un lado");
    for (i = 0; i<=180; i+=10)
    {
        // Serial.print("Wrist.write: \t");
        err = wrist.write(i);
        Serial.println(i);
		// Serial.println(err);
        delay(500);
    }

	Serial.print("gripper.write: \t");
	err = gripper.write(grip_min);
	Serial.println(err);

    Serial.println("Girando al otro lado");
    for (i = 180; i>=0; i-=10)
    {
        wrist.write(i);
        Serial.println(i);
        delay(500);
    }

	Serial.print("gripper.write: \t");
	err = gripper.write(grip_Max);
	Serial.println(err);
}
