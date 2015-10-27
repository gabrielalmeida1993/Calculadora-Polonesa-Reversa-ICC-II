//Arquivo .h com as declarções de funções e estruturas de dados

//Estruturas: Nós e Pilha dinâmica
typedef struct pilha_dinamica PILHA_DINAMICA;
typedef struct NO NO;

//Recebe um ponteiro tipo pilha e um char de operação
void identifica(PILHA_DINAMICA *pilha, char *pega);
//realiza a operação passada pela função "identifica" (+, -, / ...)
void operacao(PILHA_DINAMICA *pilha, char operacao);
//Cria uma pilha e retorna ela
PILHA_DINAMICA *criar_pilha();

unsigned long long int pop(PILHA_DINAMICA *pilha);
void push(PILHA_DINAMICA *pilha, unsigned long long int *elemento);

//Mostra todas as etapas das operações imprimindo a pilha na tela a cada passagem
void MostrarPilha(PILHA_DINAMICA *pilha);
//Push zero para a pilha
void enter(PILHA_DINAMICA *pilha);
//Modifica o int do topo com (topo*10+ numero_fornecido)
void entrarnumero(PILHA_DINAMICA *pilha, unsigned long long int *num);
//limpa a pilha
void clear (PILHA_DINAMICA **pilha);
