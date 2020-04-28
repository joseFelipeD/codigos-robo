void desvio(){
	stopAllMotors();

	//Vira
	setMotor(ME,-30);
	moveMotor(MD,345,degrees,30);
	stopAllMotors();

	playSound(soundLowBuzz);
	wait(1, seconds);

	//Vai pra frente até o sensor perder o obstaculo
	int	distancia_direita = vr_distancia_direita();
	while(distancia_direita <= 15){
		distancia_direita = vr_distancia_direita();
		displayCenteredBigTextLine(4, "%d", distancia_direita);

		setMultipleMotors(15, ME, MD);
		wait(300, milliseconds);
		stopAllMotors();
	}

	stopAllMotors();
	playSound(soundDownwardTones);
	wait(1, seconds);

	//Volta para verificar
	setMotor(ME,-40);
	moveMotor(MD,180,degrees, -40);
	stopAllMotors();


	//Vai pra frente até o sensor perder o obstaculo novamente
	distancia_direita = vr_distancia_direita();
	while(distancia_direita <= 15){
		distancia_direita = vr_distancia_direita();
		displayCenteredBigTextLine(4, "%d", distancia_direita);

		setMultipleMotors(15, ME, MD);
		wait(300, milliseconds);
		stopAllMotors();
	}

	stopAllMotors();
	playSound(soundDownwardTones);
	wait(1, seconds);

	//Vai um pouco mais pra frente
	setMotor(ME,15);
	moveMotor(MD,260,degrees, 15);
	stopAllMotors();

	//Vira
	setMotor(ME,30);
	moveMotor(MD,345,degrees, -30);
	stopAllMotors();

	//Vai pra frente até o sensor achar o obstaculo
	distancia_direita = vr_distancia_direita();
	while(distancia_direita > 15){
		distancia_direita = vr_distancia_direita();
		displayCenteredBigTextLine(4, "%d", distancia_direita);

		setMultipleMotors(20, ME, MD);
		wait(300, milliseconds);
		stopAllMotors();
	}

	//Volta um pouco
	setMotor(ME, -15);
	moveMotor(MD, 150, degrees, -15);
	stopAllMotors();

	//Vai pra frente até o sensor achar o obstaculo novamente
	distancia_direita = vr_distancia_direita();
	while(distancia_direita > 15){
		distancia_direita = vr_distancia_direita();
		displayCenteredBigTextLine(4, "%d", distancia_direita);

		setMultipleMotors(20, ME, MD);
		wait(300, milliseconds);
		stopAllMotors();
	}

	stopAllMotors();
	playSound(soundBeepBeep);
	wait(1, seconds);

	//Vai um pouco mais pra frente (garante que estará dentro do obstaculo)
	setMotor(ME,30);
	moveMotor(MD,70,degrees, 30);
	stopAllMotors();
	wait(500, milliseconds);

//Vai pra frente até o sensor perder o obstaculo
	while(distancia_direita <= 15){
		distancia_direita = vr_distancia_direita();
		displayCenteredBigTextLine(4, "%d", distancia_direita);

		setMultipleMotors(15, ME, MD);
		wait(300, milliseconds);
		stopAllMotors();
	}
	stopAllMotors();

	//Vai um pouco mais pra frente
	setMotor(ME,30);
	moveMotor(MD,280,degrees, 30);
	stopAllMotors();

	//Vira
	setMotor(ME,30);
	moveMotor(MD,345,degrees, -30);
	stopAllMotors();

	//Vai pra frente até o sensor achar o obstaculo
	distancia_direita = vr_distancia_direita();
	while(distancia_direita >= 15){
		distancia_direita = vr_distancia_direita();
		displayCenteredBigTextLine(4, "%d", distancia_direita);

		setMultipleMotors(10, ME, MD);
		wait(300, milliseconds);
		stopAllMotors();
	}
	stopAllMotors();



	//Vai até o meio do obstaculo
	setMotor(ME,30);
	moveMotor(MD,200,degrees, 30);
	stopAllMotors();

	//Vira
	setMotor(ME,50);
	moveMotor(MD,345,degrees, -50);
	stopAllMotors();

	/*
	//Da uma pequena ré
	setMotor(ME,-20);
	moveMotor(MD,100,degrees, -20);
	stopAllMotors();
	*/

	//Da ré até 4cm
	stopAllMotors();
	playSound(soundBeepBeep);
	int distancia = vr_distancia();

	wait(1,seconds);
	if(distancia < 4){
		while(distancia < 4){
			distancia = vr_distancia();
			displayCenteredBigTextLine(4,"%d",distancia);

			setMultipleMotors(-10, ME, MD);
		}
	} else if (distancia > 4){
		while(distancia > 4){
			distancia = vr_distancia();
			displayCenteredBigTextLine(4,"%d",distancia);

			setMultipleMotors(10, ME, MD);
		}
	}


	//Gira até a linha
	int direita = getColorName(S3);
	int esquerda = getColorName(S2);
	int meio = getColorName(S4);

	setMotor(ME, 15);
	moveMotor(MD, 50, degrees, -15);
	stopAllMotors();


	while(esquerda != 6){
		esquerda = getColorName(S2);
		displayCenteredBigTextLine(10, "%d", esquerda);
		setMotor(ME, 15);
		setMotor(MD, -15);
	}

	stopAllMotors();

	meio = getColorName(S4);
	while(meio!= 6){
		meio = getColorName(S4);
		displayCenteredBigTextLine(10, "%d", meio);
		setMotor(MD, 15);
		setMotor(ME, -15);
	}

	stopAllMotors();

	distancia = vr_distancia();
	if(distancia > 4){
		while(distancia > 4){
			distancia = vr_distancia();
			displayCenteredBigTextLine(4,"%d",distancia);

			setMultipleMotors(10, ME, MD);
		}
	}else if(distancia < 4){
		while(distancia < 4){
			distancia = vr_distancia();
			displayCenteredBigTextLine(4,"%d",distancia);

			setMultipleMotors(-10, ME, MD);
		}
	}

	stopAllMotors();

	esquerda = getColorName(S2);
	while(esquerda!= 6){
		esquerda = getColorName(S2);
		displayCenteredBigTextLine(10, "%d", esquerda);
		setMotor(ME, 15);
		setMotor(MD, -15);
	}

	stopAllMotors();

	playSound(soundFastUpwardTones);
	wait(1, minutes);
}
