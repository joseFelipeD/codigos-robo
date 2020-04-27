
void desvio(){
	stopAllMotors();

	//Vira
	setMotor(ME,-30);
	moveMotor(MD,350,degrees,30);
	stopAllMotors();

	playSound(soundLowBuzz);
	wait(1, seconds);

	//Vai pra frente até o sensor perder o obstaculo
	int	distancia_direita = vr_distancia_direita();
	while(distancia_direita < 25){
		setMultipleMotors(15, ME, MD);
		wait(300, milliseconds);
		stopAllMotors();

		distancia_direita = vr_distancia_direita();
		displayCenteredBigTextLine(4, "%d", distancia_direita);
	}

	stopAllMotors();
	playSound(soundDownwardTones);
	wait(1, seconds);

	//Vai um pouco mais pra frente
	setMotor(ME,15);
	moveMotor(MD,280,degrees, 15);
	stopAllMotors();

	//Vira
	setMotor(ME,30);
	moveMotor(MD,350,degrees, -30);
	stopAllMotors();

	//Vai pra frente até o sensor achar o obstaculo
	distancia_direita = vr_distancia_direita();
	while(distancia_direita > 15){
		setMultipleMotors(20, ME, MD);
		wait(300, milliseconds);
		stopAllMotors();

		distancia_direita = vr_distancia_direita();
		displayCenteredBigTextLine(4, "%d", distancia_direita);
	}

	stopAllMotors();
	playSound(soundBeepBeep);
	wait(1, seconds);

	while(distancia_direita < 15){
		setMultipleMotors(15, ME, MD);
		wait(300, milliseconds);
		stopAllMotors();

		distancia_direita = vr_distancia_direita();
		displayCenteredBigTextLine(4, "%d", distancia_direita);
	}
	stopAllMotors();

	//Vai um pouco mais pra frente
	setMotor(ME,50);
	moveMotor(MD,280,degrees, 50);
	stopAllMotors();

	//Vira
	setMotor(ME,50);
	moveMotor(MD,350,degrees, -50);
	stopAllMotors();

	//Vai pra frente até o sensor achar o obstaculo
	distancia_direita = vr_distancia_direita();
	while(distancia_direita > 15){
		setMultipleMotors(10, ME, MD);
		wait(300, milliseconds);
		stopAllMotors();

		distancia_direita = vr_distancia_direita();
		displayCenteredBigTextLine(4, "%d", distancia_direita);
	}
	stopAllMotors();

	//Vai até o meio do obstaculo
	setMotor(ME,50);
	moveMotor(MD,200,degrees, 50);
	stopAllMotors();

	setMotor(ME,50);
	moveMotor(MD,355,degrees, -50);
	stopAllMotors();

	playSound(soundFastUpwardTones);
	wait(1, seconds);
}
