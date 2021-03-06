#pragma config(Sensor, S1,     ,               sensorEV3_GenericI2C)
#pragma config(Sensor, S2,     SE,             sensorEV3_Color)
#pragma config(Sensor, S3,     SD,             sensorEV3_Color)
#pragma config(Sensor, S4,     SF,             sensorEV3_Color)
#pragma config(Motor,  motorA,          ME,            tmotorEV3_Large, PIDControl, reversed, driveLeft, encoder)
#pragma config(Motor,  motorB,          MD,            tmotorEV3_Large, PIDControl, reversed, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define ARDUINO_PORT S1
#define ARDUINO_ADDRESS	0x08     // Arduino: 0x04
#include <pegaValor.h>
#include<jf_desvio.h>
#include<vr_funcoes.h>
#include<vr_comp.h>

int erro;
int vr_rampa;


task t_ver_des_rampa(){
	while(true){
		vr_rampa = vr_rampaDesvio();
		writeDebugStreamLine("%d",vr_rampa);
		delay(100);
	}
}

task main(){

	startTask(t_ver_des_rampa); //chama task que le o desvio

	float prop,inte,deri;	//variaveis do controlador PID
	float kp,kd;	//constantes do controlador PID
	float pid; //valor total controle PID
	int erroAnterior;

	// setando constantes de ajuste
	kp = 40;
	kd = 0;
	//	ki = 10;
	while (true){

		erro = leValores();
		//definindo a decisao que o robo deve tomar baseado na leitura
		prop = erro;
		deri = erro - erroAnterior;
		inte = inte + erro;

		pid = (prop * kp) + (deri * kd);
		erroAnterior = erro;

		int velA = 30 + pid;
		int velB = 30 - pid;


		setMotor(MD,velA);
		setMotor(ME,velB);
		//

	}
}
