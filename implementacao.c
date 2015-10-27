#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "funcoes.h"

struct NO
{
	unsigned long long int item;
	struct NO *anterior;
};

struct pilha_dinamica
{
	NO *topo;
	unsigned long long int tamanho;
};
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void identifica(PILHA_DINAMICA *pilha, char *pega)
{
	if(*pega == 'E') enter(pilha);
	else if(*pega == '+') operacao(pilha,*pega);
	else if(*pega == '-') operacao(pilha,*pega);
	else if(*pega == '/') operacao(pilha,*pega);
	else if(*pega == '*') operacao(pilha,*pega);
	else if(*pega == '!') operacao(pilha,*pega);
	else if(*pega == '^') operacao(pilha,*pega);
	else 
	{
		unsigned long long int numero = atoi(pega);
		entrarnumero(pilha,&numero);
	}
}
//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
PILHA_DINAMICA *criar_pilha()
{
	PILHA_DINAMICA *pilha = (PILHA_DINAMICA *) malloc(sizeof(PILHA_DINAMICA));
	
	if(pilha!=NULL)
	{
		pilha->topo = NULL;
		pilha-> tamanho = 0;
	}
	return pilha;
}
//-----------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
unsigned long long int pop(PILHA_DINAMICA *pilha)
{
    NO *aux;
    unsigned long long int num;
   
		aux=pilha->topo;
		pilha->topo = aux->anterior; 
		num = (aux->item);
		pilha->tamanho--;
        free(aux);
		return(num);
    
}
//-----------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
void push(PILHA_DINAMICA *pilha, unsigned long long int *elemento) 
{
	NO *aux;
    aux = (struct NO *) malloc(sizeof(struct NO)); 
        
    if (aux==NULL)
	{ //Se não for possível a alocação, sai do programa
       exit(0);
    }
		(aux->item) = *elemento;
		aux->anterior = pilha->topo;
		pilha->topo=aux;
        pilha-> tamanho++;
		//MostrarPilha(pilha);
}
//-----------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
void MostrarPilha(PILHA_DINAMICA *pilha) 
{  
	unsigned long long int ajuda [10000], num;
	int i=1;
    NO *p;
	if(pilha->topo!=NULL)
	{
		p=pilha->topo;
        while(p != NULL) 
        { 
        	//num = p-> item;
			ajuda[i] = (p-> item);
            p=p->anterior;
            if(p!=NULL)
            	i++;
        } 
		while(i>0)
		{
			printf("%llu ", ajuda[i]);
			i--;
		}
		printf("\n");
	}
	else printf("-\n");
}
//-----------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
void enter(PILHA_DINAMICA *pilha)
{
	unsigned long long int ajuda=0;
	push(pilha,&ajuda);
}
//-----------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
void entrarnumero(PILHA_DINAMICA *pilha, unsigned long long int *num)
{
	unsigned long long int ajuda = (pilha->topo->item);
	ajuda = (ajuda*10) + (*num);
	pilha -> topo -> item = ajuda;
	//MostrarPilha(pilha);
}
//-----------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
void operacao(PILHA_DINAMICA *pilha, char operacao)
{
	NO *p=pilha->topo;
	if(operacao == '!')
	{
		unsigned long long int num1 = pop(pilha);
		unsigned long long int fat=1, i;
		for(i=1;i<=num1;i++)
			fat = fat * i;			
		push(pilha, &fat);
	}
	else
	{
		
		unsigned long long int num2 = pop(pilha);
		unsigned long long int num1 = pop(pilha);
		
		if(operacao == '+')
		{
			num1 = num1 + num2;
			push(pilha, &num1);
		}
		else if(operacao == '-')
		{
			num1 = num1 - num2;
			push(pilha, &num1);
		}
		else if(operacao == '*')
		{
			num1 = num1 * num2;
			push(pilha, &num1);
		}
		else if(operacao == '/')
		{
			num1 = num1/num2;
			push(pilha, &num1);
		}	
		else if(operacao == '^')
		{
			num1 =  pow(num1,num2);
			push(pilha, &num1);
		}
		
	}
}
//-----------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
void clear (PILHA_DINAMICA **pilha)
{
	
		NO *p = (*pilha)->topo;
		
		while(p!=NULL)
		{
			NO *prem = p;
			p = p->anterior;
			prem -> anterior = NULL;
			
			free(prem);
		}
	
	(*pilha)->topo = NULL;
}
//-----------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
