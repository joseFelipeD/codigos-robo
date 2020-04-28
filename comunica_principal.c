#pragma config(Sensor, S1,     ,               sensorEV3_GenericI2C)
#pragma config(Sensor, S2,     SE,             sensorNone)
#pragma config(Sensor, S3,     SD,             sensorNone)
#pragma config(Sensor, S4,     SF,             sensorNone)
#pragma config(Motor,  motorA,          ME,            tmotorEV3_Large, PIDControl, reversed, driveLeft, encoder)
#pragma config(Motor,  motorB,          MD,            tmotorEV3_Large, PIDControl, reversed, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Allow us to use "ARDUINO_PORT" instead of writing "S1"
#define ARDUINO_PORT S1
#define ARDUINO_ADDRESS	0x08     // Arduino: 0x04

#include<vr_funcoes.h>
#include<jf_desvio.h>

task main(){

	while(true){
		int distancia = vr_distancia();

		//displayCenteredBigTextLine(4, "%d", distancia);

		if(distancia < 15){
			playSound(soundBeepBeep);
			desvio();
			break;
		} else {
			setMultipleMotors(15, ME, MD);
		}
	}
}
