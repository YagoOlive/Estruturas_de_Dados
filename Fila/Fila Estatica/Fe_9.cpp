/*Receba uma Lista estática e inverta a ordem do itens da lista utilizando uma Pilha Dinâmica.*/

#define INICIOARRANJO 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXTAM 5

typedef int TipoApontadorFila;
typedef struct TipoCelula *TipoApontador; 

 struct TipoItem{
int cod;
float valor;
char operacao[20]; // saque / deposito / pagamento
};

//estrutura da fila estatica
typedef struct {
	TipoItem item [ MAXTAM ] ;
	TipoApontadorFila frente, tras ;
} TipoFila;

// Estrutura Pilha dinamica
typedef struct TipoCelula *TipoApontador; 

typedef struct TipoCelula { 
	TipoItem Item; 
	TipoApontador Prox; 
} TipoCelula; 

typedef struct { 
	TipoApontador  Fundo, Topo; 
	int Tamanho; 
} TipoPilha;

// manipulacao da fila estatica
void FFVazia( TipoFila *fila ){
	fila->frente = 1;
	fila->tras = fila->frente ;
}

int Vazia(TipoFila fila){
	return (fila.frente == fila.tras);
}

void Enfileira (TipoItem x, TipoFila * fila){
	if(fila->tras % MAXTAM + 1 == fila->frente)
			printf("Erro fila esta cheia \n" ) ;
	else {
             fila->item[fila->tras-1]=x;
             fila->tras=fila->tras%MAXTAM+1;
     }
}

void Desenfileira ( TipoFila * fila , TipoItem * item){
	if(Vazia(*fila))
		    printf("Erro fila esta vazia \n" ) ;
	else {
			 *item=fila->item [fila->frente - 1];
			 fila->frente = fila->frente % MAXTAM+1;
	}
}

void exibe (TipoFila fila){
	int i;	
	for(i=fila.frente;i != fila.tras; i=i% MAXTAM+1){
		
			printf(" posicao vetor= %d\n", i-1);
		printf(" %d\n", fila.item[i-1].cod);
		printf("operacao= %s\n", fila.item[i-1].operacao);
		printf("valor= %2.f\n\n", fila.item[i-1].valor);
	}
}

// manipulacao da pilha dinamica
void FPVazia(TipoPilha *Pilha) { 
	Pilha ->Topo=(TipoApontador) malloc(sizeof(TipoCelula)); 
	Pilha ->Fundo = Pilha ->Topo; 
	Pilha ->Topo->Prox = NULL; 
	Pilha ->Tamanho = 0; 
}

int Vazia(TipoPilha Pilha) {
	return ( Pilha .Topo == Pilha .Fundo) ; 
}

void Empilha(TipoItem x, TipoPilha *Pilha) { 
	TipoApontador Aux; 
	Aux = (TipoApontador) malloc(sizeof(TipoCelula)); 
	Pilha ->Topo->Item = x; 
	Aux->Prox = Pilha ->Topo; 
	Pilha ->Topo = Aux; 	
	Pilha ->Tamanho++; 
}

void Desempilha(TipoPilha *Pilha , TipoItem *Item) {
	TipoApontador q; 
	if (Vazia( *Pilha ) ) { 
		printf ( "Erro : lista vazia\n" ) ; 	return; 
	} 
	q = Pilha ->Topo; 
	Pilha ->Topo = q ->Prox; 
	*Item = q ->Prox->Item; 
	free(q) ;
	Pilha ->Tamanho--; 
}

int Tamanho(TipoPilha Pilha) { 
	return ( Pilha .Tamanho) ; 
}

void exibePilha(TipoPilha pilha){
	TipoApontador aux=pilha.Topo->Prox;
	while(aux!=NULL){
		printf(" %d\n", aux->Item.cod);
		printf("operacao= %s\n", aux->Item.operacao);
		printf("valor= %2.f\n\n", aux->Item.valor);
		aux=aux->Prox;
	}
}

/*TipoApontador busca(TipoPilha pilha, TipoItem item){
	TipoApontador aux=pilha.Topo->Prox;
	while(aux!=NULL){
		if(aux->Item.chave==item.chave)
			return aux;
		aux=aux->Prox;		
	}
	return NULL;
}*/

void Invertefila(TipoFila *fila){
	
	TipoPilha pilha;
	TipoItem item;
	int i;
	
	FPVazia(&pilha);
	
	for(i=fila->frente;i != fila->tras; i=i% MAXTAM+1){
			Desenfileira(fila, &item);
			Empilha(item, &pilha);
			i=fila->frente;
	}
	while(!Vazia(pilha)){
		
		Desempilha(&pilha , &item);
		Enfileira(item, fila);
	}
}

main(){
	TipoItem item;
	TipoFila fila;
	
	FFVazia(&fila);
	
	item.cod=1; strcpy(item.operacao, "pagamento"); item.valor= 600.00; Enfileira(item, &fila);
	item.cod=2; strcpy(item.operacao, "deposito"); item.valor= 100.00; Enfileira(item, &fila);
	item.cod=3; strcpy(item.operacao, "pagamento"); item.valor= 500.00; Enfileira(item, &fila);
	item.cod=4; strcpy(item.operacao, "pagamento"); item.valor= 500.00; Enfileira(item, &fila);
	
	Desenfileira(&fila, &item);
	Desenfileira(&fila, &item);
	Desenfileira(&fila, &item);

	item.cod=5; strcpy(item.operacao, "deposito"); item.valor= 500.00; Enfileira(item, &fila);
	item.cod=6; strcpy(item.operacao, "pagamento"); item.valor= 500.00; Enfileira(item, &fila);


	exibe(fila);
	printf("\n\n");
	
	Invertefila(&fila);
	
	
	exibe(fila);
	printf("\n\n");
}

