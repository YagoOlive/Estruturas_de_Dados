#include<stdio.h>
#include<stdlib.h>

// Estrutura de Dados Fila Din?mica
typedef struct TipoCelula *TipoApontador; 

typedef struct TipoItem { 
	int chave;
} TipoItem;

typedef struct TipoCelula {
	TipoItem Item;
	TipoApontador Prox;
} TipoCelula; 

typedef struct TipoFila {
	TipoApontador Frente, Tras;
}TipoFila;

// Fun??es de manipula??o da Fila Din?mica
void FFVazia(TipoFila *Fila ) { 
	Fila ->Frente = (TipoApontador) malloc(sizeof(TipoCelula )); 
	Fila ->Tras = Fila ->Frente; 
	Fila ->Frente ->Prox = NULL; 
}

int Vazia(TipoFila Fila ) { 
	return ( Fila.Frente == Fila.Tras) ;
}

void Enfileira (TipoItem x, TipoFila *Fila ) { 
	Fila ->Tras ->Prox = (TipoApontador) malloc(sizeof(TipoCelula )); 
	Fila ->Tras = Fila ->Tras ->Prox;
	Fila ->Tras ->Item = x; 
	Fila ->Tras ->Prox = NULL; 
}

void Desenfileira(TipoFila *Fila , TipoItem *Item) { 
	TipoApontador q; 
	if (Vazia( *Fila ) ) { 
		printf ( "Erro fila esta vazia\n" ) ; return;
	} 
	q = Fila ->Frente; 
	Fila ->Frente = Fila ->Frente ->Prox; 
	*Item = Fila ->Frente ->Item; 
	free(q); 
}

void exibe (TipoFila fila){
	TipoApontador aux=fila.Frente->Prox;
	while(aux!=NULL){
		printf("\n%c", aux->Item.chave);
		aux=aux->Prox;
	}
}

/* 1. Receba uma Fila de n?meros (n?o ordenada) e mova a c?lula que 
   cont?m o maior valor para a primeira posi??o (com informa??o v?lida) 
   da Fila.
*/
void moveMaior(TipoFila *fila){
	TipoApontador aux=fila->Frente, antesMaior=fila->Frente, p;
	int maior=fila->Frente->Prox->Item.chave;
	
	while(aux->Prox!=NULL){
		if(aux->Prox->Item.chave > maior){
			antesMaior=aux;
			maior=aux->Prox->Item.chave;
		}
		aux=aux->Prox;
	}
	p=antesMaior->Prox;
	antesMaior->Prox=p->Prox;
	p->Prox=fila->Frente->Prox;
	fila->Frente->Prox=p;
}

void FuraFila(TipoFila *fila, TipoItem item){
	
	TipoApontador p;
	
	p=(TipoApontador)malloc(sizeof(TipoCelula));
	p->Prox=fila->Frente->Prox;
	fila->Frente->Prox=p;
	p->Item=item;
		
}

main(){
	TipoFila fila;
	FFVazia(&fila);
	TipoItem item;
	item.chave='A'; Enfileira(item, &fila);
	item.chave='B'; Enfileira(item, &fila);
	item.chave='C'; Enfileira(item, &fila);
	item.chave='D'; Enfileira(item, &fila);
	printf("\nExibindo a fila\n");
	exibe(fila);
	
	item.chave='Z';	
	FuraFila(&fila, item);
	
	printf("\n\n");
	exibe(fila);
}
