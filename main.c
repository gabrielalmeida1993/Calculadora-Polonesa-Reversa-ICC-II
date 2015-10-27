#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "funcoes.h"


int main ()
{
	char expressao[10000];
	char *pega;
	PILHA_DINAMICA *pilha = criar_pilha();
	
	fgets(expressao,10000,stdin);
	
	MostrarPilha(pilha);
	pega = strtok(expressao, " ");
	
	while(pega!=NULL)
	{
		if(*pega== 'C')
		{
			clear(&pilha);
		}
		else identifica(pilha,pega);
		MostrarPilha(pilha);
		pega = strtok(NULL, " ");
	}
	//system("PAUSE");
}
