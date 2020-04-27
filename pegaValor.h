#define branco 6
#define preto  1
int le_erro;
#include <vr_funcoes.h>

int leValores(){

	//int arduino = vr_linha();
	//int senMeio = getColorReflected(SF);
	int senEsquerda = getColorName(SE);
	int senDireita = getColorName(SD);



	// branco 2 -  4
	//preto 2 - 3
	// Epreto Dbranco  - 1
	// Dpreto Ebranco - 2

	if ( (senDireita == branco) && (senEsquerda == branco)) {
		le_erro = 0;
	}

	if ( (senDireita == branco) && (senEsquerda == preto) )
	{
			le_erro = 1;
	}

	if ((senDireita == preto) && (senEsquerda == branco))
	{
			le_erro = -1;

	}
	//////////////////////////////////////////////
	//OUTROS CASOS
	/*if ((senDireita == preto) && (senEsquerda == preto) && (senMeio == preto)) {
		le_erro = 0;
	}*/

	return le_erro;
}
