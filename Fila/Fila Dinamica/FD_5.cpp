#include<stdio.h>
#include<stdlib.h>

// Estrutura de Dados Fila Din?mica
typedef struct TipoCelula *TipoApontador; 

typedef struct TipoItem { 
	int numero;
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
		printf("\n%d", aux->Item.numero);
		aux=aux->Prox;
	}
}



int OrdemCrescente(TipoFila *fila){
	TipoApontador aux=fila->Frente;
	int maior=fila->Frente->Prox->Item.numero;
	
	while(aux->Prox!=NULL){
		if(aux->Prox->Item.numero < maior){
			return 0;
		}
		aux=aux->Prox;
	}
	return 1;
}

main(){
	TipoFila fila;
	FFVazia(&fila);
	TipoItem item;
	item.numero=1; Enfileira(item, &fila);
	item.numero=2; Enfileira(item, &fila);
	item.numero=4; Enfileira(item, &fila);
	item.numero=6; Enfileira(item, &fila);
	printf("\nExibindo a fila\n");
	exibe(fila);
	

	
	printf("\n\n%d", OrdemCrescente(&fila));
	//exibe(fila);
}
