//Arquivo .h com as declar��es de fun��es e estruturas de dados

//Estruturas: N�s e Pilha din�mica
typedef struct pilha_dinamica PILHA_DINAMICA;
typedef struct NO NO;

//Recebe um ponteiro tipo pilha e um char de opera��o
void identifica(PILHA_DINAMICA *pilha, char *pega);
//realiza a opera��o passada pela fun��o "identifica" (+, -, / ...)
void operacao(PILHA_DINAMICA *pilha, char operacao);
//Cria uma pilha e retorna ela
PILHA_DINAMICA *criar_pilha();

unsigned long long int pop(PILHA_DINAMICA *pilha);
void push(PILHA_DINAMICA *pilha, unsigned long long int *elemento);

//Mostra todas as etapas das opera��es imprimindo a pilha na tela a cada passagem
void MostrarPilha(PILHA_DINAMICA *pilha);
//Push zero para a pilha
void enter(PILHA_DINAMICA *pilha);
//Modifica o int do topo com (topo*10+ numero_fornecido)
void entrarnumero(PILHA_DINAMICA *pilha, unsigned long long int *num);
//limpa a pilha
void clear (PILHA_DINAMICA **pilha);
