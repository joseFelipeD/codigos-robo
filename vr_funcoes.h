////////////////////////////////////////////
////////////////////////////////////////////
/// FUNCOES DA COMUNICACAO               ///
/// DESENVOLVIDO POR: VINICIUS ROOSEVELT ///
/// DATA 21/02/2019                      ///
/// CODIGO COM FUNCOES QUE ENVIAM SINAIS ///
/// PARA O ARDUINO SOLICITANDO VALORES   ///
/// DOS SENSORES ULTRASONICOS 					 ///
////////////////////////////////////////////
////////////////////////////////////////////
///--------------------------------------///
/// PARA USAR AS FUNCOES É NECESSSARIO   ///
/// INCLUIR ESTA BIBLIOTECA.						 ///
///																			 ///
/// PARA INCLUIR, COLOQUE A SEGUINTE     ///
/// LINHA DE CODIGO NO PROGRAMA PRINCIPAL///
/// #include <sensores.h>								 ///
////////////////////////////////////////////
////////////////////////////////////////////



ubyte I2Cmessage[22];
char I2Creply[20];

//funcao da comunicacao (NAO MEXER!!)
int i2c_msg(byte ard_address, int message_size, int return_size, ubyte byte0, ubyte byte1, ubyte byte2, ubyte byte3 ,ubyte byte4){
	memset(I2Creply, 0, sizeof(I2Creply));
	message_size = message_size+3;
	I2Cmessage[0] = message_size; // Messsage Size
	I2Cmessage[1] = ard_address;
	I2Cmessage[2] = byte0;
	I2Cmessage[3] = byte1;
	I2Cmessage[4] = byte2;
	I2Cmessage[5] = byte3;
	I2Cmessage[6] = byte4;
	sendI2CMsg(S1, &I2Cmessage[0], return_size);
	wait1Msec(20);
	readI2CReply(ARDUINO_PORT, &I2Creply[0], return_size);
	int x = I2Creply[0];
	wait1Msec(35);
	return x;
}


/*
----------------------------------------
----------------------------------------
--------------- FUNCOES ----------------
----------------------------------------
----------------------------------------
*/

int vr_distancia(){

	int valorEnvio = 1;

	i2c_msg(ARDUINO_ADDRESS, 2, 1, valorEnvio, 3, true , 0, 0);
	delay(50);
	int value = i2c_msg(ARDUINO_ADDRESS, 2, 1, valorEnvio, 3, true , 0, 0);
	delay(50);
	return value;
}


int vr_distancia_direita(){

	int valorEnvio = 2;

	i2c_msg(ARDUINO_ADDRESS, 2, 1, valorEnvio, 3, true , 0, 0);
	delay(50);

	int value = i2c_msg(ARDUINO_ADDRESS, 2, 1, valorEnvio, 3, true , 0, 0);
	delay(50);
	return value;
}

int vr_distancia_direita_tras(){

	int valorEnvio = 5;

	i2c_msg(ARDUINO_ADDRESS, 2, 1, valorEnvio, 3, true , 0, 0);
	delay(50);

	int value = i2c_msg(ARDUINO_ADDRESS, 2, 1, valorEnvio, 3, true , 0, 0);
	delay(50);
	return value;
}

int vr_linha(){
	int valorEnvio = 3;

	i2c_msg(ARDUINO_ADDRESS, 2, 1, valorEnvio, 3, true , 0, 0);
	delay(50);

	int value = i2c_msg(ARDUINO_ADDRESS, 2, 1, valorEnvio, 3, true , 0, 0);
	delay(50);
	return value;
}

int vr_rampaDesvio(){
	int valorEnvio = 4;

	i2c_msg(ARDUINO_ADDRESS, 2, 1, valorEnvio, 3, true , 0, 0);
	delay(70);

	int value = i2c_msg(ARDUINO_ADDRESS, 2, 1, valorEnvio, 3, true , 0, 0);
	delay(70);
	return value;
}
