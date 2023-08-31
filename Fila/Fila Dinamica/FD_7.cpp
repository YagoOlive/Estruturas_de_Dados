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

TipoApontador Busca_Item(char chave, TipoFila fila){
	TipoApontador Aux, p=NULL;
	Aux = fila.Frente->Prox;
	while (Aux != NULL){
		if(Aux->Item.chave==chave)
			p=Aux;
			
		Aux = Aux->Prox ;
	}
	return p;
}
/*Receba duas Filas dinâmicas (A e B) e gere uma terceira Fila (passada como parâmetro) que seja a
diferença entre A e B, ou seja, os elementos que pertencem a A e não pertencem a B.*/

void GeraFila(TipoFila fila1, TipoFila fila2, TipoFila fila3){
	
	TipoApontador aux1=fila1.Frente, aux2=fila2.Frente, q, auxcel; 
	TipoItem item;
	int ind;
	
	
	while(aux1->Prox!=NULL){
		ind=0;
		while(aux2->Prox!=NULL){
			
			if(aux1->Item.chave == aux2->Item.chave){
				ind=1;
				break;
			}
			aux2=aux2->Prox;
		}
		if(ind==0){
			item.chave=aux1->Item.chave;
			Enfileira(item, &fila3);
		}
		aux1=aux1->Prox;
	}
	
	
}


main(){
	
	TipoItem item;
	
	TipoFila fila1;
	FFVazia(&fila1);
	
	TipoFila fila2;
	FFVazia(&fila2);
	
	TipoFila fila3;
	FFVazia(&fila3);
	
	item.chave='A'; Enfileira(item, &fila1);
	item.chave='B'; Enfileira(item, &fila1);
	item.chave='C'; Enfileira(item, &fila1);
	item.chave='D'; Enfileira(item, &fila1);
	
	item.chave='A'; Enfileira(item, &fila2);
	item.chave='F'; Enfileira(item, &fila2);
	item.chave='E'; Enfileira(item, &fila2);
	item.chave='D'; Enfileira(item, &fila2);
	
	//printf("\nExibindo a fila\n");
	//exibe(fila);
	
	
	 GeraFila(fila1, fila2, fila3);
	
	printf("\n");
	exibe(fila3);
}
