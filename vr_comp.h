#include<vr_funcoes.h>

void vr_func_rampa(){
	playSound(soundBeepBeep);
	int vr_var_dist_direita = vr_distancia_direita();

	while(vr_var_dist_direita < 12){
		setMultipleMotors(60, motorA, motorB);
		vr_var_dist_direita = vr_distancia_direita();
		delay(50);
	}

	displayBigTextLine(4, "SAIU DA RAMPA");
	stopAllMotors();
	wait(2, minutes);
}
